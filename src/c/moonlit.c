#include <pebble.h>

// Auto-generated message key declarations (from package.json messageKeys)
extern uint32_t MESSAGE_KEY_SETTINGS_MODE_OVERRIDE;
extern uint32_t MESSAGE_KEY_SETTINGS_SHOOT_ENABLE;
extern uint32_t MESSAGE_KEY_SETTINGS_SHOOT_MAX;
extern uint32_t MESSAGE_KEY_SETTINGS_COMET_ENABLE;
extern uint32_t MESSAGE_KEY_SETTINGS_COMET_MAX;
extern uint32_t MESSAGE_KEY_WIDGET_LEFT;
extern uint32_t MESSAGE_KEY_WIDGET_RIGHT;
extern uint32_t MESSAGE_KEY_WEATHER_TEMP;
extern uint32_t MESSAGE_KEY_WEATHER_DESC;
extern uint32_t MESSAGE_KEY_WEATHER_PRECIP;
extern uint32_t MESSAGE_KEY_DATE_FMT;
extern uint32_t MESSAGE_KEY_SETTINGS_BT_VIBE;

// ============================================================
// SECTION 1: PLATFORM MACROS
// ============================================================

#if defined(PBL_PLATFORM_EMERY)
  #define SCREEN_W       200
  #define SCREEN_H       228
  #define PLATFORM_RICH  1
  #define STAR_COUNT     54
  #define SKY_ZONE_H     144
  #define MOON_POS_X     150
  #define MOON_POS_Y     70
  #define MOON_RADIUS    22
  #define EARTH_POS_X    100
  #define EARTH_POS_Y    72
  #define EARTH_RADIUS   45
  #define TIME_Y         147
  #define TIME_H         46
  #define TIME_FONT      FONT_KEY_LECO_42_NUMBERS
  #define AMPM_X         23   // right edge ~53px; immediately left of centered LECO_42 "HH:MM"
  #define AMPM_W         30
  #define AMPM_Y_OFFSET  6    // shift down within TIME_H
  #define AMPM_FONT      FONT_KEY_GOTHIC_18_BOLD
  // Single centered info row: "YYYY/MM/DD DOW"
  #define INFO_Y         196
  #define INFO_H         28
  #define INFO_FONT      FONT_KEY_GOTHIC_24_BOLD
  // Info widgets: top-left and top-right corners
  #define WIDGET_L_X     3
  #define WIDGET_L_Y     3
  #define WIDGET_L_W     90
  #define WIDGET_R_X     107
  #define WIDGET_R_Y     3
  #define WIDGET_R_W     90
  #define WIDGET_H       24
  #define WIDGET_FONT    FONT_KEY_GOTHIC_18_BOLD

#elif defined(PBL_PLATFORM_GABBRO)
  #define SCREEN_W       260
  #define SCREEN_H       260
  #define PLATFORM_RICH  1
  #define STAR_COUNT     54
  #define SKY_ZONE_H     152
  #define MOON_POS_X     195
  #define MOON_POS_Y     58
  #define MOON_RADIUS    26
  #define EARTH_POS_X    130
  #define EARTH_POS_Y    82
  #define EARTH_RADIUS   50
  #define TIME_Y         155
  #define TIME_H         46
  #define TIME_FONT      FONT_KEY_LECO_42_NUMBERS
  #define AMPM_X         53   // right edge ~83px; immediately left of centered LECO_42 "HH:MM"
  #define AMPM_W         30
  #define AMPM_Y_OFFSET  6
  #define AMPM_FONT      FONT_KEY_GOTHIC_18_BOLD
  // At glyph bottom y=230, circle chord 166px — content ~130px fits centered
  #define INFO_Y         204
  #define INFO_H         26
  #define INFO_FONT      FONT_KEY_GOTHIC_24
  // Info widgets: vertically centered left/right (round display)
  // WIDGET_R_Y is 2px higher than WIDGET_L_Y to compensate for the
  // optical illusion on round screens where right-edge content appears lower
  #define WIDGET_L_X     5
  #define WIDGET_L_Y     119
  #define WIDGET_L_W     90
  #define WIDGET_R_X     165
  #define WIDGET_R_Y     117
  #define WIDGET_R_W     90
  #define WIDGET_H       24
  #define WIDGET_FONT    FONT_KEY_GOTHIC_18_BOLD

#elif defined(PBL_PLATFORM_BASALT)
  #define SCREEN_W       144
  #define SCREEN_H       168
  #define PLATFORM_RICH  0
  #define STAR_COUNT     30
  #define SKY_ZONE_H     97
  #define MOON_POS_X     108
  #define MOON_POS_Y     48
  #define MOON_RADIUS    16
  #define EARTH_POS_X    72
  #define EARTH_POS_Y    50
  #define EARTH_RADIUS   24
  #define TIME_Y         100
  #define TIME_H         38
  #define TIME_FONT      FONT_KEY_LECO_38_BOLD_NUMBERS
  #define AMPM_X         2    // basalt is narrow; time starts ~24px so keep at edge
  #define AMPM_W         20
  #define AMPM_Y_OFFSET  4
  #define AMPM_FONT      FONT_KEY_GOTHIC_14_BOLD
  #define INFO_Y         140
  #define INFO_H         22
  #define INFO_FONT      FONT_KEY_GOTHIC_18_BOLD
  // Info widgets: top-left and top-right corners
  #define WIDGET_L_X     2
  #define WIDGET_L_Y     2
  #define WIDGET_L_W     65
  #define WIDGET_R_X     77
  #define WIDGET_R_Y     2
  #define WIDGET_R_W     65
  #define WIDGET_H       22
  #define WIDGET_FONT    FONT_KEY_GOTHIC_18_BOLD

#elif defined(PBL_PLATFORM_CHALK)
  #define SCREEN_W       180
  #define SCREEN_H       180
  #define PLATFORM_RICH  0
  #define STAR_COUNT     30
  #define SKY_ZONE_H     97
  #define MOON_POS_X     134
  #define MOON_POS_Y     38
  #define MOON_RADIUS    18
  #define EARTH_POS_X    90
  #define EARTH_POS_Y    54
  #define EARTH_RADIUS   28
  #define TIME_Y         100
  #define TIME_H         38
  #define TIME_FONT      FONT_KEY_LECO_38_BOLD_NUMBERS
  #define AMPM_X         28   // right edge ~48px; immediately left of centered LECO_38 "HH:MM"
  #define AMPM_W         20
  #define AMPM_Y_OFFSET  4
  #define AMPM_FONT      FONT_KEY_GOTHIC_14_BOLD
  // At glyph bottom y=158, circle chord 113px — "YYYY/MM/DD DOW" ~108px fits
  #define INFO_Y         140
  #define INFO_H         20
  #define INFO_FONT      FONT_KEY_GOTHIC_18
  // Info widgets: vertically centered left/right (round display)
  // WIDGET_R_Y is 2px higher than WIDGET_L_Y to compensate for the
  // optical illusion on round screens where right-edge content appears lower
  #define WIDGET_L_X     5
  #define WIDGET_L_Y     75
  #define WIDGET_L_W     75
  #define WIDGET_R_X     100
  #define WIDGET_R_Y     73
  #define WIDGET_R_W     75
  #define WIDGET_H       20
  #define WIDGET_FONT    FONT_KEY_GOTHIC_14_BOLD

#else
  // fallback - should not happen for color-only build
  #define SCREEN_W       144
  #define SCREEN_H       168
  #define PLATFORM_RICH  0
  #define STAR_COUNT     30
  #define SKY_ZONE_H     97
  #define MOON_POS_X     108
  #define MOON_POS_Y     48
  #define MOON_RADIUS    16
  #define EARTH_POS_X    72
  #define EARTH_POS_Y    50
  #define EARTH_RADIUS   24
  #define TIME_Y         100
  #define TIME_H         38
  #define TIME_FONT      FONT_KEY_LECO_38_BOLD_NUMBERS
  #define AMPM_X         2
  #define AMPM_W         20
  #define AMPM_Y_OFFSET  4
  #define AMPM_FONT      FONT_KEY_GOTHIC_14_BOLD
  #define INFO_Y         140
  #define INFO_H         22
  #define INFO_FONT      FONT_KEY_GOTHIC_18_BOLD
  #define WIDGET_L_X     2
  #define WIDGET_L_Y     2
  #define WIDGET_L_W     65
  #define WIDGET_R_X     77
  #define WIDGET_R_Y     2
  #define WIDGET_R_W     65
  #define WIDGET_H       22
  #define WIDGET_FONT    FONT_KEY_GOTHIC_18_BOLD
