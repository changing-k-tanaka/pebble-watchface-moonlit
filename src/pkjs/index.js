// ============================================================
// 星空ウォッチフェイス — 設定ページ
// ============================================================

// ============================================================
// 日の出・日没計算 (NOAA ESRL アルゴリズム簡易版)
// 戻り値: { sunrise: <0-1439>, sunset: <0-1439> } (端末ローカル時刻の分)
// GPS 取得できない場合は null
// ============================================================

function calcSunTimes(lat, lon) {
  var now = new Date();
  var tzOffsetMin = -now.getTimezoneOffset(); // 東方向が正

  // 年内経過日数 (1〜366)
  var start = new Date(now.getFullYear(), 0, 0);
  var dayOfYear = Math.floor((now - start) / 86400000);

  // 年周角 (radians)
  var gamma = 2 * Math.PI / 365 * (dayOfYear - 1);

  // 均時差 (minutes)
  var eqtime = 229.18 * (0.000075
    + 0.001868 * Math.cos(gamma)   - 0.032077 * Math.sin(gamma)
    - 0.014615 * Math.cos(2*gamma) - 0.040890 * Math.sin(2*gamma));

  // 太陽赤緯 (radians)
  var decl = 0.006918
    - 0.399912 * Math.cos(gamma)   + 0.070257 * Math.sin(gamma)
    - 0.006758 * Math.cos(2*gamma) + 0.000907 * Math.sin(2*gamma)
    - 0.002697 * Math.cos(3*gamma) + 0.001480 * Math.sin(3*gamma);

  var latRad = lat * Math.PI / 180;

  // 時角 (日出・日没の太陽天頂角 = 90.833° で大気屈折・視半径を考慮)
  var cosHA = (Math.cos(90.833 * Math.PI / 180) - Math.sin(latRad) * Math.sin(decl))
              / (Math.cos(latRad) * Math.cos(decl));

  if (cosHA < -1 || cosHA > 1) return null; // 極夜/白夜

  var ha = Math.acos(cosHA) * 180 / Math.PI;

  // UTC分 (真夜中からの分数)
  var sunriseUTC = 720 - 4 * (lon + ha) - eqtime;
  var sunsetUTC  = 720 - 4 * (lon - ha) - eqtime;

  function toLocalMin(utcMin) {
    var m = Math.round(utcMin + tzOffsetMin) % 1440;
    return m < 0 ? m + 1440 : m;
  }

  return { sunrise: toLocalMin(sunriseUTC), sunset: toLocalMin(sunsetUTC) };
}

function minToHHMM(m) {
  var h = Math.floor(m / 60) % 24;
  var mm = m % 60;
  return (h < 10 ? '0' : '') + h + ':' + (mm < 10 ? '0' : '') + mm;
}

function saveCoords(lat, lon) {
  try { localStorage.setItem('horoscope_coords', JSON.stringify({ lat: lat, lon: lon })); } catch(e) {}
}

function loadCoords() {
  try {
    var raw = localStorage.getItem('horoscope_coords');
    if (raw) return JSON.parse(raw);
  } catch(e) {}
  return null;
}

function sendSunTimes() {
  navigator.geolocation.getCurrentPosition(function(pos) {
    saveCoords(pos.coords.latitude, pos.coords.longitude);
    var times = calcSunTimes(pos.coords.latitude, pos.coords.longitude);
    if (!times) return;
    console.log('[horoscope] sunrise=' + times.sunrise + ' sunset=' + times.sunset);
    try {
      localStorage.setItem('horoscope_sun', JSON.stringify(times));
    } catch(e) {}
    try {
      Pebble.sendAppMessage({
        'SUNRISE_MINUTES': times.sunrise,
        'SUNSET_MINUTES':  times.sunset
      });
    } catch(e) {
      console.error('[horoscope] sendSunTimes error: ' + e);
    }
  }, function(err) {
    console.log('[horoscope] geolocation error: ' + err.message);
  }, { timeout: 15000 });
}

