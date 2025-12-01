/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "encoder.c"
#include "oled.c"
#include "keycode.c"
#include "os_detection.c"

void keyboard_post_init_user(void) {
    // Enable console debug
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;

    // Register deferred callback for OS Detection
    defer_exec(1000, custom_os_settings, NULL);

    // Update Dynamic Tapping Term
    user_config.raw = eeconfig_read_user();
    if (user_config.tapping_term != TAPPING_TERM) {
        g_tapping_term = user_config.tapping_term;
    }
}

// When EEPROM reset
void eeconfig_init_user(void) {
    user_config.raw          = 0;
    user_config.tapping_term = TAPPING_TERM;
    eeconfig_update_user(user_config.raw);
}

// code will run on keyboard wakeup
void suspend_wakeup_init_user(void) {
    oled_on();
}

// code will run multiple times while keyboard is suspended
void suspend_power_down_user(void) {
    oled_off();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =                                                                //
    {[0] = LAYOUT(                                                                                                          //
         KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,                                        //
         KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,                                    //
         KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,                                      //
         KC_APP, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, PDF(1),                                //
         KC_LCTL, KC_LGUI, KC_LSFT, KC_SPC, LALT_T(KC_ENT), TT(2), TT(2), RALT_T(KC_ENT), KC_SPC, KC_RSFT, KC_HOME, KC_END, //
         ALT_GUI_KC                                                                                                         //
         ),
     [1] = LAYOUT(                                                                                                   //
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //
         KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS,                               //
         KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_TRNS,                            //
         KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, PDF(0),                        //
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //
         KC_TRNS                                                                                                     //
         ),
     [2] = LAYOUT(                                                                                                        //
         QK_REBOOT, DT_DOWN, DT_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOTLOADER, //
         KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_GRV, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS,                //
         KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, ALT_GUI_KC, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS,             //
         EE_CLR, KC_F9, KC_F10, KC_F11, KC_F12, AU_TOGG, KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, OS_SWITCH_KC,        //
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      //
         KC_MUTE                                                                                                          //
         )};

layer_state_t layer_state_set_user(layer_state_t state) {
    oled_clear();
    return state;
}
