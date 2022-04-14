#include QMK_KEYBOARD_H
#include "natewlew.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_all(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   CTR_GUI_COMBO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_ESC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_CAPS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
   KC_LCTL, KC_LALT, KC_LGUI, ADJUST, LOWER,    L_SP,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_COLEMAK] = LAYOUT_all(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   _______,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   _______,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, _______,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_DVORAK] = LAYOUT_all(
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,             KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   _______,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   _______,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, _______,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_all(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_ESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,  _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  KC_LALT, _______, _______, _______, _______, SCREENSHOT_SELECTION, _______, _______, KC_QUOT, KC_DQUO, KC_DOT,  _______,  KC_ENT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END \
),

[_LOWER_SPACE] = LAYOUT_all( \
    _______, _______, ALT_SHIFT_TAB, ALT_TAB, ALT_SHIFT_GRV, ALT_GRV, _______, _______, _______, _______, _______, _______, \
    OPPOSITE_CTR_GUI_COMBO, C_SELECT_ALL, C_SAVE, C_LOG_OUT, C_CTR_FIND,  C_CTR, _______,_______, _______, _______, _______, _______, KC_ENT, \
    C_CTR_REDO, C_CTR_UNDO, C_CTR_CUT, C_CTR_COPY, C_CTR_PASTE, C_CTR_P_TEXT,  _______,_______, _______, _______, _______, C_CTR_FORWARD_SLASH, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_RAISE] = LAYOUT_all(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,   _______, KC_ENT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC__VOLDOWN, KC__VOLUP, KC_MPLY \
),

[_ADJUST] =  LAYOUT_all(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET, _______, AU_ON,   AU_OFF,  AG_NORM, _______, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD
)
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
             }
             break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            break;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){
        case _QWERTY:
            // Volume
            if (clockwise){
                tap_code16(KC_VOLD);
            } else {
                tap_code16(KC_VOLU);
            }
            break;
        case _LOWER:
            // Mouse Scroll
            if (clockwise){
                tap_code16(KC_MS_WH_DOWN);
            } else {
                tap_code16(KC_MS_WH_UP);
            }
            break;
        case _LOWER_SPACE:
            // Cycle Screen (single app)
            if (clockwise){
                register_code(KC_LGUI);
                tap_code16(KC_GRV);
                unregister_code(KC_LGUI);
            } else {
                register_code(KC_LGUI);
                tap_code16(S(KC_GRV));
                unregister_code(KC_LGUI);
            }
            break;
        case _RAISE:
            if (clockwise){
                // Undo
                send_control_key(KC_Z);
            } else {
                // Redo
                register_code(KC_LSFT);
                send_control_key(KC_Z);
                unregister_code(KC_LSFT);
            }
            break;
    }
    return true;
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Rebound Rev4\n"), false);
            oled_write_P(PSTR("   ///\\\\\\\n"), false);
            oled_write_P(PSTR("  ///  \\\\\\\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Layer: Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Layer: Raise\n"), false);
            break;
        case _LOWER_SPACE:
            oled_write_P(PSTR("Layer: Lower Space\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Layer: Adjust\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Layer: Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
