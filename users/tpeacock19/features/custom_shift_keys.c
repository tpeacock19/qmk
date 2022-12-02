#include "custom_shift_keys.h"

extern bool key_repeated;
bool key_shifted = false;

bool
custom_shift_key(uint16_t keycode, keyrecord_t *record)
{
  static uint16_t shifted_key = KC_NO;
  /* static uint8_t registered_modifier = 0; */
  // If a custom shift key is registered, then this event is either
  // releasing it or manipulating another key at the same time. Either way,
  // we release the currently registered key.
  if (shifted_key != KC_NO)
    {
      unregister_code16(shifted_key);
      shifted_key = KC_NO;
    }

  // Search for a custom key with keycode equal to `keycode`.
  for (int i = 0; i < NUM_CUSTOM_SHIFT_KEYS; ++i)
    {
      if (keycode == pgm_read_word(&custom_shift_keys[i].keycode))
        {
          if (record->event.pressed)
            {
              // Continue default handling if this is a tap-hold key being held.
              if (((QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX)
                   || (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX))
                  && record->tap.count == 0)
                {
                  return false;
                }
#if defined(CUSTOM_TAPHOLD_ENABLE)
              disable_oneshot_layer();
              disable_oneshot_mods();
#else
              clear_oneshot_layer_state(ONESHOT_PRESSED);
              clear_oneshot_mods();
#endif
              shifted_key
                = pgm_read_word(&custom_shift_keys[i].shifted_keycode);
              tap_code_mod_history16(shifted_key, 0, record);
              get_history(1)->modifier = 0;
              key_shifted = true;
              break;
            }
        }
    }
  if (shifted_key != KC_NO)
    return true;
  else
    {
      key_shifted = false;
      return false;
    }
}

process_record_result_t
process_custom_shift_keys(uint16_t keycode, keyrecord_t *record)
{
  if (isShifted)
    {
      if (custom_shift_key(keycode, record))
        {
          return PROCESS_RECORD_RETURN_FALSE;
        }
      return PROCESS_RECORD_CONTINUE;
    }
  return PROCESS_RECORD_CONTINUE;
}
