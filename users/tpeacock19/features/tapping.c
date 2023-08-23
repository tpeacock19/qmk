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

#if defined(QUICK_TAP_TERM)
extern uint16_t
get_quick_tap_term(uint16_t keycode, keyrecord_t *record)
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
      return 0;
    default:
      return QUICK_TAP_TERM;
    }
}
#endif

/* #if defined(TAPPING_FORCE_HOLD_PER_KEY) */
/* extern bool */
/* get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) */
/* { */
/*   switch (keycode) */
/*     { */
/*     case ALT_R: */
/*     case SFT_S: */
/*     case CRL_T: */
/*     case GUI_D: */
/*     case ALT_I: */
/*     case SFT_E: */
/*     case CRL_N: */
/*     case GUI_H: */
/*       return true; */
/*     default: */
/*       return false; */
/*     } */
/* } */
/* #endif */

#if defined(PERMISSIVE_HOLD_PER_KEY)
bool
get_permissive_hold(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    case SFT_S:
    case SFT_E:
    /*   // Immediately select the hold action when another key is tapped. */
      return true;
    default:
      // Do not select the hold action when another key is tapped.
      return false;
    }
}
#endif

#if defined(HOLD_ON_OTHER_KEY_PRESS_PER_KEY)
extern bool
get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    // Capture all mod-tap keycodes.
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      /* if (keycode == LCTL_T(KC_A)) { */
      // Disable HOLD_ON_OTHER_KEY_PRESS
      // aka enable IGNORE_MOD_TAP_INTERRUPT
      return false;
      /* } else { */
      /*     // Enable HOLD_ON_OTHER_KEY_PRESS for every other mod-tap keycode.
       */
      /*     return true; */
      /* } */
    default:
      return false;
    }
}
#endif
