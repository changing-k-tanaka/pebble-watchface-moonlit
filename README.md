# Moonlit

A Pebble watchface that switches between an Earth view from the Moon and a night sky depending on the time of day.

[日本語版 README](README.ja.md)

## AppStore Link

Moonlit - Pebble Appstore https://apps.repebble.com/962806faa9fb4eb4a211acbd

## Features

### Time-based visual modes

| Mode | Time | Display |
|------|------|---------|
| Daytime | Sunrise to sunset | Earth from the Moon (blue Earth with continents and clouds) |
| Early Evening | 18:00–19:59 | Twilight gradient, sparse stars |
| Evening Dark | 20:00–21:59 | Deep blue sky, more stars |
| Late Night | 22:00–23:59 | Near-black sky, many stars |
| Midnight | 00:00–02:59 | Pure black, all stars visible |
| Pre-Dawn | 03:00–05:59 | Faint blue on the horizon |

Sunrise and sunset times are fetched automatically via GPS (defaults: 06:00 / 18:00).

### Celestial animations

- **Shooting stars** — ~20% chance of appearing each minute
- **Comets** — emery / gabbro only, ~6.7% chance per minute
- **Moon** — phase calculated from the Julian date using integer arithmetic (8 phases over 29.531-day synodic month)

### Info widgets

Up to two information slots (left and right corner) can be configured independently.

| Widget | Content |
|--------|---------|
| Steps | Step count (requires Pebble Health) |
| Heart Rate | Heart rate (requires Pebble Health) |
| Battery | Battery percentage |
| Weather + Temp | Weather icon and temperature |
| Precipitation | Precipitation probability (%) |

Weather data is fetched from [Open-Meteo](https://open-meteo.com/) using a city name or GPS coordinates.

### Other

- 15 date format options
- Optional vibration on Bluetooth disconnect
- Animation interval automatically doubles when battery falls below 20% (power saving)

## Supported platforms

| Platform | Screen | Notes |
|----------|--------|-------|
| **emery** | 200×228 | Primary target, color, comet support |
| **gabbro** | 260×260 (round) | Color, comet support |
| basalt | 144×168 | Monochrome, shooting stars only |
| chalk | 180×180 (round) | Monochrome, shooting stars only |

## Build & install

```bash
# Build
pebble build

# Run in emulator
pebble install --emulator emery

# View logs
pebble logs --emulator emery

# Take a screenshot
pebble screenshot --no-open --emulator emery screenshot_emery.png
```

Output artifact: `build/horoscope.pbw`

## Configuration

The following settings are available from the Pebble app's configuration screen:

- Display mode (auto / force daytime / force nighttime)
- Night sky color override
- Shooting stars and comets (enable/disable, max probability)
- Info widgets (left and right slots)
- Weather city (leave blank to use GPS)
- Date format
- Bluetooth disconnect vibration

## Architecture

- `src/c/horoscope.c` — All drawing and logic in a single file (18 sections)
- `src/pkjs/index.js` — Settings UI, weather fetching, sunrise/sunset calculation (PebbleKit JS)

### Design constraints

- **No floating-point** — `sin_lookup()` / `cos_lookup()` are used in place of sin/cos
- **No SECOND_UNIT** — `tick_timer_service_subscribe(MINUTE_UNIT, ...)` only
- **Timer runs only when needed** — animation timer is stopped when all elements become idle
- **Text buffers live in AppState** — string lifetime is managed carefully for `text_layer_set_text()`

## License

MIT