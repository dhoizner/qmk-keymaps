#include "dhoizner.h"

static uint16_t last_key_down = KC_NO;
static uint16_t last_key_up = KC_NO;

static bool swap_caps_escape = false;
bool is_caps_swapped(void) { return swap_caps_escape; }

void tap16_repeatable(uint16_t keycode) {
  tap_code16(keycode);
  // register_key_to_repeat(keycode);
}

bool process_caps(bool key_down) {
  if (swap_caps_escape) {
    if (key_down) {
      register_code(KC_ESC);
    } else {
      unregister_code(KC_ESC);
    }
    return false;
  }
  return true;
}

bool process_escape(bool key_down) {
  if (swap_caps_escape) {
    if (key_down) {
      register_code(KC_CAPS);
    } else {
      unregister_code(KC_CAPS);
    }
    return false;
  }
  return true;
}

void tap_escape(void) { tap_code(swap_caps_escape ? KC_CAPS : KC_ESC); }

void tap_caps_lock(void) { tap_code(swap_caps_escape ? KC_ESC : KC_CAPS); }

void tap_space_shift(uint16_t key, bool key_down) {
  if (key_down) {
    tap_code16(key);
    tap_code(KC_SPC);
    set_oneshot_mods(MOD_BIT(KC_LSFT));
  }
}

void double_tap(uint16_t keycode) {
  tap_code16(keycode);
  tap_code16(keycode);
}

void double_tap_space(uint16_t keycode) {
  tap_code16(KC_SPC);
  double_tap(keycode);
  tap_code16(KC_SPC);
}

// uint16_t get_combo_term(uint16_t index, combo_t *combo) {
//   switch (index) {
//   // // Home-row and other tight combos
//   case ctrl_combo_l:
//   case escape_sym:
//   case tab_mod:
//   case del:
//   case dquo:
//   case coln_sym:
//   case ctrl_combo_r:
//   case quot:
//   case ent:
//   case vsp:
//   case gui_combo_l:
//   case gui_combo_r:
//   case dlr:
//     return COMBO_TERM;
//   // Vertical combos, very relaxed
//   case small_left_arrow:
//   case lt_eq:
//   case large_right_arrow:
//   case small_right_arrow:
//   case pipe_to:
//   case sp:
//   case gt_eq:
//     return COMBO_TERM + 55;
//     Regular combos, slightly relaxed default : return COMBO_TERM + 25;
//   }
// }

// bool get_combo_must_tap(uint16_t index, combo_t *combo) {
//   switch (index) {
//   case del:
//   case backsp:
//   case q_comb:
//   case qu_comb:
//   case z_comb:
//   case num:
//   case comb_perc:
//   case comb_grv:
//   case comb_hash:
//   case comb_pipe:
//   case comb_ques:
//   case comb_exlm:
//   case comb_ampr:
//   case comb_labk:
//   case comb_rabk:
//   case comb_lcbr:
//   case comb_lbrc:
//   case comb_at:
//   case comb_0:
//   case comb_e_acut:
//   case rev_rep:
//   case arng:
//   case adia:
//   case odia:
//   case eql:
//   case gui_combo_l:
//   case gui_combo_r:
//   case ctrl_combo_l:
//   case ctrl_combo_r:
//   case shift_combo_l:
//   case shift_combo_r:
//   case close_win:
//   case escape_sym:
//   case tab_mod:
//   case coln_sym:
//   case dquo:
//   case lalt:
//   case win_alt:
//     return false;
//   default:
//     return true;
//   }
// }

bool combo_should_trigger(uint16_t combo_index, combo_t *combo) {
  // FIXME this doesn't seem to work?
  return true;
}

#ifdef TAPPING_TERM_PER_KEY

#define THUMB_TERM 20
#define INDEX_TERM -20
#define MIDDLE_TERM 0
#define RING_TERM 80
#define PINKY_TERM 180

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MT_SPC:
    return TAPPING_TERM + THUMB_TERM;
  case DN_CTRL:
    return TAPPING_TERM + MIDDLE_TERM;
  default:
    return TAPPING_TERM;
  }
}
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode,
                                                 keyrecord_t *record) {
  return true;
}

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
  switch (keycode) {
  // Keycodes to ignore (don't disable caps word)
  case KC_A ... KC_Z:
  case KC_1 ... KC_0:
  case QU:
  case SC:
  case KC_MINS:
  case KC_UNDS:
  case KC_BSPC:
  case XCASE:
    // If mod chording, disable the mods
    if (record->event.pressed && (get_mods() != 0)) {
      return true;
    }
    break;
  default:
    if (record->event.pressed) {
      return true;
    }
    break;
  }
  return false;
}

bool use_default_xcase_separator(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_A ... KC_Z:
  case KC_1 ... KC_0:
  case CAPSWORD:
    return true;
  }
  return false;
}

void triple_tap(uint16_t keycode) {
  tap_code16(keycode);
  tap_code16(keycode);
  tap_code16(keycode);
}

