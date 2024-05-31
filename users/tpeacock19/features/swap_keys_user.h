#include "modifiers.h"
#include "swap_keys.h"

__attribute__((weak)) uint16_t
find_swap_keycode_user(uint16_t keycode, uint8_t mods)
{
  bool shifted = (mods & MOD_MASK_SHIFT); // Was Shift held?
  bool ctrled = (mods & MOD_MASK_CTRL);	  // Was Shift held?
  /* bool alted = (mods & MOD_MASK_ALT);  // Was Shift held? */
  if (ctrled)
    { // Was Ctrl held?
      switch (keycode)
	{
	case KC_Y:
	  return C(KC_Z); // Ctrl + Y reverses to Ctrl + Z.
	case KC_Z:
	  return C(KC_Y); // Ctrl + Z reverses to Ctrl + Y.
	case KC_TAB:
	  if (shifted)
	    {			// If the last key was Shift + Tab,
	      return C(KC_TAB); // ... the reverse is Tab.
	      /* return MT(MOD_LCTL, KC_A); */
	    }
	  else
	    {			   // Otherwise, the last key was Tab,
	      return C(S(KC_TAB)); // ... and the reverse is Shift + Tab.
	    }
	}
    }
  switch (keycode)
    {
    case KC_TAB:
      if (shifted)
	{		 // If the last key was Shift + Tab,
	  return KC_TAB; // ... the reverse is Tab.
	}
      else
	{		    // Otherwise, the last key was Tab,
	  return S(KC_TAB); // ... and the reverse is Shift + Tab.
	}
    }
  return KC_TRANSPARENT;
}
