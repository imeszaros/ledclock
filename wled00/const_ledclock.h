#include "inttypes.h"
#include "Arduino.h"

#ifndef WLED_CONST_LEDCLOCK_H
#define WLED_CONST_LEDCLOCK_H

#define MDNS_PREFIX "ledclock"
#define MQTT_DEVICE_TOPIC "ledclock"
#define MQTT_CLIENT_ID "LEDCLOCK"

#define BUZZER_PIN 12
#define ADC_MAX_VALUE 4095
#define ADC_MAX_VOLTAGE 3.3
#define BRIGHTNESS_SAMPLES 1024
#define BRIGHTNESS_THRESHOLD 5
#define BRIGHTNESS_PIN 34

#define STOPWATCH_MAX_LAP_TIMES 100

#define BEEP_SILENT 255

// How to configure the display?
//
// Think of your clock display as 2D matrix of pixels rather than a 7 segment display.
//
// Some pixels of this 2D matrix are missing, others are present. To get the layout
// where the pixels are missing or present, first decide on how many LEDs you want per segment.
//
// For example,  if you have only one LED per segment, the layout is the following:
//
//  -#--#---#--#-
//  #-##-###-##-#
//  -#--#---#--#-
//  #-##-###-##-#
//  -#--#---#--#-
//
// Where the symbol '-' represents a missing pixel and symbol '#' represents a pixel that presents.
// Note the two 'separator' pixels in the middle 'horizontal' column.
//
// If you have 2 LEDs per segment,  the layout is the following:
//
// -##--##---##--##-
// #--##--#-#--##--#
// #--##--###--##--#
// -##--##---##--##-
// #--##--###--##--#
// #--##--#-#--##--#
// -##--##---##--##-
//
// Similarly,  on case of 3 LEDs per segment:
//
// -###--###---###--###-
// #---##---#-#---##---#
// #---##---###---##---#
// #---##---#-#---##---#
// -###--###---###--###-
// #---##---#-#---##---#
// #---##---###---##---#
// #---##---#-#---##---#
// -###--###---###--###-
//
// Next you need to replace all the '-' symbols with -1 and all the '#' symbols with LED indices. Which index
// you write in place of a particular '#' symbol depends on the physical layout of your LED strip.
//
// In the example below there are 2 LEDs per segment, and the LED strip begins with the bottommost segment of
// the first number then continues with the leftmost segments from the bottom to the top. I added extra spaces
// between the numbers and the separator column just for better clarity.

#define LC_LEDS_PER_SEGM 9 // LEDs per segment

