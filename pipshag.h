#pragma once
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

#ifdef RGB_MATRIX_ENABLE
// Suspend rgb on suspend
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
}
// Wake rgb on wake
void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
}
#endif