#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_EDG_I,            //LED Edge Brightness Increase
    L_EDG_D,            //LED Edge Brightness Decrease
    L_EDG_M,            //LED Edge lighting mode
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_RATIOD,
    L_RATIOI,
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction and effect
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    DBG_FAC,            //DEBUG Factory light testing (All on white)
    MD_BOOT             //Restart into bootloader after hold timeout
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

// ========== MAKA ==============

// Tap Dance keycodes
enum td_keycodes {
    SHIFT_LP, //`SHIFT` when held, `(` when tapped
    SHIFT_RP,
    ALT_LCB, //'ALT' | '{'
    ALT_RCB,
    CTRL_LAB, // 'CTRL' | '<'
    CTRL_RAB,
    CLN,
    QUOT,
    EXLM_1,
    AT_2,
    HASH_3,
    DLR_4,
    PERC_5,
    CIRC_6,
    AMPR_7,
    ASTR_8,
    MIN_UND,
    EQ_PLS,
    QST_SLSH
};

// Define a type containing as many tapdance states as you need
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// ===========END================

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,         KC_F1,      KC_F2,        KC_F3,        KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,        KC_F10,       KC_F11,      KC_F12,                KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,         TD(EXLM_1), TD(AT_2),     TD(HASH_3),   TD(DLR_4),  TD(PERC_5), TD(CIRC_6), TD(AMPR_7), TD(ASTR_8), KC_9,         KC_0,         TD(MIN_UND), TD(EQ_PLS), KC_BSPC,   KC_INS,  KC_PGUP, KC_HOME, \
        KC_TAB,         KC_Q,       KC_W,         KC_E,         KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,         KC_P,         KC_LBRC,     KC_RBRC,    KC_BSLS,   KC_DEL,  KC_PGDN, KC_END , \
        KC_CAPS,        KC_A,       KC_S,         KC_D,         KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,         TD(CLN),      TD(QUOT),    KC_ENT,                                        \
        TD(SHIFT_LP),   KC_Z,       KC_X,         KC_C,         KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,       TD(QST_SLSH), TD(SHIFT_RP),                                 KC_UP,            \
        TD(CTRL_LAB),   KC_LGUI,    TD(ALT_LCB),                                       KC_SPC,                              TD(ALT_RCB),  MO(1),        KC_APP,      TD(CTRL_RAB),           KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   L_EDG_I, _______, _______, _______, U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   L_EDG_D, _______, _______, _______, _______, _______, _______, _______, _______,                                       \
        _______, L_T_MD,  _______, _______, L_EDG_M, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,                              _______,          \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                       \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______,          \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______  \
    ),
    */
};


// ================MAKA==============

// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }

    if (state->count == 2) return DOUBLE_SINGLE_TAP;

    else return 8; // Any number higher than the maximum state value you return above
}

uint8_t cur_dance_wo_interupt(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        // if (state->interrupted || !state->pressed) return SINGLE_TAP;
        if (!state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }

    if (state->count == 2) return DOUBLE_SINGLE_TAP;

    else return 8; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

// td for shift

void shiftlp_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance_wo_interupt(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSHIFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LPRN);
            register_code16(KC_LPRN);
    }
}

void shiftlp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSHIFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LPRN);
    }
}

void shiftrp_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance_wo_interupt(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_RPRN);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RSHIFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_RPRN);
            register_code16(KC_RPRN);
    }
}

void shiftrp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_RPRN);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RSHIFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RPRN);
    }
}

// td for alt

void altlcb_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance_wo_interupt(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_LCBR);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LCBR);
            register_code16(KC_LCBR);
    }
}

void altlcb_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_LCBR);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LCBR);
    }
}

void altrcb_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance_wo_interupt(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_RCBR);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_RCBR);
            register_code16(KC_RCBR);
    }
}

void altrcb_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_RCBR);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RCBR);
    }
}

// td for ctrl

void ctrllab_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance_wo_interupt(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_LABK);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTRL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LABK);
            register_code16(KC_LABK);
    }
}

void ctrllab_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_LABK);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTRL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LABK);
    }
}

void ctrlrab_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance_wo_interupt(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_RABK);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RCTRL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_RABK);
            register_code16(KC_RABK);
    }
}

void ctrlrab_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_RABK);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RCTRL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RABK);
    }
}

void colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_SCLN);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 colons `::` within tapping term
            register_code16(KC_COLN);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(KC_COLN);
            register_code16(KC_COLN);
            break;
    }
}

void colon_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_SCLN);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_COLN);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_COLN);
            break;
    }
}

