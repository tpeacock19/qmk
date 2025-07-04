// Copyright 2021 Google LLC.
// SPDX-License-Identifier: Apache-2.0

#pragma once
#include QMK_KEYBOARD_H
#include "core/core.h"
#include "history.h"
#if defined(CUSTOM_TAPHOLD_ENABLE)
# include "custom_taphold.h"
#endif

typedef struct
{
  uint16_t keycode;
  uint16_t shifted_keycode;
} custom_shift_key_t;

# if defined CONTROLLER && CONTROLLER==atmel-dfu
extern const custom_shift_key_t custom_shift_keys[] PROGMEM;
#else
extern const custom_shift_key_t custom_shift_keys[];
#endif
extern const uint8_t NUM_CUSTOM_SHIFT_KEYS;

extern uint16_t shifted_key;

extern bool custom_shift_key(uint16_t keycode, keyrecord_t *record);

extern process_record_result_t process_custom_shift_keys(uint16_t keycode,
                                                         keyrecord_t *record);
