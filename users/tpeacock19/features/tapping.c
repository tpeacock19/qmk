#include "tapping.h"

uint16_t
get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
  for (int i = 0; i < NUM_TAPPING_TERM_KEYS; ++i)
    {
      if (keycode == pgm_read_word(&tapping_term_keys[i].keycode))
        {
          return TAPPING_TERM
                 + pgm_read_word(&tapping_term_keys[i].tapping_term);
        }
    }
  return TAPPING_TERM;
}
