/*
Copyright 2025 saifymatteo <dev@saifulmashuri.com>
*/

#pragma once

// RGB Light
#define WS2812_DI_PIN F4
#define RGBLIGHT_LED_COUNT 6

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
