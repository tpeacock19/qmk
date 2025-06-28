#pragma once

#include QMK_KEYBOARD_H
#include "core/core.h"

uint16_t
get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods)
{
  bool shifted = (mods & MOD_MASK_SHIFT); // Was Shift held?
  bool ctrled = (mods & MOD_MASK_CTRL);	  // Was Shift held?
  bool alted = (mods & MOD_MASK_ALT);
  bool guid = (mods & MOD_MASK_GUI);

  if (shifted & ctrled & alted)
    {
      switch (keycode)
	{
	case KC_V:
	  return C(A(KC_V));
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
	case KC_DOT:
	  return A(KC_COMMA);
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
	}
    }
  if (ctrled)
    { // Was Ctrl held?
      switch (keycode)
	{
	case KC_S:
	  return C(KC_R);
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
  return KC_TRNS; // Defer to default definitions.
}

bool
remember_last_key_user(uint16_t keycode, keyrecord_t *record,
		       uint8_t *remembered_mods)
{
  switch (keycode)
    {
    case SYM_RPT:
    case NUM_RPT:
      return false;
    }
  return true;
}
