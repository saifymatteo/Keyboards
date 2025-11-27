/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "variables.c"
#include "tractyl_manuform.h"
#include "haptic.c"
#include "oled.c"

const char *translate_keycode_string(uint16_t keycode) {
    switch (keycode) {
        case RSFT_T(KC_SPC): // to fit 14 chars
            return "RSFT_T-KC_SPC";
        case RALT_T(KC_ENT): // to fit 14 chars
            return "RALT_T-KC_ENT";
        case DT_UP:
            user_config.tapping_term = g_tapping_term;
            eeconfig_update_user(user_config.raw);
            sprintf(text_keycode, "TAP: %03dms", g_tapping_term);
            return text_keycode;
        case DT_DOWN:
            user_config.tapping_term = g_tapping_term;
            eeconfig_update_user(user_config.raw);
            sprintf(text_keycode, "TAP: %03dms", g_tapping_term);
            return text_keycode;
        case UG_HUEU:
            sprintf(text_keycode, "RGB: %03d Hue", rgblight_get_hue());
            return text_keycode;
        case UG_VALU:
            sprintf(text_keycode, "RGB: %03d Val", rgblight_get_val());
            return text_keycode;
        case SNIPING_MODE:
            return "SNIPING";
        case SNIPING_MODE_TOGGLE:
            return "SNIPING_TOGG";
        case DRAGSCROLL_MODE:
            return "DRAGSCROLL";
        case DRAGSCROLL_MODE_TOGGLE:
            return "DRAGSCROLL_TG";
        default:
            return get_keycode_string(keycode);
    }
}

// Sync actions from master to slave
bool should_process_keypress(void) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_GUI_KC:
            if (record->event.pressed) {
                if (current_os == OS_WINDOWS || current_os == OS_LINUX) {
                    // Windows | Open Task View
                    tap_code16(LGUI(KC_TAB));
                } else if (current_os == OS_MACOS) {
                    // MacOS | Open Mission Control
                    tap_code(KC_MISSION_CONTROL);
                }
            }
            break;
        case ZOOM_KC:
            if (record->event.pressed) {
                if (current_os == OS_WINDOWS) {
                    // Windows | Cancel Magnifier
                    tap_code16(LGUI(KC_ESC));
                } else if (current_os == OS_LINUX) {
                    // Linux | Toggle Zoom (Gnome)
                    tap_code16(LAG(KC_8));
                } else if (current_os == OS_MACOS) {
                    // MacOS | Toggle Zoom
                    tap_code16(LCA(KC_8));
                }
            }
            break;
        case UG_VK_TOGG:
            if (record->event.pressed) {
                tap_code16(VK_TOGG);
            }
            break;
        case OS_SWITCH_KC:
            if (record->event.pressed) {
                switch (current_os) {
                    case OS_LINUX:
                        current_os = OS_WINDOWS;
                        break;
                    case OS_WINDOWS:
                        current_os = OS_MACOS;
                        break;
                    case OS_MACOS:
                        current_os = OS_IOS;
                        break;
                    case OS_IOS:
                        current_os = OS_LINUX;
                        break;
                    case OS_UNSURE:
                        current_os = OS_LINUX;
                        break;
                }
            }
            break;
    }

    // Haptic trigger, immediate vibrate with 350ms duration
    gpio_write_pin_high(GP13);
    defer_exec(350, cancel_haptic, NULL);

    if (is_keyboard_master()) {
        // Row and column swapped based on config
        // - Max row = 12
        // - Max column = 6
        uint8_t row    = record->event.key.row;
        uint8_t column = record->event.key.col;

        // Render Row and Column text
        sprintf(text_row_col, "R%02d-C%d", row, column);
        oled_set_cursor(0, 3);
        oled_write_ln(text_row_col, false);

        // Render current key name
        oled_set_cursor(8, 3);
        oled_write_ln(translate_keycode_string(keycode), false);

        // Render keyboard tap, switch back the row/column on master side
        bool is_master = row >= 6;
        row            = is_master ? row - 6 : row;
        column         = is_master ? column + 6 : column;
        for (uint8_t x = (CUBE_NUMBER * row) + GAP; x < CUBE_NUMBER * (row + 1); x++) {
            for (uint8_t y = (CUBE_NUMBER * column) + GAP; y < CUBE_NUMBER * (column + 1); y++) {
                oled_write_pixel(y, x, record->event.pressed);
            }
        }
    }

    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        refresh_rgb();

        // Update timer
        keycode_timer = timer_read();

        // Debug prints
        switch (current_os) {
            case OS_LINUX:
                printf("OS: Linux");
                break;
            case OS_WINDOWS:
                printf("OS: Windows");
                break;
            case OS_MACOS:
                printf("OS: MacOS");
                break;
            case OS_IOS:
                printf("OS: iOS");
                break;
            case OS_UNSURE:
                printf("OS: Unsure");
                break;
        }
        printf(" | "); // Separator
        printf("Key: %s", translate_keycode_string(keycode));
        printf("\n"); // New line
    }
};

// Alternative to [matrix_scan_user]. This function will called after all QMK processing is done.
void housekeeping_task_user(void) {
    // Periodically check for RGB timeout
    check_rgb_timeout();

    // ALT key hold timer
    if (is_alt_tab_active | is_alt_shift_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 500) {
            unregister_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
            is_alt_tab_active       = false;
            is_alt_shift_tab_active = false;
        }
    }
}
