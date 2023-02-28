/*
 * Functions and code
 */
#include QMK_KEYBOARD_H

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    if (IS_RETRO(keycode)) return true;
    switch (keycode) {
        default:
            return false;
    }
}
