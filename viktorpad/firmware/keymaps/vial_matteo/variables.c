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
        bool     haptic_enable : 1;
    };
} user_config_t;

user_config_t user_config;

// ---------------- OS DETECTION --------------------------------------------------------------

os_variant_t current_os = OS_WINDOWS;

// ---------------- KEYCODES --------------------------------------------------------------

// Clear keycode timer;
uint16_t keycode_timer = 0;

// Keycode text for OLED
char text_keycode[14];

enum custom_keycodes {
    ALT_GUI_KC = QK_KB_0,
    ALT_GUI_RER,
    ALT_GUI_REL,
    ZOOM_KC,
    ZOOM_RER,
    ZOOM_REL,
    OS_SWITCH_KC,
    HAPTIC_TOGGLE_KC,
    // App keycode
    ROTATE_CANVAS_RER,
    ROTATE_CANVAS_REL,
    BRUSH_SIZE_RER,
    BRUSH_SIZE_REL,
};

KEYCODE_STRING_NAMES_USER(                  //
    KEYCODE_STRING_NAME(ALT_GUI_KC),        //
    KEYCODE_STRING_NAME(ALT_GUI_RER),       //
    KEYCODE_STRING_NAME(ALT_GUI_REL),       //
    KEYCODE_STRING_NAME(ZOOM_KC),           //
    KEYCODE_STRING_NAME(ZOOM_RER),          //
    KEYCODE_STRING_NAME(ZOOM_REL),          //
    KEYCODE_STRING_NAME(OS_SWITCH_KC),      //
    KEYCODE_STRING_NAME(HAPTIC_TOGGLE_KC),  //
    KEYCODE_STRING_NAME(ROTATE_CANVAS_RER), //
    KEYCODE_STRING_NAME(ROTATE_CANVAS_REL), //
    KEYCODE_STRING_NAME(BRUSH_SIZE_RER), //
    KEYCODE_STRING_NAME(BRUSH_SIZE_REL), //
                                            // Keycodes not recognised by default
    KEYCODE_STRING_NAME(KC_APP),            //
    KEYCODE_STRING_NAME(KC_MUTE),           //
    KEYCODE_STRING_NAME(UG_NEXT),           //
    KEYCODE_STRING_NAME(UG_PREV),           //
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
