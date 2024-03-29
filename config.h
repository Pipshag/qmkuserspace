#pragma once

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE

#ifdef CAPS_WORD_ENABLE // CAPS_WORD settings
#    undef CAPS_WORD_IDLE_TIMEOUT
#    define BOTH_SHIFTS_TURNS_ON_CAPS_WORD // Use dedicate key instead on OSL
#    define CAPS_WORD_IDLE_TIMEOUT 5000
#endif

// Settings for home row mods
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT // Prevent normal rollover on alphas from
                                 // accidentally triggering mods.

/* #ifdef AUTO_SHIFT_ENABLED // Autoshift */
/* #define NO_AUTO_SHIFT_ALPHA */
/* #define AUTO_SHIFT_REPEAT */
/* #define AUTO_SHIFT_TIMEOUT TAPPING_TERM */
/* #define AUTO_SHIFT_NO_SETUP */
/* #    define AUTO_SHIFT_MODIFIERS */
/* #define RETRO_SHIFT 250 */
/* #endif */

#ifdef MOUSEKEY_ENABLE // Mouse key speed and acceleration.
#    undef MOUSEKEY_DELAY
#    define MOUSEKEY_DELAY 10
#    undef MOUSEKEY_INTERVAL
#    define MOUSEKEY_INTERVAL 10
#    undef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY 0
#    undef MOUSEKEY_MAX_SPEED
#    define MOUSEKEY_MAX_SPEED 6
#    undef MOUSEKEY_TIME_TO_MAX
#    define MOUSEKEY_TIME_TO_MAX 64
#endif

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 60000
#    define OLED_BRIGHTNESS 28
#    define OLED_UPDATE_INTERVAL 10
#    define OLED_FONT_WIDTH 6
#    undef WPM_SAMPLE_SECONDS
#    define WPM_SAMPLE_SECONDS 15
#    define WPM_LAUNCH_CONTROL
#    define SPLIT_WPM_ENABLE
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#    define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5
#    define RGB_MATRIX_SPLIT \
        { 27, 27 }
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
/* #    define RGB_MATRIX_KEYPRESSES */
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#endif
