# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## プロジェクト概要

Pebble Watch 用ウォッチフェイス「星空」。時刻によって景色が切り替わる。

- **昼間（06:00〜17:59）**: 月面から見た地球を描く（青い地球・大陸・雲）
- **夜間（18:00〜05:59）**: 夜空（星・月の満ち欠け・流れ星・彗星）

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

コードはすべて `src/c/horoscope.c` の1ファイルに収まっており、18のセクションに分かれている。

### 状態管理

グローバルな `AppState s_state` 1つに全状態を集約:
- `VisualMode mode` — 時刻帯（6段階）
- `Star stars[STAR_COUNT]` — 星の固定配置（LCGで固定シード生成）
- `ShootingStar shoot` / `Comet comet` — アニメーション要素（`ANIM_IDLE` / `ANIM_ACTIVE`）
- `MoonState moon` — 月相（ユリウス日から整数演算で計算）

### 時刻帯と描画モード

`VisualMode` enum で時刻を6段階に分類し、各モードで空の背景色・星の表示数・天体の描画を制御する。

| モード | 時刻 | 特徴 |
|--------|------|------|
| `MODE_DAYTIME` | 06〜17時 | 月面から見た地球（Earth view） |
| `MODE_EARLY_EVE` | 18〜19時 | 夕暮れグラデーション、星少数 |
| `MODE_EVE_DARK` | 20〜21時 | 濃い青空、星多め |
| `MODE_LATE_NIGHT` | 22〜23時 | ほぼ黒、星多数 |
| `MODE_MIDNIGHT` | 00〜02時 | 純黒、全星表示 |
| `MODE_DAWN` | 03〜05時 | 地平線に薄青 |

### プラットフォーム分岐

`PLATFORM_RICH`（emery・gabbro）と非リッチ（basalt・chalk）で描画処理が分岐する。

- **PLATFORM_RICH=1**: 彩色月面（`prv_draw_moon_rich`）・彩色彗星テール・コメット出現
- **PLATFORM_RICH=0**: 白黒月面（`prv_draw_moon_simple`）・流れ星のみ

レイアウト定数（`SCREEN_W`, `SKY_ZONE_H`, `TIME_Y` など）はすべてセクション1のプラットフォームマクロで定義。

### アニメーション設計

`app_timer_register(50ms)` でアニメーションタイマーを駆動するが、アニメーション要素が `ANIM_IDLE` になった時点でタイマーを停止するバッテリー効率設計。  
バッテリー残量 20% 未満かつ非充電中はフレーム間隔を 100ms に自動延長する。

流れ星・彗星の出現はミニット単位の `tick_handler` 内で LCG 乱数により確率的にスポーン。アニメーション中のみタイマーが回る。

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

`prv_calc_moon_phase()` がユリウス日を整数演算で求め、朔望月（29.531日）に対する位置から phase (0〜7) と illumination (0〜100) を算出。浮動小数点演算は使用していない。

## 重要な制約

- **浮動小数点なし** — sin/cos が必要なら `sin_lookup()` / `cos_lookup()` を使用
- **タイマーは必要時のみ** — アニメーション要素が全 IDLE になったらタイマーを止める
- **`tick_timer_service_subscribe(MINUTE_UNIT, ...)`** — SECOND_UNIT は使用禁止
- **テキストバッファはAppStateに保持** — `text_layer_set_text()` に渡す文字列の寿命に注意