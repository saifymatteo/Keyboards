/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H

uint32_t cancel_haptic(uint32_t trigger_time, void *cb_arg) {
    gpio_write_pin_low(GP28);
    return 0;
}
