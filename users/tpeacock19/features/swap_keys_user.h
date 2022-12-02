#include "swap_keys.h"

extern bool
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
