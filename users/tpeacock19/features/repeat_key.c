#include "repeat_key.h"

bool key_repeated;
extern bool key_shifted;

void
repeat_key(const keyrecord_t *record)
{
  key_repeated = true;
  if (record->event.pressed)
    {
      register_mods(get_history(1)->modifier);
      register_code16(get_history(1)->keycode);
    }
  else
    {
      unregister_code16(get_history(1)->keycode);
      unregister_mods(get_history(1)->modifier);
    }
}

process_record_result_t
process_repeat_key(uint16_t keycode, keyrecord_t *record)
{
  key_repeated = false;
  if (repeat_key_press_user(keycode, record) && record->tap.count != 0)
    {
#if defined(CUSTOM_SHIFT_ENABLE)
      if (key_shifted)
        {
          /* If custom shift is enabled we want to repeat that custom
           * key */
          custom_shift_key(get_history(1)->keycode, record);
        }
      else
#endif
        repeat_key(record);
      /* skip default processing */
      return PROCESS_RECORD_RETURN_FALSE;
    }
  return PROCESS_RECORD_CONTINUE;
}
