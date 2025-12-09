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
        case RSFT_T(KC_SPC): // to fit 14 chars
            return "RSFT_T-KC_SPC";
        case RALT_T(KC_ENT): // to fit 14 chars
            return "RALT_T-KC_ENT";
        case HAPTIC_TOGGLE_KC:
            sprintf(text_keycode, "HAPTIC: %d", user_config.haptic_enable);
            return text_keycode;
        case DT_UP:
        case DT_DOWN:
            sprintf(text_keycode, "TAP: %03dms", g_tapping_term);
            return text_keycode;
        case UG_HUEU:
        case UG_HUED:
            sprintf(text_keycode, "RGB: %03d Hue", rgblight_get_hue());
            return text_keycode;
        case UG_VALU:
        case UG_VALD:
            sprintf(text_keycode, "RGB: %03d Val", rgblight_get_val());
            return text_keycode;
        case UG_SPDU:
        case UG_SPDD:
            sprintf(text_keycode, "RGB: %03d Spd", rgblight_get_speed());
            return text_keycode;
        case UG_SATU:
        case UG_SATD:
            sprintf(text_keycode, "RGB: %03d Sat", rgblight_get_sat());
            return text_keycode;
        case AU_TOGG:
            sprintf(text_keycode, "Audio: %d", audio_is_on());
            return text_keycode;
        default:
            return get_keycode_string(keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);

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
                break;
            case ALT_GUI_REL: // Shift alt tab
                register_code(current_os == OS_MACOS ? KC_LEFT_CTRL : KC_LALT);
                if (!is_alt_shift_tab_active) {
                    is_alt_shift_tab_active = true;
                }
                alt_tab_timer = timer_read();
                tap_code16(LSFT(KC_TAB));
                break;
            case ZOOM_KC:
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
                break;
            case ZOOM_REL: // OS zoom out
                if (current_os == OS_WINDOWS) {
                    tap_code16(LGUI(KC_KP_MINUS));
                } else if (current_os == OS_LINUX) {
                    tap_code16(LAG(KC_KP_MINUS));
                } else if (current_os == OS_MACOS) {
                    tap_code16(LCA(KC_KP_MINUS));
                }
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
            case HAPTIC_TOGGLE_KC:
                if (user_config.haptic_enable) {
                    user_config.haptic_enable = false;
                } else {
                    user_config.haptic_enable = true;
                }
                eeconfig_update_user(user_config.raw);
                break;
            case DT_UP:
            case DT_DOWN:
                user_config.tapping_term = g_tapping_term;
                eeconfig_update_user(user_config.raw);
                break;
            case ROTATE_CANVAS_RER:
                register_code(KC_SPACE);
                register_code(KC_LEFT_ALT);
                register_code(MS_BTN1);
                register_code(MS_RGHT);
                break;
            case ROTATE_CANVAS_REL:
                register_code(KC_SPACE);
                register_code(KC_LEFT_ALT);
                register_code(MS_BTN1);
                register_code(MS_LEFT);
                break;
            case BRUSH_SIZE_RER:
                register_code(MS_RGHT);
                tap_code16(LCA(MS_BTN1));
                break;
            case BRUSH_SIZE_REL:
                register_code(MS_LEFT);
                tap_code16(LCA(MS_BTN1));
                break;
        }
    }

    // Haptic trigger, immediate vibrate with 350ms duration
    if (user_config.haptic_enable) {
        gpio_write_pin_high(GP27);
        defer_exec(350, cancel_haptic, NULL);
    }

    if (current_layer == 4) {
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
        refresh_rgb();
    }

    // Cannot put under `record->event.pressed` as the
    // [translate_keycode_string] will trigger multiple times

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

    // Clear up key register
    switch (keycode) {
        case ROTATE_CANVAS_RER:
            unregister_code(KC_SPACE);
            unregister_code(KC_LEFT_ALT);
            unregister_code(MS_BTN1);
            unregister_code(MS_RGHT);
            break;
        case ROTATE_CANVAS_REL:
            unregister_code(KC_SPACE);
            unregister_code(KC_LEFT_ALT);
            unregister_code(MS_BTN1);
            unregister_code(MS_LEFT);
            break;
        case BRUSH_SIZE_RER:
            unregister_code(MS_RGHT);
            break;
        case BRUSH_SIZE_REL:
            unregister_code(MS_LEFT);
            break;
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