void quote_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_QUOT);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(KC_DQT);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(KC_DQT);
            register_code16(KC_DQT);
            break;
    }
}

void quote_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_QUOT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_DQT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_DQT);
            break;
    }
}

void exlm_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    uint16_t alt_kc = KC_EXLM;
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_1);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(alt_kc);
            register_code16(alt_kc);
            break;
    }
}

void exlm_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_EXLM;
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_1);
            break;
        case SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(alt_kc);
            break;
    }
}

void at_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    uint16_t alt_kc = KC_AT;
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_2);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(alt_kc);
            register_code16(alt_kc);
            break;
    }
}

void at_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_AT;
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_2);
            break;
        case SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(alt_kc);
            break;
    }
}

void hash_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    uint16_t alt_kc = KC_HASH;
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_3);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(alt_kc);
            register_code16(alt_kc);
            break;
    }
}

void hash_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_HASH;
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_3);
            break;
        case SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(alt_kc);
            break;
    }
}

void dlr_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    uint16_t alt_kc = KC_DLR;
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_4);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(alt_kc);
            register_code16(alt_kc);
            break;
    }
}

void dlr_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_DLR;
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_4);
            break;
        case SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(alt_kc);
            break;
    }
}

void perc_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    uint16_t alt_kc = KC_PERC;
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_5);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(alt_kc);
            register_code16(alt_kc);
            break;
    }
}

void perc_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_PERC;
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_5);
            break;
        case SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(alt_kc);
            break;
    }
}

void circ_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    uint16_t alt_kc = KC_CIRC;
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_6);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(alt_kc);
            register_code16(alt_kc);
            break;
    }
}

void circ_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_CIRC;
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_6);
            break;
        case SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(alt_kc);
            break;
    }
}

void ampr_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    uint16_t alt_kc = KC_AMPR;
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_7);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(alt_kc);
            register_code16(alt_kc);
            break;
    }
}

void ampr_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_AMPR;
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_7);
            break;
        case SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(alt_kc);
            break;
    }
}

void astr_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    uint16_t alt_kc = KC_ASTR;
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_8);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(alt_kc);
            register_code16(alt_kc);
            break;
    }
}

void astr_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_ASTR;
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_8);
            break;
        case SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(alt_kc);
            break;
    }
}

void unds_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_MINS);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(KC_UNDS);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(KC_MINS);
            register_code16(KC_MINS);
            break;
    }
}

void unds_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_MINS);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_UNDS);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_MINS);
            break;
    }
}

void plus_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_EQL);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(KC_PLUS);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(KC_EQL);
            register_code16(KC_EQL);
            break;
    }
}

void plus_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_EQL);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_PLUS);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_EQL);
            break;
    }
}

void qst_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_SLSH);
            break;
        case SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(KC_QUES);
            break;
        case DOUBLE_SINGLE_TAP: 
            tap_code16(KC_SLSH);
            register_code16(KC_SLSH);
            break;
    }
}

void qst_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_SLSH);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_QUES);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_SLSH);
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [SHIFT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shiftlp_finished, shiftlp_reset),
    [SHIFT_RP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shiftrp_finished, shiftrp_reset),
    [ALT_LCB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlcb_finished, altlcb_reset),
    [ALT_RCB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altrcb_finished, altrcb_reset),
    [CTRL_LAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrllab_finished, ctrllab_reset),
    [CTRL_RAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrlrab_finished, ctrlrab_reset),
    [CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, colon_finished, colon_reset),
    [QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quote_finished, quote_reset),
    [EXLM_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, exlm_finished, exlm_reset),
    [AT_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, at_finished, at_reset),
    [HASH_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, hash_finished, hash_reset),
    [DLR_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dlr_finished, dlr_reset),
    [PERC_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, perc_finished, perc_reset),
    [CIRC_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, circ_finished, circ_reset),
    [AMPR_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ampr_finished, ampr_reset),
    [ASTR_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, astr_finished, astr_reset),
    [MIN_UND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, unds_finished, unds_reset),
    [EQ_PLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, plus_finished, plus_reset),
    [QST_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, qst_finished, qst_reset),
};