#endif

// Swapped layout: date on top (TIME_Y), time on bottom (flush to screen bottom)
#define TIME_Y_BOT (TIME_Y + INFO_H - 4)

// ============================================================
// SECTION 2: TYPEDEFS
// ============================================================

typedef enum {
  MODE_DAYTIME    = 0,  // 06:00-17:59
  MODE_EARLY_EVE  = 1,  // 18:00-19:59 (宵の口)
  MODE_EVE_DARK   = 2,  // 20:00-21:59 (宵闇)
  MODE_LATE_NIGHT = 3,  // 22:00-23:59 (夜更け)
  MODE_MIDNIGHT   = 4,  // 00:00-02:59 (深夜)
  MODE_DAWN       = 5,  // 03:00-05:59 (薄明)
} VisualMode;

typedef enum {
  ANIM_IDLE = 0,
  ANIM_ACTIVE,
} AnimState;

typedef struct {
  uint8_t x;
  uint8_t y;
  uint8_t size;       // 1, 2, or 3
  uint8_t brightness; // 0=dim, 1=mid, 2=bright
} Star;

typedef struct {
  int16_t   x, y;
  int8_t    dx, dy;
  uint8_t   tail_len;
  uint8_t   frame;
  uint8_t   duration;
  AnimState state;
} ShootingStar;

typedef struct {
  int16_t   x, y;
  int8_t    dx, dy;
  uint8_t   tail_len;
  uint8_t   frame;
  uint8_t   duration;
  AnimState state;
} Comet;

typedef struct {
  uint8_t phase;       // 0=new,1=wax-cres,2=1st-q,3=wax-gib,4=full,5=wan-gib,6=last-q,7=wan-cres
  uint8_t illumination;// 0-100
  bool    is_waxing;
} MoonState;

#define MOON_NEW_THRESHOLD   2
#define MOON_FULL_THRESHOLD 98

typedef struct {
  struct tm    current_time;
  VisualMode   mode;
  Window      *window;
  Layer       *canvas_layer;
  TextLayer   *time_layer;
  TextLayer   *ampm_layer;
  TextLayer   *dow_layer;
  TextLayer   *date_layer;
  AppTimer    *anim_timer;
  uint16_t     s_frame;
  Star         stars[STAR_COUNT];
  ShootingStar shoot;
  Comet        comet;
  MoonState    moon;
  uint8_t      shoot_cooldown;
  uint8_t      shoot_burst_remaining;
  uint8_t      comet_cooldown;
  char         time_buf[8];
  char         ampm_buf[4];  // "A\nM" or "P\nM" for 12H mode
  char         dow_buf[8];   // UTF-8 kanji
  char         date_buf[16];
  GBitmap     *earth_bitmap;
  GBitmap     *from_moon_bitmap;
  // Info widget data
  int32_t      widget_steps;        // -1 = unavailable
  int32_t      widget_heart_rate;   // -1 = unavailable
  uint8_t      widget_precip;       // 0-100%, 255 = unavailable
  int32_t      widget_temp;         // INT32_MIN = unavailable
  char         widget_weather[12];  // short description string
  GBitmap     *foot_bitmap;
  GBitmap     *heart_bitmap;
  // Weather icon bitmaps
  GBitmap     *weather_sunny_bitmap;
  GBitmap     *weather_rainy_bitmap;
  GBitmap     *weather_cloudy_bitmap;
  GBitmap     *weather_partly_bitmap;
  GBitmap     *weather_snowy_bitmap;
  GBitmap     *weather_foggy_bitmap;
  GBitmap     *weather_thundery_bitmap;
  // Battery icon bitmaps
  GBitmap     *battery_30_bitmap;
  GBitmap     *battery_50_bitmap;
  GBitmap     *battery_80_bitmap;
  GBitmap     *battery_full_bitmap;
  GBitmap     *battery_charging_empty_bitmap;
  GBitmap     *battery_charging_full_bitmap;
  // Precipitation icon bitmap
  GBitmap     *cloud_falling_bitmap;
  // Bluetooth disconnected icon bitmap
  GBitmap     *bluetooth_disabled_bitmap;
  bool         bluetooth_connected;
  int16_t      layout_date_y;   // dynamic Y for date row (shifts up when TQV visible)
  int16_t      layout_time_y;   // dynamic Y for time row (shifts up when TQV visible)
} AppState;

static AppState s_state;

// ============================================================
// SECTION 2b: SETTINGS (persist + AppMessage)
// ============================================================

#define PERSIST_KEY_SETTINGS 1

typedef struct {
  uint8_t  mode_override;  // 0=auto, 1=force daytime, 2=force nighttime
  uint8_t  sky_override;   // 0=auto, 1=宵の口, 2=宵闇, 3=夜更け, 4=深夜, 5=夜明け
  uint8_t  shoot_enable;   // 0=off, 1=on
  uint8_t  shoot_max;      // 0=normal probability, 1=100%
  uint8_t  comet_enable;   // 0=off, 1=on
  uint8_t  comet_max;      // 0=normal probability, 1=100%
  uint16_t sunrise_min;    // local minutes since midnight (0-1439), default 360 (06:00)
  uint16_t sunset_min;     // local minutes since midnight (0-1439), default 1080 (18:00)
  uint8_t  date_fmt;       // 0-13: date format index (see prv_update_text)
  uint8_t  bt_vibe;        // 0=off, 1=on: vibrate when Bluetooth disconnects
} WatchSettings;

static WatchSettings s_settings;

static void prv_settings_load(void) {
  s_settings.mode_override = 0;
  s_settings.sky_override  = 0;
  s_settings.shoot_enable  = 1;
  s_settings.shoot_max     = 0;
  s_settings.comet_enable  = 1;
  s_settings.comet_max     = 0;
  s_settings.sunrise_min   = 360;   // 06:00 default
  s_settings.sunset_min    = 1080;  // 18:00 default
  s_settings.shoot_max     = 0;
  s_settings.comet_enable  = 1;
  s_settings.comet_max     = 0;
  s_settings.date_fmt      = 12;    // default: Weekday, YYYY-MM-DD
  s_settings.bt_vibe       = 1;     // default: vibrate on BT disconnect
  if (persist_exists(PERSIST_KEY_SETTINGS)) {
    persist_read_data(PERSIST_KEY_SETTINGS, &s_settings, sizeof(s_settings));
  }
}

static void prv_settings_save(void) {
  persist_write_data(PERSIST_KEY_SETTINGS, &s_settings, sizeof(s_settings));
}

// ---- Widget settings (separate persist key to preserve existing settings) ----

#define PERSIST_KEY_WIDGET_SETTINGS 2

typedef struct {
  uint8_t widget_left;   // 0=none,1=steps,2=heart,3=battery,4=weather+temp,6=precip
  uint8_t widget_right;  // same
} WidgetSettings;

static WidgetSettings s_widget_settings;

static void prv_widget_settings_load(void) {
  s_widget_settings.widget_left  = 0;
  s_widget_settings.widget_right = 0;
  if (persist_exists(PERSIST_KEY_WIDGET_SETTINGS)) {
    persist_read_data(PERSIST_KEY_WIDGET_SETTINGS, &s_widget_settings, sizeof(s_widget_settings));
  }
}

static void prv_widget_settings_save(void) {
  persist_write_data(PERSIST_KEY_WIDGET_SETTINGS, &s_widget_settings, sizeof(s_widget_settings));
}

// ============================================================
// SECTION 3: LCG PRNG (fixed seed for stars, variable for spawns)
// ============================================================

#define LCG_A    1664525UL
#define LCG_C    1013904223UL
#define STAR_SEED 0xDEADBEEFUL

static uint32_t s_lcg;

static uint32_t prv_lcg_next(void) {
  s_lcg = s_lcg * LCG_A + LCG_C;
  return s_lcg;
}

// ============================================================
// SECTION 4: VISUAL MODE
// ============================================================

// Returns true if t (minutes since midnight) is in [a, b) with midnight wraparound
static bool prv_in_range(int t, int a, int b) {
  if (a == b) return false;
  if (a < b)  return t >= a && t < b;
  return t >= a || t < b;  // range crosses midnight
}

