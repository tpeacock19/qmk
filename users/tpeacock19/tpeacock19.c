#include "tpeacock19.h"

#if defined(COMBO_ENABLE)
# include "keyboards/gboards/g/keymap_combo.h"
#endif

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
const combo_term_per_combo_t combo_terms[] PROGMEM = {
  { OS_MODS, KC_NO, 10 },
  { MOD_SPC, KC_NO, 10 },
  { MOD_T, KC_NO, 10 },
};

const uint8_t NUM_COMBO_TERMS
  = sizeof(combo_terms) / sizeof(combo_term_per_combo_t);
#endif

#if defined(TAPPING_TERM_PER_KEY)
const tapping_term_per_key_t tapping_term_keys[] PROGMEM = {
  { GUI_D, 50 },    // Shift . is ?
  { GUI_H, 50 },    // Shift . is ?
  { NUM_RPT, -10 }, // Shift . is ?
  { SWAPKEY, -10 }, // Shift . is ?
};

const uint8_t NUM_TAPPING_TERM_KEYS
  = sizeof(tapping_term_keys) / sizeof(tapping_term_per_key_t);
#endif

#if defined(CUSTOM_SHIFT_ENABLE)
const custom_shift_key_t custom_shift_keys[] PROGMEM = {
  /* Emacs */
  { KC_COLON, KC_SEMICOLON },		    // Shift : is ;
  { KC_SEMICOLON, KC_EXCLAIM },		    // Shift : is ;
  { LALT(KC_EXCLAIM), LALT(KC_AMPERSAND) }, // query-replace{-regexp}
  { LALT(KC_PERCENT), C(A(KC_PERCENT)) },   // Shift . is ?
};
const uint8_t NUM_CUSTOM_SHIFT_KEYS
  = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
#endif

#if defined(SWAP_KEYS_ENABLE)
const swap_key_t swap_keys[] PROGMEM = {
  { KC_TAB, S(KC_TAB) },       // tab (button) forward/backward
  { C(KC_TAB), C(S(KC_TAB)) }, // tabs forward/backward
  /* Emacs */
  { C(KC_F), C(KC_B) },		  // {forward,backward}-char
  { A(KC_F), A(KC_B) },		  // {forward,backward}-word
  { C(A(KC_N)), C(A(KC_P)) },	  // {forward,backward}-list
  { C(A(KC_UP)), C(A(KC_DOWN)) }, // {backward-up,down}-list
  { C(A(KC_A)), C(A(KC_E)) },	  // {beginning,end}-of-defun
  { C(A(KC_F)), C(A(KC_B)) },	  // {forward,backward}-sexp
  { C(KC_S), C(KC_R) },		  // isearch-{forward,backward}
  { C(KC_I), C(KC_O) },		  // isearch-{forward,backward}
  { C(KC_V), A(KC_V) },		  // scroll-{up,down}-command
  { C(A(KC_V)), S(C(A(KC_V))) },  // scroll-other-window(-down)
  { S(KC_U), KC_U },		  // undo-redo
  { C(KC_RIGHT), C(KC_LEFT) },	  // {right,left}-word
  { KC_RIGHT, KC_LEFT },	  // scroll-{up,down}-command
  { KC_PGUP, KC_PGDN },		  // page-{up,down}
  { KC_GT, KC_LT },		  // slurp/barf
  { C(KC_GT), C(KC_LT) },	  // scroll-other-winow
  { C(KC_U), C(KC_D) },		  // scroll up/down (vim?)
  { A(KC_DOT), A(KC_COMMA) },	  // M-. / M-, xref forward/backward
  /* Media */
  { KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN },   // vol {up,down}
  { KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN }, // brightness {up,down}
  { KC_WWW_FORWARD, KC_WWW_BACK },	    // move desktops (linux)
  /* Windows */
  { C(G(KC_RIGHT)), C(G(KC_LEFT)) }, // move virtual desktops (windows)
};
const uint16_t NUM_SWAP_KEYS = sizeof(swap_keys) / sizeof(swap_key_t);
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
