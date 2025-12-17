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
    // Update the haptic if true
    if (user_config.haptic_enable) {
        user_config.haptic_enable = true;
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
            LCTL(KC_S), KC_B, KC_E, PDF(4),                  //
            KC_M, KC_V, KC_L, PDF(1),                        //
            LCTL(KC_T), KC_ENT, LCTL(KC_D), LCTL(KC_0),      //
            LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_G)   //
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
        [3] = LAYOUT(                                        // Navigation
            MS_BTN4, MS_BTN3, MS_BTN5, PDF(2),               //
            MS_BTN1, MS_UP, MS_BTN2, PDF(4),                 //
            MS_LEFT, MS_DOWN, MS_RGHT, ZOOM_KC,              //
            MS_WHLU, KC_LSFT, MS_WHLD, ALT_GUI_KC            //
            ),                                               //
        [4] = LAYOUT(                                        // Settings
            QK_RBT, EE_CLR, QK_BOOT, PDF(3),                 //
            AU_TOGG, OS_SWITCH_KC, HAPTIC_TOGGLE_KC, PDF(0), //
            UG_SATU, UG_HUEU, UG_NEXT, VK_TOGG,              //
            UG_SATD, UG_HUED, UG_PREV, UG_TOGG               //
            ),                                               //
};

layer_state_t layer_state_set_user(layer_state_t state) {
    oled_clear();
    return state;
}
