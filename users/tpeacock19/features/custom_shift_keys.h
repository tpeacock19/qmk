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

/* typedef struct */
/* { */
/*   uint16_t keycode; */
/*   uint8_t modifier; */
/* } shifted_key_t; */

/* struct shifted_key; */

/* extern const custom_shift_key_t custom_shift_keys[]; */
extern const custom_shift_key_t custom_shift_keys[] PROGMEM;
extern const uint8_t NUM_CUSTOM_SHIFT_KEYS;

bool key_shifted;

extern bool custom_shift_key(uint16_t keycode, keyrecord_t *record);

extern process_record_result_t process_custom_shift_keys(uint16_t keycode,
                                                         keyrecord_t *record);
