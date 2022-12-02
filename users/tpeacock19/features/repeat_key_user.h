#include "repeat_key.h"

extern bool
repeat_key_press_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
    {
    case NUM_RPT:
    case SYM_RPT:
      if (!record->tap.interrupted)
        return true;
      else
        return false;
    case REPEAT:
      return true;
    default:
      return false;
    }
}
