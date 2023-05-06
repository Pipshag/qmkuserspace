/*
 * Functions and code
 */
#include QMK_KEYBOARD_H

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
/* bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) { */
/*     if (IS_RETRO(keycode)) return true; */
/*     switch (keycode) { */
/*         case RALT(KC_Q): */
/*             return true; */
/*         case RALT(KC_W): */
/*             return true; */
/*         case RALT(KC_P): */
/*             return true; */
/*         default: */
/*             return false; */
/*     } */
/* } */
/**/
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
