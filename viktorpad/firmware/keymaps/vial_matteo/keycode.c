/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "variables.c"
#include "oled.c"
#include "haptic.c"

const char *translate_keycode_string(uint16_t keycode) {
    switch (keycode) {
        // case RSFT_T(KC_SPC): // to fit 14 chars
        //     return "RSFT_T-KC_SPC";
        // case RALT_T(KC_ENT): // to fit 14 chars
        //     return "RALT_T-KC_ENT";
        default:
            return get_keycode_string(keycode);
    }
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
        case ALT_GUI_RER: // Alt tab
            // Windows: Alt tab (need to hold alt)
            // MacOS: Command tab (need to hold command)
            register_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
            }
            alt_tab_timer = timer_read();
            tap_code(KC_TAB);
            oled_write_ln("RE_ALT_GUI+", false);
            break;
        case ALT_GUI_REL: // Shift alt tab
            register_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
            if (!is_alt_shift_tab_active) {
                is_alt_shift_tab_active = true;
            }
            alt_tab_timer = timer_read();
            tap_code16(LSFT(KC_TAB));
            oled_write_ln("RE_ALT_GUI-", false);
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
        case ZOOM_RER: // OS zoom in
            // Windows: Magnifier - Windows plus/minus sign
            // MacOS: Zoom - Option (Alt) Command plus/minus sign | Need to enable "Use keyboard shortcuts to zoom"
            // Linux: Zoom (Gnome) - Super Alt plus/minus sign
            if (current_os == OS_WINDOWS) {
                tap_code16(LGUI(KC_KP_PLUS));
            } else if (current_os == OS_LINUX) {
                tap_code16(LAG(KC_KP_PLUS));
            } else if (current_os == OS_MACOS) {
                tap_code16(LCA(KC_KP_PLUS));
            }
            oled_write_ln("RE_ZOOM+", false);
            break;
        case ZOOM_REL: // OS zoom out
            if (current_os == OS_WINDOWS) {
                tap_code16(LGUI(KC_KP_MINUS));
            } else if (current_os == OS_LINUX) {
                tap_code16(LAG(KC_KP_MINUS));
            } else if (current_os == OS_MACOS) {
                tap_code16(LCA(KC_KP_MINUS));
            }
            oled_write_ln("RE_ZOOM-", false);
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
        case ROTATE_CANVAS_RER:
            if (record->event.pressed) {
                tap_code(KC_SPACE);
                tap_code(KC_LEFT_ALT);
                tap_code(MS_RGHT);
            }
            break;
        case ROTATE_CANVAS_REL:
            if (record->event.pressed) {
                tap_code(KC_SPACE);
                tap_code(KC_LEFT_ALT);
                tap_code(MS_LEFT);
            }
            break;
    }

    // Haptic trigger, immediate vibrate with 350ms duration
    gpio_write_pin_high(B5);
    defer_exec(350, cancel_haptic, NULL);

    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);
    if (current_layer != 1) {
        // Row and column swapped based on config
        // - Max row = 5 + 1 encoder row
        // - Max column = 12
        uint8_t row    = record->event.key.row;
        uint8_t column = record->event.key.col;

        // Render Row and Column text
        oled_set_cursor(0, 3);
        oled_write_P(PSTR("R"), false);
        oled_write(get_u8_str(row, '0'), false);
        oled_write_P(PSTR("-C"), false);
        oled_write_ln(get_u8_str(column, ' '), false);

        // Render current key name
        oled_set_cursor(8, 3);
        oled_write_ln(translate_keycode_string(keycode), false);

        // Render keyboard tap, switch back the row/column on master side
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
        // Update timer
        keycode_timer = timer_read();
    }
};

// Alternative to [matrix_scan_user]. This function will called after all QMK processing is done.
void housekeeping_task_user(void) {
    // ALT key hold timer
    if (is_alt_tab_active | is_alt_shift_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 500) {
            unregister_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
            is_alt_tab_active       = false;
            is_alt_shift_tab_active = false;
        }
    }
};
