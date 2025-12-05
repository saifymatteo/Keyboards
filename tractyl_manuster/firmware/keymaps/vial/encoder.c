/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "variables.c"
#include "tractyl_manuform.h"
#include "rgb_underglow.c"

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(ALT_GUI_REL, ALT_GUI_RER), ENCODER_CCW_CW(ZOOM_REL, ZOOM_RER)},
    [1] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [3] = {ENCODER_CCW_CW(POINTER_DEFAULT_DPI_REVERSE, POINTER_DEFAULT_DPI_FORWARD), ENCODER_CCW_CW(POINTER_SNIPING_DPI_REVERSE, POINTER_SNIPING_DPI_FORWARD)},
};

// // Note: current keyboard and RP2040 does not support ENCODER_MAP_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     bool is_master_right = index == 1; // Master (right) encoder
//     bool is_slave_left   = index == 0; // Slave (left) encoder

//     // Set matrix for Rotary rotation
//     oled_set_cursor(0, 3);

//     if (clockwise) {
//         oled_write_ln("--RE->", false);
//         if (is_slave_left) {
//             print("Slave encoder: clockwise\n");
//         } else if (is_master_right) {
//             print("Master encoder: clockwise\n");
//         }
//     } else {
//         oled_write_ln("<-RE--", false);
//         if (is_slave_left) {
//             print("Slave encoder: counter clockwise\n");
//         } else if (is_master_right) {
//             print("Master encoder: counter clockwise\n");
//         }
//     }

//     // Set keycode for Rotary rotation
//     oled_set_cursor(8, 3);

//     switch (get_highest_layer(layer_state | default_layer_state)) {
//         case 0:
//         case 1:
//             // Alt tab / shift alt tab
//             if (is_slave_left) {
//                 // Windows: Alt tab (need to hold alt)
//                 // MacOS: Command tab (need to hold command)
//                 register_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
//                 if (clockwise) {
//                     if (!is_alt_tab_active) {
//                         is_alt_tab_active = true;
//                     }
//                     alt_tab_timer = timer_read();
//                     tap_code(KC_TAB);
//                     oled_write_ln("RE_ALT_GUI+", false);
//                 } else {
//                     if (!is_alt_shift_tab_active) {
//                         is_alt_shift_tab_active = true;
//                     }
//                     alt_tab_timer = timer_read();
//                     tap_code16(LSFT(KC_TAB));
//                     oled_write_ln("RE_ALT_GUI-", false);
//                 }
//             }
//             // OS zoom in / out
//             else if (is_master_right) {
//                 // Windows: Magnifier - Windows plus/minus sign
//                 // MacOS: Zoom - Option (Alt) Command plus/minus sign | Need to enable "Use keyboard shortcuts to zoom"
//                 // Linux: Zoom (Gnome) - Super Alt plus/minus sign
//                 if (clockwise) {
//                     if (current_os == OS_WINDOWS) {
//                         tap_code16(LGUI(KC_KP_PLUS));
//                     } else if (current_os == OS_LINUX) {
//                         tap_code16(LAG(KC_KP_PLUS));
//                     } else if (current_os == OS_MACOS) {
//                         tap_code16(LCA(KC_KP_PLUS));
//                     }
//                     oled_write_ln("RE_ZOOM+", false);
//                 } else {
//                     if (current_os == OS_WINDOWS) {
//                         tap_code16(LGUI(KC_KP_MINUS));
//                     } else if (current_os == OS_LINUX) {
//                         tap_code16(LAG(KC_KP_MINUS));
//                     } else if (current_os == OS_MACOS) {
//                         tap_code16(LCA(KC_KP_MINUS));
//                     }
//                     oled_write_ln("RE_ZOOM-", false);
//                 }
//             }
//             break;
//         case 2:
//             // Volume up / down
//             if (is_slave_left) {
//                 if (clockwise) {
//                     tap_code(KC_VOLU);
//                     oled_write_ln("RE_VOL+", false);
//                 } else {
//                     tap_code(KC_VOLD);
//                     oled_write_ln("RE_VOL-", false);
//                 }
//             }
//             // Media Previous / Media Next
//             else if (is_master_right) {
//                 if (clockwise) {
//                     tap_code(KC_MEDIA_NEXT_TRACK);
//                     oled_write_ln("RE_MEDIA+", false);
//                 } else {
//                     tap_code(KC_MEDIA_PREV_TRACK);
//                     oled_write_ln("RE_MEDIA-", false);
//                 }
//             }
//             break;
//         case 3:
//             // Trackball Default DPI Forward/Reverse
//             if (is_slave_left) {
//                 if (clockwise) {
//                     // "DPI: DEF1000"
//                     charybdis_cycle_pointer_default_dpi(true);
//                 } else {
//                     charybdis_cycle_pointer_default_dpi(false);
//                 }
//                 sprintf(text_keycode, "DPI: D-%d", charybdis_get_pointer_default_dpi());
//                 oled_write_ln(text_keycode, false);
//             }
//             // Trackball Sniping DPI Forward/Reverse
//             else if (is_master_right) {
//                 if (clockwise) {
//                     charybdis_cycle_pointer_sniping_dpi(true);
//                 } else {
//                     charybdis_cycle_pointer_sniping_dpi(false);
//                 }
//                 sprintf(text_keycode, "DPI: S-%d", charybdis_get_pointer_sniping_dpi());
//                 oled_write_ln(text_keycode, false);
//             }
//             break;
//     }

//     return false;
// }

// void post_encoder_update_user(uint8_t index, bool clockwise) {
//     refresh_rgb();

//     // Update keycode timer
//     keycode_timer = timer_read();
// }
