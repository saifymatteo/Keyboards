/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "variables.c"
#include "oled.c"

const char *translate_keycode_string(uint16_t keycode) {
    switch (keycode) {
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
        case LALT_T(KC_ENT): // to fit 14 chars
            return "LALT_T-KC_ENT";
        case RALT_T(KC_ENT): // to fit 14 chars
            return "RALT_T-KC_ENT";
        default:
            return get_keycode_string(keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case ALT_GUI_KC:
                if (current_os == OS_WINDOWS || current_os == OS_LINUX) {
                    // Windows | Open Task View
                    tap_code16(LGUI(KC_TAB));
                } else if (current_os == OS_MACOS) {
                    // MacOS | Open Mission Control
                    tap_code(KC_MISSION_CONTROL);
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
            case ALT_GUI_REL: // shift alt tab
                register_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
                if (!is_alt_shift_tab_active) {
                    is_alt_shift_tab_active = true;
                }
                alt_tab_timer = timer_read();
                tap_code16(LSFT(KC_TAB));
                oled_write_ln("RE_ALT_GUI-", false);
                break;
            case OS_SWITCH_KC:
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
                break;
        }
    }

    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);
    if (current_layer != 1) {
        uint8_t row    = record->event.key.row;
        uint8_t column = record->event.key.col;

        // Render Row and Column text
        sprintf(text_row_col, "R%02d-C%d", row, column);
        oled_set_cursor(0, 3);
        oled_write_ln(text_row_col, false);

        // Render current key name
        oled_set_cursor(8, 3);
        oled_write_ln(translate_keycode_string(keycode), false);
    }

    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
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
    // ALT key hold timer
    if (is_alt_tab_active | is_alt_shift_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 500) {
            unregister_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
            is_alt_tab_active       = false;
            is_alt_shift_tab_active = false;
        }
    }
}
