#include "tpeacock19.h"
#include "keycodes.h"


#if defined(COMBO_ENABLE)
# include "keyboards/gboards/g/keymap_combo.h"
#endif

#if defined(ADAPTIVE_KEYS_ENABLE)
# include "features/adaptive_keys.h"
#endif

#if defined(TAPPING_TERM_PER_KEY)
const tapping_term_per_key_t tapping_term_keys[] PROGMEM = {
  { NUM_RPT, -10 }, // Shift . is ?
  { SWAPKEY, -10 }, // Shift . is ?
};

const uint8_t NUM_TAPPING_TERM_KEYS
  = sizeof(tapping_term_keys) / sizeof(tapping_term_per_key_t);
#endif

#if defined(CUSTOM_SHIFT_ENABLE)
const custom_shift_key_t custom_shift_keys[] PROGMEM = {
  { LALT(KC_EXCLAIM), LALT(KC_AMPERSAND) }, // Shift . is ?
  { LALT(KC_PERCENT), C(A(KC_PERCENT)) },   // Shift . is ?
  { KC_COMM, KC_EXLM },			    // Shift , is !
  { KC_MINS, KC_EQL },			    // Shift - is =
  { KC_COLN, KC_SCLN },			    // Shift : is ;
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

__attribute__((weak)) bool
process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
  return true;
};

bool
process_record_user(uint16_t keycode, keyrecord_t *record)
{
  current_timer = timer_read();
  current_mod_state = get_mods();
  current_oneshot_mod_state = get_oneshot_mods();
  current_modifier = current_oneshot_mod_state | current_mod_state;
  current_layer = get_highest_layer(layer_state);
  isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
  isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || isOneShotLockedShift;
  isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

  if (!process_record_keymap(keycode, record))
    {
      return false;
    };

#if defined(OS_TOGGLE_ENABLE)
  switch (process_os_toggle(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(ADAPTIVE_KEYS_ENABLE)
  switch (process_adaptive_key(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(REPEAT_KEYS_ENABLE)
  switch (process_repeat_key(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(LAYER_LOCK_ENABLE)
  if (!process_layer_lock(keycode, record, LLOCK))
    {
      return false;
    }
#endif

#if defined(NUMWORD_ENABLE)
  switch (process_num_word(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(CUSTOM_TAPHOLD_ENABLE)
  switch (process_custom_taphold(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(SWAP_KEYS_ENABLE)
  switch (process_swap_key(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(CUSTOM_SHIFT_ENABLE)
  switch (process_custom_shift_keys(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(ESC_MOD_ENABLE)
  switch (process_esc_mod(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

#if defined(HISTORY_ENABLE)
  switch (process_history(keycode, record))
    {
    case PROCESS_RECORD_RETURN_TRUE:
      return true;
    case PROCESS_RECORD_RETURN_FALSE:
      return false;
    default:
      break;
    };
#endif

  last_mod_state = current_mod_state;
  last_oneshot_mod_state = current_oneshot_mod_state;

  return true;
};

__attribute__((weak)) void
post_process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
}

void
post_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  post_process_record_keymap(keycode, record);
#if defined(CUSTOM_TAPHOLD_ENABLE)
  check_disable_oneshot_layer(keycode);
#endif
}

__attribute__((weak)) layer_state_t
layer_state_set_keymap(layer_state_t state)
{
  last_layer_state = state;
  return state;
}

layer_state_t
layer_state_set_user(layer_state_t state)
{
  return layer_state_set_keymap(state);
}

__attribute__((weak)) void
matrix_scan_keymap(void)
{
}

__attribute__((weak)) void
matrix_scan_user(void)
{
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