//=================END===============


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    static uint8_t scroll_effect = 0;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_EDG_M:
            if (record->event.pressed) {
                led_edge_mode++;
                if (led_edge_mode > LED_EDGE_MODE_MAX) {
                    led_edge_mode = LED_EDGE_MODE_ALL;
                }
            }
            return false;
        case L_EDG_I:
            if (record->event.pressed) {
                led_edge_brightness += 0.1;
                if (led_edge_brightness > 1) { led_edge_brightness = 1; }
            }
            return false;
        case L_EDG_D:
            if (record->event.pressed) {
                led_edge_brightness -= 0.1;
                if (led_edge_brightness < 0) { led_edge_brightness = 0; }
            }
            return false;
        case L_RATIOI:
            if (record->event.pressed) {
                led_ratio_brightness += 0.2;
                if (led_ratio_brightness > 2.0) { led_ratio_brightness = 2.0; }
            }
            return false;
        case L_RATIOD:
            if (record->event.pressed) {
                led_ratio_brightness -= 0.2;
                if (led_ratio_brightness < 0.0) { led_ratio_brightness = 0.0; }
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                I2C3733_Control_Set(!I2C3733_Control_Get());
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                I2C3733_Control_Set(1);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                I2C3733_Control_Set(0);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                scroll_effect++;
                if (scroll_effect == 1) {               //Patterns with scroll move horizontal (Right to left)
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                } else if (scroll_effect == 2) {        //Patterns with scroll move vertical (Top to bottom)
                    led_animation_direction = 1;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 3) {        //Patterns with scroll move vertical (Bottom to top)
                    led_animation_direction = 0;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 4) {        //Patterns with scroll explode from center
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else if (scroll_effect == 5) {        //Patterns with scroll implode on center
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else {                                //Patterns with scroll move horizontal (Left to right)
                    scroll_effect = 0;
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                }
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_FAC:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                led_lighting_mode = LED_MODE_NORMAL;
                led_edge_brightness = 1;
                led_edge_mode = LED_EDGE_MODE_ALL;
                led_animation_breathing = 0;
                led_animation_id = 7; //led_programs.c led_setups leds_white index
                gcr_desired = LED_GCR_MAX;
                I2C3733_Control_Set(1);
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions[] = {
    //LEDs are normally inactive, no processing is performed on them
    //Flags are used in matching criteria for an LED to be active and indicate how to color it
    //Flags can be found in tmk_core/protocol/arm_atsam/led_matrix.h (prefixed with LED_FLAG_)
    //LED IDs can be found in config_led.h in the keyboard's directory
    //Examples are below

    //All LEDs use the user's selected pattern (this is the factory default)
     { .flags = LED_FLAG_USE_ROTATE_PATTERN },

    //Specific LEDs use the user's selected pattern while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 0xFFFFFFFF, .id1 = 0xAAAAAAAA, .id2 = 0x55555555, .id3 = 0x11111111 },

    //Specific LEDs use specified RGB values while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFF, .id1 = 0x00FF, .id2 = 0x0000FF00, .id3 = 0xFF000000, .r = 75, .g = 150, .b = 225 },

    //All LEDs use the user's selected pattern
    //On layer 1, all key LEDs (except the top row which keeps active pattern) are red while all edge LEDs are green
    //When layer 1 is active, key LEDs use red    (id0  32 -  17: 1111 1111 1111 1111 0000 0000 0000 0000 = 0xFFFF0000) (except top row 16 - 1)
    //When layer 1 is active, key LEDs use red    (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //When layer 1 is active, key LEDs use red    (id2  87 -  65: 0000 0000 0111 1111 1111 1111 1111 1111 = 0x007FFFFF)
    //When layer 1 is active, edge LEDs use green (id2  95 -  88: 1111 1111 1000 0000 0000 0000 0000 0000 = 0xFF800000)
    //When layer 1 is active, edge LEDs use green (id3 119 -  96: 0000 0000 1111 1111 1111 1111 1111 1111 = 0x00FFFFFF)
    // { .flags = LED_FLAG_USE_ROTATE_PATTERN },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0xFFFF0000, .id1 = 0xFFFFFFFF, .id2 = 0x007FFFFF, .r = 255, .layer = 1 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id2 = 0xFF800000, .id3 = 0x00FFFFFF, .g = 127, .layer = 1 },

    //All key LEDs use red while edge LEDs use the active pattern
    //All key LEDs use red     (id0  32 -   1: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id2  87 -  65: 0000 0000 0111 1111 1111 1111 1111 1111 = 0x007FFFFF)
    //Edge uses active pattern (id2  95 -  88: 1111 1111 1000 0000 0000 0000 0000 0000 = 0xFF800000)
    //Edge uses active pattern (id3 119 -  96: 0000 0000 1111 1111 1111 1111 1111 1111 = 0x00FFFFFF)
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFFFFFFFF, .id1 = 0xFFFFFFFF, .id2 = 0x007FFFFF, .r = 255 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN , .id2 = 0xFF800000, .id3 = 0x00FFFFFF },

    //end must be set to 1 to indicate end of instruction set
     { .end = 1 }
};
