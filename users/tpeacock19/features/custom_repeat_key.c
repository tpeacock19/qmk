#include "custom_repeat_key.h"
#include "keycodes.h"

bool key_repeated;
extern uint16_t shifted_key;

void
repeat_key(keyrecord_t *record)
{
  if (record->event.pressed)
    {
      register_mods(get_history(1)->modifier);
      register_code16(get_history(1)->record.keycode);
    }
  if (!record->event.pressed)
    {
      unregister_code16(get_history(1)->record.keycode);
      unregister_mods(get_history(1)->modifier);
    }
}

process_record_result_t
process_custom_repeat_key(uint16_t keycode, keyrecord_t *record)
{
  if (repeat_key_press_user(keycode, record) && record->tap.count != 0)
    {
      key_repeated = true;
#if defined(CUSTOM_SHIFT_ENABLE)
      if (shifted_key != KC_NO)
        {
          tap_code_history16(shifted_key, record);
          shifted_key = KC_NO;
          return PROCESS_RECORD_RETURN_FALSE;
        }
      else
#endif
        {
          repeat_key(record);
          return PROCESS_RECORD_RETURN_FALSE;
        }
    }
  key_repeated = false;
  return PROCESS_RECORD_CONTINUE;
}
