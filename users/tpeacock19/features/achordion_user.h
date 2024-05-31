#include "achordion.h"
#include "core/keycodes.h"

__attribute__((weak)) bool
achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                uint16_t other_keycode, keyrecord_t* other_record)
{
  if (tap_hold_record->event.key.row == 4
      || tap_hold_record->event.key.row == 8)
    {
      return true;
    }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

__attribute__((weak)) uint16_t
achordion_timeout(uint16_t tap_hold_keycode)
{
  switch (tap_hold_keycode)
    {
    case CUSTOM_KEYCODE_START ... CUSTOM_KEYCODE_END:
    case NAV_SFT:
    case OS_MODS:
    case MOD_SPC:
    case SYM_RPT:
    case COMPAR:
    case DOTMIN:
    case SLSEXC:
    case LINBRC:
    case LINPRN:
    case LINCBR:
    case LINQ:
      return 0; // Bypass Achordion for these keys.
    }

  return 800; // Otherwise use a timeout of 800 ms.
}

__attribute__((weak)) bool
achordion_eager_mod(uint8_t mod)
{
  switch (mod)
    {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
      return true; // Eagerly apply Shift and Ctrl mods.

    default:
      return false;
    }
}
