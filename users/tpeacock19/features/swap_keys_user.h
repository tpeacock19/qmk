#include QMK_KEYBOARD_H

__attribute__((weak)) uint16_t
find_swap_keycode_user(uint16_t keycode, uint8_t mods)
{
  bool shifted = (mods & MOD_MASK_SHIFT); // Was Shift held?
  bool ctrled = (mods & MOD_MASK_CTRL);	  // Was Shift held?
  bool alted = (mods & MOD_MASK_ALT);
  bool guid = (mods & MOD_MASK_GUI); //
  /* bool alted = (mods & MOD_MASK_ALT);  // Was Shift held? */
  if (shifted & ctrled & alted)
    {
      switch (keycode)
	{
	case KC_V:
	  return C(A(KC_V));
	}
    }
  if (ctrled & shifted)
    {
      switch (keycode)
	{
	case KC_TAB:
	  return C(KC_TAB);
	}
    }
  if (ctrled & alted)
    {
      switch (keycode)
	{
	case KC_V:
	  return S(C(A(KC_V)));
	}
    }
  if (guid && shifted)
    {
      switch (keycode)
	{
	case KC_COMMA:
	  return S(G(KC_DOT));
	case KC_DOT:
	  return S(G(KC_COMMA));
	}
    }
  if (alted)
    {
      switch (keycode)
	{
	case KC_V:
	  return C(KC_V);
	case KC_DOT:
	  return A(KC_COMMA);
	case KC_COMMA:
	  return A(KC_DOT);
	}
    }
  if (guid)
    {
      switch (keycode)
	{
	case KC_DOT:
	  return G(KC_COMMA);
	case KC_COMMA:
	  return G(KC_DOT);
	}
    }
  if (ctrled)
    { // Was Ctrl held?
      switch (keycode)
	{
	case KC_S:
	  return C(KC_R);
	case KC_R:
	  return C(KC_S);
	case KC_I:
	  return C(KC_O);
	case KC_V:
	  return A(KC_V);
	case KC_GT:
	  return C(KC_LT);
	case KC_U:
	  return C(KC_D);
	case KC_Y:
	  return C(KC_Z);
	case KC_Z:
	  return C(KC_Y);
	case KC_TAB:
	  return C(S(KC_TAB));
	}
    }
  if (shifted)
    {
      switch (keycode)
	{
	case KC_U:
	  return KC_U;
	}
    }
  switch (keycode)
    {
    case KC_U:
      return S(KC_U);
    case KC_GT:
      return KC_LT;
    case KC_WWW_FORWARD:
      return KC_WWW_BACK;
    }

  return KC_TRANSPARENT;
}
