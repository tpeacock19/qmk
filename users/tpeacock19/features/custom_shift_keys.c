#include "custom_shift_keys.h"
extern bool key_repeated;
uint16_t shifted_key;

bool
custom_shift_key(uint16_t keycode, keyrecord_t *record)
{
  // Search for a custom key with keycode equal to `keycode`.
  if (shifted_key != KC_NO)
    {
      shifted_key = KC_NO;
    }
  for (int i = 0; i < NUM_CUSTOM_SHIFT_KEYS; ++i)
    {
      if (keycode == pgm_read_word(&custom_shift_keys[i].keycode))
        {
          if (record->event.pressed)
            {
              if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode))
                  && record->tap.count == 0)
                {
                  return false;
                }
              // Continue default handling if this is a tap-hold key being held.
              shifted_key
                = pgm_read_word(&custom_shift_keys[i].shifted_keycode);
#if defined(CUSTOM_TAPHOLD_ENABLE)
              disable_oneshot_layer();
              disable_oneshot_mods();
#else
              clear_oneshot_layer_state(ONESHOT_PRESSED);
              clear_oneshot_mods();
#endif
              clear_shift();
              current_modifier = 0;
              tap_code_history16(shifted_key, record);
            }
          return true;
        }
    }
  return false;
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
    }
  return PROCESS_RECORD_CONTINUE;
}
