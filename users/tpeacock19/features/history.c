#include "history.h"

extern void *memset(void *, int, size_t);
extern void *memmove(void *, const void *, size_t);

extern bool key_repeated;
extern bool key_swapped;

history_key_t history[HISTORY_SIZE] = {};

static uint16_t deadline = 0;

void
set_history(uint16_t keycode, keyrecord_t record, uint8_t mods)
{
  shift_history_keys();
  /* keyrecord_t hkey = *record; */
  /* hkey.keycode = keycode; */
  record.keycode = keycode;
  get_history(1)->modifier = mods;
  get_history(1)->record = record;
}
history_key_t *
get_history(int n)
{
  return &history[HISTORY_SIZE - n];
};

/* Helper function to tap basic keycode and current modifiers. Current modifiers
 * defined by an early call to get_mods() and get_oneshot_mods() in
 * process_record_user */
void
tap_code_history(uint8_t keycode, keyrecord_t *record)
{
  register_mods(current_modifier);
  tap_code(keycode);
  unregister_mods(current_modifier);
  set_history(keycode, *record, current_modifier);
}

void
tap_code_history16(uint16_t keycode, keyrecord_t *record)
{
  uint8_t current_mods = current_modifier | extract_mods_from(keycode);
  register_mods(current_mods);
  tap_code16(keycode);
  unregister_mods(current_mods);
  set_history(keycode, *record, current_mods);
}

void
clear_history_keys(void)
{
  memset(&history, 0, sizeof(history));
}

void
clear_history_index(int n)
{
  memset(&history[n - 1], 0, sizeof(history[n - 1]));
}

void
shift_history_keys(void)
{
  memmove(&history[0], &history[1], (HISTORY_SIZE - 1) * sizeof(*history));
}

// Handles one event. Returns true if the key was appended to `history`.
process_record_result_t
process_history(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    case QK_TO ... QK_TO_MAX:
    case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
    case QK_MOMENTARY ... QK_MOMENTARY_MAX:
    case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
    case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
    case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
    case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
    case QK_TRI_LAYER_LOWER:
    case QK_TRI_LAYER_UPPER:
      return PROCESS_RECORD_CONTINUE;
    default:
      /* Handle Mod/Layer Tap keys. Extract the keycode when tapped, skip when
         being held. */
#ifndef NO_ACTION_TAPPING
      switch (keycode)
        {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
# ifndef NO_ACTION_LAYER
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
# endif
          if (record->tap.count == 0)
            {
              return PROCESS_RECORD_CONTINUE;
            }
        }
#endif
      /* Shift the history buffer and insert the current keycode and
         modifiers. */
      if (record->event.pressed)
        {
          shift_history_keys();
          set_history(keycode, *record, current_modifier);
          deadline = record->event.time + HISTORY_TIMEOUT_MS;
          last_modifier = current_modifier;
        }
      return PROCESS_RECORD_CONTINUE;
    }
}

void
history_matrix_scan_user(void)
{
  if ((get_history(1)->record.keycode != KC_NO)
#if defined(CUSTOM_REPEAT_KEY_ENABLE)
      && !key_repeated
#endif
#if defined(SWAP_KEYS_ENABLE)
      && !key_swapped
#endif
      && timer_expired(timer_read(), deadline))
    {
      clear_history_keys(); // Timed out; clear the buffer.
    }
}
