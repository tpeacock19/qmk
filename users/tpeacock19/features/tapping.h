#pragma once
#include QMK_KEYBOARD_H
#include "core/core.h"

typedef struct
{
  uint16_t keycode;
  int tapping_term;
} tapping_term_per_key_t;

extern const tapping_term_per_key_t tapping_term_keys[] PROGMEM;
extern const uint8_t NUM_TAPPING_TERM_KEYS;

extern process_record_result_t process_tapping_term_keys(uint16_t keycode,
                                                         keyrecord_t *record);
