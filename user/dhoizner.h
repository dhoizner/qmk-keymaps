#pragma once

#include "casemodes.h"
#include "keycodes.h"
#include "layermodes.h"
#include "oneshot.h"
#include "taphold.h"
#include "wrappers.h"

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

enum custom_keycodes {
  // Direct dead keys ~`^
  SAVE_VIM = SAFE_RANGE,
  VIM_VS,
  VIM_SP,
  CLOSE_WIN,

  // Multiple chars
  QU,
  SC,
  AT_U,

  // Custom keycodes for instant processing for NUMWORD
  NUM_G,

  // Instant oneshot mods
  OS_SHFT,
  OS_CTRL,
  OS_ALT,
  OS_GUI,

  // Smart caps lock and layers that turn off on certain keys
  CAPSWORD,
  NUMWORD,
  XCASE,

  // Layer management
  CANCEL, // Cancel SYMWORD and NUMWORD
  CLEAR,  // Clear all WORD, one-shots and reset to BASE

  // Instant leader key
  LEADER,

  // Repeat keys
  REPEAT,
  REV_REP,
};
