#pragma once

#include "lang/keymap_us_international.h"

#ifdef CAPS_WORD_ENABLE // CAPS_WORD settings
#    undef CAPS_WORD_IDLE_TIMEOUT
#    define BOTH_SHIFTS_TURNS_ON_CAPS_WORD // Use dedicate key instead on OSL
#    define CAPS_WORD_IDLE_TIMEOUT 3000
#endif

// Settings for home row mods
#undef TAPPING_TERM
#define TAPPING_TERM 175
#define IGNORE_MOD_TAP_INTERRUPT // Prevent normal rollover on alphas from accidentally triggering mods.
#define PERMISSIVE_HOLD

#ifdef AUTO_SHIFT_ENABLED // Autoshift
#    define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#    define AUTO_SHIFT_NO_SETUP
#    define RETRO_SHIFT 300
#    define AUTO_SHIFT_REPEAT
/* #    define AUTO_SHIFT_MODIFIERS */
/* #define NO_AUTO_SHIFT_ALPHA */
#endif

#ifdef MOUSEKEY_ENABLE // Mouse key speed and acceleration.
#    undef MOUSEKEY_DELAY
#    define MOUSEKEY_DELAY 0
#    undef MOUSEKEY_INTERVAL
#    define MOUSEKEY_INTERVAL 16
#    undef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY 0
#    undef MOUSEKEY_MAX_SPEED
#    define MOUSEKEY_MAX_SPEED 6
#    undef MOUSEKEY_TIME_TO_MAX
#    define MOUSEKEY_TIME_TO_MAX 64
#endif

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 60000
#    undef WPM_SAMPLE_SECONDS
#    define WPM_SAMPLE_SECONDS 15
#    define WPM_LAUNCH_CONTROL
#    define SPLIT_WPM_ENABLE
#    ifdef KEYBOARD_splitkb_aurora_corne_rev1
#        undef OLED_FONT_H
#        define OLED_FONT_H "users/pipshag/oled/corne_font.c"
#    endif
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    define RGB_MATRIX_HUE_STEP 4
#    define RGB_MATRIX_SAT_STEP 4
#    define RGB_MATRIX_VAL_STEP 4
#    define RGB_MATRIX_SPD_STEP 10
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#endif