// Computes visual mode from current time using sunrise/sunset stored in settings.
// Boundaries (relative to sunset/sunrise):
//   sunset+0h  .. sunset+1h  → EARLY_EVE  (twilight after sunset)
//   sunset+1h  .. sunset+3h  → LATE_NIGHT  (deepening night)
//   sunset+3h  .. sunrise-1h → MIDNIGHT    (deep night)
//   sunrise-1h .. sunrise+30m→ EARLY_EVE  (pre-dawn / post-sunrise glow)
//   everything else          → DAYTIME
static VisualMode prv_get_visual_mode(int hour, int min) {
  int now  = hour * 60 + min;
  int set  = (int)s_settings.sunset_min;
  int rise = (int)s_settings.sunrise_min;

  int A = set;
  int B = (set  +  60) % 1440;
  int C = (set  + 180) % 1440;
  int D = (rise -  60 + 1440) % 1440;
  int E = (rise +  30) % 1440;

  if (prv_in_range(now, A, B)) return MODE_EARLY_EVE;
  if (prv_in_range(now, B, C)) return MODE_LATE_NIGHT;
  if (prv_in_range(now, C, D)) return MODE_MIDNIGHT;
  if (prv_in_range(now, D, E)) return MODE_EARLY_EVE;
  return MODE_DAYTIME;
}

// ============================================================
// SECTION 5: MOON PHASE (integer arithmetic only)
// ============================================================

static MoonState prv_calc_moon_phase(time_t timestamp) {
  // Reference new moon: 2000-01-06 18:14 UTC
  // Synodic month: 29.530588853 days => 2551443 seconds
  const int64_t ref_new_moon = 947182440LL;
  const int64_t synodic_seconds = 2551443LL;
  int64_t cycle_pos = ((int64_t)timestamp - ref_new_moon) % synodic_seconds;
  if (cycle_pos < 0) cycle_pos += synodic_seconds;

  // Phase 0-7
  uint8_t phase = (uint8_t)((cycle_pos * 8LL) / synodic_seconds);

  // Illumination 0-100
  uint8_t illum;
  int64_t half = synodic_seconds / 2;
  if (cycle_pos <= half) {
    illum = (uint8_t)(cycle_pos * 100LL / half);
  } else {
    illum = (uint8_t)((synodic_seconds - cycle_pos) * 100LL / half);
  }

  MoonState ms;
  ms.phase = phase;
  ms.illumination = illum;
  ms.is_waxing = (cycle_pos < half);
  return ms;
}

// ============================================================
// SECTION 6: STAR FIELD GENERATION
// ============================================================

static void prv_init_stars(void) {
  s_lcg = STAR_SEED;
  for (int i = 0; i < STAR_COUNT; i++) {
    uint32_t r1 = prv_lcg_next();
    uint32_t r2 = prv_lcg_next();
    uint32_t r3 = prv_lcg_next();
    s_state.stars[i].x = (uint8_t)(r1 % SCREEN_W);
    s_state.stars[i].y = (uint8_t)(r2 % SKY_ZONE_H);
    uint8_t t = (uint8_t)(r3 % 100);
    s_state.stars[i].size = (t < 70) ? 1 : (t < 92) ? 2 : 3;
    s_state.stars[i].brightness = (uint8_t)((r3 >> 8) % 3);
  }
  // After star init, reseed LCG from time so spawns vary
  s_lcg = (uint32_t)time(NULL);
}

// ============================================================
// SECTION 7: DRAWING — SKY BACKGROUND
// ============================================================

static GColor prv_sky_color(VisualMode mode) {
  switch (mode) {
    case MODE_EARLY_EVE:  return GColorCobaltBlue;                  // B=255
    case MODE_EVE_DARK:   return (GColor){.argb=0b11000010};        // B=170
    case MODE_LATE_NIGHT: return GColorOxfordBlue;                  // B=85
    case MODE_DAWN:       return GColorOxfordBlue;                  // B=85
    default:              return GColorBlack;                       // daytime/midnight
  }
}

static void prv_draw_sky(GContext *ctx, VisualMode mode) {
  graphics_context_set_fill_color(ctx, prv_sky_color(mode));
  graphics_fill_rect(ctx, GRect(0, 0, SCREEN_W, SCREEN_H), 0, GCornerNone);
}

// ============================================================
// SECTION 8: DRAWING — EARTH (daytime)
// ============================================================

static void prv_draw_earth(GContext *ctx) {
  if (!s_state.earth_bitmap) return;
  int diam = EARTH_RADIUS * 2;
  GRect dest = GRect(EARTH_POS_X - EARTH_RADIUS, EARTH_POS_Y - EARTH_RADIUS, diam, diam);
  graphics_context_set_compositing_mode(ctx, GCompOpSet);
  graphics_draw_bitmap_in_rect(ctx, s_state.earth_bitmap, dest);
}

static void prv_draw_from_moon(GContext *ctx) {
  if (!s_state.from_moon_bitmap) return;
  GRect bmp_bounds = gbitmap_get_bounds(s_state.from_moon_bitmap);
  int h = bmp_bounds.size.h;
  GRect dest = GRect(0, SCREEN_H - h, SCREEN_W, h);
  graphics_context_set_compositing_mode(ctx, GCompOpSet);
  graphics_draw_bitmap_in_rect(ctx, s_state.from_moon_bitmap, dest);
}

// ============================================================
// SECTION 9: DRAWING — STARS
// ============================================================

static void prv_draw_stars(GContext *ctx, VisualMode mode) {
  int visible;
  switch (mode) {
    case MODE_DAYTIME:    visible = STAR_COUNT;           break; // moon surface: full starfield (no atmosphere)
    case MODE_EARLY_EVE:  visible = STAR_COUNT / 5;      break;
    case MODE_EVE_DARK:   visible = STAR_COUNT * 2 / 3;  break;
    case MODE_LATE_NIGHT: visible = STAR_COUNT * 9 / 10; break;
    case MODE_MIDNIGHT:   visible = STAR_COUNT;           break;
    case MODE_DAWN:       visible = STAR_COUNT / 4;       break;
    default:              visible = 0;
  }

  for (int i = 0; i < visible; i++) {
    Star *st = &s_state.stars[i];
    GPoint p = GPoint(st->x, st->y);
    GColor col;
    switch (st->brightness) {
      case 0:  col = GColorDarkGray;  break;
      case 1:  col = GColorLightGray; break;
      default: col = GColorWhite;     break;
    }
    graphics_context_set_fill_color(ctx, col);
    if (st->size == 1) {
      graphics_draw_pixel(ctx, p);
    } else {
      graphics_fill_circle(ctx, p, st->size - 1);
    }
  }
}

// ============================================================
// SECTION 10: DRAWING — MOON
// ============================================================

// Returns the distance between the moon center and the shadow circle center.
// 0% illumination => 0 (shadow centered over the disk)
// 50% illumination => r (half moon)
// 100% illumination => 2r (shadow fully off the disk)
static int16_t prv_terminator_offset(uint8_t illumination, int r) {
  return (int16_t)((int32_t)illumination * 2 * r / 100);
}

static bool prv_is_new_moon(const MoonState *m) {
  return m->illumination <= MOON_NEW_THRESHOLD;
}

static bool prv_is_full_moon(const MoonState *m) {
  return m->illumination >= MOON_FULL_THRESHOLD;
}

#if !PLATFORM_RICH
static void prv_draw_moon_simple(GContext *ctx, MoonState *m, GColor shadow) {
  if (prv_is_new_moon(m)) return; // near-new moon hidden
  GPoint center = GPoint(MOON_POS_X, MOON_POS_Y);
  int r = MOON_RADIUS;

  // Lit disk
  graphics_context_set_fill_color(ctx, GColorWhite);
  graphics_fill_circle(ctx, center, r);

  if (prv_is_full_moon(m)) return; // near-full moon: done

  // Shadow overlay circle — matches sky background
  int16_t off = prv_terminator_offset(m->illumination, r);
  GPoint shadow_c;
  if (m->is_waxing) {
    shadow_c = GPoint(center.x - off, center.y);
  } else {
    shadow_c = GPoint(center.x + off, center.y);
  }
  graphics_context_set_fill_color(ctx, shadow);
  graphics_fill_circle(ctx, shadow_c, r + 1);

  // Thin outline to show disk boundary
  graphics_context_set_stroke_color(ctx, GColorDarkGray);
  graphics_context_set_stroke_width(ctx, 1);
  graphics_draw_circle(ctx, center, r);
}

#endif // !PLATFORM_RICH

