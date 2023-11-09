/* Copyright 2021 projectcain
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

#include "dhoizner.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────┬───┬─────────────┬─────┬─────┐           ┌───┬─────┬─────┬─────┬───┬─────┐
//    │ REPEAT │ w │      f      │  p  │  b  │           │ j │  l  │  u  │  y  │ . │     │
//    ├────────┼───┼─────────────┼─────┼─────┤           ├───┼─────┼─────┼─────┼───┴─────┤
//    │   a    │ r │      s      │  t  │  g  │           │ m │  n  │  e  │  i  │    o    │
//    ├────────┴───┼─────────────┼─────┼─────┼───┐       └───┼─────┼─────┼─────┼───┬─────┤
//    │     ,      │      x      │  c  │  d  │ v │           │  k  │  h  │  (  │ ) │  _  │
//    └────────────┼─────────────┼─────┼─────┼───┴───┬───────┼─────┼─────┼─────┼───┴─────┘
//                 │ MO(_DEVICE) │     │     │LT_SPC │MY_LSFT│     │     │     │          
//                 └─────────────┴─────┴─────┴───────┴───────┴─────┴─────┴─────┘          
[_BASE] = LAYOUT_split_4space(
  REPEAT , KC_W , KC_F        , KC_P    , KC_B    ,                KC_J , KC_L    , KC_U    , KC_Y    , KC_DOT  , _______,
  KC_A   , KC_R , KC_S        , KC_T    , KC_G    ,                KC_M , KC_N    , KC_E    , KC_I    ,       KC_O       ,
     KC_COMM    , KC_X        , KC_C    , KC_D    , KC_V ,                KC_K    , KC_H    , KC_LPRN , KC_RPRN , KC_UNDS,
                  MO(_DEVICE) , KC_TRNS , KC_TRNS ,  LT_SPC  , MY_LSFT  , KC_TRNS , KC_TRNS , KC_TRNS                    
),

//    ┌───┬───┬─────┬───────┬─────┐             ┌─────┬─────┬──────┬────────┬─────┬─────┐
//    │ j │ + │  *  │   !   │  p  │             │  x  │     │ AT_U │ REPEAT │     │     │
//    ├───┼───┼─────┼───────┼─────┤             ├─────┼─────┼──────┼────────┼─────┴─────┤
//    │ 6 │ 4 │  0  │   2   │  k  │             │     │  3  │  1   │   5    │     7     │
//    ├───┴───┼─────┼───────┼─────┼─────┐       └─────┼─────┼──────┼────────┼─────┬─────┤
//    │   ,   │     │ NUM_G │  8  │     │             │  /  │  9   │   (    │  )  │  _  │
//    └───────┼─────┼───────┼─────┼─────┴───┬─────────┼─────┼──────┼────────┼─────┴─────┘
//            │     │       │     │         │ CANCEL  │     │      │        │            
//            └─────┴───────┴─────┴─────────┴─────────┴─────┴──────┴────────┘            
[_NUM] = LAYOUT_split_4space(
  KC_J , KC_PLUS , KC_ASTR , KC_EXLM , KC_P    ,                   KC_X    , _______ , AT_U    , REPEAT  , _______ , _______,
  KC_6 , KC_4    , KC_0    , KC_2    , KC_K    ,                   _______ , KC_3    , KC_1    , KC_5    ,       KC_7       ,
     KC_COMM     , _______ , NUM_G   , KC_8    , _______ ,                   KC_SLSH , KC_9    , KC_LPRN , KC_RPRN , KC_UNDS,
                   _______ , _______ , _______ ,   _______   ,   CANCEL    , _______ , _______ , _______                    
),

//    ┌──────┬────────┬─────────┬───────┬──────┐             ┌─────┬──────┬──────┬─────┬─────┬─────┐
//    │ G(j) │  left  │   up    │ rght  │ home │             │     │      │      │     │     │     │
//    ├──────┼────────┼─────────┼───────┼──────┤             ├─────┼──────┼──────┼─────┼─────┴─────┤
//    │ pgup │ SC_TAB │ DN_CTRL │ C_TAB │ G(k) │             │     │ left │ down │ up  │   rght    │
//    ├──────┴────────┼─────────┼───────┼──────┼─────┐       └─────┼──────┼──────┼─────┼─────┬─────┤
//    │      ent      │         │       │ pgdn │ end │             │      │      │     │     │     │
//    └───────────────┼─────────┼───────┼──────┼─────┴───┬─────────┼──────┼──────┼─────┼─────┴─────┘
//                    │         │       │      │         │         │      │      │     │            
//                    └─────────┴───────┴──────┴─────────┴─────────┴──────┴──────┴─────┘            
[_NAV] = LAYOUT_split_4space(
  G(KC_J) , KC_LEFT , KC_UP   , KC_RGHT , KC_HOME ,                  _______ , _______ , _______ , _______ , _______ , _______,
  KC_PGUP , SC_TAB  , DN_CTRL , C_TAB   , G(KC_K) ,                  _______ , KC_LEFT , KC_DOWN , KC_UP   ,      KC_RGHT     ,
       KC_ENT       , _______ , _______ , KC_PGDN , KC_END ,                   _______ , _______ , _______ , _______ , _______,
                      _______ , _______ , _______ ,  _______   ,   _______   , _______ , _______ , _______                    
),

//    ┌───┬───┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬───┬─────┐
//    │ ~ │ + │  *  │  !  │     │             │     │  #  │  @  │  ^  │ . │     │
//    ├───┼───┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼───┴─────┤
//    │ | │ { │  }  │  -  │  \  │             │  `  │  ?  │  [  │  ]  │ REPEAT  │
//    ├───┴───┼─────┼─────┼─────┼─────┐       └─────┼─────┼─────┼─────┼───┬─────┤
//    │   ,   │  <  │  >  │  %  │     │             │  /  │  &  │  (  │ ) │  _  │
//    └───────┼─────┼─────┼─────┼─────┴───┬─────────┼─────┼─────┼─────┼───┴─────┘
//            │     │     │     │         │ CANCEL  │     │     │     │          
//            └─────┴─────┴─────┴─────────┴─────────┴─────┴─────┴─────┘          
[_SYM] = LAYOUT_split_4space(
  KC_TILD , KC_PLUS , KC_ASTR , KC_EXLM , _______ ,                   _______ , KC_HASH , KC_AT   , KC_CIRC , KC_DOT  , _______,
  KC_PIPE , KC_LCBR , KC_RCBR , KC_MINS , KC_BSLS ,                   KC_GRV  , KC_QUES , KC_LBRC , KC_RBRC ,      REPEAT      ,
       KC_COMM      , KC_LABK , KC_RABK , KC_PERC , _______ ,                   KC_SLSH , KC_AMPR , KC_LPRN , KC_RPRN , KC_UNDS,
                      _______ , _______ , _______ ,   _______   ,   CANCEL    , _______ , _______ , _______                    
),

//    ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬────────┬─────────┬─────────┬─────┬─────┐
//    │     │     │     │     │     │             │     │        │         │         │     │     │
//    ├─────┼─────┼─────┼─────┼─────┤             ├─────┼────────┼─────────┼─────────┼─────┴─────┤
//    │     │     │     │     │     │             │     │ OS_GUI │ OS_CTRL │ OS_SHFT │  OS_ALT   │
//    ├─────┴─────┼─────┼─────┼─────┼─────┐       └─────┼────────┼─────────┼─────────┼─────┬─────┤
//    │           │     │     │     │     │             │        │         │         │     │     │
//    └───────────┼─────┼─────┼─────┼─────┴───┬─────────┼────────┼─────────┼─────────┼─────┴─────┘
//                │     │     │     │         │         │        │         │         │            
//                └─────┴─────┴─────┴─────────┴─────────┴────────┴─────────┴─────────┘            
[_MODS] = LAYOUT_split_4space(
  _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ ,                   _______ , OS_GUI  , OS_CTRL , OS_SHFT ,      OS_ALT      ,
       _______      , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______,
                      _______ , _______ , _______ ,   _______   ,   _______   , _______ , _______ , _______                    
),

//    ┌─────────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │ QK_BOOT │     │     │     │     │             │     │     │     │     │     │     │
//    ├─────────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┴─────┤
//    │         │     │     │     │     │             │     │     │     │     │           │
//    ├─────────┴─────┼─────┼─────┼─────┼─────┐       └─────┼─────┼─────┼─────┼─────┬─────┤
//    │               │     │     │     │     │             │     │     │     │     │     │
//    └───────────────┼─────┼─────┼─────┼─────┴───┬─────────┼─────┼─────┼─────┼─────┴─────┘
//                    │     │     │     │         │         │     │     │     │            
//                    └─────┴─────┴─────┴─────────┴─────────┴─────┴─────┴─────┘            
[_DEVICE] = LAYOUT_split_4space(
  QK_BOOT , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS     ,
       KC_TRNS      , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                      KC_TRNS , KC_TRNS , KC_TRNS ,   KC_TRNS   ,   KC_TRNS   , KC_TRNS , KC_TRNS , KC_TRNS                    
)
};


//empty
// _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ , _______,
// _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ ,      _______     ,
//      _______      , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______,
//                     _______ , _______ , _______ ,   _______   ,   _______   , _______ , _______ , _______                    

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
  default : return COMBO_TERM + 25;
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

/*
qmk:json:start
{
  "name": "LAYOUT_split_4space",
  "layout": [
    "x x x x x _ _ _ x x x x x x",
    "x x x x x _ _ _ x x x x x^x",
    "x^x x x x x _ _ _ x x x x x",
    "_ _ x x x x^x x^x x x x _ _"
  ],
  "comment_preview": {
    "keymap_overrides": {
      "SFT_T%(KC_B␣%)": "⇧|⌫",
      "KC_CA": "⌃|a",
      "KC_AR": "⌥|r",
      "KC_GS": "⌘|s",
      "KC_ST": "⇧|t",
      "KC_SN": "n|⇧",
      "KC_GE": "e|⌘",
      "KC_AI": "a|⌥",
      "KC_COLON": ":",
      "LT%(_NUM, KC_SPACE%)": "num|␣",
      "LT%(_SYM, OSM%(KC_LSFT%)%)": "sym|%(⇧%)"
    }
  }
}
 qmk:json:end
*/
