# Bootloader
BOOTLOADER = rp2040

# Driver
SERIAL_DRIVER = vendor
I2C_DRIVER_REQUIRED = yes
SPI_DRIVER_REQUIRED = yes

# Split keyboard
SPLIT_KEYBOARD = yes

# OS Detection
OS_DETECTION_ENABLE = yes

# Deferred Callback
DEFERRED_EXEC_ENABLE = yes

# Audio
AUDIO_ENABLE = yes
AUDIO_DRIVER = pwm_hardware

# Backlight LED
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor
VELOCIKEY_ENABLE = yes

# Encoders
ENCODER_ENABLE = yes

# N~Key rollover
NKRO_ENABLE = yes

# Mouse Key
MOUSEKEY_ENABLE = yes

# System, Audio control keys
EXTRAKEY_ENABLE = yes

# OLED
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c

# WPM
WPM_ENABLE = yes

# Tapping Term
DYNAMIC_TAPPING_TERM_ENABLE = yes

# Debug
CONSOLE_ENABLE = yes
KEYCODE_STRING_ENABLE = yes
