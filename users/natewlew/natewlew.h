#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _LOWER_SPACE,
    _RAISE,
    _ADJUST
};

enum my_custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    C_CTR_UNDO,
    C_CTR_REDO,
    C_CTR_CUT,
    C_CTR_COPY,
    C_CTR_PASTE,
    C_CTR_P_TEXT,
    C_SELECT_ALL,
    C_SAVE,
    C_LOG_OUT,
    C_CTR_FIND,
    C_CTR_FORWARD_SLASH,
    C_CTR,
    ALT_TAB,
    ALT_SHIFT_TAB,
    ALT_GRV,
    ALT_SHIFT_GRV,
    SCREENSHOT_SELECTION,
    CTR_GUI_COMBO,
    OPPOSITE_CTR_GUI_COMBO,
    NEW_SAFE_RANGE
};

bool is_ag_swapped(void);
void send_swapped_key(int keycode);
void start_tabbing(void);
void finish_tabbing(void);
void send_control_key(uint8_t keycode);

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

extern keymap_config_t keymap_config;

#define LOWER     MO(_LOWER)
#define L_SP      LT(_LOWER_SPACE, KC_SPC)
#define RAISE     MO(_RAISE)
#define ADJUST    MO(_ADJUST)
