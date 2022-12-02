#include "esc_mod.h"

/* extern bool is_num_word_on(void);     /\**< Activates Num Word. *\/ */
/* extern void num_word_on(void);     /\**< Activates Num Word. *\/ */
/* extern void num_word_off(void);     /\**< Activates Num Word. *\/ */
/* extern bool is_caps_word_on(void);     /\**< Activates Num Word. *\/ */
/* extern void caps_word_on(void);     /\**< Activates Num Word. *\/ */
/* extern void caps_word_off(void);     /\**< Activates Num Word. *\/ */

process_record_result_t
process_esc_mod(uint16_t keycode, keyrecord_t *record)
{
  if (keycode == KC_ESC && record->event.pressed)
    {
      bool rc = true;
      uint8_t mods = 0;
      if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out())
        {
          clear_oneshot_mods();
          rc = false;
        }
      if ((mods = get_oneshot_locked_mods()))
        {
          clear_oneshot_locked_mods();
          rc = false;
        }
        /* if (is_oneshot_layer_active()) { */
        /*     layer_clear(); */
        /*     rc = false; */
        /* } */
#if defined(CAPS_WORD_ENABLE)
      if (is_caps_word_on())
        {
          caps_word_off();
          rc = false;
        }
#endif
#if defined(NUMWORD_ENABLE)
      if (is_num_word_on())
        {
          num_word_off();
          rc = false;
        }
#endif
      tap_code(KC_ESCAPE);
      if (rc == true)
        {
          return PROCESS_RECORD_RETURN_FALSE;
        }
      else
        return PROCESS_RECORD_RETURN_FALSE;
    }
  else
    return PROCESS_RECORD_CONTINUE;
}
