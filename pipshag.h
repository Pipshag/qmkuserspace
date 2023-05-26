#pragma once

#include QMK_KEYBOARD_H

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    CDE_BLCK, // markdown code block
};

#define OSM_LSFT            OSM(MOD_LSFT)       // Regular one shot shift key
#define KC_STAB             LSFT(KC_TAB)        // Shift+Tab

#define NEXT_TAB            LCTL(KC_TAB)        // Next tab (in browser etc)
#define PREV_TAB            LCTL(KC_STAB)       // Previous tab (in browser etc)

#define SCRNSHT             LGUI(LSFT(KC_P))   // Start the screenshot app

#define KC_EUR              LSFT(RALT(KC_2))    // €