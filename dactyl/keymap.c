// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "dhoizner.h"
#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────┬───┬───┬────────┬─────────────┐           ┌─────────────┬─────────┬───┬───┬───┐
//    │ REPEAT │ w │ f │   p    │      b      │           │      j      │    l    │ u │ y │ . │
//    ├────────┼───┼───┼────────┼─────────────┤           ├─────────────┼─────────┼───┼───┼───┤
//    │   a    │ r │ s │   t    │      g      │           │      m      │    n    │ e │ i │ o │
//    ├────────┼───┼───┼────────┼─────────────┤           ├─────────────┼─────────┼───┼───┼───┤
//    │   ,    │ x │ c │   d    │      v      │           │      k      │    h    │ ( │ ) │ _ │
//    └────────┴───┴───┼────────┼─────────────┤           ├─────────────┼─────────┼───┴───┴───┘
//                     │ LT_SPC │ MO(_DEVICE) │           │ MO(_DEVICE) │ MY_LSFT │            
//                     └────────┴─────────────┘           └─────────────┴─────────┘            
[_BASE] = LAYOUT_split_3x5_2(
  REPEAT  , KC_W , KC_F , KC_P   , KC_B        ,             KC_J        , KC_L    , KC_U    , KC_Y    , KC_DOT ,
  KC_A    , KC_R , KC_S , KC_T   , KC_G        ,             KC_M        , KC_N    , KC_E    , KC_I    , KC_O   ,
  KC_COMM , KC_X , KC_C , KC_D   , KC_V        ,             KC_K        , KC_H    , KC_LPRN , KC_RPRN , KC_UNDS,
                          LT_SPC , MO(_DEVICE) ,             MO(_DEVICE) , MY_LSFT                              
),

//    ┌───┬─────┬───────┬─────┬─────┐           ┌─────┬────────┬──────┬────────┬─────┐
//    │ j │  +  │   *   │  !  │  p  │           │  x  │        │ AT_U │ REPEAT │     │
//    ├───┼─────┼───────┼─────┼─────┤           ├─────┼────────┼──────┼────────┼─────┤
//    │ 6 │  4  │   0   │  2  │  k  │           │     │   3    │  1   │   5    │  7  │
//    ├───┼─────┼───────┼─────┼─────┤           ├─────┼────────┼──────┼────────┼─────┤
//    │ , │     │ NUM_G │  8  │     │           │  /  │   9    │  (   │   )    │  _  │
//    └───┴─────┴───────┼─────┼─────┤           ├─────┼────────┼──────┴────────┴─────┘
//                      │     │     │           │     │ CANCEL │                      
//                      └─────┴─────┘           └─────┴────────┘                      
[_NUM] = LAYOUT_split_3x5_2(
  KC_J    , KC_PLUS , KC_ASTR , KC_EXLM , KC_P    ,             KC_X    , _______ , AT_U    , REPEAT  , _______,
  KC_6    , KC_4    , KC_0    , KC_2    , KC_K    ,             _______ , KC_3    , KC_1    , KC_5    , KC_7   ,
  KC_COMM , _______ , NUM_G   , KC_8    , _______ ,             KC_SLSH , KC_9    , KC_LPRN , KC_RPRN , KC_UNDS,
                                _______ , _______ ,             _______ , CANCEL                               
),

//    ┌──────┬────────┬─────────┬───────┬──────┐           ┌─────┬──────┬──────┬─────┬──────┐
//    │ G(j) │  left  │   up    │ rght  │ home │           │     │      │      │     │      │
//    ├──────┼────────┼─────────┼───────┼──────┤           ├─────┼──────┼──────┼─────┼──────┤
//    │ pgup │ SC_TAB │ DN_CTRL │ C_TAB │ G(k) │           │     │ left │ down │ up  │ rght │
//    ├──────┼────────┼─────────┼───────┼──────┤           ├─────┼──────┼──────┼─────┼──────┤
//    │ ent  │        │         │ pgdn  │ end  │           │     │      │      │     │      │
//    └──────┴────────┴─────────┼───────┼──────┤           ├─────┼──────┼──────┴─────┴──────┘
//                              │       │      │           │     │      │                    
//                              └───────┴──────┘           └─────┴──────┘                    
[_NAV] = LAYOUT_split_3x5_2(
  G(KC_J) , KC_LEFT , KC_UP   , KC_RGHT , KC_HOME ,             _______ , _______ , _______ , _______ , _______,
  KC_PGUP , SC_TAB  , DN_CTRL , C_TAB   , G(KC_K) ,             _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT,
  KC_ENT  , _______ , _______ , KC_PGDN , KC_END  ,             _______ , _______ , _______ , _______ , _______,
                                _______ , _______ ,             _______ , _______                              
),

