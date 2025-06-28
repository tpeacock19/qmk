#pragma once
#include QMK_KEYBOARD_H
#include "num_word.h"

extern bool
num_word_press_user(uint16_t keycode)
{
  if (!is_num_word_on())
    {
      return true;
    }
  else
    switch (keycode)
      {
      case KC_1 ... KC_0:
      case MT(MOD_LSFT, KC_1):
      case MT(MOD_LSFT, KC_0):
      case KC_COMM:
      case KC_DOT:
      case KC_SLSH:
      case COMPAR:
      case DOTMIN:
      case SLSEXC:
      case OS_MODS:
      case KC_MINUS:
      case KC_ASTERISK:
      case KC_DOLLAR:
      case KC_PLUS:
      case KC_COLON:
      case KC_EQUAL:
      case KC_UNDS:
      case KC_BSPC:
      case REPEAT:
      case OSM(MOD_LSFT):
      case KC_NO:
      case KC_UP:
      case KC_DOWN:
      case KC_TAB:
      case KC_ENT:
	return true;
      default:
	num_word_off();
	return false;
      }
}