#if PLATFORM_RICH
static void prv_draw_moon_rich(GContext *ctx, MoonState *m, GColor shadow) {
  if (prv_is_new_moon(m)) return;
  GPoint center = GPoint(MOON_POS_X, MOON_POS_Y);
  int r = MOON_RADIUS;

  // Dark side base — matches sky background
  graphics_context_set_fill_color(ctx, shadow);
  graphics_fill_circle(ctx, center, r);

  // Lit disk
  graphics_context_set_fill_color(ctx, GColorLightGray);
  graphics_fill_circle(ctx, center, r);

  // Shadow overlay — matches sky background
  if (!prv_is_full_moon(m)) {
    int16_t off = prv_terminator_offset(m->illumination, r);
    GPoint shadow_c;
    if (m->is_waxing) {
      shadow_c = GPoint(center.x - off, center.y);
    } else {
      shadow_c = GPoint(center.x + off, center.y);
    }
    graphics_context_set_fill_color(ctx, shadow);
    graphics_fill_circle(ctx, shadow_c, r + 1);
  }

  // Craters on lit side when well-illuminated
  if (m->illumination > 55) {
    graphics_context_set_fill_color(ctx, GColorDarkGray);
    int cr_r = r / 7; if (cr_r < 1) cr_r = 1;
    graphics_fill_circle(ctx, GPoint(center.x - r/4, center.y - r/4), cr_r);
    graphics_fill_circle(ctx, GPoint(center.x + r/5, center.y + r/3), cr_r);
    graphics_fill_circle(ctx, GPoint(center.x - r/6, center.y + r/5), cr_r);
  }

  // Outline
  graphics_context_set_stroke_color(ctx, GColorDarkGray);
  graphics_context_set_stroke_width(ctx, 1);
  graphics_draw_circle(ctx, center, r);
}

#endif // PLATFORM_RICH

// ============================================================
// SECTION 11: SHOOTING STAR
// ============================================================

static void prv_spawn_shoot(void); // forward declaration for burst continuation

static void prv_draw_shoot(GContext *ctx) {
  ShootingStar *ss = &s_state.shoot;
  if (ss->state != ANIM_ACTIVE) return;

  int half = ss->tail_len / 2;
  int16_t mid_x  = ss->x - (int16_t)ss->dx * half;
  int16_t mid_y  = ss->y - (int16_t)ss->dy * half;
  int16_t tail_x = ss->x - (int16_t)ss->dx * ss->tail_len;
  int16_t tail_y = ss->y - (int16_t)ss->dy * ss->tail_len;

  // Bright inner tail (head → mid): LightGray line
  graphics_context_set_stroke_color(ctx, GColorLightGray);
  graphics_context_set_stroke_width(ctx, 1);
  graphics_draw_line(ctx, GPoint(ss->x, ss->y), GPoint(mid_x, mid_y));

  // Dim outer tail (mid → end): DarkGray line
  graphics_context_set_stroke_color(ctx, GColorDarkGray);
  graphics_draw_line(ctx, GPoint(mid_x, mid_y), GPoint(tail_x, tail_y));

  // Head pixel: White (on top of tail)
  if (ss->x >= 0 && ss->x < SCREEN_W && ss->y >= 0 && ss->y < SKY_ZONE_H) {
    graphics_context_set_fill_color(ctx, GColorWhite);
    graphics_draw_pixel(ctx, GPoint(ss->x, ss->y));
  }
}

static void prv_advance_shoot(void) {
  ShootingStar *ss = &s_state.shoot;
  if (ss->state != ANIM_ACTIVE) return;
  ss->x += ss->dx;
  ss->y += ss->dy;
  ss->frame++;
  if (ss->frame >= ss->duration || ss->x >= SCREEN_W || ss->y >= SKY_ZONE_H
      || ss->x < 0 || ss->y < 0) {
    ss->state = ANIM_IDLE;
    // Burst: immediately spawn next star if remaining
    if (s_state.shoot_burst_remaining > 0) {
      s_state.shoot_burst_remaining--;
      prv_spawn_shoot();
    }
  }
}

static void prv_spawn_shoot(void) {
  if (s_state.shoot.state != ANIM_IDLE) return;
  // Start from left area, move fast and nearly horizontal (straight)
  ShootingStar *ss = &s_state.shoot;
  uint32_t r1 = prv_lcg_next();
  uint32_t r2 = prv_lcg_next();
  ss->x        = (int16_t)(r1 % (SCREEN_W / 4));  // left quarter
  ss->y        = (int16_t)(r2 % (SKY_ZONE_H / 2)); // upper half
  ss->dx       = 8;   // fast horizontal
  ss->dy       = 1;   // slight downward — looks straight
  ss->tail_len = 10;  // long continuous tail via line drawing
  ss->frame    = 0;
  ss->duration = 22;  // travels 176px in ~1.1s
  ss->state    = ANIM_ACTIVE;
}

static void prv_maybe_spawn_shoot(void) {
  if (!s_settings.shoot_enable) return;
  if (s_state.mode == MODE_DAYTIME) return; // 月面は大気なし→流れ星なし
  if (s_state.shoot.state == ANIM_ACTIVE) return;
  if (s_state.shoot_burst_remaining > 0) return; // burst already in progress
  if (s_state.shoot_cooldown > 0) { s_state.shoot_cooldown--; return; }
  if (s_settings.shoot_max) {
    s_state.shoot_burst_remaining = 2; // 1st + 2 more = 3 total
    prv_spawn_shoot();
    s_state.shoot_cooldown = 0;
  } else {
    uint32_t r = prv_lcg_next();
    if ((r % 5) == 0) {
      s_state.shoot_burst_remaining = 2; // always 3 in a burst
      prv_spawn_shoot();
      s_state.shoot_cooldown = 3 + (uint8_t)(prv_lcg_next() % 4);
    } else {
      s_state.shoot_cooldown = 1;
    }
  }
}

// ============================================================
// SECTION 12: COMET (rich platforms only)
// ============================================================

#if PLATFORM_RICH

static void prv_draw_comet(GContext *ctx) {
  Comet *c = &s_state.comet;
  if (c->state != ANIM_ACTIVE) return;

  // Tail drawn as 3 colored line segments: LightGray → PictonBlue → OxfordBlue
  int q = c->tail_len / 3;  // 4 frames per section (tail_len=12)
  GPoint p0 = GPoint(c->x,                               c->y);
  GPoint p1 = GPoint(c->x - (int16_t)c->dx * q,         c->y - (int16_t)c->dy * q);
  GPoint p2 = GPoint(c->x - (int16_t)c->dx * (q * 2),   c->y - (int16_t)c->dy * (q * 2));
  GPoint p3 = GPoint(c->x - (int16_t)c->dx * c->tail_len, c->y - (int16_t)c->dy * c->tail_len);

  graphics_context_set_stroke_width(ctx, 1);

  // Bright inner tail: LightGray
  graphics_context_set_stroke_color(ctx, GColorLightGray);
  graphics_draw_line(ctx, p0, p1);

  // Mid tail: vivid blue
  graphics_context_set_stroke_color(ctx, GColorPictonBlue);
  graphics_draw_line(ctx, p1, p2);

  // Outer tail: dark blue
  graphics_context_set_stroke_color(ctx, GColorOxfordBlue);
  graphics_draw_line(ctx, p2, p3);

  // Head: white circle (larger than shooting star's pixel head)
  if (c->x >= 0 && c->x < SCREEN_W && c->y >= 0 && c->y < SKY_ZONE_H) {
    graphics_context_set_fill_color(ctx, GColorWhite);
    graphics_fill_circle(ctx, GPoint(c->x, c->y), 2);
  }
}

static void prv_advance_comet(void) {
  Comet *c = &s_state.comet;
  if (c->state != ANIM_ACTIVE) return;
  c->x += c->dx;
  c->y += c->dy;
  c->frame++;
  if (c->frame >= c->duration || c->x >= SCREEN_W || c->y >= SKY_ZONE_H
      || c->x < 0 || c->y < 0) {
    c->state = ANIM_IDLE;
  }
}

static void prv_spawn_comet(void) {
  if (s_state.comet.state != ANIM_IDLE) return;
  Comet *c = &s_state.comet;
  uint32_t r1 = prv_lcg_next();
  uint32_t r2 = prv_lcg_next();
  c->x        = (int16_t)(r1 % (SCREEN_W / 3));
  c->y        = (int16_t)(r2 % (SKY_ZONE_H / 4));
  c->dx       = 2;
  c->dy       = 1;
  c->tail_len = 12;
  c->frame    = 0;
  c->duration = 120;
  c->state    = ANIM_ACTIVE;
}

static void prv_maybe_spawn_comet(void) {
  if (!s_settings.comet_enable) return;
  if (s_state.comet.state == ANIM_ACTIVE) return;
  if (s_state.comet_cooldown > 0) { s_state.comet_cooldown--; return; }
  if (s_settings.comet_max) {
    prv_spawn_comet();
    s_state.comet_cooldown = 0;
  } else {
    uint32_t r = prv_lcg_next();
    if ((r % 15) == 0) {
      prv_spawn_comet();
      s_state.comet_cooldown = 50 + (uint8_t)(prv_lcg_next() % 15);
    } else {
      s_state.comet_cooldown = 5;
    }
  }
}

