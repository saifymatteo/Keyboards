/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END 5

// ---------------- TAP TERM --------------------------------------------------------------

typedef union {
    uint32_t raw;
    struct {
        uint32_t tapping_term;
        bool     haptic_enable;
    };
} user_config_t;

user_config_t user_config;

// ---------------- Tap Dance --------------------------------------------------------------

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_HOLD,
    TD_SINGLE_TAP,
    TD_DOUBLE_TAP,
    TD_TRIPLE_TAP,
    TD_QUAD_TAP,
} td_state_t;

static td_state_t td_state = TD_NONE;

// ---------------- OS DETECTION --------------------------------------------------------------

os_variant_t current_os = OS_WINDOWS;

// ---------------- KEYCODES --------------------------------------------------------------

// Clear keycode timer;
uint16_t keycode_timer = 0;

// Keycode text for OLED
char text_keycode[14];

enum custom_keycodes {
    ALT_GUI_KC = SAFE_RANGE,
    ALT_GUI_RER,
    ALT_GUI_REL,
    ZOOM_KC,
    ZOOM_RER,
    ZOOM_REL,
    OS_SWITCH_KC,
    HAPTIC_TOGGLE_KC,
    LAYER_UP_KC,
    LAYER_DOWN_KC,
    // Tap Dance
    TD_1_KC,
    TD_2_KC,
    TD_3_KC,
    TD_4_KC,
    TD_5_KC,
    TD_6_KC,
    TD_7_KC,
    TD_8_KC,
    TD_9_KC,
    TD_0_KC,
    // App keycode
    ROTATE_CANVAS_RER,
    ROTATE_CANVAS_REL,
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
    KEYCODE_STRING_NAME(LAYER_UP_KC),       //
    KEYCODE_STRING_NAME(LAYER_DOWN_KC),     //
    KEYCODE_STRING_NAME(TD_1_KC),           //
    KEYCODE_STRING_NAME(TD_2_KC),           //
    KEYCODE_STRING_NAME(TD_3_KC),           //
    KEYCODE_STRING_NAME(TD_4_KC),           //
    KEYCODE_STRING_NAME(TD_5_KC),           //
    KEYCODE_STRING_NAME(TD_6_KC),           //
    KEYCODE_STRING_NAME(TD_7_KC),           //
    KEYCODE_STRING_NAME(TD_8_KC),           //
    KEYCODE_STRING_NAME(TD_9_KC),           //
    KEYCODE_STRING_NAME(TD_0_KC),           //
    KEYCODE_STRING_NAME(ROTATE_CANVAS_RER), //
    KEYCODE_STRING_NAME(ROTATE_CANVAS_REL), //
                                            // Keycodes not recognised by default
    KEYCODE_STRING_NAME(KC_APP),            //
    KEYCODE_STRING_NAME(KC_MUTE),           //
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
