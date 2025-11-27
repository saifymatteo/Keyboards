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
    // QK_KB_0 is reserved for Trackball enum (8 keys)
    ALT_GUI_KC = QK_KB_8,
    ZOOM_KC,
    UG_VK_TOGG,
    OS_SWITCH_KC,
};

KEYCODE_STRING_NAMES_USER(             //
    KEYCODE_STRING_NAME(ALT_GUI_KC),   //
    KEYCODE_STRING_NAME(ZOOM_KC),      //
    KEYCODE_STRING_NAME(UG_VK_TOGG),   //
    KEYCODE_STRING_NAME(OS_SWITCH_KC), //
    // Keycodes not recognised by default
    KEYCODE_STRING_NAME(KC_APP),  //
    KEYCODE_STRING_NAME(UG_NEXT), //
    KEYCODE_STRING_NAME(UG_TOGG), //
);

// ---------------- RGB UNDERGLOW --------------------------------------------------------------

static uint32_t rgb_key_timer;          // timer for last keyboard activity, use 32bit value and function to make longer idle time possible
bool            is_rgb_timeout = false; // store if RGB has timed out or not in a boolean

// ---------------- ENCODER --------------------------------------------------------------

// Alt (Windows) / Command (MacOS)
// Taken from [reddit](https://www.reddit.com/r/MechanicalKeyboards/comments/s52e51/added_alttab_to_my_rotary_encoder_on_my_qmk_board/)
bool     is_alt_tab_active       = false;
bool     is_alt_shift_tab_active = false;
uint16_t alt_tab_timer           = 0;

// ---------------- OLED --------------------------------------------------------------

// Row/Column text
char text_row_col[13];
