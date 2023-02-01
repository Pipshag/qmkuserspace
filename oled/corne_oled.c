/*
 * Render OLED screens
 */
#include QMK_KEYBOARD_H

// Helpers
static void render_space(void) {
    oled_write_ln_P(PSTR(""), false);
}
static void render_secondary_text(void) {
    oled_write_P(PSTR("corne"), false);
    oled_write_P(PSTR("+pips"), false);
}
// Layers
static void render_current_layer(void) {
    // Write heading
    oled_write_P(PSTR("  LAY"), false);

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            oled_write_P(PSTR("**NRM"), false);
            break;
        case 1:
            oled_write_P(PSTR("**NAV"), false);
            break;
        case 2:
            oled_write_P(PSTR("**NUM"), false);
            break;
        case 3:
            oled_write_P(PSTR("**SYM"), false);
            break;
        case 4:
            oled_write_P(PSTR("**FUN"), false);
            break;
        case 5:
            oled_write_P(PSTR("**MSE"), false);
            break;
        case 6:
            oled_write_P(PSTR("**MED"), false);
            break;
        default:
            oled_write_P(PSTR("**000"), false);
            break;
    }
}

// Mods
void render_modifiers(void) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();
    // Write heading
    oled_write_P(PSTR("  MOD"), false);

    (is_caps_word_on()) ? oled_write_P(PSTR("W"), false) : oled_write_P(PSTR("*"), false);
    (modifiers & MOD_MASK_GUI) ? oled_write_P(PSTR("G"), false) : oled_write_P(PSTR("*"), false);
    (modifiers & MOD_MASK_ALT) ? oled_write_P(PSTR("A"), false) : oled_write_P(PSTR("*"), false);
    (modifiers & MOD_MASK_CTRL) ? oled_write_P(PSTR("C"), false) : oled_write_P(PSTR("*"), false);
    (modifiers & MOD_MASK_SHIFT) ? oled_write_P(PSTR("S"), false) : oled_write_P(PSTR("*"), false);
}

// Word per minute indicator
void render_wpm(void) {
    // Write heading
    oled_write_P(PSTR("  WPM"), false);
    oled_write_P(PSTR("**"), false);
    oled_write(get_u8_str(get_current_wpm(), '*'), false);
}

// Images
static void render_crkbd_logo(void) {
    static const char PROGMEM crkbd_logo[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(crkbd_logo, false);
}

void render_kapi(void) {
    static const char PROGMEM kapi[2][16] = {
        {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0},
        {0x85, 0x86, 0x87, 0x88, 0x89, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0},
    };
    oled_write_P(kapi[get_current_wpm() % 2], false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Render master layout
        render_current_layer();
        render_space();
        render_modifiers();
        render_space();
        render_wpm();
    } else {
        // Render secondary layout
        render_crkbd_logo();
        render_secondary_text();
        render_space();
        render_space();
        render_space();
        render_space();
        render_space();
        render_kapi();
    }
    return false;
}