void double_parens_left(uint16_t left, uint16_t right) {
  tap_code16(left);
  tap_code16(right);
  tap_code16(KC_LEFT);
}

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case CLEAR:
    return true;
  default:
    return false;
  }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
  case CLEAR:
  case OS_SHFT:
  case OS_CTRL:
  case OS_ALT:
  case OS_GUI:
  case TAB_MOD:
  case MY_LSFT:
    return true;
  default:
    return false;
  }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
  update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
  update_oneshot_pre(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
  update_oneshot_pre(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
  update_oneshot_pre(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
  update_oneshot_post(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
  update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
  update_oneshot_post(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
  update_oneshot_post(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
  update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
  update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
}

bool tap_hold(uint16_t keycode) {
  switch (keycode) {
  case KC_DQUO:
  case KC_LABK:
  case KC_RABK:
  case KC_DOT:
  case KC_PERC:
  case KC_GRV:
  case KC_AT:
  case KC_PIPE:
  case KC_EXLM:
  case KC_AMPR:
  case KC_QUES:
  case KC_HASH:
  case KC_LPRN:
  case KC_LCBR:
  case KC_LBRC:
  case KC_EQL:
  case KC_UNDS:
  case KC_0:
  case G(KC_0):
  case G(KC_1):
  case G(KC_2):
  case G(KC_3):
  case G(KC_4):
  case G(KC_5):
  case G(KC_6):
  case G(KC_7):
  case G(KC_8):
  case G(KC_9):
  case G(KC_K):
  case G(KC_J):
  case G(KC_W):
  case G(KC_E):
  case G(KC_R):
  case G(KC_C):
  case KC_A ... KC_Z:
  // case KC_ARNG:
  // case KC_ADIA:
  // case KC_ODIA:
  case QU:
  case SC:
  // case E_ACUT:
  case CLOSE_WIN:
  case C(KC_A):
  case C(KC_C):
  case C(KC_W):
  case C(KC_F):
  case C(KC_E):
  case C(KC_R):
  case C(KC_S):
  case C(KC_T):
  case C(KC_H):
  case C(KC_X):
  case C(KC_V):
  case C(KC_G):
  case C(KC_D):
  case C(KC_B):
    return true;
  default:
    return false;
  }
}

void tap_hold_send_tap(uint16_t keycode) {
  switch (keycode) {
  // case GRV:
  //     register_key_to_repeat(keycode);
  //     tap_undead_key(true, KC_GRV);
  //     return;
  case QU:
    send_string("qu");
    return;
  case SC:
    send_string("sc");
    return;
  // case KC_Q:
  // case KC_Z:
  //     if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
  //         tap16_repeatable(C(keycode));
  //     } else {
  //         tap16_repeatable(keycode);
  //     }
  //     return;
  // case E_ACUT:
  //     tap_code16(KC_ACUT);
  //     tap_code16(KC_E);
  //     return;
  // case CLOSE_WIN:
  //     tap_code16(C(KC_W));
  //     tap_code(KC_Q);
  //     /* tap_escape(); */
  //     /* tap_code16(KC_COLN); */
  //     /* tap_code(KC_Q); */
  //     /* tap_code(KC_ENT); */
  //     return;
  default:
    tap16_repeatable(keycode);
  }
}

void tap_hold_send_hold(uint16_t keycode) {
  disable_caps_word();

  switch (keycode) {
  case KC_LABK:
  case KC_RABK:
  case KC_UNDS:
    // FIXME should be repeatable
    double_tap(keycode);
    return;
  case KC_DQUO:
  case KC_DOT:
  case KC_GRV:
  case KC_0:
    triple_tap(keycode);
    return;
  case KC_PERC:
    send_string("%{}");
    return;
  case KC_AT:
    tap_code16(KC_AT);
    tap16_repeatable(KC_U);
    return;
  case KC_PIPE:
  case KC_AMPR:
  case KC_EQL:
    double_tap_space(keycode);
    return;
  case KC_EXLM:
    send_string(" != ");
    return;
  case KC_QUES:
    send_string("{:?}");
    return;
  case KC_HASH:
    send_string("{:#?}");
    return;
  case KC_LPRN:
    double_parens_left(keycode, KC_RPRN);
    return;
  case KC_LCBR:
    double_parens_left(keycode, KC_RCBR);
    return;
  case KC_LBRC:
    double_parens_left(keycode, KC_RBRC);
    return;
  case QU:
    send_string("Qu");
    return;
  case SC:
    send_string("Sc");
    return;
  // case CLOSE_WIN:_
  //     tap16_repeatable(S(G(SE_C)));
  //     return;
  // case SE_Q:
  // case SE_Z:
  //     if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
  //         tap16_repeatable(S(C(keycode)));
  //     } else {
  //         tap16_repeatable(S(keycode));
  //     }
  //     return;
  default:
    tap16_repeatable(S(keycode));
  }
}

uint16_t tap_hold_timeout(uint16_t keycode) {
  // TODO: refine these
  switch (keycode) {
  // Thumb
  case MY_LSFT:
    return 120;
  // Pinky
  case KC_Q:
  case KC_A:
  case KC_Z:
  case KC_DOT:
  case KC_COMM:
  case KC_SLSH:
  case KC_O:
  case KC_UNDS:
    return 135;
  // Index
  default:
    return 100;
  }
}

// // https://github.com/andrewjrae/kyria-keymap#userspace-leader-sequences
// void *leader_toggles_func(uint16_t keycode) {
//     switch (keycode) {
//         case KC_N:
//             layer_invert(_NUM);
//             return NULL;
//         case KC_S:
//             layer_invert(_SYM);
//             return NULL;
//         case KC_C:
//             swap_caps_esc();
//             return NULL;
//         default:
//             return NULL;
//     }
// }
//
// void *leader_start_func(uint16_t keycode) {
//     switch (keycode) {
//         case KC_T:
//             return leader_toggles_func;
//         case KC_C:
//             tap_caps_lock();
//             return NULL;
//         case ESC_SYM:
//             tap_code16(C(S(KC_ESC)));
//             return NULL;
//         default:
//             return NULL;
//     }
// }

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if (!process_leader(keycode, record)) {
  //   return false;
  // }

  if (!process_case_modes(keycode, record)) {
    return false;
  }

  if (!process_num_word(keycode, record)) {
    return false;
  }

  // if (!process_roll(keycode, record)) {
  //   return false;
  // }

  if (!process_tap_hold(keycode, record)) {
    // Extra register here to allow fast rolls without waiting for tap hold
    // (which will also overwrite this).
    if (record->event.pressed) {
      // register_key_to_repeat(keycode);
    }
    return false;
  }

  if (!(process_record_keymap(keycode, record))) {
    return false;
  }

  switch (keycode) {
  case ESC_SYM:
    if (record->tap.count && record->event.pressed) {
      tap_escape();
      return false;
    }
    break;
  case KC_CAPS:
    return process_caps(record->event.pressed);
  case CLEAR:
    clear_oneshot_mods();
    if (get_oneshot_layer() != 0) {
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    }
    // stop_leading();
    layer_off(_NUM);
    layer_off(_SYM);
    layer_move(_BASE);
    return false;
  case CANCEL:
    // stop_leading();
    layer_off(_NUM);
    layer_off(_SYM);
    return false;
  case NUMWORD:
    process_num_word_activation(record);
    return false;
  case CAPSWORD:
    if (record->event.pressed) {
      enable_caps_word();
    }
    return false;
  case XCASE:
    if (record->event.pressed) {
      enable_xcase();
    }
    return false;
  case SAVE_VIM:
    if (record->event.pressed) {
      tap_escape();
      tap_code16(KC_COLN);
      tap_code(KC_W);
      tap_code(KC_ENT);
    }
    return false;
  case VIM_SP:
    if (record->event.pressed) {
      tap_code16(C(KC_W));
      tap_code(KC_S);
    }
    return false;
  case VIM_VS:
    if (record->event.pressed) {
      tap_code16(C(KC_W));
      tap_code(KC_V);
    }
    return false;
  case NUM_G:
    if (record->event.pressed) {
      tap_code16(S(KC_G));
    }
    return false;
  case AT_U:
    if (record->event.pressed) {
      tap_code16(KC_AT);
      tap16_repeatable(KC_U);
    }
    return false;
  case COLN_SYM:
    if (record->tap.count && record->event.pressed) {
      tap16_repeatable(KC_COLN);
      return false;
    }
    break;
  case KC_ENT:
    if (record->event.pressed) {
      if (IS_LAYER_ON(_NUM)) {
        tap16_repeatable(KC_PENT);
      } else {
        tap16_repeatable(KC_ENT);
      }
      disable_num_word();
    }
    return false;
    // case LEADER:
    //   start_leading();
    //   return false;
    // case REPEAT:
    //   // Enable fast UI rolls with repeat key
    //   end_tap_hold();
    //   update_repeat_key(record);
    //   return false;
    // case REV_REP:
    //   update_reverse_repeat_key(record);
    //   return false;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_oneshot_pre(keycode, record);

  // If `false` was returned, then we did something special and should register
  // that manually. Otherwise register keyrepeat here by default
  bool res = _process_record_user(keycode, record);

  // // Space needs some special handling to not interfere with NAV toggling.
  // // Maybe there's a more general way to do this, but I dunno.
  // if (keycode == MT_SPC) {
  //     if (!record->event.pressed && last_key_down == MT_SPC) {
  //         register_key_to_repeat(KC_SPC);
  //     }
  // } else if (res && record->event.pressed) {
  //     register_key_to_repeat(keycode);
  // }

  process_oneshot_post(keycode, record);

  if (record->event.pressed) {
    last_key_down = keycode;
  } else {
    last_key_up = keycode;
  }

  return res;
}

void matrix_scan_user(void) { tap_hold_matrix_scan(); }
