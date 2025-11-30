/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "deferred_exec.h"
#include "os_detection.c"
#include "encoder.c"
#include "keycode.c"
#include "oled.c"

void keyboard_pre_init_user(void) {
    // Haptic motor PIN
    gpio_set_pin_output(B5);
}

void keyboard_post_init_user(void) {
    // Register deferred callback for OS Detection
    defer_exec(1000, custom_os_settings, NULL);
}

// code will run on keyboard wakeup
void suspend_wakeup_init_user(void) {
    oled_on();
}

// code will run multiple times while keyboard is suspended
void suspend_power_down_user(void) {
    oled_off();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = //
    {[0] = LAYOUT(                                           //
         KC_F22, KC_F23, KC_F24, LCTL(KC_0),                    //
         KC_F19, KC_F20, KC_F21, DF(1),                      //
         KC_F16, KC_F17, KC_F18, KC_TRNS,                    //
         LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS                     //
         ),
     [1] = LAYOUT(                                //
         KC_KP_7, KC_KP_8, KC_KP_9, KC_TRNS,      //
         KC_KP_4, KC_KP_5, KC_KP_6, DF(2),        //
         KC_KP_1, KC_KP_2, KC_KP_3, KC_MEDIA_PLAY_PAUSE,      //
         KC_KP_DOT, KC_KP_0, KC_KP_ENTER, KC_MUTE //
         ),
     [2] = LAYOUT(                           //
         MS_BTN4, MS_BTN3, MS_BTN5, OS_SWITCH_KC, //
         MS_BTN1, MS_UP, MS_BTN2, DF(3),     //
         MS_LEFT, MS_DOWN, MS_RGHT, ZOOM_KC, //
         MS_WHLU, KC_LSFT, MS_WHLD, ALT_GUI_KC  //
         ),
     [3] = LAYOUT(                           //
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //
         KC_TRNS, KC_TRNS, KC_TRNS, DF(0),   //
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, //
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  //
         )};

layer_state_t layer_state_set_user(layer_state_t state) {
    oled_clear();
    return state;
}

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
