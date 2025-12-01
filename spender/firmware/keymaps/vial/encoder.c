/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "variables.c"

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(ALT_GUI_REL, ALT_GUI_RER)},
    [1] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};

// // Note: disable ENCODER_MAP_ENABLE for custom encoder handling
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     // Update keycode timer
//     keycode_timer = timer_read();

//     // Set matrix for Rotary rotation
//     oled_set_cursor(0, 3);

//     if (clockwise) {
//         oled_write_ln("--RE->", false);
//         print("Encoder: clockwise\n");
//     } else {
//         oled_write_ln("<-RE--", false);
//         print("Encoder: counter clockwise\n");
//     }

//     // Set keycode for Rotary rotation
//     oled_set_cursor(8, 3);

//     switch (get_highest_layer(layer_state | default_layer_state)) {
//         case 0:
//         case 1:
//             // Alt tab / shift alt tab
//             // Windows: Alt tab (need to hold alt)
//             // MacOS: Command tab (need to hold command)
//             register_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
//             if (clockwise) {
//                 if (!is_alt_tab_active) {
//                     is_alt_tab_active = true;
//                 }
//                 alt_tab_timer = timer_read();
//                 tap_code(KC_TAB);
//                 oled_write_ln("RE_ALT_GUI+", false);
//             } else {
//                 if (!is_alt_shift_tab_active) {
//                     is_alt_shift_tab_active = true;
//                 }
//                 alt_tab_timer = timer_read();
//                 tap_code16(LSFT(KC_TAB));
//                 oled_write_ln("RE_ALT_GUI-", false);
//             }
//             break;
//         case 2:
//             // Volume up / down
//             if (clockwise) {
//                 tap_code(KC_VOLU);
//                 oled_write_ln("RE_VOL+", false);
//             } else {
//                 tap_code(KC_VOLD);
//                 oled_write_ln("RE_VOL-", false);
//             }
//             break;
//     }

//     return false;
// }
