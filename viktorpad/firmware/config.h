/*
Copyright 2025 saifymatteo <dev@saifulmashuri.com>
*/

#pragma once

// Max dynamic layer for VIAL
#define DYNAMIC_KEYMAP_LAYER_COUNT 16

// N-Key Rollover | Allow 248 keys held down at once
#define NKRO_DEFAULT_ON true

// For OS Detection | helps with detection issue with KVM device
#define OS_DETECTION_KEYBOARD_RESET

// Tapping Toggle feature TT(layer)
#define TAPPING_TOGGLE 3

// Tapping Term
#define TAPPING_TERM 160
#define DYNAMIC_TAPPING_TERM_INCREMENT 10 // in ms

// Audio features
#define AUDIO_PIN GP8 // Pin for audio output
#define AUDIO_PWM_DRIVER PWMD0
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define AUDIO_INIT_DELAY
#define AUDIO_DAC_SAMPLE_MAX 4095U

// Audio Song
#define STARTUP_SONG SONG(USSR_ANTHEM)

// Audio Clicky | Keypress Sound
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f

// RGB Light
#define WS2812_DI_PIN GP26
#define RGBLIGHT_LED_COUNT 6
#define RGBLIGHT_SLEEP
#define RGBLIGHT_TIMEOUT 180000 // 3 minutes
#define RGBLIGHT_SPLIT
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

// I2C configuration (for OLED)
#define I2C1_SCL_PIN GP15
#define I2C1_SDA_PIN GP14

// OLED configuration
#define SPLIT_OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE // For Layer state
#define SPLIT_LED_STATE_ENABLE   // For Caps, Num Lock state
#define OLED_BRIGHTNESS 255      // from 0 to 255
#define OLED_TIMEOUT 60000       // 60 seconds
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32
#define OLED_DISPLAY_128X64 // required for 128x64 displays

// Encoders
#define ENCODER_A_PINS {GP9, GP9, GP9, GP9}
#define ENCODER_B_PINS {GP10, GP11, GP12, GP13}
#define ENCODER_RESOLUTION 4

// Deferred Callbacks
#define MAX_DEFERRED_EXECUTORS 16

// Allow enter bootloader with double tap of reset button (RUN + GND)
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