function loadSunTimes() {
  try {
    var raw = localStorage.getItem('horoscope_sun');
    if (raw) return JSON.parse(raw);
  } catch(e) {}
  return { sunrise: 360, sunset: 1080 }; // defaults: 06:00 / 18:00
}

// Pure-JS base64 エンコーダ (btoa が未定義な環境向けポリフィル)
function _b64enc(str) {
  var C = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';
  var r = '', i = 0, n = str.length;
  while (i < n) {
    var a = str.charCodeAt(i++);
    var b = str.charCodeAt(i++);
    var c = str.charCodeAt(i++);
    r += C[a >> 2] + C[((a & 3) << 4) | (b >> 4)];
    if (isNaN(b)) { r += '=='; }
    else if (isNaN(c)) { r += C[(b & 15) << 2] + '='; }
    else { r += C[((b & 15) << 2) | (c >> 6)] + C[c & 63]; }
  }
  return r;
}
var _btoa = (typeof btoa === 'function') ? btoa : _b64enc;

function loadSettings() {
  try {
    var raw = localStorage.getItem('horoscope_settings');
    if (raw) {
      var s = JSON.parse(raw);
      // Fill in defaults for new fields if missing
      if (s.widget_left  === undefined) s.widget_left  = 0;
      if (s.widget_right === undefined) s.widget_right = 0;
      if (s.city         === undefined) s.city         = '';
      if (s.date_fmt     === undefined) s.date_fmt     = 12;
      if (s.bt_vibe      === undefined) s.bt_vibe      = 1;
      return s;
    }
  } catch (e) {}
  return {
    mode: 0,
    sky_override: 0,
    shoot_enable: 1,
    shoot_max: 0,
    comet_enable: 1,
    comet_max: 0,
    widget_left: 0,
    widget_right: 0,
    city: '',
    date_fmt: 12,
    bt_vibe: 1
  };
}

function saveSettings(s) {
  try { localStorage.setItem('horoscope_settings', JSON.stringify(s)); } catch (e) {}
}

function weatherCodeToDesc(code) {
  if (code === 0)            return 'Clear';
  if (code <= 3)             return 'Partly';
  if (code <= 48)            return 'Fog';
  if (code <= 57)            return 'Drizzle';
  if (code <= 67)            return 'Rain';
  if (code <= 77)            return 'Snow';
  if (code <= 82)            return 'Shower';
  if (code <= 86)            return 'Snow';
  if (code <= 99)            return 'Thunder';
  return 'N/A';
}

// ── 座標から天気データを取得してウォッチに送信 ──
function fetchWeatherForCoords(lat, lon) {
  var url = 'https://api.open-meteo.com/v1/forecast?latitude=' + lat +
            '&longitude=' + lon +
            '&current=temperature_2m,weather_code' +
            '&hourly=precipitation_probability&forecast_days=1&timezone=auto';
  var xhr = new XMLHttpRequest();
  xhr.open('GET', url, true);
  xhr.onload = function() {
    try {
      var data = JSON.parse(xhr.responseText);
      var code   = data.current.weather_code;
      var temp   = Math.round(data.current.temperature_2m);
      var precip = 0;
      if (data.hourly && data.hourly.precipitation_probability) {
        var h = new Date().getHours();
        precip = data.hourly.precipitation_probability[h] || 0;
      }
      var desc = weatherCodeToDesc(code);
      console.log('[horoscope] weather: ' + desc + ' ' + temp + '\u00b0C ' + precip + '%');
      try {
        Pebble.sendAppMessage({
          'WEATHER_TEMP':   temp,
          'WEATHER_DESC':   desc,
          'WEATHER_PRECIP': precip
        }, function() {
          console.log('[horoscope] Weather sent OK');
        }, function(err) {
          console.log('[horoscope] Weather send failed: ' + JSON.stringify(err));
        });
      } catch(e) {
        console.error('[horoscope] sendWeather sendAppMessage error: ' + e);
      }
    } catch(e) {
      console.error('[horoscope] sendWeather parse error: ' + e);
    }
  };
  xhr.onerror = function() {
    console.log('[horoscope] fetchWeather XHR error');
  };
  xhr.send();
}

