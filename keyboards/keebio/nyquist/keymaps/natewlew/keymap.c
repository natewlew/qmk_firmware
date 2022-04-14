#include QMK_KEYBOARD_H
#include "natewlew.h"

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    CTR_GUI_COMBO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LALT, KC_LGUI, ADJUST,  LOWER, L_SP,  KC_SPC,  RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT \
),

[_LOWER] = LAYOUT_ortho_4x12( \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    KC_ESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    KC_LALT, _______, _______, _______, SCREENSHOT_SELECTION, _______, _______, KC_QUOT, KC_DQUO, KC_DOT,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END \
),

[_LOWER_SPACE] = LAYOUT_ortho_4x12( \
    _______, _______, ALT_SHIFT_TAB, ALT_TAB, ALT_SHIFT_GRV, ALT_GRV, _______, _______, _______, _______, _______, _______, \
    OPPOSITE_CTR_GUI_COMBO, C_SELECT_ALL, C_SAVE, C_LOG_OUT, C_CTR_FIND,  C_CTR, _______, _______, _______, _______, _______, _______, \
    C_CTR_REDO, C_CTR_UNDO, C_CTR_CUT, C_CTR_COPY, C_CTR_PASTE, C_CTR_P_TEXT, _______, _______, _______, _______, C_CTR_FORWARD_SLASH, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_RAISE] = LAYOUT_ortho_4x12( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_ADJUST] =  LAYOUT_ortho_4x12( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    _______, RESET  , _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______, _______, \
    _______, MUV_DE, MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
)

};
