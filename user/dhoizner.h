#pragma once

#include "keycodes.h"
#include "wrappers.h"
#include "casemodes.h"
#include "layermodes.h"

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

enum custom_keycodes {
    // Direct dead keys ~`^
    TILD = SAFE_RANGE,
    GRV,
    CIRC,

    MY_000,
    SAVE_VIM,
    CLOSE_VIM,
    VIM_VS,
    VIM_SP,

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
    CLEAR, // Clear all WORD, one-shots and reset to BASE

    TO_GAME,
    TO_NUM,

    // Smileys
    // SHRUGIE,        // ┐(°‿°)┌ (nicer) or 乁(ツ)ㄏ (whatever)
    // TABLE_F,        // (╯°□°)╯ ︵ ┻━┻ or (ノಠ益ಠ)ノ彡┻━┻
    // FACE_1,         // ✖‿✖ (excited) or (╯︵╰,) (crying)
    // FACE_2,         // (¬‿¬) (skeptical) or ಠ_ಠ (disapproval)

    // Runtime options
    TG_NIX,
    TG_CAPS,
};