// ── 都市名からジオコーディングして座標を返す (Open-Meteo Geocoding API) ──
function fetchCoordsForCity(cityName, onSuccess, onError) {
  var url = 'https://geocoding-api.open-meteo.com/v1/search?name=' +
            encodeURIComponent(cityName) + '&count=1&language=ja&format=json';
  var xhr = new XMLHttpRequest();
  xhr.open('GET', url, true);
  xhr.onload = function() {
    try {
      var data = JSON.parse(xhr.responseText);
      if (data.results && data.results.length > 0) {
        var r = data.results[0];
        console.log('[horoscope] geocode: ' + cityName + ' -> ' + r.latitude + ',' + r.longitude + ' (' + r.name + ')');
        onSuccess(r.latitude, r.longitude, r.name);
      } else {
        console.log('[horoscope] geocode: city not found: ' + cityName);
        if (onError) onError('not found');
      }
    } catch(e) {
      console.error('[horoscope] geocode parse error: ' + e);
      if (onError) onError(e);
    }
  };
  xhr.onerror = function() {
    console.log('[horoscope] geocode XHR error');
    if (onError) onError('xhr error');
  };
  xhr.send();
}

// ── 天気を送信（設定された都市名 or GPS） ──
function sendWeather() {
  var settings = loadSettings();
  var city = (settings.city || '').trim();

  if (city) {
    // 都市名が設定されている場合はジオコーディング経由
    fetchCoordsForCity(city, function(lat, lon) {
      fetchWeatherForCoords(lat, lon);
    }, function() {
      // ジオコーディング失敗時は GPS にフォールバック
      console.log('[horoscope] geocode failed, falling back to GPS');
      sendWeatherByGPS();
    });
  } else {
    sendWeatherByGPS();
  }
}

function sendWeatherByGPS() {
  var cached = loadCoords();
  navigator.geolocation.getCurrentPosition(function(pos) {
    saveCoords(pos.coords.latitude, pos.coords.longitude);
    fetchWeatherForCoords(pos.coords.latitude, pos.coords.longitude);
  }, function(err) {
    console.log('[horoscope] weather geolocation error: ' + err.message);
    // GPS 失敗時はキャッシュ座標で天気を取得
    if (cached) {
      console.log('[horoscope] falling back to cached coords');
      fetchWeatherForCoords(cached.lat, cached.lon);
    }
  }, { timeout: 15000 });
}

