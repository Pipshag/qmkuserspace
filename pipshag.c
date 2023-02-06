/*
 * Functions and code
 */
#include QMK_KEYBOARD_H

#ifdef AUTO_SHIFT_ENABLED
// Retro shift requirement
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    if (IS_RETRO(keycode)) {
        return true;
    }
    return false;
}
#endif
