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
    T3_SINGLE_TAP,
    T3_SINGLE_HOLD,
    T3_DOUBLE_TAP
} td_state3_t;



// Determine the tapdance state to return
uint8_t cur_dance3(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return T3_SINGLE_TAP;
        else return T3_SINGLE_HOLD;
    }

    if (state->count == 2) return T3_DOUBLE_TAP;

    else return 8; // Any number higher than the maximum state value you return above
}


uint8_t cur_dance3_wo_interupt(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return T3_SINGLE_TAP;
        else return T3_SINGLE_HOLD;
    }

    if (state->count == 2) return T3_DOUBLE_TAP;

    else return 8; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

static td_state3_t shiftlp_state;
void shiftlp_finished(qk_tap_dance_state_t *state, void *user_data) {
    shiftlp_state = cur_dance3_wo_interupt(state);
    switch (shiftlp_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case T3_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSHIFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LPRN);
            register_code16(KC_LPRN);
    }
}

void shiftlp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (shiftlp_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case T3_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSHIFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_LPRN);
    }
}

static td_state3_t shiftrp_state;
void shiftrp_finished(qk_tap_dance_state_t *state, void *user_data) {
    shiftrp_state = cur_dance3_wo_interupt(state);
    switch (shiftrp_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_RPRN);
            break;
        case T3_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RSHIFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_RPRN);
            register_code16(KC_RPRN);
    }
}

void shiftrp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (shiftrp_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_RPRN);
            break;
        case T3_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RSHIFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_RPRN);
    }
}

// td for alt

static td_state3_t ltlcb_state;
void altlcb_finished(qk_tap_dance_state_t *state, void *user_data) {
    ltlcb_state = cur_dance3_wo_interupt(state);
    switch (ltlcb_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_LCBR);
            break;
        case T3_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LCBR);
            register_code16(KC_LCBR);
    }
}

void altlcb_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ltlcb_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_LCBR);
            break;
        case T3_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_LCBR);
    }
}

static td_state3_t altrcb_state;
void altrcb_finished(qk_tap_dance_state_t *state, void *user_data) {
    altrcb_state = cur_dance3_wo_interupt(state);
    switch (altrcb_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_RCBR);
            break;
        case T3_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_RCBR);
            register_code16(KC_RCBR);
    }
}

void altrcb_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (altrcb_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_RCBR);
            break;
        case T3_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_RCBR);
    }
}

// td for ctrl

static td_state3_t ctrllab_state;
void ctrllab_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctrllab_state = cur_dance3_wo_interupt(state);
    switch (ctrllab_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_LABK);
            break;
        case T3_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTRL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LABK);
            register_code16(KC_LABK);
    }
}

void ctrllab_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctrllab_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_LABK);
            break;
        case T3_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTRL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_LABK);
    }
}

static td_state3_t ctrlrab_state;
void ctrlrab_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctrlrab_state = cur_dance3_wo_interupt(state);
    switch (ctrlrab_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_RABK);
            break;
        case T3_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RCTRL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_RABK);
            register_code16(KC_RABK);
    }
}

void ctrlrab_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctrlrab_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_RABK);
            break;
        case T3_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RCTRL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_RABK);
    }
}

static td_state3_t colon_state;
void colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    colon_state = cur_dance3(state);
    switch (colon_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_SCLN);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 colons `::` within tapping term
            register_code16(KC_COLN);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_COLN);
            register_code16(KC_COLN);
            break;
    }
}

void colon_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (colon_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_SCLN);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(KC_COLN);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_COLN);
            break;
    }
}

static td_state3_t quote_state;
void quote_finished(qk_tap_dance_state_t *state, void *user_data) {
    quote_state = cur_dance3(state);
    switch (quote_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_QUOT);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(KC_DQT);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_DQT);
            register_code16(KC_DQT);
            break;
    }
}

void quote_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (quote_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_QUOT);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(KC_DQT);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_DQT);
            break;
    }
}

static td_state3_t exlm_state;
void exlm_finished(qk_tap_dance_state_t *state, void *user_data) {
    exlm_state = cur_dance3(state);
    uint16_t alt_kc = KC_EXLM;
    switch (exlm_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_1);
            break;
        case T3_SINGLE_HOLD:
            register_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_1);
            register_code16(KC_1);
            break;
    }
}

void exlm_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_EXLM;
    switch (exlm_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_1);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_1);
            break;
    }
}

