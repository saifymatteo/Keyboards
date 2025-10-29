/*
Copyright 2025 saifymatteo <dev@saifulmashuri.com>
*/

#pragma once

// Dynamic Keymap
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

// For OS Detection | helps with detection issue with KVM device
#define OS_DETECTION_KEYBOARD_RESET

// I2C configuration (for OLED)
#define I2C1_SCL_PIN D0
#define I2C1_SDA_PIN D1

// OLED configuration
#define OLED_BRIGHTNESS 255 // from 0 to 255
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 64

// Encoders
#define ENCODER_A_PINS {B6, B6, B6}
#define ENCODER_B_PINS {B1, B3, B2}
#define ENCODER_RESOLUTION 4

// Save memory
#define LAYER_STATE_8BIT
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define DISABLE_LEADER
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