#endif // PLATFORM_RICH

// ============================================================
// SECTION 13: ANIMATION TIMER
// ============================================================

static void prv_start_anim_timer(void);

static void prv_anim_timer_cb(void *data) {
  s_state.anim_timer = NULL;
  s_state.s_frame++;
  prv_advance_shoot();
#if PLATFORM_RICH
  prv_advance_comet();
#endif
  layer_mark_dirty(s_state.canvas_layer);

  bool any_active = (s_state.shoot.state == ANIM_ACTIVE);
#if PLATFORM_RICH
  any_active = any_active || (s_state.comet.state == ANIM_ACTIVE);
#endif
  if (any_active) {
    prv_start_anim_timer();
  }
}

static void prv_start_anim_timer(void) {
  if (s_state.anim_timer != NULL) return;
  BatteryChargeState bat = battery_state_service_peek();
  uint32_t interval = (!bat.is_charging && bat.charge_percent < 20) ? 100 : 50;
  s_state.anim_timer = app_timer_register(interval, prv_anim_timer_cb, NULL);
}

static void prv_stop_anim_timer(void) {
  if (s_state.anim_timer) {
    app_timer_cancel(s_state.anim_timer);
    s_state.anim_timer = NULL;
  }
}

// ============================================================
// SECTION 13b: HEALTH DATA UPDATE
// ============================================================

static void prv_update_health(void) {
#ifdef PBL_HEALTH
  time_t end   = time(NULL);
  time_t start = time_start_of_today();
  time_t hr_start = end - (5 * 60);
  if (hr_start < start) {
    hr_start = start;
  }
  HealthServiceAccessibilityMask steps_mask =
    health_service_metric_accessible(HealthMetricStepCount, start, end);
  if (steps_mask & HealthServiceAccessibilityMaskAvailable) {
    s_state.widget_steps = (int32_t)health_service_sum(HealthMetricStepCount, start, end);
  } else {
    s_state.widget_steps = -1;
  }
  HealthServiceAccessibilityMask hr_mask =
    health_service_metric_accessible(HealthMetricHeartRateBPM, hr_start, end);
  if (hr_mask & HealthServiceAccessibilityMaskAvailable) {
    s_state.widget_heart_rate =
      (int32_t)health_service_peek_current_value(HealthMetricHeartRateBPM);
  } else {
    s_state.widget_heart_rate = -1;
  }
#else
  s_state.widget_steps      = -1;
  s_state.widget_heart_rate = -1;
#endif
}

#ifdef PBL_HEALTH
static void prv_health_handler(HealthEventType event, void *context) {
  (void)event;
  (void)context;

  prv_update_health();
  if (s_state.canvas_layer) {
    layer_mark_dirty(s_state.canvas_layer);
  }
}
#endif

// ============================================================
// SECTION 13c: WIDGET DRAWING
// ============================================================

static void prv_draw_widget_slot(GContext *ctx, uint8_t type, GRect area, bool right_align) {
  if (type == 0) return;

  char text[16] = "";
  GBitmap *icon = NULL;

  switch (type) {
    case 1: // steps
      icon = s_state.foot_bitmap;
      if (s_state.widget_steps >= 0) {
        snprintf(text, sizeof(text), "%d", (int)s_state.widget_steps);
      } else {
        snprintf(text, sizeof(text), "--");
      }
      break;
    case 2: // heart rate
      icon = s_state.heart_bitmap;
      if (s_state.widget_heart_rate > 0) {
        snprintf(text, sizeof(text), "%d", (int)s_state.widget_heart_rate);
      } else {
        snprintf(text, sizeof(text), "-");
      }
      break;
    case 3: { // battery — icon + number + %
      BatteryChargeState bat = battery_state_service_peek();
      snprintf(text, sizeof(text), "%d%%", bat.charge_percent);
      if (bat.is_charging) {
        icon = (bat.charge_percent < 50)
          ? s_state.battery_charging_empty_bitmap
          : s_state.battery_charging_full_bitmap;
      } else {
        if      (bat.charge_percent <= 40) icon = s_state.battery_30_bitmap;
        else if (bat.charge_percent <= 65) icon = s_state.battery_50_bitmap;
        else if (bat.charge_percent <= 90) icon = s_state.battery_80_bitmap;
        else                               icon = s_state.battery_full_bitmap;
      }
      break;
    }
    case 4: // weather icon + temperature
      if (s_state.widget_weather[0]) {
        const char *w = s_state.widget_weather;
        if (strcmp(w, "Clear") == 0) {
          icon = s_state.weather_sunny_bitmap;
        } else if (strcmp(w, "Partly") == 0) {
          icon = s_state.weather_partly_bitmap;
        } else if (strcmp(w, "Snow") == 0) {
          icon = s_state.weather_snowy_bitmap;
        } else if (strcmp(w, "Fog") == 0) {
          icon = s_state.weather_foggy_bitmap;
        } else if (strcmp(w, "Thunder") == 0) {
          icon = s_state.weather_thundery_bitmap;
        } else if (strcmp(w, "Rain") == 0 || strcmp(w, "Drizzle") == 0 ||
                   strcmp(w, "Shower") == 0) {
          icon = s_state.weather_rainy_bitmap;
        } else {
          icon = s_state.weather_cloudy_bitmap;
        }
      } else {
        icon = s_state.weather_cloudy_bitmap;
      }
      if (s_state.widget_temp != INT32_MIN) {
        snprintf(text, sizeof(text), "%d\xc2\xb0", (int)s_state.widget_temp);
      } else {
        snprintf(text, sizeof(text), "--");
      }
      break;
    case 6: // precipitation probability — icon + number + %
      icon = s_state.cloud_falling_bitmap;
      if (s_state.widget_precip <= 100) {
        snprintf(text, sizeof(text), "%d%%", s_state.widget_precip);
      } else {
        snprintf(text, sizeof(text), "--");
      }
      break;
    default:
      return;
  }

  GFont font = fonts_get_system_font(WIDGET_FONT);
  int text_x = area.origin.x;
  int text_w = area.size.w;

  if (right_align) {
    // Measure text to position icon+text as a unit at the right edge
    GSize text_size = graphics_text_layout_get_content_size(
      text, font, GRect(0, 0, area.size.w, area.size.h),
      GTextOverflowModeTrailingEllipsis, GTextAlignmentLeft);
    int icon_w = icon ? gbitmap_get_bounds(icon).size.w + 2 : 0;
    int group_w = icon_w + text_size.w;
    int start_x = area.origin.x + area.size.w - group_w;
    if (start_x < area.origin.x) start_x = area.origin.x;

    if (icon) {
      GRect icon_bounds = gbitmap_get_bounds(icon);
      int icon_h = icon_bounds.size.h;
      int icon_y = area.origin.y + (area.size.h - icon_h) / 2;
      if (icon_y < area.origin.y) icon_y = area.origin.y;
      graphics_context_set_compositing_mode(ctx, GCompOpSet);
      graphics_draw_bitmap_in_rect(ctx, icon,
        GRect(start_x, icon_y, icon_bounds.size.w, icon_h));
    }
    text_x = start_x + icon_w;
    text_w = text_size.w + 2; // +2 to avoid clipping
  } else {
    if (icon) {
      GRect icon_bounds = gbitmap_get_bounds(icon);
      int icon_w = icon_bounds.size.w;
      int icon_h = icon_bounds.size.h;
      int icon_y = area.origin.y + (area.size.h - icon_h) / 2;
      if (icon_y < area.origin.y) icon_y = area.origin.y;
      graphics_context_set_compositing_mode(ctx, GCompOpSet);
      graphics_draw_bitmap_in_rect(ctx, icon,
        GRect(area.origin.x, icon_y, icon_w, icon_h));
      text_x = area.origin.x + icon_w + 2;
      text_w = area.size.w - icon_w - 2;
    }
  }

  GRect text_rect = GRect(text_x, area.origin.y, text_w, area.size.h);
  // Drop shadow for readability on any background
  graphics_context_set_text_color(ctx, GColorBlack);
  graphics_draw_text(ctx, text, font,
    GRect(text_rect.origin.x + 1, text_rect.origin.y + 1,
          text_rect.size.w, text_rect.size.h),
    GTextOverflowModeTrailingEllipsis, GTextAlignmentLeft, NULL);
  // White text
  graphics_context_set_text_color(ctx, GColorWhite);
  graphics_draw_text(ctx, text, font, text_rect,
    GTextOverflowModeTrailingEllipsis, GTextAlignmentLeft, NULL);
}