static td_state3_t at_state;
void at_finished(qk_tap_dance_state_t *state, void *user_data) {
    at_state = cur_dance3(state);
    uint16_t alt_kc = KC_AT;
    switch (at_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_2);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_2);
            register_code16(KC_2);
            break;
    }
}

void at_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_AT;
    switch (at_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_2);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_2);
            break;
    }
}

static td_state3_t hash_state;
void hash_finished(qk_tap_dance_state_t *state, void *user_data) {
    hash_state = cur_dance3(state);
    uint16_t alt_kc = KC_HASH;
    switch (hash_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_3);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_3);
            register_code16(KC_3);
            break;
    }
}

void hash_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_HASH;
    switch (hash_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_3);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_3);
            break;
    }
}

static td_state3_t dlr_state;
void dlr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dlr_state = cur_dance3(state);
    uint16_t alt_kc = KC_DLR;
    switch (dlr_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_4);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_4);
            register_code16(KC_4);
            break;
    }
}

void dlr_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_DLR;
    switch (dlr_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_4);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_4);
            break;
    }
}

static td_state3_t perc_state;
void perc_finished(qk_tap_dance_state_t *state, void *user_data) {
    perc_state = cur_dance3(state);
    uint16_t alt_kc = KC_PERC;
    switch (perc_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_5);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_5);
            register_code16(KC_5);
            break;
    }
}

void perc_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_PERC;
    switch (perc_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_5);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_5);
            break;
    }
}

static td_state3_t circ_state;
void circ_finished(qk_tap_dance_state_t *state, void *user_data) {
    circ_state = cur_dance3(state);
    uint16_t alt_kc = KC_CIRC;
    switch (circ_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_6);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_6);
            register_code16(KC_6);
            break;
    }
}

void circ_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_CIRC;
    switch (circ_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_6);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_6);
            break;
    }
}

static td_state3_t ampr_state;
void ampr_finished(qk_tap_dance_state_t *state, void *user_data) {
    ampr_state = cur_dance3(state);
    uint16_t alt_kc = KC_AMPR;
    switch (ampr_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_7);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_7);
            register_code16(KC_7);
            break;
    }
}

void ampr_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_AMPR;
    switch (ampr_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_7);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_7);
            break;
    }
}

static td_state3_t astr_state;
void astr_finished(qk_tap_dance_state_t *state, void *user_data) {
    astr_state = cur_dance3(state);
    uint16_t alt_kc = KC_ASTR;
    switch (astr_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_8);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_8);
            register_code16(KC_8);
            break;
    }
}

void astr_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t alt_kc = KC_ASTR;
    switch (astr_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_8);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(alt_kc);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_8);
            break;
    }
}

static td_state3_t unds_state;
void unds_finished(qk_tap_dance_state_t *state, void *user_data) {
    unds_state = cur_dance3(state);
    switch (unds_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_MINS);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(KC_UNDS);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_MINS);
            register_code16(KC_MINS);
            break;
    }
}

void unds_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (unds_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_MINS);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(KC_UNDS);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_MINS);
            break;
    }
}

static td_state3_t plus_state;
void plus_finished(qk_tap_dance_state_t *state, void *user_data) {
    plus_state = cur_dance3(state);
    switch (plus_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_EQL);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(KC_PLUS);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_EQL);
            register_code16(KC_EQL);
            break;
    }
}

void plus_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (plus_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_EQL);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(KC_PLUS);
            break;
        case T3_DOUBLE_TAP:
            unregister_code16(KC_EQL);
            break;
    }
}

static td_state3_t qst_state;
void qst_finished(qk_tap_dance_state_t *state, void *user_data) {
    qst_state = cur_dance3(state);
    switch (qst_state) {
        case T3_SINGLE_TAP:
            register_code16(KC_SLSH);
            break;
        case T3_SINGLE_HOLD: // Allow nesting of 2 quotes `""` within tapping term
            register_code16(KC_QUES);
            break;
        case T3_DOUBLE_TAP: 
            tap_code16(KC_SLSH);
            register_code16(KC_SLSH);
            break;
    }
}

void qst_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (qst_state) {
        case T3_SINGLE_TAP:
            unregister_code16(KC_SLSH);
            break;
        case T3_SINGLE_HOLD:
            unregister_code16(KC_QUES);
            break;
        case T3_DOUBLE_TAP:
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