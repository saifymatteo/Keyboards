# Bootloader
BOOTLOADER = caterina

# Driver
I2C_DRIVER_REQUIRED = yes

# OS Detection
OS_DETECTION_ENABLE = yes

# Deferred Callback
DEFERRED_EXEC_ENABLE = yes

# Audio
AUDIO_ENABLE = yes
AUDIO_DRIVER = pwm_hardware

# Encoders
ENCODER_ENABLE = yes

# OLED
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c

# WPM
WPM_ENABLE = yes

# Debug
CONSOLE_ENABLE = yes
KEYCODE_STRING_ENABLE = yes