// ============================================================
// SECTION 13b: BLUETOOTH CONNECTION HANDLER
// ============================================================

static void prv_bluetooth_handler(bool connected) {
  bool was_connected = s_state.bluetooth_connected;
  s_state.bluetooth_connected = connected;
  if (!connected && was_connected && s_settings.bt_vibe) {
    vibes_double_pulse();
  }
  if (s_state.canvas_layer) {
    layer_mark_dirty(s_state.canvas_layer);
  }
}

// ============================================================
// SECTION 14: CANVAS UPDATE PROC
// ============================================================

static void prv_canvas_update_proc(Layer *layer, GContext *ctx) {
  // 1. Sky / background fill (sky zone)
  // sky_override: 0=auto, 1=宵の口, 2=宵闇, 3=夜更け, 4=深夜, 5=夜明け
  VisualMode sky_mode = s_state.mode;
  if (s_settings.sky_override != 0 && s_state.mode != MODE_DAYTIME) {
    const VisualMode sky_map[] = {
      MODE_EARLY_EVE, MODE_EVE_DARK, MODE_LATE_NIGHT, MODE_MIDNIGHT, MODE_DAWN
    };
    int idx = (int)s_settings.sky_override - 1;
    if (idx >= 0 && idx < 5) sky_mode = sky_map[idx];
  }
  prv_draw_sky(ctx, sky_mode);

  // 3. Stars (always drawn; daytime = full starfield since no lunar atmosphere)
  prv_draw_stars(ctx, s_state.mode);

  if (s_state.mode == MODE_DAYTIME) {
    // 3a. Daytime: Earth view from moon (drawn on top of stars)
    prv_draw_earth(ctx);
    prv_draw_from_moon(ctx);
  }

  // 4. Moon (skip near-new moon, skip daytime)
  if (s_state.mode != MODE_DAYTIME && !prv_is_new_moon(&s_state.moon)) {
    GColor shadow = prv_sky_color(sky_mode);
#if PLATFORM_RICH
    prv_draw_moon_rich(ctx, &s_state.moon, shadow);
#else
    prv_draw_moon_simple(ctx, &s_state.moon, shadow);
#endif
  }

  // 5. Shooting star
  prv_draw_shoot(ctx);

  // 6. Comet (rich only)
#if PLATFORM_RICH
  prv_draw_comet(ctx);
#endif

  // 7. Text shadows — drawn on canvas so TextLayers (white) render on top
  graphics_context_set_text_color(ctx, GColorBlack);
  GFont time_font = fonts_get_system_font(TIME_FONT);
  GFont info_font = fonts_get_system_font(INFO_FONT);
  graphics_draw_text(ctx, s_state.time_buf, time_font,
                     GRect(1, s_state.layout_time_y + 1, SCREEN_W, TIME_H),
                     GTextOverflowModeWordWrap, GTextAlignmentCenter, NULL);
  if (s_state.ampm_buf[0] != '\0') {
    GFont ampm_font = fonts_get_system_font(AMPM_FONT);
    graphics_draw_text(ctx, s_state.ampm_buf, ampm_font,
                       GRect(AMPM_X + 1, s_state.layout_time_y + AMPM_Y_OFFSET + 1, AMPM_W, TIME_H - AMPM_Y_OFFSET),
                       GTextOverflowModeWordWrap, GTextAlignmentLeft, NULL);
  }
  graphics_draw_text(ctx, s_state.date_buf, info_font,
                     GRect(1, s_state.layout_date_y + 1, SCREEN_W, INFO_H),
                     GTextOverflowModeWordWrap, GTextAlignmentCenter, NULL);

  // 8. Info widgets (left and right slots)
  prv_draw_widget_slot(ctx, s_widget_settings.widget_left,
    GRect(WIDGET_L_X, WIDGET_L_Y, WIDGET_L_W, WIDGET_H), false);
  prv_draw_widget_slot(ctx, s_widget_settings.widget_right,
    GRect(WIDGET_R_X, WIDGET_R_Y, WIDGET_R_W, WIDGET_H), true);

  // 9. Bluetooth disconnected icon (top center, shown only when disconnected)
  if (!s_state.bluetooth_connected && s_state.bluetooth_disabled_bitmap) {
    GRect bmp_bounds = gbitmap_get_bounds(s_state.bluetooth_disabled_bitmap);
    int bmp_w = bmp_bounds.size.w;
    int bmp_h = bmp_bounds.size.h;
    GRect dest = GRect((SCREEN_W - bmp_w) / 2, 2, bmp_w, bmp_h);
    graphics_context_set_compositing_mode(ctx, GCompOpSet);
    graphics_draw_bitmap_in_rect(ctx, s_state.bluetooth_disabled_bitmap, dest);
  }
}

// ============================================================
// SECTION 15: TEXT UPDATE
// ============================================================

