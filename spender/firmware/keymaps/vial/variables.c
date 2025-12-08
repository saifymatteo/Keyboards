/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H

// ---------------- TAP TERM --------------------------------------------------------------

typedef union {
    uint32_t raw;
    struct {
        uint32_t tapping_term;
    };
} user_config_t;

user_config_t user_config;

// ---------------- OS DETECTION --------------------------------------------------------------

os_variant_t current_os = OS_MACOS;

// ---------------- KEYCODES --------------------------------------------------------------

// Clear keycode timer;
uint16_t keycode_timer = 0;

// Keycode text for OLED
char text_keycode[14];

enum custom_keycodes {
    ALT_GUI_KC = QK_KB_0,
    ALT_GUI_REL,
    ALT_GUI_RER,
    OS_SWITCH_KC,
};

KEYCODE_STRING_NAMES_USER(             //
    KEYCODE_STRING_NAME(ALT_GUI_KC),   //
    KEYCODE_STRING_NAME(ALT_GUI_REL),  //
    KEYCODE_STRING_NAME(ALT_GUI_RER),  //
    KEYCODE_STRING_NAME(OS_SWITCH_KC), //
    // Keycodes not recognised by default
    KEYCODE_STRING_NAME(KC_APP),  //
    KEYCODE_STRING_NAME(KC_MUTE), //
    KEYCODE_STRING_NAME(KC_VOLU), //
    KEYCODE_STRING_NAME(KC_VOLD), //
);

// ---------------- ENCODER --------------------------------------------------------------

// Alt (Windows) / Command (MacOS)
// Taken from [reddit](https://www.reddit.com/r/MechanicalKeyboards/comments/s52e51/added_alttab_to_my_rotary_encoder_on_my_qmk_board/)
bool     is_alt_tab_active       = false;
bool     is_alt_shift_tab_active = false;
uint16_t alt_tab_timer           = 0;

// ---------------- OLED --------------------------------------------------------------

// Row/Column text
char text_row_col[13];
