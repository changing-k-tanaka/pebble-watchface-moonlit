# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## プロジェクト概要

Pebble Watch 用ウォッチフェイス「Moonlit」。時刻と日の出・日没に応じて景色が切り替わる。

- **昼間**: 月面から見た地球を描く（青い地球・大陸・雲）
- **夜間**: 夜空（星・月の満ち欠け・流れ星・彗星）
- **情報ウィジェット**: Steps / Heart Rate / Battery / Weather + Temp / Precipitation を左右に表示可能

ターゲットプラットフォーム: `basalt`, `chalk`, `emery`, `gabbro`（emery がメイン）

## ビルドとテスト

```bash
# ビルド
pebble build

# エミュレータで実行（emery がデフォルト）
pebble install --emulator emery

# ログ確認
pebble logs --emulator emery

# スクリーンショット取得
pebble screenshot --no-open --emulator emery screenshot_emery.png

# プレビューGIF生成
python3 .claude/skills/pebble-watchface/scripts/create_preview_gif.py . --frames 8 --delay 400

# アプリアイコン生成
python3 .claude/skills/pebble-watchface/scripts/create_app_icons.py .
```

成果物: `build/horoscope.pbw`

## アーキテクチャ

Watch 側の主要実装は `src/c/moonlit.c`、設定 UI と天気・日の出日の入り取得は `src/pkjs/index.js` にある。

### 状態管理

グローバルな `AppState s_state` 1つに全状態を集約:
- `VisualMode mode` — 時刻帯（6段階）
- `Star stars[STAR_COUNT]` — 星の固定配置（LCGで固定シード生成）
- `ShootingStar shoot` / `Comet comet` — アニメーション要素（`ANIM_IDLE` / `ANIM_ACTIVE`）
- `MoonState moon` — 基準新月タイムスタンプから整数演算で計算する月相
- `widget_*` 群 — Steps / Heart Rate / Weather / Battery / Bluetooth 状態
- `layout_date_y` / `layout_time_y` — Timeline Quick View を避ける動的レイアウト位置

### 時刻帯と描画モード

`VisualMode` enum で時刻を6段階に分類し、`s_settings.sunrise_min` / `sunset_min` を基準に各モードを切り替える。各モードで空の背景色・星の表示数・天体の描画を制御する。

| モード | 時刻 | 特徴 |
|--------|------|------|
| `MODE_DAYTIME` | `sunrise + 30m` 〜 sunset | 月面から見た地球（Earth view） |
| `MODE_EARLY_EVE` | sunset 〜 `sunset + 1h`、および `sunrise - 1h` 〜 `sunrise + 30m` | 夕暮れ / 薄明グラデーション、星少数 |
| `MODE_LATE_NIGHT` | `sunset + 1h` 〜 `sunset + 3h` | 暗い青空、星多数 |
| `MODE_MIDNIGHT` | `sunset + 3h` 〜 `sunrise - 1h` | 純黒、全星表示 |
| `MODE_EVE_DARK` | 自動遷移では未使用。空色オーバーライドで選択可 | 濃い青空 |
| `MODE_DAWN` | 自動遷移では未使用。空色オーバーライドで選択可 | 地平線に薄青 |

### プラットフォーム分岐

`PLATFORM_RICH`（emery・gabbro）と非リッチ（basalt・chalk）で描画処理が分岐する。

- **PLATFORM_RICH=1**: 彩色月面（`prv_draw_moon_rich`）・彩色彗星テール・コメット出現
- **PLATFORM_RICH=0**: 白黒月面（`prv_draw_moon_simple`）・流れ星のみ

レイアウト定数（`SCREEN_W`, `SKY_ZONE_H`, `TIME_Y` など）はすべてセクション1のプラットフォームマクロで定義。

### アニメーション設計

`app_timer_register(50ms)` でアニメーションタイマーを駆動するが、アニメーション要素が `ANIM_IDLE` になった時点でタイマーを停止するバッテリー効率設計。  
バッテリー残量 20% 未満かつ非充電中はフレーム間隔を 100ms に自動延長する。

流れ星・彗星の出現はミニット単位の `tick_handler` 内で LCG 乱数により確率的にスポーン。アニメーション中のみタイマーが回る。

### Health / システムイベント

- `health_service_events_subscribe()` で Steps / Heart Rate ウィジェットを随時更新
- 心拍数は「今日 00:00 から現在」ではなく直近 5 分窓で可用性を確認する
- `connection_service_subscribe()` で Bluetooth 切断状態を監視し、設定に応じてバイブ
- `unobstructed_area_service_subscribe()` で Timeline Quick View 表示時に時刻・日付行を上へ再配置

### レイヤー構成

```
Window (黒背景)
 ├── canvas_layer (全画面カスタム描画)
 │    ├── 空背景（グラデーション帯）
 │    ├── テキストエリア背景（黒）
 │    ├── 地球 or 星フィールド
 │    ├── 月
 │    ├── 流れ星
 │    └── 彗星（PLATFORM_RICH のみ）
 ├── time_layer (TextLayer: HH:MM)
 └── date_layer (TextLayer: YYYY/MM/DD DOW)
```

### 月相計算

`prv_calc_moon_phase()` は `time_t` を基に、基準新月 `2000-01-06 18:14 UTC` からの秒差を朔望月長 `2551443` 秒で割って phase (0〜7) と illumination (0〜100) を算出する。描画側では新月付近 / 満月付近のしきい値を使って不自然な縁残りを避けている。

## 重要な制約

- **浮動小数点なし** — sin/cos が必要なら `sin_lookup()` / `cos_lookup()` を使用
- **タイマーは必要時のみ** — アニメーション要素が全 IDLE になったらタイマーを止める
- **`tick_timer_service_subscribe(MINUTE_UNIT, ...)`** — SECOND_UNIT は使用禁止
- **テキストバッファはAppStateに保持** — `text_layer_set_text()` に渡す文字列の寿命に注意