static const char *DOW_EN[] = {
  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static void prv_update_text(struct tm *t) {
  if (clock_is_24h_style()) {
    snprintf(s_state.time_buf, sizeof(s_state.time_buf),
             "%02d:%02d", t->tm_hour, t->tm_min);
    s_state.ampm_buf[0] = '\0';
    if (s_state.ampm_layer) {
      layer_set_hidden(text_layer_get_layer(s_state.ampm_layer), true);
    }
  } else {
    int h = t->tm_hour % 12;
    if (h == 0) h = 12;
    snprintf(s_state.time_buf, sizeof(s_state.time_buf),
             "%02d:%02d", h, t->tm_min);
    // Build stacked AM/PM: "A\nM" or "P\nM"
    s_state.ampm_buf[0] = (t->tm_hour >= 12) ? 'P' : 'A';
    s_state.ampm_buf[1] = '\n';
    s_state.ampm_buf[2] = 'M';
    s_state.ampm_buf[3] = '\0';
    if (s_state.ampm_layer) {
      text_layer_set_text(s_state.ampm_layer, s_state.ampm_buf);
      layer_set_hidden(text_layer_get_layer(s_state.ampm_layer), false);
    }
  }
  // Date formatting — format selected via settings
  {
    int yyyy = t->tm_year + 1900;
    int yy   = yyyy % 100;
    int mm   = t->tm_mon + 1;
    int dd   = t->tm_mday;
    const char *dow = DOW_EN[t->tm_wday];
    switch (s_settings.date_fmt) {
      case 0:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d, %02d", dow, dd, mm); break;
      case 1:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d.%02d.%02d", dow, dd, mm, yy); break;
      case 2:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d.%02d.%04d", dow, dd, mm, yyyy); break;
      case 3:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%02d.%02d.%04d", dd, mm, yyyy); break;
      case 4:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d/%02d", dow, dd, mm); break;
      case 5:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d/%02d/%02d", dow, dd, mm, yy); break;
      case 6:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d/%02d/%04d", dow, dd, mm, yyyy); break;
      case 7:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%02d/%02d/%04d", dd, mm, yyyy); break;
      case 8:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d/%02d", dow, mm, dd); break;
      case 9:  snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d/%02d/%02d", dow, mm, dd, yy); break;
      case 10: snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %02d/%02d/%04d", dow, mm, dd, yyyy); break;
      case 11: snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%02d/%02d/%04d", mm, dd, yyyy); break;
      case 12: snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%s, %04d-%02d-%02d", dow, yyyy, mm, dd); break;
      case 13: snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%04d-%02d-%02d", yyyy, mm, dd); break;
      case 14: snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%04d-%02d-%02d %s", yyyy, mm, dd, dow); break;
      default: snprintf(s_state.date_buf, sizeof(s_state.date_buf), "%04d-%02d-%02d", yyyy, mm, dd); break;
    }
  }

  text_layer_set_text(s_state.time_layer, s_state.time_buf);
  text_layer_set_text(s_state.date_layer, s_state.date_buf);
}

// ============================================================
// SECTION 16: TICK HANDLER
// ============================================================

static void prv_tick_handler(struct tm *tick_time, TimeUnits changed) {
  s_state.current_time = *tick_time;
  s_state.mode = prv_get_visual_mode(tick_time->tm_hour, tick_time->tm_min);
  if      (s_settings.mode_override == 1) s_state.mode = MODE_DAYTIME;
  else if (s_settings.mode_override == 2) s_state.mode = MODE_MIDNIGHT;
  s_state.moon = prv_calc_moon_phase(time(NULL));

  prv_update_text(tick_time);
  prv_update_health();
  prv_maybe_spawn_shoot();
#if PLATFORM_RICH
  prv_maybe_spawn_comet();
#endif
  // Start animation timer if anything was just spawned
  bool any_active = (s_state.shoot.state == ANIM_ACTIVE);
#if PLATFORM_RICH
  any_active = any_active || (s_state.comet.state == ANIM_ACTIVE);
#endif
  if (any_active) prv_start_anim_timer();
  layer_mark_dirty(s_state.canvas_layer);
}

// ============================================================
// SECTION 16b: UNOBSTRUCTED AREA (Timeline Quick View)
// ============================================================

static void prv_update_layout(void) {
  if (!s_state.window) return;
  Layer *root = window_get_root_layer(s_state.window);
  GRect ub = layer_get_unobstructed_bounds(root);
  int16_t avail_bottom = (int16_t)(ub.origin.y + ub.size.h);

  // Maintain original 11px bottom margin, shift both rows up together
  int16_t time_y = avail_bottom - TIME_H - 11;
  int16_t date_y = time_y - INFO_H + 4;  // mirrors TIME_Y_BOT = TIME_Y + INFO_H - 4

  s_state.layout_time_y = time_y;
  s_state.layout_date_y = date_y;

  if (s_state.time_layer) {
    layer_set_frame(text_layer_get_layer(s_state.time_layer),
                    GRect(0, time_y, SCREEN_W, TIME_H));
  }
  if (s_state.ampm_layer) {
    layer_set_frame(text_layer_get_layer(s_state.ampm_layer),
                    GRect(AMPM_X, time_y + AMPM_Y_OFFSET, AMPM_W, TIME_H - AMPM_Y_OFFSET));
  }
  if (s_state.date_layer) {
    layer_set_frame(text_layer_get_layer(s_state.date_layer),
                    GRect(0, date_y, SCREEN_W, INFO_H));
  }

  if (s_state.canvas_layer) layer_mark_dirty(s_state.canvas_layer);
}

static void prv_unobstructed_change(AnimationProgress progress, void *context) {
  prv_update_layout();
}

static void prv_unobstructed_did_change(void *context) {
  prv_update_layout();
}

// ============================================================
// SECTION 17: WINDOW LIFECYCLE
// ============================================================

static void prv_window_load(Window *window) {
  Layer *root = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(root);
  (void)bounds; // using macros for positions

  // Canvas layer (full screen)
  s_state.canvas_layer = layer_create(GRect(0, 0, SCREEN_W, SCREEN_H));
  layer_set_update_proc(s_state.canvas_layer, prv_canvas_update_proc);
  layer_add_child(root, s_state.canvas_layer);

  // Time layer (swapped: now at bottom)
  s_state.time_layer = text_layer_create(GRect(0, TIME_Y_BOT, SCREEN_W, TIME_H));
  text_layer_set_background_color(s_state.time_layer, GColorClear);
  text_layer_set_text_color(s_state.time_layer, GColorWhite);
  text_layer_set_font(s_state.time_layer, fonts_get_system_font(TIME_FONT));
  text_layer_set_text_alignment(s_state.time_layer, GTextAlignmentCenter);
  layer_add_child(root, text_layer_get_layer(s_state.time_layer));

  // AM/PM layer — shown only in 12H mode, stacked "A\nM" or "P\nM" to the left of the time
  s_state.ampm_layer = text_layer_create(GRect(AMPM_X, TIME_Y_BOT + AMPM_Y_OFFSET, AMPM_W, TIME_H - AMPM_Y_OFFSET));
  text_layer_set_background_color(s_state.ampm_layer, GColorClear);
  text_layer_set_text_color(s_state.ampm_layer, GColorWhite);
  text_layer_set_font(s_state.ampm_layer, fonts_get_system_font(AMPM_FONT));
  text_layer_set_text_alignment(s_state.ampm_layer, GTextAlignmentLeft);
  layer_add_child(root, text_layer_get_layer(s_state.ampm_layer));
  layer_set_hidden(text_layer_get_layer(s_state.ampm_layer), true); // hidden until prv_update_text

  // Combined info row — "YYYY/MM/DD DOW" centered (swapped: now at top)
  s_state.date_layer = text_layer_create(
    GRect(0, TIME_Y, SCREEN_W, INFO_H));
  text_layer_set_background_color(s_state.date_layer, GColorClear);
  text_layer_set_text_color(s_state.date_layer, GColorWhite);
  text_layer_set_font(s_state.date_layer, fonts_get_system_font(INFO_FONT));
  text_layer_set_text_alignment(s_state.date_layer, GTextAlignmentCenter);
  layer_add_child(root, text_layer_get_layer(s_state.date_layer));

  // dow_layer is no longer used (merged into date_layer)
  s_state.dow_layer = NULL;

  // Earth / from_moon bitmaps (used in daytime mode)
  s_state.earth_bitmap     = gbitmap_create_with_resource(RESOURCE_ID_EARTH);
  s_state.from_moon_bitmap = gbitmap_create_with_resource(RESOURCE_ID_FROM_MOON);

  // Icon bitmaps for info widgets
  s_state.foot_bitmap  = gbitmap_create_with_resource(RESOURCE_ID_FOOT_ICON);
  s_state.heart_bitmap = gbitmap_create_with_resource(RESOURCE_ID_HEART_ICON);
  // Weather icons
  s_state.weather_sunny_bitmap    = gbitmap_create_with_resource(RESOURCE_ID_WEATHER_SUNNY);
  s_state.weather_rainy_bitmap    = gbitmap_create_with_resource(RESOURCE_ID_WEATHER_RAINY);
  s_state.weather_cloudy_bitmap   = gbitmap_create_with_resource(RESOURCE_ID_WEATHER_CLOUDY);
  s_state.weather_partly_bitmap   = gbitmap_create_with_resource(RESOURCE_ID_WEATHER_PARTLY_CLOUDY);
  s_state.weather_snowy_bitmap    = gbitmap_create_with_resource(RESOURCE_ID_WEATHER_SNOWY);
  s_state.weather_foggy_bitmap    = gbitmap_create_with_resource(RESOURCE_ID_WEATHER_FOGGY);
  s_state.weather_thundery_bitmap = gbitmap_create_with_resource(RESOURCE_ID_WEATHER_THUNDERY);
  // Battery icons
  s_state.battery_30_bitmap             = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_30);
  s_state.battery_50_bitmap             = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_50);
  s_state.battery_80_bitmap             = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_80);
  s_state.battery_full_bitmap           = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_FULL);
  s_state.battery_charging_empty_bitmap = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_CHARGING_EMPTY);
  s_state.battery_charging_full_bitmap  = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_CHARGING_FULL);
  // Precipitation icon
  s_state.cloud_falling_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CLOUD_FALLING);
  // Bluetooth disconnected icon
  s_state.bluetooth_disabled_bitmap = gbitmap_create_with_resource(RESOURCE_ID_BLUETOOTH_DISABLED);
  s_state.bluetooth_connected = connection_service_peek_pebble_app_connection();

  // Initialize stars (once, fixed seed)
  prv_init_stars();

  // Shooting star starts idle
  s_state.shoot.state    = ANIM_IDLE;
  s_state.shoot_cooldown = 2;
#if PLATFORM_RICH
  s_state.comet.state    = ANIM_IDLE;
  s_state.comet_cooldown = 30;
#endif

  // Initial time, mode, moon
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  s_state.current_time = *t;
  s_state.mode = prv_get_visual_mode(t->tm_hour, t->tm_min);
  if      (s_settings.mode_override == 1) s_state.mode = MODE_DAYTIME;
  else if (s_settings.mode_override == 2) s_state.mode = MODE_MIDNIGHT;
  s_state.moon = prv_calc_moon_phase(now);
  prv_update_text(t);
  prv_update_health();
  prv_update_layout();
}

