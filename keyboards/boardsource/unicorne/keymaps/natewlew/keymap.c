/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include "natewlew.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LGUI, KC_A, ALT_T(KC_S), GUI_T(KC_D), CTL_T(KC_F), KC_G,   KC_H, CTL_T(KC_J), GUI_T(KC_K), ALT_T(KC_L), KC_SCLN,  KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  ADJUST,    LOWER,    L_SP,       KC_SPC,  RAISE, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX,     XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
    XXXXXXX, KC_BSPC, KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, KC_QUOT, KC_DQUO, KC_DOT, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

 [_LOWER_SPACE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
  XXXXXXX, XXXXXXX, ALT_SHIFT_TAB, ALT_TAB, ALT_SHIFT_GRV, ALT_GRV,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  OPPOSITE_CTR_GUI_COMBO, C_SELECT_ALL, C_SAVE, C_LOG_OUT, C_CTR_FIND,  C_CTR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  C_CTR_REDO, C_CTR_UNDO, C_CTR_CUT, C_CTR_COPY, C_CTR_PASTE, C_CTR_P_TEXT,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C_CTR_FORWARD_SLASH, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,     XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, XXXXXXX,    _______, XXXXXXX, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
     [_ADJUST] = LAYOUT(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   UG_TOGG, UG_NEXT, UG_HUEU,  UG_SATU, UG_VALU, UG_SPDU,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         EE_CLR, XXXXXXX, AG_NORM, AG_SWAP,  XXXXXXX, XXXXXXX,   KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    _______, _______, XXXXXXX,    _______, XXXXXXX, _______
    //                            ╰───────────────────────────╯ ╰──────────────────╯
    ),
};
// clang-format on
