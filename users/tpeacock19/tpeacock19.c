#include "tpeacock19.h"

/* #if defined(ACHORDION_ENABLE) */
/* # include "features/achordion.h" */
/* bool */
/* achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, */
/*                 uint16_t other_keycode, keyrecord_t *other_record) */
/* { */
/*   return achordion_opposite_hands(tap_hold_record, other_record); */
/* } */
/* #endif */

#if defined(COMBO_TERM_PER_COMBO)
# if defined CONTROLLER && CONTROLLER == atmel-dfu
const combo_term_per_combo_t combo_terms[] PROGMEM = {
# else
const combo_term_per_combo_t combo_terms[] = {
# endif

  { OS_MODS, KC_NO, -100 },
  { MOD_SPC, KC_NO, -100 },
  { MOD_T, KC_NO, 10 },
};
  
const uint8_t NUM_COMBO_TERMS
  = sizeof(combo_terms) / sizeof(combo_term_per_combo_t);
#endif

#if defined(TAPPING_TERM_PER_KEY)
# if defined CONTROLLER && CONTROLLER == atmel-dfu
const tapping_term_per_key_t tapping_term_keys[] PROGMEM = {
# else
const tapping_term_per_key_t tapping_term_keys[] = {
# endif
  { GUI_D, 50 },    // Shift . is ?
  { GUI_H, 50 },    // Shift . is ?
  { NUM_RPT, -10 }, // Shift . is ?
  { SYM_RPT, -10 }, // Shift . is ?
  { SWAPKEY, -10 }, // Shift . is ?
};

const uint8_t NUM_TAPPING_TERM_KEYS
  = sizeof(tapping_term_keys) / sizeof(tapping_term_per_key_t);
#endif

#if defined(CUSTOM_SHIFT_ENABLE)
# if defined CONTROLLER && CONTROLLER == atmel-dfu
const custom_shift_key_t custom_shift_keys[] PROGMEM = {
# else
const custom_shift_key_t custom_shift_keys[] = {
# endif
  /* Emacs */
  { KC_COLON, KC_SEMICOLON },		    // Shift : is ;
  { KC_SEMICOLON, KC_EXCLAIM },		    // Shift : is ;
  { LALT(KC_EXCLAIM), LALT(KC_AMPERSAND) }, // query-replace{-regexp}
  { LALT(KC_PERCENT), C(A(KC_PERCENT)) },   // Shift . is ?
};
const uint8_t NUM_CUSTOM_SHIFT_KEYS
  = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
#endif

__attribute__((weak)) layer_state_t
layer_state_set_keymap(layer_state_t state)
{
  last_layer_state = state;
  return state;
}

layer_state_t
layer_state_set_user(layer_state_t state)
{
  /* uprintf("KBHLayer%u\n", get_highest_layer(state)); */
  return layer_state_set_keymap(state);
}

__attribute__((weak)) void
matrix_scan_keymap(void)
{
}

__attribute__((weak)) void
matrix_scan_user(void)
{
#if defined(ACHORDION_ENABLE)
  achordion_task();
#endif
#if defined(CUSTOM_TAPHOLD_ENABLE)
  check_oneshot_timeout();
#endif
#if defined(LAYER_LOCK_ENABLE)
  layer_lock_task();
#endif
#if defined(HISTORY_ENABLE)
  history_matrix_scan_user();
#endif
  matrix_scan_keymap();
}
