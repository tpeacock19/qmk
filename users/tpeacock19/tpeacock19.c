#include "tpeacock19.h"

#if defined(COMBO_ENABLE)
# include "keyboards/gboards/g/keymap_combo.h"
#endif

#if defined(ADAPTIVE_KEYS_ENABLE)
# include "features/adaptive_keys.h"
#endif

#if !defined(NO_ACTION_TAPPING)
const tapping_term_per_key_t tapping_term_keys[] PROGMEM = {
  { NUM_RPT, -20 }, // Shift . is ?
  { SWAPKEY, -20 }, // Shift . is ?
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
  /* Emacs specific */
  { C(KC_S), C(KC_R) },		   // scroll-{up,down}-command
  { C(KC_V), A(KC_V) },		   // scroll-{up,down}-command
  { C(A(KC_V)), S(C(A(KC_V))) },   // scroll-other-window(-down)
  { S(KC_U), KC_U },		   // undo-redo
  { KC_RIGHT, KC_LEFT },	   // scroll-{up,down}-command
  { KC_PGUP, KC_PGDN },		   // scroll-other-winow
  { C(KC_U), C(KC_D) },		   // scroll up/down (vim?)
  { A(KC_DOT), A(KC_COMMA) },	   // M-. / M-, xref forward/backward
  { KC_TAB, S(KC_TAB) },	   // tab (button) forward/backward
  { C(KC_TAB), C(S(KC_TAB)) },	   // tabs forward/backward
  { KC_WWW_FORWARD, KC_WWW_BACK }, // move 'workspaces'

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

#if defined(LAYER_LOCK_ENABLE)
  if (!process_layer_lock(keycode, record, LLOCK))
    {
      return false;
    }
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
