#include "zeta.h"
#include QMK_KEYBOARD_H

bool is_ag_swapped(void);
void send_swapped_key(int keycode);
void start_tabbing(void);
void finish_tabbing(void);

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers
{
	QWERTY,
	LOWER,
    LOWER_SPACE,
	RAISE,
	ADJUST
};

enum custom_keycodes
{
    C_CTR_UNDO = SAFE_RANGE,
    C_CTR_REDO,
    C_CTR_CUT,
    C_CTR_COPY,
    C_CTR_PASTE,
    C_SELECT_ALL,
    C_SAVE,
    C_LOG_OUT,
    C_CTR_FIND,
    C_CTR_FORWARD_SLASH,
    C_CTR,
    ALT_TAB,
    ALT_SHIFT_TAB,
    SCREENSHOT_SELECTION
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

// Handle whether or not we are using alt+tab.
bool tabbing = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[QWERTY] = LAYOUT_ortho_4x12( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
    KC_LCTL, KC_LALT, KC_LGUI, MO(ADJUST),  MO(LOWER),   LT(LOWER_SPACE, KC_SPC),  KC_SPC,  MO(RAISE),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),


[LOWER] = LAYOUT_ortho_4x12( \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    KC_CAPS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, _______, _______, _______, SCREENSHOT_SELECTION, _______, _______, _______, _______, KC_DOT,  _______,  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

[LOWER_SPACE] = LAYOUT_ortho_4x12( \
    _______, _______, _______, ALT_SHIFT_TAB, ALT_TAB,  LGUI(KC_TILD), _______, _______, _______, _______, _______, _______, \
    _______, C_SELECT_ALL, C_SAVE, C_LOG_OUT, C_CTR_FIND,  C_CTR, _______, _______, _______, _______, _______, _______, \
    C_CTR_REDO, C_CTR_UNDO, C_CTR_CUT, C_CTR_COPY, C_CTR_PASTE, _______, _______, _______, _______, _______, C_CTR_FORWARD_SLASH, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[RAISE] = LAYOUT_ortho_4x12( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),


[ADJUST] =  LAYOUT_ortho_4x12( \
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

// Send control. Changes to gui if ag hasn't been swapped.
void send_control_key(uint8_t keycode) {
    if (is_ag_swapped()) {
        register_code(KC_LCTL);
        tap_code(keycode);
        unregister_code(KC_LCTL);
    } else {
        register_code(KC_LGUI);
        tap_code(keycode);
        unregister_code(KC_LGUI);
    }
}

void start_tabbing() {
    if (tabbing == false) {
        // We just started so press alt/gui.
        tabbing = true;
        if (is_ag_swapped()) {
            register_code(KC_LALT);
        } else {
            register_code(KC_LGUI);
        }
    }
}

void finish_tabbing() {
    if (tabbing == true) {
        // We are finished with our alt+tab combo.
        // Release Alt/Gui
        tabbing = false;
        if (is_ag_swapped()) {
            unregister_code(KC_LALT);
        } else {
            unregister_code(KC_LGUI);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case C_CTR:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    register_code(KC_LCTL);
                } else {
                    register_code(KC_LGUI);
                }
            } else {
                if (is_ag_swapped()) {
                    unregister_code(KC_LCTL);
                } else {
                    unregister_code(KC_LGUI);
                }
            }
            return false;

        case C_CTR_UNDO:
            if (record->event.pressed) {
                send_control_key(KC_Z);
            }
            return false;

        case C_CTR_REDO:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                send_control_key(KC_Z);
                unregister_code(KC_LSFT);
            }
            return false;

        case C_CTR_CUT:
            if (record->event.pressed) {
                send_control_key(KC_X);
            }
            return false;

        case C_CTR_COPY:
            if (record->event.pressed) {
                send_control_key(KC_C);
            }
            return false;

        case C_CTR_PASTE:
            if (record->event.pressed) {
                send_control_key(KC_V);
            }
            return false;

        case C_SELECT_ALL:
            if (record->event.pressed) {
                send_control_key(KC_A);
            }
            return false;

        case C_SAVE:
            if (record->event.pressed) {
                send_control_key(KC_S);
            }
            return false;

        case C_LOG_OUT:
            if (record->event.pressed) {
                send_control_key(KC_D);
            }
            return false;

        case C_CTR_FIND:
            if (record->event.pressed) {
                send_control_key(KC_F);
            }
            return false;

        case C_CTR_FORWARD_SLASH:
            if (record->event.pressed) {
                send_control_key(KC_SLASH);
            }
            return false;

        case ALT_TAB:
            // Custom Function for Alt+Tab
            if (record->event.pressed) {
                start_tabbing();
                tap_code(KC_TAB);
            }
            return false;

        case ALT_SHIFT_TAB:
            // Custom Function for Alt+Shift+Tab
            if (record->event.pressed) {
                start_tabbing();
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            return false;

        case SCREENSHOT_SELECTION:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    // Linux
                    register_code(KC_LSFT);
                    tap_code(KC_PSCR);
                    unregister_code(KC_LSFT);
                } else {
                    // Mac
                    register_code(KC_LSFT);
                    register_code(KC_LGUI);
                    tap_code(KC_4);
                    unregister_code(KC_LGUI);
                    unregister_code(KC_LSFT);
                }
            }
            return false;

        default:
            return true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case QWERTY:
            // When switching back to the default layer, check if we need to finish tabbing.
            finish_tabbing();
            break;
        default:
            break;
    }
  return state;
}

void matrix_scan_user(void) {
	return;
};
