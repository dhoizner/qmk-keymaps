#pragma once

#include "action.h"
#include "quantum.h"
#include "version.h"
/* #include "oneshot.h" */

enum layers {
  _BASE,
  _NUM,
  _NAV,
  _SYM,
  _MODS,
  _DEVICE,
};

#define xxxxxxx KC_NO

// thumbs
#define LT_SPC LT(_NAV, KC_SPC)
#define LT_BSPC LT(_SYM, KC_BSPC)
#define LT_ESC LT(_NAV, KC_ESC)

#define DN_CTRL LCTL_T(KC_DOWN)

#define ESC_SYM LT(_SYM, KC_ESC)
#define COLN_SYM LT(_SYM, KC_COLN)
#define TAB_MOD LT(_MODS, KC_TAB)

#define C_TAB C(KC_TAB)
#define S_TAB S(KC_TAB)
#define SC_TAB S(C(KC_TAB))

#define KC_CA LCTL_T(KC_A)
#define KC_AR LALT_T(KC_R)
#define KC_GS LGUI_T(KC_S)
#define KC_ST LSFT_T(KC_T)
#define KC_SN LSFT_T(KC_N)
#define KC_GE LGUI_T(KC_E)
#define KC_AI LALT_T(KC_I)
#define KC_CO LCTL_T(KC_O)

// --- mine above ---
#define MT_BTN1 LGUI_T(KC_BTN1)
#define MT_SPC LT(_NAV, KC_SPC)
#define MT_BSPC MO(_NAV)
#define MY_LSFT OSM(MOD_LSFT)
#define ALT OSM(MOD_LALT)
#define MY_LALT OSM(MOD_LALT)
#define CTRL OSM(MOD_LCTL)
#define GUI OSM(MOD_LGUI)
#define DN_CTRL LCTL_T(KC_DOWN)

#define C_TAB C(KC_TAB)
#define SC_TAB S(C(KC_TAB))

#define LMOD OSL(_LMOD)
#define RMOD OSL(_RMOD)
// #define NUM MO(_NUM)
// #define TG_NUM TG(_NUM)
// #define G_WNAV LM(_WNAV, MOD_LGUI)
#define WNAV MO(_WNAV)
#define TG_WNAV TG(_WNAV)
#define TG_SWE TG(_SWE)
#define OPT OSL(_OPT)
#define FUN OSL(_FUN)

#define GAME2 OSL(_GAME2)
