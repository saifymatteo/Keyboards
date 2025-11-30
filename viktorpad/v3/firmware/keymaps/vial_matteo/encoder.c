/*
 * Copyright 2025 saifymatteo <dev@saifulmashuri.com>
 */

#pragma once

#include QMK_KEYBOARD_H
#include "variables.c"

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(LCTL(MS_WHLD), LCTL(MS_WHLU)), ENCODER_CCW_CW(LCTL(KC_Z), LCTL(KC_Y)), //
           ENCODER_CCW_CW(ROTATE_CANVAS_REL, ROTATE_CANVAS_RER),                                 //
           ENCODER_CCW_CW(LCA(MS_DOWN), LCA(MS_UP))},                                            //
    [1] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS),                   //
           ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK),                             //
           ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},                                                    //
    [2] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS),                   //
           ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK),                             //
           ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},                                                    //
    [3] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS),                   //
           ENCODER_CCW_CW(ZOOM_REL, ZOOM_RER),                                                   //
           ENCODER_CCW_CW(ALT_GUI_REL, ALT_GUI_RER)},                                            //
};
