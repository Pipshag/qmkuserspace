#pragma once

#define LAYER_STATE_8BIT

// Oneshot settings
#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 10000

// Settings for home row mods
#define TAP_CODE_DELAY 5
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM TAPPING_TERM / 2
// #define TAPPING_FORCE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT // Prevent normal rollover
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#ifdef SPLIT_KEYBOARD
#    ifdef __AVR__
#        define SPLIT_USB_DETECT
#        define SPLIT_WATCHDOG_ENABLE
#    endif
#    if defined(OLED_ENABLE) || defined(RGB_MATRIX_ENABLE)
#        define SPLIT_OLED_ENABLE
#        define SPLIT_MODS_ENABLE
#        define SPLIT_LED_STATE_ENABLE
#        define SPLIT_LAYER_STATE_ENABLE
#    endif
#endif

#ifdef CAPS_WORD_ENABLE
#    define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD // Tap to activate
#    define CAPS_WORD_IDLE_TIMEOUT 5000
#endif

#ifdef AUTO_SHIFT_ENABLED // Autoshift
#    define NO_AUTO_SHIFT_ALPHA
#    define AUTO_SHIFT_REPEAT
#    define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#    define AUTO_SHIFT_NO_SETUP
#    define AUTO_SHIFT_MODIFIERS
#endif

#ifdef MOUSEKEY_ENABLE // Mouse key speed and acceleration.
#    undef MOUSEKEY_DELAY
#    define MOUSEKEY_DELAY 0
#    undef MOUSEKEY_INTERVAL
#    define MOUSEKEY_INTERVAL 15
#    define MOUSEKEY_MOVE_DELTA 10
#    undef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY 16
#    undef MOUSEKEY_MAX_SPEED
#    define MOUSEKEY_MAX_SPEED 9
#    undef MOUSEKEY_TIME_TO_MAX
#    define MOUSEKEY_TIME_TO_MAX 80
#endif

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 10000
#    define OLED_BRIGHTNESS 28
#    define OLED_UPDATE_INTERVAL 10
#    define OLED_FONT_WIDTH 6
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_TIMEOUT 180000
#    define RGB_MATRIX_SPLIT \
        { 27, 27 }
#    define RGB_MATRIX_KEYPRESSES
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#endif

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 1
#endif
