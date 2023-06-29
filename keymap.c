// Created by: pip
// Mod tap ZMK-like functionality
// https://github.com/filterpaper/qmk_userspace

#include "config.h"
#include QMK_KEYBOARD_H
#include "oled/corne_oled.c"
#include "rgb/rgb.c"

static inline bool process_tap_hold(uint16_t keycode, keyrecord_t *record);

enum layers {
    _CMK,
    _NAV,
    _NUM,
    _SYM,
    _MSE,
    _GAM,
};

// Tap för åäö

// Shortcuts
// #define Z_UND KC_UNDO
// #define Z_CUT KC_CUT
// #define Z_CPY KC_COPY
// #define Z_PST KC_PASTE
#define Z_CLNS KC_COLN

#define US_ARNG RALT(KC_W) // å
#define US_ADIA RALT(KC_Q) // ä
#define US_ODIA RALT(KC_P) // ö
#define US_EUR RALT(KC_5)  // €

#define M_SPST RCS(KC_V) // Paste from clipboard + shift ctrl
#define NEXT_TAB LCTL(KC_TAB)
#define PREV_TAB LCTL(LSFT(KC_TAB))
#define SCRNSHT LGUI(KC_P)

#define BSPC_WRD LCTL(KC_BSPC)
#define DEL_WRD LCTL(KC_DEL)

// Tap hold macros
#define TH_CLNS LT(0, KC_SCLN)
#define TH_UM_ACOMM LT(0, KC_COMM)
#define TH_UM_AECOMM LT(0, KC_DOT)
#define TH_UM_OCOMM LT(0, KC_SLSH)
// #define TH_COMM LT(0, KC_COMM)
// #define TH_DOT LT(0, KC_DOT)
// #define TH_SLSH LT(0, KC_SLSH)

/* Keymap start */
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CMK] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_G,                                            KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO,
        KC_NO, LGUI_T(KC_A),LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D,             KC_H, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_NO,
        KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,                                            KC_K, KC_M, TH_UM_ACOMM, TH_UM_AECOMM, TH_UM_OCOMM, KC_NO,
                                LT(_MSE,KC_ESC), LT(_NAV,KC_SPC), OSM(MOD_LSFT),        KC_ENT, LT(_NUM,KC_BSPC), LT(_SYM,KC_DEL)
    ),

    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO, LSFT(KC_TAB), KC_TAB, PREV_TAB, NEXT_TAB, SCRNSHT,                       KC_PGUP, KC_H, KC_J, KC_K, KC_L, KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                               KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
        KC_NO, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, M_SPST,                               KC_HOME, KC_NO, KC_NO, KC_NO, KC_END, KC_NO,
                                KC_NO, KC_NO, KC_NO,                                    KC_ENT, BSPC_WRD, DEL_WRD
    ),

	[_NUM] = LAYOUT_split_3x6_3(
        KC_NO, QK_BOOT, KC_7, KC_8, KC_9, KC_VOLU,                                      KC_MNXT, KC_NO, RGB_SAI, RGB_SPI, RGB_MOD, KC_NO,
        KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_VOLD,                                        KC_MPLY, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_NO,
        AS_TOGG, KC_1, KC_2, KC_3, KC_DOT,                                              KC_MPRV, CW_TOGG, RGB_HUI, RGB_VAI, RGB_TOG, KC_NO,
                       KC_EQL, KC_0, KC_MINS,                                           KC_NO, KC_NO, KC_NO
    ),

	[_SYM] = LAYOUT_split_3x6_3(
        KC_NO, KC_PERC, KC_CIRC, KC_DLR, US_EUR, TH_CLNS,                               KC_NO, KC_LCBR, KC_RCBR, KC_AT, KC_HASH, KC_NO,
        KC_NO, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_PIPE,                             KC_NO, KC_LPRN, KC_RPRN, KC_LT, KC_GT, KC_NO,
        KC_NO, KC_BSLS, KC_AMPR, KC_EXLM, KC_EQL, KC_UNDS,                              KC_NO, KC_LBRC, KC_RBRC, KC_TILD, KC_GRV, KC_NO,
                                 KC_ESC, KC_SPC, KC_TAB,                                KC_NO, KC_NO, KC_NO
    ),

	[_MSE] = LAYOUT_split_3x6_3(
        KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,                                      KC_WH_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_NO,                                       KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
        KC_NO, TG(5), KC_F1, KC_F2, KC_F3, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO,                                       KC_BTN2, KC_BTN1, KC_BTN3
    ),

	[_GAM] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_G,                                            KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO,
        KC_NO, KC_A, KC_R, KC_S, KC_T, KC_D,                                            KC_H, KC_N, KC_E, KC_I, KC_O, KC_NO,
        KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,                                            KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                           LT(4,KC_ESC), LT(1,KC_SPC), KC_LSFT,                         KC_ENT, LT(2,KC_BSPC), TG(5)
    )
};
// clang-format on

