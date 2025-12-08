/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "encoder.c"
#include "oled.c"
#include "haptic.c"
#include "keycode.c"
#include "os_detection.c"
#include "tap_dance.c"

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
    user_config.raw           = 0;
    user_config.tapping_term  = TAPPING_TERM;
    user_config.haptic_enable = true;
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
        [0] = LAYOUT(                                        // Default
            KC_F22, KC_F23, KC_F24, PDF(5),                  //
            KC_F19, KC_F20, KC_F21, PDF(1),                  //
            KC_F16, KC_F17, KC_F18, LCTL(KC_0),              //
            LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS      //
            ),                                               //
        [1] = LAYOUT(                                        // Numpad
            KC_KP_7, KC_KP_8, KC_KP_9, PDF(0),               //
            KC_KP_4, KC_KP_5, KC_KP_6, PDF(2),               //
            KC_KP_1, KC_KP_2, KC_KP_3, KC_MEDIA_PLAY_PAUSE,  //
            KC_KP_DOT, KC_KP_0, KC_KP_ENTER, KC_MUTE         //
            ),                                               //
        [2] = LAYOUT(                                        // WASD
            KC_TAB, KC_W, KC_Y, PDF(1),                      //
            KC_A, KC_S, KC_D, PDF(3),                        //
            KC_LSFT, KC_X, KC_C, KC_MEDIA_PLAY_PAUSE,        //
            KC_LCTL, KC_LALT, KC_SPC, KC_MUTE                //
            ),                                               //
        [3] = LAYOUT(                                        // Mouse
            MS_BTN4, MS_BTN3, MS_BTN5, PDF(2),               //
            MS_BTN1, MS_UP, MS_BTN2, PDF(4),                 //
            MS_LEFT, MS_DOWN, MS_RGHT, ZOOM_KC,              //
            MS_WHLU, KC_LSFT, MS_WHLD, ALT_GUI_KC            //
            ),                                               //
        [4] = LAYOUT(                                        // T9 Keypad
            TD(TD_1_KC), TD(TD_2_KC), TD(TD_3_KC), PDF(3),   //
            TD(TD_4_KC), TD(TD_5_KC), TD(TD_6_KC), PDF(5),   //
            TD(TD_7_KC), TD(TD_8_KC), TD(TD_9_KC), KC_TRNS,  //
            KC_LSFT, TD(TD_0_KC), KC_ENT, KC_TRNS            //
            ),                                               //
        [5] = LAYOUT(                                        // Settings
            QK_RBT, EE_CLR, QK_BOOT, PDF(4),                 //
            AU_TOGG, OS_SWITCH_KC, HAPTIC_TOGGLE_KC, PDF(0), //
            UG_SATU, UG_HUEU, UG_NEXT, VK_TOGG,              //
            UG_SATD, UG_HUED, UG_PREV, UG_TOGG               //
            ),                                               //
};

layer_state_t layer_state_set_user(layer_state_t state) {
    oled_clear();
    return state;
}
