// Copyright 2021 Google LLC.
// SPDX-License-Identifier: Apache-2.0

#pragma once
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "core/core.h"
#if defined(CUSTOM_TAPHOLD_ENABLE)
# include "custom_taphold.h"
#endif
#include "history.h"

typedef struct
{
  uint16_t keycode;
  uint16_t swapped_keycode;
} swap_pair_t;

typedef struct
{
  uint16_t keycode;
  uint16_t swapped_keycode;
} swap_key_t;

bool key_swapped;

/* extern const swap_key_t swap_keys[]; */
#if defined CONTROLLER && CONTROLLER == atmel - dfu
extern const swap_key_t swap_keys[] PROGMEM;
extern const uint16_t swap_pairs[][2] PROGMEM;
#else
extern const swap_key_t swap_keys[];
extern const uint16_t swap_pairs[][2];
#endif
extern const uint16_t NUM_SWAP_KEYS;
extern const uint16_t NUM_SWAP_PAIRS;

/* swapped_key_t swap_key(uint16_t keycode, uint8_t modifier, keyrecord_t
 * *record); */

extern process_record_result_t process_swap_key(uint16_t keycode,
						keyrecord_t *record);

__attribute__((weak)) bool swap_key_press_user(uint16_t keycode,
					       keyrecord_t *record);

__attribute__((weak)) uint16_t find_swap_keycode_user(uint16_t keycode,
						      uint8_t mods);