/* Home row mods logic start */

// Home row mod-taps on either side
// Match rows on a 3x5_2 split keyboard
#define IS_TYPING() (timer_elapsed_fast(tap_timer) < TAPPING_TERM * 2)
#define IS_HOMEROW(r) (r->event.key.row == 1 || r->event.key.row == 5)
#define IS_MOD_TAP_SHIFT(kc) (QK_MOD_TAP_GET_MODS(kc) & MOD_LSFT)

#define L_HRM() (record->event.key.row == 1)
#define R_HRM() (record->event.key.row == 5)
#define L_ALPHA() (0 <= next_record.event.key.row && next_record.event.key.row <= 2)
#define R_ALPHA() (4 <= next_record.event.key.row && next_record.event.key.row <= 6)

#define IS_UNILATERAL_TAP(r, n) ((r->event.key.row == 1 && 0 <= n.event.key.row && n.event.key.row <= 2) || (r->event.key.row == 5 && 4 <= n.event.key.row && n.event.key.row <= 6))

#define IS_BILATERAL_TAP(r, n) ((r->event.key.row == 1 && 4 <= n.event.key.row && n.event.key.row <= 6) || (r->event.key.row == 5 && 0 <= n.event.key.row && n.event.key.row <= 2))

// For contextual mod-taps
static uint16_t    next_keycode;
static keyrecord_t next_record;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Copy the next key record for tap-hold decisions
        next_keycode = keycode;
        next_record  = *record;
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Hold Shift with a nested bilateral tap
    return IS_BILATERAL_TAP(record, next_record) && IS_MOD_TAP_SHIFT(keycode);
}

static fast_timer_t tap_timer = 0;

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSM(MOD_LSFT):
            return TAPPING_TERM * 2;
        case TH_UM_ACOMM:
            return QUICK_TAP_TERM;
        case TH_UM_AECOMM:
            return QUICK_TAP_TERM;
        case TH_UM_OCOMM:
            return QUICK_TAP_TERM;
        default:
            // Increase tapping term for the home row mod-tap while typing
            return IS_HOMEROW(record) && !IS_MOD_TAP_SHIFT(keycode) && IS_TYPING() ? TAPPING_TERM * 2 : TAPPING_TERM;
    }
}

/* Home row mods logic end */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        tap_timer = timer_read_fast();

        switch (keycode) {
            case TH_CLNS:
                return process_tap_hold(Z_CLNS, record);
            case TH_UM_ACOMM:
                return process_tap_hold(US_ARNG, record); // å
            case TH_UM_AECOMM:
                return process_tap_hold(US_ADIA, record); // ä
            case TH_UM_OCOMM:
                return process_tap_hold(US_ODIA, record); // ö
                                                          // case TH_M:
                                                          //     return process_tap_hold(Z_PST, record);
        }
    }
    return true;
}

// Process custom hold keycode
static inline bool process_tap_hold(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count == 0) {
        tap_code16(keycode);
        return false;
    }
    return true;
}

// Custom tapping terms
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
// switch (keycode) {
//     case OSM(MOD_LSFT):
//         return TAPPING_TERM + 150;
//     default:
//         return TAPPING_TERM;
// }
// }
