#include "natewlew.h"

// Handle whether or not we are using alt+tab.
bool tabbing = false;

// Check if AG_SWAP is enabled. NOTE: default is mac.
bool is_ag_swapped() {
    return (keymap_config.swap_lalt_lgui || keymap_config.swap_ralt_rgui);
}

// Send control. Changes to gui if ag hasn't been swapped.
void send_control_key(uint8_t keycode) {
    if (is_ag_swapped()) {
        tap_code16(LCTL(keycode));
    } else {
        tap_code16(G(keycode));
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


//layer_state_t layer_state_set_user(layer_state_t state) {
//    switch (get_highest_layer(state)) {
//        case _QWERTY:
//            // When switching back to the default layer, check if we need to finish tabbing.
//            finish_tabbing();
//            break;
//        default:
//            break;
//    }
////    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
////    state = update_tri_layer_state(state, _LOWER, _RAISE, _LOWER_SPACE);
//    return state;
//}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
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

        case C_CTR_P_TEXT:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    // Linux
                    tap_code16(S(C(KC_V)));
                } else {
                    // Mac
                    tap_code16(S(A(G(KC_V))));
                }
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
                tap_code16(S(KC_TAB));
            }
            return false;

        case ALT_GRV:
            // Custom Function for Alt+`
            if (record->event.pressed) {
                start_tabbing();
                tap_code(KC_GRV);
            }
            return false;

        case ALT_SHIFT_GRV:
            // Custom Function for Alt+Shift+`
            if (record->event.pressed) {
                start_tabbing();
                tap_code16(S(KC_GRV));
            }
            return false;

        case SCREENSHOT_SELECTION:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    // Linux
                    tap_code16(S(KC_PSCR));
                } else {
                    // Mac
                    tap_code16(S(G(KC_4)));
                }
            }
            return false;

        case CTR_GUI_COMBO:
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

        case OPPOSITE_CTR_GUI_COMBO:
            if (record->event.pressed) {
                if (is_ag_swapped()) {
                    register_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                }
            } else {
                if (is_ag_swapped()) {
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_LCTL);
                }
            }
            return false;

        default:
            if (!record->event.pressed) {
                // Check if we are un-pressing a key and need to finish tabbing
                finish_tabbing();
            }
    }
    return process_record_keymap(keycode, record);
}
