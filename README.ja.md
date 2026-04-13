# Moonlit（星空）

Pebble 用ウォッチフェイス。時刻に応じて「月面から見た地球」と「夜空」が切り替わる。

## AppStore Link

Moonlit - Pebble Appstore https://apps.repebble.com/962806faa9fb4eb4a211acbd

## 機能

### 時刻帯による景色の切り替え

| モード | 時刻 | 描画 |
|--------|------|------|
| 昼間 | 日の出〜日の入り | 月面から見た地球（青い地球・大陸・雲） |
| 宵の口 | 18〜19時 | 夕暮れグラデーション、星少数 |
| 宵闇 | 20〜21時 | 濃い青空、星多め |
| 夜更け | 22〜23時 | ほぼ黒、星多数 |
| 深夜 | 00〜02時 | 純黒、全星表示 |
| 薄明 | 03〜05時 | 地平線に薄青 |

日の出・日の入り時刻は GPS で自動取得（デフォルト 06:00 / 18:00）。

### 天体アニメーション

- **流れ星** — ミニット毎に約 20% の確率で出現
- **彗星** — emery / gabbro のみ、約 6.7% の確率で出現
- **月** — ユリウス日から整数演算で月相（朔望月 29.531 日）を算出し 8 段階で描画

### 情報ウィジェット

左右の隅に任意の情報を 1 つずつ表示できる。

| ウィジェット | 内容 |
|-------------|------|
| Steps | 歩数（Pebble Health 必要） |
| Heart Rate | 心拍数（Pebble Health 必要） |
| Battery | バッテリー残量 % |
| Weather + Temp | 天気アイコン＋気温 |
| Precipitation | 降水確率 % |

天気は [Open-Meteo](https://open-meteo.com/) から取得。都市名入力または GPS で位置を特定。

### その他

- 日付フォーマット 15 種類から選択
- Bluetooth 切断時バイブレーション（設定で切替可）
- バッテリー残量 20% 未満時はアニメーション間隔を自動延長（省電力）

## 対応プラットフォーム

| プラットフォーム | 画面サイズ | 備考 |
|-----------------|-----------|------|
| **emery** | 200×228 | メイン開発環境、カラー・彗星対応 |
| **gabbro** | 260×260 (丸型) | カラー・彗星対応 |
| basalt | 144×168 | 白黒、流れ星のみ |
| chalk | 180×180 (丸型) | 白黒、流れ星のみ |

## ビルドとインストール

```bash
# ビルド
pebble build

# エミュレータで実行
pebble install --emulator emery

# ログ確認
pebble logs --emulator emery

# スクリーンショット取得
pebble screenshot --no-open --emulator emery screenshot_emery.png
```

成果物: `build/horoscope.pbw`

## 設定

Pebble アプリの設定画面から以下を変更できる。

- 表示モード（自動 / 強制昼間 / 強制夜間）
- 夜空の色合い
- 流れ星・彗星の有効/無効、出現率
- 情報ウィジェット（左右スロット）
- 天気取得都市（空白で GPS）
- 日付フォーマット
- Bluetooth 切断バイブ

## アーキテクチャ

- `src/c/horoscope.c` — すべての描画・ロジックを含む単一ファイル（18 セクション構成）
- `src/pkjs/index.js` — 設定 UI・天気取得・日の出日の入り計算（PebbleKit JS）

### 設計上の制約

- **浮動小数点なし** — sin/cos は `sin_lookup()` / `cos_lookup()` を使用
- **SECOND_UNIT 禁止** — `tick_timer_service_subscribe(MINUTE_UNIT, ...)` のみ使用
- **タイマーは必要時のみ** — アニメーション要素が全 IDLE になったらタイマーを停止
- **テキストバッファは AppState に保持** — `text_layer_set_text()` に渡す文字列の寿命管理

## ライセンス

MIT
