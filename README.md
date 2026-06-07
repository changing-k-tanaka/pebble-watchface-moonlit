# Moonlit

A Pebble watchface that switches between an Earth view from the Moon and a night sky depending on the time of day.

[日本語版 README](README.ja.md)

## AppStore Link

Moonlit - Pebble Appstore https://apps.repebble.com/962806faa9fb4eb4a211acbd

## Features

### Time-based visual modes

| Mode | Time | Display |
|------|------|---------|
| Daytime | `sunrise + 30m` to sunset | Earth from the Moon (blue Earth with continents and clouds) |
| Early Evening | sunset to `sunset + 1h`, and `sunrise - 1h` to `sunrise + 30m` | Twilight / dawn glow with sparse stars |
| Late Night | `sunset + 1h` to `sunset + 3h` | Darker blue sky, more stars |
| Midnight | `sunset + 3h` to `sunrise - 1h` | Pure black, all stars visible |
| Evening Dark | Manual sky-color override only | Deep blue night palette |
| Pre-Dawn | Manual sky-color override only | Faint blue on the horizon |

Sunrise and sunset times are fetched automatically via GPS (defaults: 06:00 / 18:00).

### Celestial animations

- **Shooting stars** — ~20% chance of appearing each minute
- **Comets** — emery / gabbro only, ~6.7% chance per minute
- **Moon** — phase calculated from a reference new-moon timestamp using integer arithmetic, with near-new / near-full thresholds for cleaner rendering

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
- Time and date rows shift upward automatically when Timeline Quick View obstructs the screen

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

- `src/c/moonlit.c` — All drawing and logic in a single file, including unobstructed-area layout handling and Health widget updates
- `src/pkjs/index.js` — Settings UI, weather fetching, sunrise/sunset calculation (PebbleKit JS)

### Design constraints

- **No floating-point** — `sin_lookup()` / `cos_lookup()` are used in place of sin/cos
- **No SECOND_UNIT** — `tick_timer_service_subscribe(MINUTE_UNIT, ...)` only
- **Timer runs only when needed** — animation timer is stopped when all elements become idle
- **Text buffers live in AppState** — string lifetime is managed carefully for `text_layer_set_text()`
- **Health widgets are event-driven** — steps and heart rate refresh through Pebble Health events
- **Timeline-safe layout** — text rows are recomputed from the unobstructed area when system overlays appear

## License

MIT