static void prv_window_unload(Window *window) {
  prv_stop_anim_timer();
  layer_destroy(s_state.canvas_layer);
  text_layer_destroy(s_state.time_layer);
  if (s_state.ampm_layer) text_layer_destroy(s_state.ampm_layer);
  if (s_state.dow_layer) text_layer_destroy(s_state.dow_layer);
  text_layer_destroy(s_state.date_layer);
  if (s_state.earth_bitmap) {
    gbitmap_destroy(s_state.earth_bitmap);
    s_state.earth_bitmap = NULL;
  }
  if (s_state.from_moon_bitmap) {
    gbitmap_destroy(s_state.from_moon_bitmap);
    s_state.from_moon_bitmap = NULL;
  }
  if (s_state.foot_bitmap) {
    gbitmap_destroy(s_state.foot_bitmap);
    s_state.foot_bitmap = NULL;
  }
  if (s_state.heart_bitmap) {
    gbitmap_destroy(s_state.heart_bitmap);
    s_state.heart_bitmap = NULL;
  }
  if (s_state.weather_sunny_bitmap)    { gbitmap_destroy(s_state.weather_sunny_bitmap);    s_state.weather_sunny_bitmap    = NULL; }
  if (s_state.weather_rainy_bitmap)    { gbitmap_destroy(s_state.weather_rainy_bitmap);    s_state.weather_rainy_bitmap    = NULL; }
  if (s_state.weather_cloudy_bitmap)   { gbitmap_destroy(s_state.weather_cloudy_bitmap);   s_state.weather_cloudy_bitmap   = NULL; }
  if (s_state.weather_partly_bitmap)   { gbitmap_destroy(s_state.weather_partly_bitmap);   s_state.weather_partly_bitmap   = NULL; }
  if (s_state.weather_snowy_bitmap)    { gbitmap_destroy(s_state.weather_snowy_bitmap);    s_state.weather_snowy_bitmap    = NULL; }
  if (s_state.weather_foggy_bitmap)    { gbitmap_destroy(s_state.weather_foggy_bitmap);    s_state.weather_foggy_bitmap    = NULL; }
  if (s_state.weather_thundery_bitmap) { gbitmap_destroy(s_state.weather_thundery_bitmap); s_state.weather_thundery_bitmap = NULL; }
  if (s_state.battery_30_bitmap)             { gbitmap_destroy(s_state.battery_30_bitmap);             s_state.battery_30_bitmap             = NULL; }
  if (s_state.battery_50_bitmap)             { gbitmap_destroy(s_state.battery_50_bitmap);             s_state.battery_50_bitmap             = NULL; }
  if (s_state.battery_80_bitmap)             { gbitmap_destroy(s_state.battery_80_bitmap);             s_state.battery_80_bitmap             = NULL; }
  if (s_state.battery_full_bitmap)           { gbitmap_destroy(s_state.battery_full_bitmap);           s_state.battery_full_bitmap           = NULL; }
  if (s_state.battery_charging_empty_bitmap) { gbitmap_destroy(s_state.battery_charging_empty_bitmap); s_state.battery_charging_empty_bitmap = NULL; }
  if (s_state.battery_charging_full_bitmap)  { gbitmap_destroy(s_state.battery_charging_full_bitmap);  s_state.battery_charging_full_bitmap  = NULL; }
  if (s_state.cloud_falling_bitmap) { gbitmap_destroy(s_state.cloud_falling_bitmap); s_state.cloud_falling_bitmap = NULL; }
  if (s_state.bluetooth_disabled_bitmap) { gbitmap_destroy(s_state.bluetooth_disabled_bitmap); s_state.bluetooth_disabled_bitmap = NULL; }
}

// ============================================================
// SECTION 17b: APPMESSAGE — receive settings from phone
// ============================================================

static void prv_inbox_received(DictionaryIterator *iter, void *context) {
  Tuple *t;

  t = dict_find(iter, MESSAGE_KEY_SETTINGS_MODE_OVERRIDE);
  if (t) s_settings.mode_override = (uint8_t)t->value->uint8;

  t = dict_find(iter, MESSAGE_KEY_SETTINGS_SKY_OVERRIDE);
  if (t) s_settings.sky_override = (uint8_t)t->value->uint8;

  t = dict_find(iter, MESSAGE_KEY_SETTINGS_SHOOT_ENABLE);
  if (t) s_settings.shoot_enable = (uint8_t)t->value->uint8;

  t = dict_find(iter, MESSAGE_KEY_SETTINGS_SHOOT_MAX);
  if (t) s_settings.shoot_max = (uint8_t)t->value->uint8;

  t = dict_find(iter, MESSAGE_KEY_SETTINGS_COMET_ENABLE);
  if (t) s_settings.comet_enable = (uint8_t)t->value->uint8;

  t = dict_find(iter, MESSAGE_KEY_SETTINGS_COMET_MAX);
  if (t) s_settings.comet_max = (uint8_t)t->value->uint8;

  t = dict_find(iter, MESSAGE_KEY_SUNRISE_MINUTES);
  if (t) s_settings.sunrise_min = (uint16_t)t->value->uint32;

  t = dict_find(iter, MESSAGE_KEY_SUNSET_MINUTES);
  if (t) s_settings.sunset_min = (uint16_t)t->value->uint32;

  // Widget settings
  bool widget_changed = false;
  t = dict_find(iter, MESSAGE_KEY_WIDGET_LEFT);
  if (t) { s_widget_settings.widget_left  = (uint8_t)t->value->uint8; widget_changed = true; }
  t = dict_find(iter, MESSAGE_KEY_WIDGET_RIGHT);
  if (t) { s_widget_settings.widget_right = (uint8_t)t->value->uint8; widget_changed = true; }
  if (widget_changed) prv_widget_settings_save();

  t = dict_find(iter, MESSAGE_KEY_DATE_FMT);
  if (t) {
    s_settings.date_fmt = (uint8_t)t->value->uint8;
    prv_update_text(&s_state.current_time);
  }

  t = dict_find(iter, MESSAGE_KEY_SETTINGS_BT_VIBE);
  if (t) s_settings.bt_vibe = (uint8_t)t->value->uint8;

  // Weather data from phone
  t = dict_find(iter, MESSAGE_KEY_WEATHER_TEMP);
  if (t) s_state.widget_temp = (int32_t)t->value->int32;
  t = dict_find(iter, MESSAGE_KEY_WEATHER_DESC);
  if (t) snprintf(s_state.widget_weather, sizeof(s_state.widget_weather),
                  "%s", t->value->cstring);
  t = dict_find(iter, MESSAGE_KEY_WEATHER_PRECIP);
  if (t) s_state.widget_precip = (uint8_t)t->value->uint8;

  prv_settings_save();

  // Re-apply visual mode immediately
  s_state.mode = prv_get_visual_mode(s_state.current_time.tm_hour, s_state.current_time.tm_min);
  if      (s_settings.mode_override == 1) s_state.mode = MODE_DAYTIME;
  else if (s_settings.mode_override == 2) s_state.mode = MODE_MIDNIGHT;

  // Immediately attempt spawning so user sees the effect right away
  s_state.shoot_cooldown = 0;
  prv_maybe_spawn_shoot();
#if PLATFORM_RICH
  s_state.comet_cooldown = 0;
  prv_maybe_spawn_comet();
#endif

  bool any_active = (s_state.shoot.state == ANIM_ACTIVE);
#if PLATFORM_RICH
  any_active = any_active || (s_state.comet.state == ANIM_ACTIVE);
#endif
  if (any_active) prv_start_anim_timer();
  layer_mark_dirty(s_state.canvas_layer);
}

// ============================================================
// SECTION 18: INIT / DEINIT / MAIN
// ============================================================

static void prv_init(void) {
  memset(&s_state, 0, sizeof(s_state));
  prv_settings_load();
  prv_widget_settings_load();
  // Widget data defaults (unavailable until first update)
  s_state.widget_steps       = -1;
  s_state.widget_heart_rate  = -1;
  s_state.widget_precip      = 255;
  s_state.widget_temp        = INT32_MIN;
  s_state.window = window_create();
  window_set_background_color(s_state.window, GColorBlack);
  window_set_window_handlers(s_state.window, (WindowHandlers){
    .load   = prv_window_load,
    .unload = prv_window_unload,
  });
  window_stack_push(s_state.window, true);
  tick_timer_service_subscribe(MINUTE_UNIT, prv_tick_handler);
  unobstructed_area_service_subscribe((UnobstructedAreaHandlers){
    .change      = prv_unobstructed_change,
    .did_change  = prv_unobstructed_did_change,
  }, NULL);
  connection_service_subscribe((ConnectionHandlers){
    .pebble_app_connection_handler = prv_bluetooth_handler,
  });
  app_message_register_inbox_received(prv_inbox_received);
  app_message_open(256, 0);
#ifdef PBL_HEALTH
  health_service_events_subscribe(prv_health_handler, NULL);
#endif
}

static void prv_deinit(void) {
  tick_timer_service_unsubscribe();
  unobstructed_area_service_unsubscribe();
  connection_service_unsubscribe();
#ifdef PBL_HEALTH
  health_service_events_unsubscribe();
#endif
  window_destroy(s_state.window);
}

int main(void) {
  prv_init();
  app_event_loop();
  prv_deinit();
}
