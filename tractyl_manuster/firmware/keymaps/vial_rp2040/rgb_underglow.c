/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H

// Translate the mode number to human readable text. Max 14 `chars`.
// See: `quantum/rgblight/rgblight.h:25`.
const char *translate_rgb_mode_string(uint8_t mode) {
    switch (mode) {
        case 1:
            return "Static Light";
        case 2:
            return "Breathing";
        case 3:
            return "Breathing 1";
        case 4:
            return "Breathing 2";
        case 5:
            return "Breathing 3";
        case 6:
            return "RB Mood";
        case 7:
            return "RB Mood 1";
        case 8:
            return "RB Mood 2";
        case 9:
            return "RB Swirl";
        case 10:
            return "RB Swirl 1";
        case 11:
            return "RB Swirl 2";
        case 12:
            return "RB Swirl 3";
        case 13:
            return "RB Swirl 4";
        case 14:
            return "RB Swirl 5";
        case 15:
            return "Snake";
        case 16:
            return "Snake 1";
        case 17:
            return "Snake 2";
        case 18:
            return "Snake 3";
        case 19:
            return "Snake 4";
        case 20:
            return "Snake 5";
        case 21:
            return "Knight";
        case 22:
            return "Knight 1";
        case 23:
            return "Knight 2";
        case 24:
            return "Christmas";
        case 25:
            return "Gradient";
        case 26:
            return "Gradient 1";
        case 27:
            return "Gradient 2";
        case 28:
            return "Gradient 3";
        case 29:
            return "Gradient 4";
        case 30:
            return "Gradient 5";
        case 31:
            return "Gradient 6";
        case 32:
            return "Gradient 7";
        case 33:
            return "Gradient 8";
        case 34:
            return "Gradient 9";
        case 35:
            return "RGB Test";
        case 36:
            return "Alternating";
        case 37:
            return "Twinkle";
        case 38:
            return "Twinkle 1";
        case 39:
            return "Twinkle 2";
        case 40:
            return "Twinkle 3";
        case 41:
            return "Twinkle 4";
        case 42:
            return "Twinkle 5";
        default:
            return "Undefined";
    }
}