#define LC_LEDMAP \
   -1, 206, 205, 204, 203, 202, 201, 200, 199, 198,  -1,       -1, 143, 142, 141, 140, 139, 138, 137, 136, 135,  -1,      -1,      -1,  80,  79,  78,  77,  76,  75,  74,  73,  72,  -1,    -1, 17, 16, 15, 14, 13, 12, 11, 10,  9, -1, \
  207,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 197,      144,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 134,     252,      81,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  71,    18, -1, -1, -1, -1, -1, -1, -1, -1, -1,  8, \
  208,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 196,      145,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 133,     253,      82,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  70,    19, -1, -1, -1, -1, -1, -1, -1, -1, -1,  7, \
  209,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 195,      146,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 132,     254,      83,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  69,    20, -1, -1, -1, -1, -1, -1, -1, -1, -1,  6, \
  210,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 194,      147,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 131,     255,      84,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  68,    21, -1, -1, -1, -1, -1, -1, -1, -1, -1,  5, \
  211,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 193,      148,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 130,     256,      85,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  67,    22, -1, -1, -1, -1, -1, -1, -1, -1, -1,  4, \
  212,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 192,      149,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 129,     257,      86,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  66,    23, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3, \
  213,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 191,      150,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 128,     258,      87,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  65,    24, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, \
  214,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 190,      151,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 127,      -1,      88,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  64,    25, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, \
  215,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 189,      152,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 126,      -1,      89,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  63,    26, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, \
   -1, 216, 217, 218, 219, 220, 221, 222, 223, 224,  -1,       -1, 153, 154, 155, 156, 157, 158, 159, 160, 161,  -1,      -1,      -1,  90,  91,  92,  93,  94,  95,  96,  97,  98,  -1,    -1, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, \
  251,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 225,      188,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 162,     259,     125,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  99,    62, -1, -1, -1, -1, -1, -1, -1, -1, -1, 36, \
  250,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 226,      187,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 163,     260,     124,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 100,    61, -1, -1, -1, -1, -1, -1, -1, -1, -1, 37, \
  249,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 227,      186,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 164,     261,     123,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 101,    60, -1, -1, -1, -1, -1, -1, -1, -1, -1, 38, \
  248,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 228,      185,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 165,     262,     122,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 102,    59, -1, -1, -1, -1, -1, -1, -1, -1, -1, 39, \
  247,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 229,      184,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 166,     263,     121,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 103,    58, -1, -1, -1, -1, -1, -1, -1, -1, -1, 40, \
  246,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 230,      183,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 167,     264,     120,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 104,    57, -1, -1, -1, -1, -1, -1, -1, -1, -1, 41, \
  245,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 231,      182,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 168,     265,     119,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 105,    56, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, \
  244,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 232,      181,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 169,      -1,     118,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 106,    55, -1, -1, -1, -1, -1, -1, -1, -1, -1, 43, \
  243,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 233,      180,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 170,      -1,     117,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 107,    54, -1, -1, -1, -1, -1, -1, -1, -1, -1, 44, \
   -1, 242, 241, 240, 239, 238, 237, 236, 235, 234,  -1,       -1, 179, 178, 177, 176, 175, 174, 173, 172, 171,  -1,      -1,      -1, 116, 115, 114, 113, 112, 111, 110, 109, 108,  -1,    -1, 53, 52, 51, 50, 49, 48, 47, 46,  45, -1 


// Next configure the separator LEDs by first defining how many of them you have:
#define LC_SEP_LEDS 14

// Then write their row indices separated by commas below (notice the separator LEDs #28 and #29 having row indices 2 and 4 in the above LED map):
// #define LC_SEP_LED_ROWS 1, 2
#define LC_SEP_LED_ROWS 1, 2,3,4,5,6,7,11,12,13,14,15,16,17

// Finally, don't forget to change the total number of LEDs (DEFAULT_LED_COUNT) in `platformio_override.ini`,
// set it to the total size of the LED matrix you have. This number is calculated below and a compiler warning
// is emitted if it does not match with DEFAULT_LED_COUNT.

#define LC_COLS     (((LC_LEDS_PER_SEGM + 2) * 4) + 1)
#define LC_ROWS      ((LC_LEDS_PER_SEGM * 2) + 3)
#define LC_TOTAL_LEDS (LC_COLS * LC_ROWS) // DEFAULT_LED_COUNT should be set to this value

#if !defined(DEFAULT_LED_COUNT) || DEFAULT_LED_COUNT != LC_TOTAL_LEDS
#define LC_XSTR(x) LC_STR(x)
#define LC_STR(x) #x
#pragma message "Macro DEFAULT_LED_COUNT is not defined or is not equal to the calculated number of total LEDs: " LC_XSTR(LC_TOTAL_LEDS)
#endif

// Your display still does not work properly? Verify all the steps above, and if everything looks right, follow these steps:
//   1. navigate your browser http://wled-ip/edit
//   2. right click on /ledmap.json
//   3. choose 'Delete'
//   4. reboot WLED
// The file ledmap.json should now be regenerated with the correct settings and your display should now work properly.


#define LC_PHYSICAL_LEDS (LC_SEP_LEDS + 4 * 7 * LC_LEDS_PER_SEGM)

