/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "encoder.c"
#include "oled.c"
#include "haptic.c"
#include "keycode.c"
#include "os_detection.c"

void keyboard_pre_init_user(void) {
    // Haptic motor PIN
    gpio_set_pin_output(GP27);
}

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
    rgblight_wakeup();
    oled_on();
}

// code will run multiple times while keyboard is suspended
void suspend_power_down_user(void) {
    rgblight_suspend();
    oled_off();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = //
    {
        [0] = LAYOUT(                                       //
            KC_F22, KC_F23, KC_F24, LCTL(KC_0),             //
            KC_F19, KC_F20, KC_F21, PDF(1),                 //
            KC_F16, KC_F17, KC_F18, KC_TRNS,                //
            LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS     //
            ),                                              //
        [1] = LAYOUT(                                       //
            KC_KP_7, KC_KP_8, KC_KP_9, KC_TRNS,             //
            KC_KP_4, KC_KP_5, KC_KP_6, PDF(2),              //
            KC_KP_1, KC_KP_2, KC_KP_3, KC_MEDIA_PLAY_PAUSE, //
            KC_KP_DOT, KC_KP_0, KC_KP_ENTER, KC_MUTE        //
            ),                                              //
        [2] = LAYOUT(                                       //
            KC_TAB, KC_W, KC_Y, KC_TRNS,                    //
            KC_A, KC_S, KC_D, PDF(3),                       //
            KC_LSFT, KC_X, KC_C, KC_MEDIA_PLAY_PAUSE,       //
            KC_LCTL, KC_LALT, KC_SPC, KC_MUTE               //
            ),                                              //
        [3] = LAYOUT(                                       //
            MS_BTN4, MS_BTN3, MS_BTN5, OS_SWITCH_KC,        //
            MS_BTN1, MS_UP, MS_BTN2, PDF(4),                //
            MS_LEFT, MS_DOWN, MS_RGHT, ZOOM_KC,             //
            MS_WHLU, KC_LSFT, MS_WHLD, ALT_GUI_KC           //
            ),                                              //
        [4] = LAYOUT(                                       //
            TD_1_KC, TD_2_KC, TD_3_KC, KC_TRNS,             //
            TD_4_KC, TD_5_KC, TD_6_KC, PDF(5),              //
            TD_7_KC, TD_8_KC, TD_9_KC, KC_TRNS,             //
            KC_LSFT, TD_0_KC, KC_ENT, KC_TRNS               //
            ),                                              //
        [5] = LAYOUT(                                       //
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             //
            KC_TRNS, KC_TRNS, KC_TRNS, PDF(0),              //
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             //
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS              //
            ),                                              //
};

layer_state_t layer_state_set_user(layer_state_t state) {
    oled_clear();
    return state;
}
