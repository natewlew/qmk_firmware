#include "zeta.h"
#include QMK_KEYBOARD_H

bool is_ag_swapped(void); /* function prototype for add */
void handle_swapped_send(const char *str);

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers
{
	_QWERTY,
	_LOWER,
    _LOWER_SPACE,
	_RAISE,
	_ADJUST
};

enum custom_keycodes
{
    QWERTY = SAFE_RANGE,
    LOWER,
    LOWER_SPACE,
    RAISE,
    ADJUST,
    // Custom Keycodes for moding mac/linux ctrl functions
    C_CTR_UNDO,
    C_CTR_CUT,
    C_CTR_COPY,
    C_CTR_PASTE,
    C_CTR_FIND,
    ALT_TAB
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

#define LOWER_SPACE LT(LOWER_SPACE, KC_SPC)
#define ALT_TILD LGUI(KC_TILD)

// Handle whether or not we are using alt+tab.
bool tabbing = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
    KC_LCTL, KC_LALT, KC_LGUI, ADJUST,  LOWER,   LOWER_SPACE,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),


[_LOWER] = LAYOUT_ortho_4x12( \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    KC_CAPS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,  _______,  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

[_LOWER_SPACE] = LAYOUT_ortho_4x12( \
    ALT_TAB, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
    ALT_TILD, _______, _______, _______, C_CTR_FIND,  _______, _______, _______, _______, _______, _______, _______, \
    _______, C_CTR_UNDO, C_CTR_CUT, C_CTR_COPY, C_CTR_PASTE, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_RAISE] = LAYOUT_ortho_4x12( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),


[_ADJUST] =  LAYOUT_ortho_4x12( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    LGUI(KC_TILD), RESET, _______,   AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______,  KC_DEL, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

// Check if AG_SWAP is enabled. NOTE: default is mac.
bool is_ag_swapped() {
    if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
        return true;
    }
    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
            break;

        case LOWER_SPACE:
            if (record->event.pressed) {
                layer_on(_LOWER_SPACE);
            } else {
                if (tabbing == true) {
                    // We are finished with our alt+tab combo.
                    // Release Alt/Gui
                    tabbing = false;
                    SEND_STRING(SS_UP(X_LGUI));
                }
                layer_off(_LOWER_SPACE);
            }
            return false;
            break;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
            break;

        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;

        case C_CTR_UNDO:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    SEND_STRING(SS_LCTL("z"));
                } else {
                    SEND_STRING(SS_LGUI("z"));
                }
            }
            break;

        case C_CTR_CUT:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    SEND_STRING(SS_LCTL("x"));
                } else {
                    SEND_STRING(SS_LGUI("x"));
                }
            }
            break;

        case C_CTR_COPY:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    SEND_STRING(SS_LCTL("c"));
                } else {
                    SEND_STRING(SS_LGUI("c"));
                }
            }
            break;

        case C_CTR_PASTE:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    SEND_STRING(SS_LCTL("v"));
                } else {
                    SEND_STRING(SS_LGUI("v"));
                }
            }
            break;

        case C_CTR_FIND:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    SEND_STRING(SS_LCTL("f"));
                } else {
                    SEND_STRING(SS_LGUI("f"));
                }
            }
            break;

        case ALT_TAB:
            // Custom Function for Alt+Tab
            if (record->event.pressed) {
                if (tabbing == false) {
                    // We just started so press alt/gui.
                    tabbing = true;
                    SEND_STRING(SS_DOWN(X_LGUI));
                }
                SEND_STRING(SS_TAP(X_TAB));
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
	return;
};
