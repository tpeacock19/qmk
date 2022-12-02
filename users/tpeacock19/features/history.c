#include "history.h"

extern void *memset(void *, int, size_t);
extern void *memmove(void *, const void *, size_t);

extern bool key_repeated;
extern bool key_swapped;

history_key_t history[HISTORY_SIZE] = {};

static uint16_t deadline = 0;

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
  tap_code_mod_history(keycode, current_modifier, record);
}

/* Base function to tap and insert into history a basic keycode and modifiers.
 */
void
tap_code_mod_history(uint8_t keycode, uint8_t modifier, keyrecord_t *record)
{
  register_mods(modifier);
  tap_code(keycode);
  unregister_mods(modifier);
  shift_history_keys();
  get_history(1)->keycode = keycode;
  get_history(1)->modifier = modifier;
  get_history(1)->keydown = record->event.time;
}

void
tap_code_history16(uint16_t keycode, keyrecord_t *record)
{
  tap_code_mod_history16(keycode, current_modifier, record);
}

void
tap_code_mod_history16(uint16_t keycode, uint8_t modifier, keyrecord_t *record)
{
  modifier = modifier | QK_MODS_GET_MODS(keycode);
  register_mods(modifier);
  tap_code16(keycode);
  unregister_mods(modifier);
  shift_history_keys();
  get_history(1)->keycode = keycode;
  get_history(1)->modifier = modifier;
  get_history(1)->keydown = record->event.time;
}

static void
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
  static uint8_t hmodifier;
  static uint16_t hkeycode = KC_NO;

  switch (keycode)
    {
    case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
    case QK_MOMENTARY ... QK_MOMENTARY_MAX:
    case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
    case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
    case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
    case QK_TO ... QK_TO_MAX:
    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
      return PROCESS_RECORD_CONTINUE;
    default:
      /* Default to the mod state prior to this key. */
      hmodifier = last_oneshot_mod_state | last_mod_state;
      hkeycode = keycode;

#if defined(AUTO_SHIFT_ENABLE)
      bool get_autoshift_shift_state(uint16_t keycode);
      if (get_autoshift_shift_state(keycode))
        {
          hmodifier = MOD_BIT(KC_LSFT);
        }
#endif
#if defined(CAPS_WORD_ENABLE)
      bool is_caps_word_on(void); /**< Gets whether currently active. */
      if (is_caps_word_on())
        {
          hmodifier = MOD_BIT(KC_LSFT);
        }
#endif

      if (keycode != KC_NO && keycode > SAFE_RANGE)
        {
          hmodifier = hmodifier | QK_MODS_GET_MODS(keycode);
        }

#ifndef NO_ACTION_TAPPING
      switch (keycode)
        {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
# ifndef NO_ACTION_LAYER
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
# endif // NO_ACTION_LAYER
          if (record->tap.count == 0)
            {
              /* Ignore holding events with Mod/Layer taps */
              return PROCESS_RECORD_CONTINUE;
            }
          /* Set the keycode to the base tapping keycode of a mod- or layer-tap
          key. */
          hkeycode &= 0xff;
        }
#endif
      shift_history_keys();
      get_history(1)->keycode = hkeycode;
      get_history(1)->modifier = hmodifier | QK_MODS_GET_MODS(keycode);
      get_history(1)->keydown = record->event.time;
      deadline = record->event.time + HISTORY_TIMEOUT_MS;
      return PROCESS_RECORD_CONTINUE;
    }
}

void
history_matrix_scan_user(void)
{
  if ((get_history(1)->keycode != KC_NO)
#if defined(REPEAT_KEYS_ENABLE)
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
