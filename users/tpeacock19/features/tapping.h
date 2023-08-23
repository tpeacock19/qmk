#pragma once
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "core/core.h"

#if defined(TAPPING_TERM_PER_KEY)
typedef struct
{
  uint16_t keycode;
  int tapping_term;
} tapping_term_per_key_t;

extern const tapping_term_per_key_t tapping_term_keys[] PROGMEM;
extern const uint8_t NUM_TAPPING_TERM_KEYS;

/* extern uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record); */
#endif


#if defined(TAPPING_FORCE_HOLD_PER_KEY)
extern bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record);
#endif

#if defined(QUICK_TAP_TERM)
extern uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record);
#endif

#if defined(PERMISSIVE_HOLD_PER_KEY)
extern bool get_permissive_hold(uint16_t keycode, keyrecord_t *record);
#endif

#if defined(HOLD_ON_OTHER_KEY_PRESS_PER_KEY)
extern bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record);
#endif
