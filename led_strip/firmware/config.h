/*
Copyright 2025 saifymatteo <dev@saifulmashuri.com>
*/

#pragma once

// Dynamic Keymap
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// N-Key Rollover | Allow 248 keys held down at once
#define NKRO_DEFAULT_ON true

// Tapping Toggle feature TT(layer)
#define TAPPING_TOGGLE 3

// Tapping Term
#define TAPPING_TERM 160

// RGB Light
#define RGBLIGHT_TIMEOUT 180000 // 3 minutes
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL + 5 // Last Rainbow Swirl mode
#define RGBLIGHT_DEFAULT_VAL 136                              // 8th-step of 17 out of 255

// RGB Light Modes
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE
