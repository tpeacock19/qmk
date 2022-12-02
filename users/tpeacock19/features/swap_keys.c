#include "swap_keys.h"

bool key_swapped = false;

static void
swap_key(keyrecord_t *record)
{
  uint16_t swapped_keycode = KC_NO;
  uint8_t swapped_modifier = 0;

  if (get_history(1)->keycode == KC_NO || record->tap.count == 0)
    {
      return;
    }

  /* Search for a swap key pair with a keycode equal to the last pressed keycode
  and modifier.  */
  for (int i = 0; i < NUM_SWAP_KEYS; ++i)
    {
      uint16_t code = pgm_read_word(&swap_keys[i].keycode);
      uint16_t swap = pgm_read_word(&swap_keys[i].swapped_keycode);
      uint16_t code_basic = QK_MODS_GET_BASIC_KEYCODE(code);
      uint16_t swap_basic = QK_MODS_GET_BASIC_KEYCODE(swap);
      /* Modifiers are stored in history whether executed with a Keycode (such
      as Shift in KC_LPRN), One-Shot Modifiers, or Standard Modifiers */
      if (get_history(1)->modifier == QK_MODS_GET_MODS(code))
        {
          /* One-Shot Modified keys register in the History Module as basic
          keycodes, so we check them first */
          if (get_history(1)->keycode == code_basic)
            {
              swapped_keycode = swap_basic;
              swapped_modifier = QK_MODS_GET_MODS(swap);
              break;
            }
          else if (get_history(1)->keycode == code)
            {
              swapped_keycode = swap;
              swapped_modifier = QK_MODS_GET_MODS(swap);
              break;
            }
        }
      /* If the key wasn't matched, try the second key in the swap pair.  */
      if (!swapped_keycode)
        {
          if (get_history(1)->modifier == QK_MODS_GET_MODS(swap))
            {
              /* One-Shot Modified keys register in the History Module as basic
              keycodes, so we check them first */
              if (get_history(1)->keycode == swap_basic)
                {
                  swapped_keycode = code_basic;
                  swapped_modifier = QK_MODS_GET_MODS(code);
                  break;
                }
              else if (get_history(1)->keycode == swap)
                {
                  swapped_keycode = code;
                  swapped_modifier = QK_MODS_GET_MODS(code);
                  break;
                }
            }
        }
    }

  if (swapped_keycode != KC_NO)
    {
      key_swapped = true;
      if (record->event.pressed)
        {
          /* disable oneshot layers/mods */
#if defined(CUSTOM_TAPHOLD_ENABLE)
          disable_oneshot_layer();
          disable_oneshot_mods();
#else
          clear_oneshot_layer_state(ONESHOT_PRESSED);
          clear_oneshot_mods();
          clear_oneshot_locked_mods();
#endif
          register_mods(swapped_modifier);
          register_code16(swapped_keycode);
          /* Instead of shifting the history we swap the last entry for this
           * key. This lets us use the repeat key with the 'correct' keycode. */
          clear_history_index(1);
          get_history(1)->keycode = swapped_keycode;
          get_history(1)->modifier = swapped_modifier;
          get_history(1)->keydown = record->event.time;
        }
      else
        {
          unregister_code16(get_history(1)->keycode);
          unregister_mods(get_history(1)->modifier);
        }
    }
}

process_record_result_t
process_swap_key(uint16_t keycode, keyrecord_t *record)
{
  key_swapped = false;
  if (swap_key_press_user(keycode, record))
    {
      swap_key(record);
      return PROCESS_RECORD_RETURN_FALSE;
    }
  return PROCESS_RECORD_CONTINUE;
}

__attribute__((weak)) bool
swap_key_press_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    case SWAPKEY:
      return true;
    default:
      return false;
    }
}
