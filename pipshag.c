/*
 * Functions and code
 */
#include "pipshag.h"
#include "oneshot/oneshot.h"

#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

enum custom_keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    CDE_BLCK, // markdown code block
};

// clang-format off
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO, KC_NO, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_NO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_LGUI, LT(1,KC_SPC), OSM_LSFT, KC_ENT, LT(2,KC_BSPC), LT(3,KC_ESC)),

[_LAYER1] = LAYOUT(KC_NO, KC_STAB, KC_TAB, PREV_TAB, NEXT_TAB, SCRNSHT, KC_PGUP, KC_H, KC_J, KC_K, KC_L, KC_NO, KC_NO, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT, KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, RCS(KC_V), KC_HOME, RALT(KC_P), RALT(KC_Q), RALT(KC_W), KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_BSPC, KC_ESC),

[_LAYER2] = LAYOUT(KC_NO, QK_BOOT, KC_7, KC_8, KC_9, KC_VOLU, KC_MNXT, KC_NO, RGB_SAI, RGB_SPI, RGB_MOD, KC_NO, KC_NO, OSL(4), KC_4, KC_5, KC_6, KC_VOLD, KC_MPLY, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, KC_NO, KC_NO, AS_TOGG, KC_1, KC_2, KC_3, KC_DOT, KC_MPRV, CW_TOGG, RGB_HUI, RGB_VAI, RGB_TOG, KC_NO, KC_EQL, KC_0, KC_MINS, KC_NO, KC_NO, KC_NO),

[_LAYER3] = LAYOUT(KC_NO, KC_PERC, KC_CIRC, KC_DLR, KC_EUR, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_AT, KC_HASH, KC_NO, KC_NO, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_BSLS, KC_NO, KC_LPRN, KC_RPRN, KC_LT, KC_GT, KC_NO, KC_NO, KC_BSLS, KC_7, KC_EXLM, KC_EQL, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_TILD, KC_GRV, KC_NO, KC_ESC, KC_SPC, KC_TAB, KC_NO, KC_NO, KC_NO),

[_LAYER4] = LAYOUT(KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)

};
// clang-format on

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LT(1, KC_SPC):
        case LT(2, KC_BSPC):
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LT(1, KC_SPC):
        case LT(2, KC_BSPC):
        case OSM_LSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    if (keycode == CDE_BLCK && record->event.pressed) {
        tap_code(KC_GRV);
        tap_code(KC_GRV);
        tap_code(KC_GRV);
        register_code(KC_LSFT);
        tap_code(KC_ENTER);
        tap_code(KC_ENTER);
        unregister_code(KC_LSFT);
        tap_code(KC_GRV);
        tap_code(KC_GRV);
        tap_code(KC_GRV);
        tap_code(KC_UP);
    }

    return true;
}

// rgb functions for layers
void set_underglow(void) {
    // right underglow
    for (uint8_t i = 0; i < 6; i++) {
        rgb_matrix_set_color(i, 107, 29, 71);
    }
    // left underglow
    for (uint8_t i = 27; i < 33; i++) {
        rgb_matrix_set_color(i, 32, 80, 92);
    }
}

void set_base_colors(void) {
    set_underglow();
    // right
    for (uint8_t i = 6; i < 26; i++) {
        rgb_matrix_set_color(i, 18, 5, 12);
    }
    // left
    for (uint8_t i = 33; i < 54; i++) {
        rgb_matrix_set_color(i, 3, 7, 8);
    }
    // accents
    /* rgb_matrix_set_color(36, 80, 80, 80); */
}

void set_nav_colors(void) {
    // accents
    rgb_matrix_set_color(7, 74, 20, 49);
    rgb_matrix_set_color(37, 18, 5, 12);
    rgb_matrix_set_color(38, 18, 5, 12);
    rgb_matrix_set_color(39, 18, 5, 12);
    rgb_matrix_set_color(40, 18, 5, 12);

    /* rgb_matrix_set_color(42, 18, 5, 12); */
    /* rgb_matrix_set_color(43, 18, 5, 12); */
    /* rgb_matrix_set_color(44, 18, 5, 12); */
    /* rgb_matrix_set_color(45, 18, 5, 12); */
}
void set_numbers_colors(void) {
    // accent
    rgb_matrix_set_color(34, 37, 96, 112);

    rgb_matrix_set_color(6, 14, 33, 38);
    rgb_matrix_set_color(7, 14, 33, 38);
    rgb_matrix_set_color(8, 14, 33, 38);

    rgb_matrix_set_color(10, 14, 33, 38);
    rgb_matrix_set_color(11, 14, 33, 38);
    rgb_matrix_set_color(12, 14, 33, 38);
    rgb_matrix_set_color(15, 14, 33, 38);
    rgb_matrix_set_color(16, 14, 33, 38);
    rgb_matrix_set_color(17, 14, 33, 38);
    rgb_matrix_set_color(20, 14, 33, 38);
    rgb_matrix_set_color(21, 14, 33, 38);
    rgb_matrix_set_color(22, 14, 33, 38);
}

bool rgb_matrix_indicators_user(void) {
#ifdef RGB_MATRIX_ENABLE
    /* RGB_MATRIX_USE_LIMITS(led_min, led_max); */
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 1:
            set_underglow();
            set_base_colors();

            set_nav_colors();
            break;
        case 2:
            set_underglow();
            set_base_colors();
            set_numbers_colors();
            break;
        case 3:
            set_underglow();
            set_base_colors();
            // accent
            rgb_matrix_set_color(33, 37, 96, 112);
            break;
        default:
            set_underglow();
            set_base_colors();
            break;
    }
#endif
    return true;
}

/* void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case RALT(KC_Q): */
/*             register_code16((!shifted) ? RALT(KC_Q) : RSFT(RALT(KC_Q))); */
/*             break; */
/*         case RALT(KC_P): */
/*             register_code16((!shifted) ? RALT(KC_P) : RSFT(RALT(KC_P))); */
/*             break; */
/*         case RALT(KC_W): */
/*             register_code16((!shifted) ? RALT(KC_W) : RSFT(RALT(KC_W))); */
/*             break; */
/*         default: */
/*             if (shifted) { */
/*                 add_weak_mods(MOD_BIT(KC_LSFT)); */
/*             } */
/*             register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode); */
/*     } */
/* } */
/**/
/* void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case RALT(KC_Q): */
/*             unregister_code16((!shifted) ? RALT(KC_Q) : RSFT(RALT(KC_Q))); */
/*             break; */
/*         case RALT(KC_P): */
/*             unregister_code16((!shifted) ? RALT(KC_P) : RSFT(RALT(KC_P))); */
/*             break; */
/*         case RALT(KC_W): */
/*             unregister_code16((!shifted) ? RALT(KC_W) : RSFT(RALT(KC_W))); */
/*             break; */
/*         default: */
/*             unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode); */
/*     } */
/* } */
