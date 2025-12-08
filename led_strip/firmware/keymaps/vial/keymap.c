/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = //
 {
        [0] = LAYOUT(                                           //
            QK_UNDERGLOW_MODE_PREVIOUS, QK_UNDERGLOW_MODE_NEXT, //
            QK_UNDERGLOW_VALUE_DOWN, QK_UNDERGLOW_VALUE_UP,     //
            QK_UNDERGLOW_HUE_DOWN, QK_UNDERGLOW_HUE_UP     //
            ),                                                  //
};

// ---------------- SAVE MEMORY --------------------------------------------------------------

#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif

// END OF FILE
