#include "rgb.h"

// Suspend rgb on suspend
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
}
// Wake rgb on wake
void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
}

// This code iterates over every row and column on a per-key RGB keyboard, searching for keys that have been configured (not KC_TRANS) and lighting the corresponding index location. It is set to activate on layers other than the default layer. This can be further customized by using a layer switch condition inside the last if statement.
bool rgb_matrix_indicators_user(void) {
    if (get_mods()) {
        uint8_t const mods = get_mods();
        // Scale hue to mod bits
        HSV const hsv = {(mods >> 4 | mods) * 48, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};
        RGB const rgb = hsv_to_rgb(hsv);
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
            // Mask left and right mods
            if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }
    if (is_caps_word_on()) {
        // Scale hue to caps word
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
            // Mask left and right mods
            if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                rgb_matrix_set_color(i, RGB_DPINK);
            }
        }
    }
    if (get_highest_layer(layer_state) > 0) {
        uint8_t const layer = get_highest_layer(layer_state);
        // Scale hue to layer number
        HSV const hsv = {layer * 48, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};
        RGB const rgb = hsv_to_rgb(hsv);
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t const  led = g_led_config.matrix_co[row][col];
                uint16_t const key = keymap_key_to_keycode(layer, (keypos_t){col, row});
                // Match only LEDs with configured keycodes
                if (led != NO_LED && key > KC_TRNS) {
                    rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
                }
            }
        }
    }
    return false;
}