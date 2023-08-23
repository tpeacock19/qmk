#pragma once
#include QMK_KEYBOARD_H
#include "core/core.h"

#if defined(COMBO_TERM_PER_COMBO)
typedef struct
{
  uint16_t key1;
  uint16_t key2;
  int combo_term;
} combo_term_per_combo_t;

extern const combo_term_per_combo_t combo_terms[] PROGMEM;
extern const uint8_t NUM_COMBO_TERMS;

extern uint16_t get_combo_term(uint16_t index, combo_t *combo);
#endif


#if defined(COMBO_MUST_HOLD_PER_COMBO)
extern bool get_combo_must_hold(uint16_t keycode, combo_t *combo);
#endif

#if defined(COMBO_MUST_TAP_PER_COMBO)
extern bool get_combo_must_tap(uint16_t keycode, combo_t *combo);
#endif