//    ┌───┬───┬───┬─────┬─────┐           ┌─────┬────────┬───┬───┬────────┐
//    │ ~ │ + │ * │  !  │     │           │     │   #    │ @ │ ^ │   .    │
//    ├───┼───┼───┼─────┼─────┤           ├─────┼────────┼───┼───┼────────┤
//    │ | │ { │ } │  -  │  \  │           │  `  │   ?    │ [ │ ] │ REPEAT │
//    ├───┼───┼───┼─────┼─────┤           ├─────┼────────┼───┼───┼────────┤
//    │ , │ < │ > │  %  │     │           │  /  │   &    │ ( │ ) │   _    │
//    └───┴───┴───┼─────┼─────┤           ├─────┼────────┼───┴───┴────────┘
//                │     │     │           │     │ CANCEL │                 
//                └─────┴─────┘           └─────┴────────┘                 
[_SYM] = LAYOUT_split_3x5_2(
  KC_TILD , KC_PLUS , KC_ASTR , KC_EXLM , _______ ,             _______ , KC_HASH , KC_AT   , KC_CIRC , KC_DOT ,
  KC_PIPE , KC_LCBR , KC_RCBR , KC_MINS , KC_BSLS ,             KC_GRV  , KC_QUES , KC_LBRC , KC_RBRC , REPEAT ,
  KC_COMM , KC_LABK , KC_RABK , KC_PERC , _______ ,             KC_SLSH , KC_AMPR , KC_LPRN , KC_RPRN , KC_UNDS,
                                _______ , _______ ,             _______ , CANCEL                               
),

//    ┌─────┬─────┬─────┬─────┬─────┐           ┌─────┬────────┬─────────┬─────────┬────────┐
//    │     │     │     │     │     │           │     │        │         │         │        │
//    ├─────┼─────┼─────┼─────┼─────┤           ├─────┼────────┼─────────┼─────────┼────────┤
//    │     │     │     │     │     │           │     │ OS_GUI │ OS_CTRL │ OS_SHFT │ OS_ALT │
//    ├─────┼─────┼─────┼─────┼─────┤           ├─────┼────────┼─────────┼─────────┼────────┤
//    │     │     │     │     │     │           │     │        │         │         │        │
//    └─────┴─────┴─────┼─────┼─────┤           ├─────┼────────┼─────────┴─────────┴────────┘
//                      │     │     │           │     │        │                             
//                      └─────┴─────┘           └─────┴────────┘                             
[_MODS] = LAYOUT_split_3x5_2(
  _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ ,             _______ , OS_GUI  , OS_CTRL , OS_SHFT , OS_ALT ,
  _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______,
                                _______ , _______ ,             _______ , _______                              
),

//    ┌─────────┬─────┬─────┬─────┬─────┐           ┌─────┬─────┬─────┬─────┬─────────┐
//    │ QK_BOOT │     │     │     │     │           │     │     │     │     │ QK_BOOT │
//    ├─────────┼─────┼─────┼─────┼─────┤           ├─────┼─────┼─────┼─────┼─────────┤
//    │         │     │     │     │     │           │     │     │     │     │         │
//    ├─────────┼─────┼─────┼─────┼─────┤           ├─────┼─────┼─────┼─────┼─────────┤
//    │         │     │     │     │     │           │     │     │     │     │         │
//    └─────────┴─────┴─────┼─────┼─────┤           ├─────┼─────┼─────┴─────┴─────────┘
//                          │     │     │           │     │     │                      
//                          └─────┴─────┘           └─────┴─────┘                      
[_DEVICE] = LAYOUT_split_3x5_2(
  QK_BOOT , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , QK_BOOT,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                KC_TRNS , KC_TRNS ,             KC_TRNS , KC_TRNS                              
)
};
// clang-format on

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
  // // Home-row and other tight combos
  case ctrl_combo_l:
  case escape_sym:
  case tab_mod:
  case del:
  case dquo:
  case coln_sym:
  case ctrl_combo_r:
  case quot:
  case ent:
  case vsp:
  case gui_combo_l:
  case gui_combo_r:
  case dlr:
    return COMBO_TERM;
  // Vertical combos, very relaxed
  case small_left_arrow:
  case lt_eq:
  case large_right_arrow:
  case small_right_arrow:
  case pipe_to:
  case sp:
  case gt_eq:
    return COMBO_TERM + 55;
  // Regular combos, slightly relaxed
  default:
    return COMBO_TERM + 25;
  }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  switch (index) {
  case del:
  case backsp:
  case q_comb:
  case qu_comb:
  case z_comb:
  case num:
  case comb_perc:
  case comb_dot:
  case comb_grv:
  case comb_hash:
  case comb_pipe:
  case comb_ques:
  case comb_exlm:
  case comb_ampr:
  case comb_labk:
  case comb_rabk:
  case comb_lcbr:
  case comb_lbrc:
  case comb_at:
  case comb_0:
  // case comb_e_acut:
  case rev_rep:
  // case arng:
  // case adia:
  // case odia:
  case eql:
  case gui_combo_l:
  case gui_combo_r:
  case ctrl_combo_l:
  case ctrl_combo_r:
  case shift_combo_l:
  case shift_combo_r:
  case close_win:
  case escape_sym:
  case tab_mod:
  case coln_sym:
  case dquo:
  case lalt:
    // case win_alt:
    return false;
  default:
    return true;
  }
}
