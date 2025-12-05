/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H

// ---------------- OS DETECTION --------------------------------------------------------------

os_variant_t current_os = OS_WINDOWS;

// ---------------- KEYCODES --------------------------------------------------------------

// Clear keycode timer;
uint16_t keycode_timer = 0;

enum custom_keycodes {
    ALT_GUI_KC = SAFE_RANGE,
    ALT_GUI_RER,
    ALT_GUI_REL,
    ZOOM_KC,
    ZOOM_RER,
    ZOOM_REL,
    OS_SWITCH_KC,
    // App keycode
    ROTATE_CANVAS_RER,
    ROTATE_CANVAS_REL,
};

KEYCODE_STRING_NAMES_USER(             //
    KEYCODE_STRING_NAME(ALT_GUI_KC),   //
    KEYCODE_STRING_NAME(ALT_GUI_RER),  //
    KEYCODE_STRING_NAME(ALT_GUI_REL),  //
    KEYCODE_STRING_NAME(ZOOM_KC),      //
    KEYCODE_STRING_NAME(ZOOM_RER),     //
    KEYCODE_STRING_NAME(ZOOM_REL),     //
    KEYCODE_STRING_NAME(OS_SWITCH_KC), //
    KEYCODE_STRING_NAME(ROTATE_CANVAS_RER), //
    KEYCODE_STRING_NAME(ROTATE_CANVAS_REL), //
    // Keycodes not recognised by default
    KEYCODE_STRING_NAME(KC_APP),  //
    KEYCODE_STRING_NAME(KC_MUTE), //
);

// ---------------- ENCODER --------------------------------------------------------------

// Alt (Windows) / Command (MacOS)
// Taken from
// [reddit](https://www.reddit.com/r/MechanicalKeyboards/comments/s52e51/added_alttab_to_my_rotary_encoder_on_my_qmk_board/)
bool     is_alt_tab_active       = false;
bool     is_alt_shift_tab_active = false;
uint16_t alt_tab_timer           = 0;