#define LC_R(c) (byte((c) >> 16))
#define LC_G(c) (byte((c) >> 8))
#define LC_B(c) (byte(c))
#define LC_W(c) (byte((c) >> 24))

class LedClockSettingsKeys {
public:
    static const char *root;

    class Brightness {
    public:
        static const char *autom, *min, *max;
    };

    class Display {
    public:
        static const char *separatorMode, *hideZero;
    };

    class Beeps {
    public:
        static const char *mute, *startup, *wifi;

        class Clock {
        public:
            static const char *minute, *hour;
        };

        class Timer {
        public:
            static const char *set, *start, *pause, *resume, *reset, *increase, *hour, *minute, *second, *timeout;
        };

        class Stopwatch {
        public:
            static const char *start, *pause, *resume, *reset, *second, *minute, *hour, *lapTime;
        };
    };
};

class LedClockStateKeys {
public:
    static const char *root, *command, *mode, *beep, *blendingMode, *canvasColor;

    class Timer {
    public:
        static const char *root, *running, *paused, *left, *value;
    };

    class Stopwatch{
    public:
        static const char *root, *running, *paused, *elapsed, *lapTimes, *lapTimeNr, *lastLapTime;
    };
};

class LedClockSettings {

public:
    enum SeparatorMode {
        ON, OFF, BLINK
    };

    virtual ~LedClockSettings() {}
    bool autoBrightness = true;
    uint8_t minBrightness = 50; // must NOT be lower than 1
    uint8_t maxBrightness = 255;
    SeparatorMode separatorMode = SeparatorMode::BLINK;
    bool hideZero = true;

    bool muteBeeps = false;

    uint8_t beepStartup, beepWiFi;
    uint8_t clockBeepMinute, clockBeepHour;
    uint8_t timerBeepSet, timerBeepStart, timerBeepPause, timerBeepResume, timerBeepReset, timerBeepIncrease, timerBeepHour, timerBeepMinute, timerBeepSecond, timerBeepTimeout;
    uint8_t stopwatchBeepStart, stopwatchBeepPause, stopwatchBeepResume, stopwatchBeepReset, stopwatchBeepSecond, stopwatchBeepMinute, stopwatchBeepHour, stopwatchBeepLapTime;

    virtual void applySettings() = 0;

    static uint8_t constrainBeep(uint8_t beep);
};

const char JSON_ledclock_beeps[] PROGMEM = R"=====([
"1x 330Hz (short)",
"2x 330Hz (short)",
"3x 330Hz (short)",
"1x 440Hz (short)",
"2x 440Hz (short)",
"3x 440Hz (short)",
"1x 880Hz (short)",
"2x 880Hz (short)",
"3x 880Hz (short)",
"1x 330Hz (medium)",
"2x 330Hz (medium)",
"3x 330Hz (medium)",
"1x 440Hz (medium)",
"2x 440Hz (medium)",
"3x 440Hz (medium)",
"1x 880Hz (medium)",
"2x 880Hz (medium)",
"3x 880Hz (medium)",
"1x 330Hz (long)",
"2x 330Hz (long)",
"3x 330Hz (long)",
"1x 440Hz (long)",
"2x 440Hz (long)",
"3x 440Hz (long)",
"1x 880Hz (long)",
"2x 880Hz (long)",
"3x 880Hz (long)",
"440/880Hz (short)",
"880/440Hz (short)",
"440/880Hz (medium)",
"880/440Hz (medium)",
"440/880Hz (long)",
"880/440Hz (long)",
"Turn Up",
"Turn Down",
"Flip Up",
"Flip Down",
"Tadaaa"
])=====";

// custom effects

#define FX_MODE_LC_2SOFIX     187
#define FX_MODE_LC_VORTEX     188
#define FX_MODE_LC_CONCENTRIC 189

// forward declarations

void ledClockTimeUpdated();

#endif