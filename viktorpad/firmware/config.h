/*
Copyright 2025 saifymatteo <dev@saifulmashuri.com>
*/

#pragma once

// Save memory
#define LAYER_STATE_16BIT

// Dynamic Keymap
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// For OS Detection | helps with detection issue with KVM device
#define OS_DETECTION_KEYBOARD_RESET

// Tapping Toggle feature TT(layer)
#define TAPPING_TOGGLE 3

// Deferred Callbacks
#define MAX_DEFERRED_EXECUTORS 16

// Audio features
// #define AUDIO_PIN GP16 // Pin for audio output
// #define AUDIO_PWM_DRIVER PWMD0
// #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
// #define AUDIO_INIT_DELAY
// #define AUDIO_DAC_SAMPLE_MAX 4095U

// Audio Song
// #define STARTUP_SONG SONG(USSR_ANTHEM)

// Audio Clicky | Keypress Sound
// #define AUDIO_CLICKY
// #define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f

// I2C configuration (for OLED)
// #define I2C1_SCL_PIN GP27
// #define I2C1_SDA_PIN GP26

// OLED configuration
// #define SPLIT_OLED_ENABLE
// #define SPLIT_LAYER_STATE_ENABLE // For Layer state
// #define SPLIT_LED_STATE_ENABLE   // For Caps, Num Lock state
// #define OLED_BRIGHTNESS 255      // from 0 to 255
// #define OLED_DISPLAY_WIDTH 128
// #define OLED_DISPLAY_HEIGHT 32

// Encoders
// #define ENCODER_A_PINS {GP14}
// #define ENCODER_B_PINS {GP15}
// #define ENCODER_RESOLUTION 4

// Save memory
// #define NO_ACTION_ONESHOT
// #define DISABLE_LEADER
// #ifndef NO_DEBUG
// #define NO_DEBUG
// #endif // !NO_DEBUG
// #if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
// #define NO_PRINT
// #endif // !NO_PRINT