function buildConfigHTML(settings) {
  var sel = function(val, opt) { return val === opt ? ' selected' : ''; };
  var chk = function(val) { return val ? ' checked' : ''; };
  var sun = loadSunTimes();
  var sunInfo = 'Sunrise: ' + minToHHMM(sun.sunrise) + ' / Sunset: ' + minToHHMM(sun.sunset);
  // Escape city value for safe HTML attribute embedding
  var cityEsc = (settings.city || '').replace(/&/g,'&amp;').replace(/"/g,'&quot;').replace(/</g,'&lt;');
  // キャッシュ済み座標を HTML に埋め込む（data: URL 内では GPS が使えないため）
  var cachedCoords = loadCoords();
  var cachedCoordsJson = cachedCoords ? JSON.stringify(cachedCoords) : 'null';

  var h = '<!DOCTYPE html><html><head>'
    + '<meta name="viewport" content="width=device-width,initial-scale=1">'
    + '<style>'
    + 'body{background:#1a1a2e;color:#eee;font-family:sans-serif;padding:16px;margin:0}'
    + 'h1{font-size:18px;margin:0 0 16px;color:#7eb8f7}'
    + '.card{background:#16213e;border-radius:8px;padding:12px 14px;margin-bottom:12px}'
    + '.card h2{font-size:13px;font-weight:bold;color:#a0c4ff;margin:0 0 10px;text-transform:uppercase;letter-spacing:.05em}'
    + '.row{display:flex;justify-content:space-between;align-items:center;padding:5px 0}'
    + '.row label{font-size:13px}'
    + '.note{color:#888;font-size:11px;margin-top:6px}'
    + '.info{color:#7eb8f7;font-size:12px;margin:4px 0 8px;text-align:center}'
    + '.wx-row{display:flex;justify-content:space-between;padding:3px 0;font-size:13px}'
    + '.wx-label{color:#a0c4ff;flex-shrink:0;margin-right:8px}'
    + '.wx-val{color:#eee;text-align:right}'
    + 'select{background:#0f3460;color:#eee;border:1px solid #557;border-radius:4px;padding:4px 8px;font-size:13px}'
    + 'input[type=text]{background:#0f3460;color:#eee;border:1px solid #557;border-radius:4px;padding:4px 8px;font-size:13px;width:140px;box-sizing:border-box}'
    + '.sw{position:relative;display:inline-block;width:44px;height:24px;flex-shrink:0}'
    + '.sw input{opacity:0;width:0;height:0}'
    + '.sl{position:absolute;cursor:pointer;inset:0;background:#444;border-radius:24px;transition:.3s}'
    + '.sl:before{content:"";position:absolute;width:18px;height:18px;left:3px;bottom:3px;background:#fff;border-radius:50%;transition:.3s}'
    + 'input:checked+.sl{background:#7eb8f7}'
    + 'input:checked+.sl:before{transform:translateX(20px)}'
    + 'button{width:100%;padding:12px;background:#7eb8f7;color:#1a1a2e;border:none;border-radius:8px;font-size:16px;font-weight:bold;margin-top:8px;cursor:pointer}'
    + '</style></head><body>'
    + '<h1>Moonlit Settings</h1>'

    // Visual Mode
    + '<div class="card"><h2>Visual Mode</h2>'
    + '<p class="info">' + sunInfo + '</p>'
    + '<div class="row"><label>Display Mode</label>'
    + '<select id="mode">'
    + '<option value="0"' + sel(settings.mode, 0) + '>Auto (by time)</option>'
    + '<option value="1"' + sel(settings.mode, 1) + '>Daytime (Earth)</option>'
    + '<option value="2"' + sel(settings.mode, 2) + '>Nighttime (Stars)</option>'
    + '</select></div>'
    + '<p class="note">Auto: shows Earth view from sunrise+30m to sunset. Night sky transitions around sunrise/sunset. Forced night locks to midnight mode (all stars).</p>'

    // Sky Color
    + '<div class="row"><label>Sky Color</label>'
    + '<select id="sky_override">'
    + '<option value="0"' + sel(settings.sky_override, 0) + '>Auto (follow time)</option>'
    + '<option value="1"' + sel(settings.sky_override, 1) + '>Early Evening (brightest blue)</option>'
    + '<option value="2"' + sel(settings.sky_override, 2) + '>Evening Dark</option>'
    + '<option value="3"' + sel(settings.sky_override, 3) + '>Late Night (dark navy)</option>'
    + '<option value="4"' + sel(settings.sky_override, 4) + '>Midnight (black)</option>'
    + '<option value="5"' + sel(settings.sky_override, 5) + '>Pre-Dawn</option>'
    + '</select></div>'
    + '<p class="note">Active when not in Daytime mode.</p>'
    + '</div>'

    // Shooting Stars
    + '<div class="card"><h2>Shooting Stars</h2>'
    + '<div class="row"><label>Enable</label>'
    + '<label class="sw"><input type="checkbox" id="shoot_enable"' + chk(settings.shoot_enable) + '><span class="sl"></span></label></div>'
    + '<div class="row"><label>100% chance (every minute)</label>'
    + '<label class="sw"><input type="checkbox" id="shoot_max"' + chk(settings.shoot_max) + '><span class="sl"></span></label></div>'
    + '<p class="note">Normally ~20% chance per minute.</p>'
    + '</div>'

    // Comet
    + '<div class="card"><h2>Comet</h2>'
    + '<div class="row"><label>Enable</label>'
    + '<label class="sw"><input type="checkbox" id="comet_enable"' + chk(settings.comet_enable) + '><span class="sl"></span></label></div>'
    + '<div class="row"><label>100% chance (every minute)</label>'
    + '<label class="sw"><input type="checkbox" id="comet_max"' + chk(settings.comet_max) + '><span class="sl"></span></label></div>'
    + '<p class="note">Normally ~6.7% chance per minute (emery/gabbro only).</p>'
    + '</div>'

    // Info Widgets
    + '<div class="card"><h2>Info Widgets</h2>'
    + '<div class="row"><label>Left slot</label>'
    + '<select id="wl">'
    + '<option value="0"' + sel(settings.widget_left, 0) + '>None</option>'
    + '<option value="1"' + sel(settings.widget_left, 1) + '>Steps</option>'
    + '<option value="2"' + sel(settings.widget_left, 2) + '>Heart Rate</option>'
    + '<option value="3"' + sel(settings.widget_left, 3) + '>Battery %</option>'
    + '<option value="4"' + sel(settings.widget_left, 4) + '>Weather + Temp</option>'
    + '<option value="6"' + sel(settings.widget_left, 6) + '>Precipitation</option>'
    + '</select></div>'
    + '<div class="row"><label>Right slot</label>'
    + '<select id="wr">'
    + '<option value="0"' + sel(settings.widget_right, 0) + '>None</option>'
    + '<option value="1"' + sel(settings.widget_right, 1) + '>Steps</option>'
    + '<option value="2"' + sel(settings.widget_right, 2) + '>Heart Rate</option>'
    + '<option value="3"' + sel(settings.widget_right, 3) + '>Battery %</option>'
    + '<option value="4"' + sel(settings.widget_right, 4) + '>Weather + Temp</option>'
    + '<option value="6"' + sel(settings.widget_right, 6) + '>Precipitation</option>'
    + '</select></div>'
    + '<div class="row"><label>City (weather)</label>'
    + '<input type="text" id="city" value="' + cityEsc + '" placeholder="Leave blank for GPS"></div>'
    + '<p class="note">City name for weather data (e.g. Tokyo, New York, Paris). Leave blank to use GPS location.</p>'
    + '<p class="note">Steps &amp; Heart Rate require Pebble Health. Weather / Precip require phone connection.</p>'
    + '<p class="note">Round watch: slots appear at center-left and center-right.</p>'
    + '</div>'

    // Bluetooth
    + '<div class="card"><h2>Bluetooth</h2>'
    + '<div class="row"><label>Vibrate on disconnect</label>'
    + '<label class="sw"><input type="checkbox" id="bt_vibe"' + chk(settings.bt_vibe) + '><span class="sl"></span></label></div>'
    + '<p class="note">Double-pulse vibration when the phone connection is lost.</p>'
    + '</div>'

    // Date Format
    + '<div class="card"><h2>Date Format</h2>'
    + '<div class="row"><label>Format</label>'
    + '<select id="date_fmt">'
    + '<option value="0"'  + sel(settings.date_fmt,  0) + '>Weekday, DD, MM</option>'
    + '<option value="1"'  + sel(settings.date_fmt,  1) + '>Weekday, DD.MM.YY</option>'
    + '<option value="2"'  + sel(settings.date_fmt,  2) + '>Weekday, DD.MM.YYYY</option>'
    + '<option value="3"'  + sel(settings.date_fmt,  3) + '>DD.MM.YYYY</option>'
    + '<option value="4"'  + sel(settings.date_fmt,  4) + '>Weekday, DD/MM</option>'
    + '<option value="5"'  + sel(settings.date_fmt,  5) + '>Weekday, DD/MM/YY</option>'
    + '<option value="6"'  + sel(settings.date_fmt,  6) + '>Weekday, DD/MM/YYYY</option>'
    + '<option value="7"'  + sel(settings.date_fmt,  7) + '>DD/MM/YYYY</option>'
    + '<option value="8"'  + sel(settings.date_fmt,  8) + '>Weekday, MM/DD</option>'
    + '<option value="9"'  + sel(settings.date_fmt,  9) + '>Weekday, MM/DD/YY</option>'
    + '<option value="10"' + sel(settings.date_fmt, 10) + '>Weekday, MM/DD/YYYY</option>'
    + '<option value="11"' + sel(settings.date_fmt, 11) + '>MM/DD/YYYY</option>'
    + '<option value="12"' + sel(settings.date_fmt, 12) + '>Weekday, YYYY-MM-DD</option>'
    + '<option value="13"' + sel(settings.date_fmt, 13) + '>YYYY-MM-DD</option>'
    + '<option value="14"' + sel(settings.date_fmt, 14) + '>YYYY-MM-DD Weekday</option>'
    + '</select></div>'
    + '</div>'

    // Location & Weather info card
    + '<div class="card"><h2>Location &amp; Weather</h2>'
    + '<div class="wx-row"><span class="wx-label">Lat / Lon</span><span class="wx-val" id="wx-latlon">---</span></div>'
    + '<div class="wx-row"><span class="wx-label">City</span><span class="wx-val" id="wx-city">---</span></div>'
    + '<div class="wx-row"><span class="wx-label">Conditions</span><span class="wx-val" id="wx-desc">---</span></div>'
    + '<div class="wx-row"><span class="wx-label">Temperature</span><span class="wx-val" id="wx-temp">---</span></div>'
    + '<div class="wx-row"><span class="wx-label">Precipitation</span><span class="wx-val" id="wx-precip">---</span></div>'
    + '<p id="wx-status" class="note">Fetching...</p>'
    + '<button type="button" onclick="wxFetch()" style="margin-top:8px;padding:6px 16px;font-size:12px;width:auto;background:#3a5a8a;color:#eee">Refresh</button>'
    + '</div>'

    + '<button onclick="save()">Save &amp; Close</button>'
    + '<script>'
    // キャッシュ済み座標（data: URL 内では GPS が使えないためフォールバック用）
    + 'var _cc=' + cachedCoordsJson + ';'
    // ── 天気情報取得 ──
    + 'function wxSet(id,v){var e=document.getElementById(id);if(e)e.textContent=v;}'
    + 'function wxSt(v){wxSet("wx-status",v);}'
    + 'function wxDoFetch(lat,lon){'
    +   'wxSet("wx-latlon",lat.toFixed(4)+"\u00b0 / "+lon.toFixed(4)+"\u00b0");'
    +   'var rx=new XMLHttpRequest();'
    +   'rx.open("GET","https://nominatim.openstreetmap.org/reverse?format=json&lat="+lat+"&lon="+lon+"&zoom=10&accept-language=en",true);'
    +   'rx.onload=function(){try{var d=JSON.parse(rx.responseText),a=d.address||{};'
    +     'wxSet("wx-city",a.city||a.town||a.village||a.county||d.display_name||"---");'
    +   '}catch(e){wxSet("wx-city","---");}};'
    +   'rx.onerror=function(){wxSet("wx-city","---");};rx.send();'
    +   'var wx=new XMLHttpRequest();'
    +   'wx.open("GET","https://api.open-meteo.com/v1/forecast?latitude="+lat+"&longitude="+lon+"&current=temperature_2m,weather_code&hourly=precipitation_probability&forecast_days=1&timezone=auto",true);'
    +   'wx.onload=function(){try{'
    +     'var d=JSON.parse(wx.responseText),c=d.current;'
    +     'wxSet("wx-temp",c.temperature_2m+"\u00b0C");'
    +     'var cd=c.weather_code;'
    +     'var desc=cd===0?"Clear":cd<=3?"Partly Cloudy":cd<=48?"Fog":cd<=57?"Drizzle":cd<=67?"Rain":cd<=77?"Snow":cd<=82?"Showers":cd<=86?"Snow":cd<=99?"T-Storm":"Unknown";'
    +     'wxSet("wx-desc",desc);'
    +     'var h=new Date().getHours();'
    +     'var pp=d.hourly&&d.hourly.precipitation_probability?d.hourly.precipitation_probability[h]||0:0;'
    +     'wxSet("wx-precip",pp+"%");'
    +     'wxSt("");'
    +   '}catch(e){wxSt("Fetch failed");}};'
    +   'wx.onerror=function(){wxSt("Fetch failed");};wx.send();'
    + '}'
    + 'function wxFetch(){'
    +   'var city=document.getElementById("city").value.trim();'
    +   'if(city){'
    +     'wxSt("Fetching from city name...");'
    +     'var gx=new XMLHttpRequest();'
    +     'gx.open("GET","https://geocoding-api.open-meteo.com/v1/search?name="+encodeURIComponent(city)+"&count=1&language=en&format=json",true);'
    +     'gx.onload=function(){try{'
    +       'var d=JSON.parse(gx.responseText);'
    +       'if(d.results&&d.results.length>0){var r=d.results[0];wxSet("wx-city",r.name);wxDoFetch(r.latitude,r.longitude);}'
    +       'else{wxSt("City not found");}'
    +     '}catch(e){wxSt("Fetch failed");}};'
    +     'gx.onerror=function(){wxSt("Fetch failed");};gx.send();'
    +   '}else{'
    +     'wxSt("Locating via GPS...");'
    +     'navigator.geolocation.getCurrentPosition('
    +       'function(p){wxDoFetch(p.coords.latitude,p.coords.longitude);},'
    +       'function(){'
    +         'if(_cc){wxSt("Using cached location...");wxDoFetch(_cc.lat,_cc.lon);}'
    +         'else{wxSt("GPS failed (no cached location)");}'
    +       '},'
    +       '{timeout:10000});'
    +   '}'
    + '}'
    + 'wxFetch();'
    // ── 保存 ──
    + 'function save(){'
    + 'var S={'
    + 'mode:+document.getElementById("mode").value,'
    + 'sky_override:+document.getElementById("sky_override").value,'
    + 'shoot_enable:document.getElementById("shoot_enable").checked?1:0,'
    + 'shoot_max:document.getElementById("shoot_max").checked?1:0,'
    + 'comet_enable:document.getElementById("comet_enable").checked?1:0,'
    + 'comet_max:document.getElementById("comet_max").checked?1:0,'
    + 'widget_left:+document.getElementById("wl").value,'
    + 'widget_right:+document.getElementById("wr").value,'
    + 'city:document.getElementById("city").value.trim(),'
    + 'date_fmt:+document.getElementById("date_fmt").value,'
    + 'bt_vibe:document.getElementById("bt_vibe").checked?1:0'
    + '};'
    + 'var cfg=encodeURIComponent(JSON.stringify(S));'
    + 'var m=location.href.match(/[?&]return_to=([^&]+)/);'
    + 'if(m){location.href=decodeURIComponent(m[1])+cfg;}'
    + 'else{location.href="pebblejs://close#"+cfg;}'
    + '}<\/script>'
    + '</body></html>';

  return h;
}

// ── 設定画面を開く ──
Pebble.addEventListener('showConfiguration', function () {
  try {
    var settings = loadSettings();
    var html = buildConfigHTML(settings);

    var isEmulator = false;
    try {
      var info = Pebble.getActiveWatchInfo();
      if (info && info.model && info.model.indexOf('qemu') !== -1) isEmulator = true;
    } catch (e) {}

    var url;
    if (isEmulator) {
      // エミュレータ: percent-encoding で Chrome に渡す（base64 は ?return_to= で破損）
      url = 'data:text/html;charset=utf-8,' + encodeURIComponent(html);
    } else {
      // 実機: base64 で WKWebView に渡す
      // unescape+encodeURIComponent は UTF-8→Latin-1 変換（ASCII HTML には実質 no-op だが
      // btoa が Latin-1 のみ受け付ける仕様のため保険として残す）
      url = 'data:text/html;base64,' + _btoa(unescape(encodeURIComponent(html)));
    }
    console.log('[horoscope] showConfiguration isEmulator=' + isEmulator + ' urlLen=' + url.length);
    Pebble.openURL(url);
  } catch (err) {
    console.error('[horoscope] showConfiguration error: ' + (err && err.message ? err.message : String(err)));
  }
});

// ── 設定画面が閉じたら Watch に送信 ──
Pebble.addEventListener('webviewclosed', function (e) {
  if (!e.response || e.response === 'CANCELLED') return;
  var settings;
  try { settings = JSON.parse(decodeURIComponent(e.response)); } catch (e2) { return; }
  saveSettings(settings);
  try {
    Pebble.sendAppMessage({
      'SETTINGS_MODE_OVERRIDE': settings.mode,
      'SETTINGS_SKY_OVERRIDE':  settings.sky_override,
      'SETTINGS_SHOOT_ENABLE':  settings.shoot_enable,
      'SETTINGS_SHOOT_MAX':     settings.shoot_max,
      'SETTINGS_COMET_ENABLE':  settings.comet_enable,
      'SETTINGS_COMET_MAX':     settings.comet_max,
      'WIDGET_LEFT':            settings.widget_left  || 0,
      'WIDGET_RIGHT':           settings.widget_right || 0,
      'DATE_FMT':               settings.date_fmt     || 0,
      'SETTINGS_BT_VIBE':       settings.bt_vibe !== undefined ? settings.bt_vibe : 1
    }, function () {
      console.log('[horoscope] Settings sent OK');
      // Send fresh weather after settings update
      sendWeather();
    }, function (err) {
      console.log('[horoscope] Settings send failed: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('[horoscope] webviewclosed sendAppMessage error: ' + err);
  }
});

// ── 接続時に保存済み設定を同期 + 日の出/日没/天気を送信 ──
Pebble.addEventListener('ready', function () {
  sendSunTimes();
  sendWeather();
  // Refresh weather every 30 minutes
  setInterval(sendWeather, 30 * 60 * 1000);
  var settings = loadSettings();
  try {
    Pebble.sendAppMessage({
      'SETTINGS_MODE_OVERRIDE': settings.mode,
      'SETTINGS_SKY_OVERRIDE':  settings.sky_override,
      'SETTINGS_SHOOT_ENABLE':  settings.shoot_enable,
      'SETTINGS_SHOOT_MAX':     settings.shoot_max,
      'SETTINGS_COMET_ENABLE':  settings.comet_enable,
      'SETTINGS_COMET_MAX':     settings.comet_max,
      'WIDGET_LEFT':            settings.widget_left  || 0,
      'WIDGET_RIGHT':           settings.widget_right || 0,
      'DATE_FMT':               settings.date_fmt     || 0,
      'SETTINGS_BT_VIBE':       settings.bt_vibe !== undefined ? settings.bt_vibe : 1
    });
  } catch (err) {
    console.error('[horoscope] ready sendAppMessage error: ' + err);
  }
});