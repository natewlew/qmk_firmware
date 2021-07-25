/* Copyright 2020 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "natewlew.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        CTR_GUI_COMBO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT  , \
        KC_LCTL, KC_LALT, KC_LGUI, ADJUST,  LOWER,   L_SP, KC_SPC,  KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
        ),

    [_LOWER] = LAYOUT( \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
        KC_ESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,                   _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
        KC_LALT, _______, _______, _______, SCREENSHOT_SELECTION, _______, KC_LPRN, KC_RPRN, _______, KC_QUOT, KC_DQUO, KC_DOT,  _______,  _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END \
        ),

    [_LOWER_SPACE] = LAYOUT( \
        _______, _______, _______, _______, _______, _______,                   _______, _______,_______, _______, _______, _______, \
        _______, _______, ALT_SHIFT_TAB, ALT_TAB, ALT_SHIFT_GRV, ALT_GRV,       _______, _______, _______, _______, _______, _______, \
        OPPOSITE_CTR_GUI_COMBO, C_SELECT_ALL, C_SAVE, C_LOG_OUT, C_CTR_FIND,  C_CTR,           _______, _______, _______, _______, _______, _______, \
        C_CTR_REDO, C_CTR_UNDO, C_CTR_CUT, C_CTR_COPY, C_CTR_PASTE, C_CTR_P_TEXT, _______, _______,_______, _______, _______, _______, C_CTR_FORWARD_SLASH, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
        ),

    [_RAISE] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
        KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,                   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
        KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,   _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC__VOLDOWN, KC__VOLUP, KC_MPLY \
        ),

    [_ADJUST] =  LAYOUT( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
        _______, RESET,   _______,  _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL, \
        _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, _______,  _______, _______,  _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
        )
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}
