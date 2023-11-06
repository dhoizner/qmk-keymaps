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
//    ┌─────┬─────┬─────────────┬─────┬─────┐           ┌───┬─────┬─────┬───────┬───┬──────┐
//    │  q  │  w  │      f      │  p  │  b  │           │ j │  l  │  u  │   y   │ ' │ bspc │
//    ├─────┼─────┼─────────────┼─────┼─────┤           ├───┼─────┼─────┼───────┼───┴──────┤
//    │ ⌃|a │ ⌥|r │     ⌘|s     │ ⇧|t │  g  │           │ m │ n|⇧ │ e|⌘ │  a|⌥  │   o|⌃    │
//    ├─────┴─────┼─────────────┼─────┼─────┼───┐       └───┼─────┼─────┼───────┼───┬──────┤
//    │     z     │      x      │  c  │  d  │ v │           │  k  │  h  │ o|⌃MM │ . │  /   │
//    └───────────┼─────────────┼─────┼─────┼───┴───┬───────┼─────┼─────┼───────┼───┴──────┘
//                │ MO(_DEVICE) │     │     │ num|␣ │sym|(⇧)│     │     │       │           
//                └─────────────┴─────┴─────┴───────┴───────┴─────┴─────┴───────┘           
[_BASE] = LAYOUT_split_4space(
  KC_Q  , KC_W  , KC_F        , KC_P    , KC_B    ,                KC_J , KC_L    , KC_U    , KC_Y    , KC_QUOTE , KC_BSPC,
  KC_CA , KC_AR , KC_GS       , KC_ST   , KC_G    ,                KC_M , KC_SN   , KC_GE   , KC_AI   ,       KC_CO       ,
      KC_Z      , KC_X        , KC_C    , KC_D    , KC_V ,                KC_K    , KC_H    , KC_COMM , KC_DOT   , KC_SLSH,
                  MO(_DEVICE) , KC_TRNS , KC_TRNS , LT(_NUM, KC_SPACE) , LT(_SYM, OSM(KC_LSFT)) , KC_TRNS , KC_TRNS , KC_TRNS                     
),

//    ┌─────┬───┬─────┬─────┬───────────┐           ┌─────┬─────┬─────┬─────┬───┬─────┐
//    │     │ 7 │  8  │  9  │     =     │           │     │  &  │  *  │  (  │ + │     │
//    ├─────┼───┼─────┼─────┼───────────┤           ├─────┼─────┼─────┼─────┼───┴─────┤
//    │  0  │ 1 │  2  │  3  │ sEMICOLON │           │  )  │  !  │  @  │  #  │    :    │
//    ├─────┴───┼─────┼─────┼───────────┼───┐       └─────┼─────┼─────┼─────┼───┬─────┤
//    │    `    │  4  │  5  │     6     │ \ │             │  ~  │  $  │  %  │ ^ │  |  │
//    └─────────┼─────┼─────┼───────────┼───┴───┬─────────┼─────┼─────┼─────┼───┴─────┘
//              │     │     │           │       │         │     │     │     │          
//              └─────┴─────┴───────────┴───────┴─────────┴─────┴─────┴─────┘          
[_NUM] = LAYOUT_split_4space(
  KC_TRNS , KC_7 , KC_8    , KC_9    , KC_EQUAL     ,                        KC_TRNS        , KC_AMPERSAND , KC_ASTERISK , KC_LEFT_PAREN , KC_PLUS       , KC_TRNS,
  KC_0    , KC_1 , KC_2    , KC_3    , KC_SEMICOLON ,                        KC_RIGHT_PAREN , KC_EXCLAIM   , KC_AT       , KC_HASH       ,        KC_COLON        ,
     KC_GRAVE    , KC_4    , KC_5    , KC_6         , KC_BACKSLASH ,                          KC_TILDE     , KC_DOLLAR   , KC_PERCENT    , KC_CIRCUMFLEX , KC_PIPE,
                   KC_TRNS , KC_TRNS , KC_TRNS      ,     KC_TRNS      ,      KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS                                
),

//    ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │             │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┴─────┤
//    │     │     │     │     │     │             │     │     │     │     │           │
//    ├─────┴─────┼─────┼─────┼─────┼─────┐       └─────┼─────┼─────┼─────┼─────┬─────┤
//    │           │     │     │     │     │             │     │     │     │     │     │
//    └───────────┼─────┼─────┼─────┼─────┴───┬─────────┼─────┼─────┼─────┼─────┴─────┘
//                │     │     │     │         │         │     │     │     │            
//                └─────┴─────┴─────┴─────────┴─────────┴─────┴─────┴─────┘            
[_SYM] = LAYOUT_split_4space(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS     ,
       KC_TRNS      , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                      KC_TRNS , KC_TRNS , KC_TRNS ,   KC_TRNS   ,   KC_TRNS   , KC_TRNS , KC_TRNS , KC_TRNS                    
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
      "KC_CO": "o|⌃",
      "KC_COLON": ":",
      "LT%(_NUM, KC_SPACE%)": "num|␣",
      "LT%(_SYM, OSM%(KC_LSFT%)%)": "sym|%(⇧%)"
    }
  }
}
 qmk:json:end
*/
