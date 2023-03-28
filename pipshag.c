/*
 * Functions and code
 */
#include QMK_KEYBOARD_H

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    if (IS_RETRO(keycode)) return true;
    switch (keycode) {
        case RALT(KC_Q):
            return true;
        case RALT(KC_W):
            return true;
        case RALT(KC_P):
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case RALT(KC_Q):
            register_code16((!shifted) ? RALT(KC_Q) : RSFT(RALT(KC_Q)));
            break;
        case RALT(KC_P):
            register_code16((!shifted) ? RALT(KC_P) : RSFT(RALT(KC_P)));
            break;
        case RALT(KC_W):
            register_code16((!shifted) ? RALT(KC_W) : RSFT(RALT(KC_W)));
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case RALT(KC_Q):
            unregister_code16((!shifted) ? RALT(KC_Q) : RSFT(RALT(KC_Q)));
            break;
        case RALT(KC_P):
            unregister_code16((!shifted) ? RALT(KC_P) : RSFT(RALT(KC_P)));
            break;
        case RALT(KC_W):
            unregister_code16((!shifted) ? RALT(KC_W) : RSFT(RALT(KC_W)));
            break;
        default:
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
