/*
Copyright 2025 saifymatteo <dev@saifulmashuri.com>
*/

#pragma once

#define MASTER_RIGHT

// Remnant from USB C Pro Micro
#define SPLIT_USB_TIMEOUT 2500
#define SPLIT_WATCHDOG_ENABLE

// For OS Detection | helps with detection issue with KVM device
#define OS_DETECTION_KEYBOARD_RESET

// Tapping Toggle feature TT(layer)
#define TAPPING_TOGGLE 3

// Tapping Term
#define TAPPING_TERM 160
#define DYNAMIC_TAPPING_TERM_INCREMENT 10 // in ms

// Audio features
#define AUDIO_PIN GP16 // Pin for audio output
#define AUDIO_PWM_DRIVER PWMD0
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define AUDIO_INIT_DELAY
#define AUDIO_DAC_SAMPLE_MAX 4095U

// Audio Song
#define STARTUP_SONG SONG(USSR_ANTHEM)

// Audio Clicky | Keypress Sound
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f

// Serial using USART | Half Duplex
#define SERIAL_USART_TX_PIN GP12

// I2C configuration (for OLED)
#define I2C1_SCL_PIN GP27
#define I2C1_SDA_PIN GP26

// OLED configuration
#define SPLIT_OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE // For Layer state
#define SPLIT_LED_STATE_ENABLE   // For Caps, Num Lock state
#define OLED_BRIGHTNESS 255      // from 0 to 255
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32

// Encoders
#define ENCODER_A_PINS {GP14}
#define ENCODER_B_PINS {GP15}
#define ENCODER_RESOLUTION 4

// Deferred Callbacks
#define MAX_DEFERRED_EXECUTORS 16

// Trackball | PMW3360
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP19
#define POINTING_DEVICE_CS_PIN GP21

// Trackball settings
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 1000    // The minimum sensitivity in default mode.
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200 // Change of the sensitivity in cursor mode each time POINTER_DEFAULT_DPI_FORWARD/ REVERSE is pressed.
#define CHARYBDIS_MINIMUM_SNIPING_DPI 400     // The sensitivity in sniping mode.
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100 // Change of the pointers sensitivity in sniping mode each time POINTER_SNIPING_DPI_FORWARD/ REVERSE is pressed.
#define CHARYBDIS_DRAGSCROLL_DPI 100          // The sensitivity in dragscroll mode.
// #define CHARYBDIS_DRAGSCROLL_REVERSE_X // Reverse the scroll direction in dragscroll mode for the x / y axis.
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y // Reverse the scroll direction in dragscroll mode for the x / y axis.
// #define CHARYBDIS_CARRET_BUFFER 40 // The sensitivity in carret mode. Higher number means less sensitive.
// #define CHARYBDIS_CARRET_REVERSE_X / _Y // Reverse the direction in carret mode for the x / y axis.
// #define CHARYBDIS_POINTER_ACCELERATION_ENABLE // Enable pointer acceleration.
// #define CHARYBDIS_POINTER_ACCELERATION_FACTOR 24 // Amount of pointer acceleration.
// #define CUSTOM_FN_RIGHT / CUSTOM_FN_LEFT / _UP / _DOWN // Here you can define the keycode that gets executed in custom mode when the trackball is rotated to the right / left / up / down.
#define CHARYBDIS_CONFIG_SYNC // If you want/need to enable syncing of the charybdis config, such as to read the sniping or drag scroll modes on the other half (such as for displaying the status via rgb matrix, or added on screens, or what not), you can enabled this.

// Allow enter bootloader with double tap of reset button (RUN + GND)
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
