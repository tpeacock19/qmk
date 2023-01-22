#include "tapping.h"

#if defined(TAPPING_TERM_PER_KEY)
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
#endif

#if defined(TAPPING_FORCE_HOLD_PER_KEY)
bool
get_tapping_force_hold(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    case ALT_R:
    case SFT_S:
    case CRL_T:
    case GUI_D:
    case ALT_I:
    case SFT_E:
    case CRL_N:
    case GUI_H:
      return true;
    default:
      return false;
    }
}
#endif

#if defined(PERMISSIVE_HOLD_PER_KEY)
bool
get_permissive_hold(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    case SFT_S:
    case SFT_E:
      // Immediately select the hold action when another key is tapped.
      return true;
    default:
      // Do not select the hold action when another key is tapped.
      return false;
    }
}
#endif
