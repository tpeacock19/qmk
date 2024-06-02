#pragma once

#include "keycodes.h"
#include "layers.h"
#include QMK_KEYBOARD_H

// Define os types
enum os_types
{
  _OS_MACOS = 0,
  _OS_LINUX,
  _OS_WINDOWS,
};

extern bool isOneShotLockedShift;
extern bool isOneShotShift;
extern bool isShifted;

uint8_t current_mod_state;
uint8_t current_oneshot_mod_state;
uint8_t current_keycode_mod_state;
uint8_t current_modifier;

uint8_t current_layer;

uint8_t last_modifier;

// Initialize variables holding the bitfield
// representation of active modifiers.
layer_state_t last_layer_state;

/* struct key_mods */
/* { */
/*   uint16_t keycode; */
/*   uint8_t modifier; */
/* }; */

// Tap dance codes
#if defined(TAP_DANCE_ENABLE)
int cur_dance(qk_tap_dance_state_t *state);
int hold_cur_dance(qk_tap_dance_state_t *state);

typedef struct
{
  bool is_press_action;
  int state;
} xtap;
#endif

// Custom Shortcuts

uint8_t extract_keycode_from(uint16_t keycode);
uint8_t extract_mods_from(uint16_t keycode);
uint8_t extract_layer_from(uint16_t keycode);

void clear_shift(void);

#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

#define MOD_MASK_LCTRL MOD_BIT(KC_LEFT_CTRL)
#define MOD_MASK_LSHIFT MOD_BIT(KC_LEFT_SHIFT)
#define MOD_MASK_LALT MOD_BIT(KC_LEFT_ALT)
#define MOD_MASK_LGUI MOD_BIT(KC_LEFT_GUI)
#define MOD_MASK_LCS (MOD_MASK_LCTRL | MOD_MASK_LSHIFT)
#define MOD_MASK_LCA (MOD_MASK_LCTRL | MOD_MASK_LALT)
#define MOD_MASK_LCG (MOD_MASK_LCTRL | MOD_MASK_LGUI)
#define MOD_MASK_LSA (MOD_MASK_LSHIFT | MOD_MASK_LALT)
#define MOD_MASK_LSG (MOD_MASK_LSHIFT | MOD_MASK_LGUI)
#define MOD_MASK_LAG (MOD_MASK_LALT | MOD_MASK_LGUI)
#define MOD_MASK_LCSA (MOD_MASK_LCTRL | MOD_MASK_LSHIFT | MOD_MASK_LALT)
#define MOD_MASK_LCSG (MOD_MASK_LCTRL | MOD_MASK_LSHIFT | MOD_MASK_LGUI)
#define MOD_MASK_LCAG (MOD_MASK_LCTRL | MOD_MASK_LALT | MOD_MASK_LGUI)
#define MOD_MASK_LSAG (MOD_MASK_LSHIFT | MOD_MASK_LALT | MOD_MASK_LGUI)
#define MOD_MASK_LCSAG \
  (MOD_MASK_LCTRL | MOD_MASK_LSHIFT | MOD_MASK_LALT | MOD_MASK_LGUI)

#define MOD_MASK_RCTRL MOD_BIT(KC_RIGHT_CTRL)
#define MOD_MASK_RSHIFT MOD_BIT(KC_RIGHT_SHIFT)
#define MOD_MASK_RALT MOD_BIT(KC_RIGHT_ALT)
#define MOD_MASK_RGUI MOD_BIT(KC_RIGHT_GUI)
#define MOD_MASK_RCS (MOD_MASK_RCTRL | MOD_MASK_RSHIFT)
#define MOD_MASK_RCA (MOD_MASK_RCTRL | MOD_MASK_RALT)
#define MOD_MASK_RCG (MOD_MASK_RCTRL | MOD_MASK_RGUI)
#define MOD_MASK_RSA (MOD_MASK_RSHIFT | MOD_MASK_RALT)
#define MOD_MASK_RSG (MOD_MASK_RSHIFT | MOD_MASK_RGUI)
#define MOD_MASK_RAG (MOD_MASK_RALT | MOD_MASK_RGUI)
#define MOD_MASK_RCSA (MOD_MASK_RCTRL | MOD_MASK_RSHIFT | MOD_MASK_RALT)
#define MOD_MASK_RCSG (MOD_MASK_RCTRL | MOD_MASK_RSHIFT | MOD_MASK_RGUI)
#define MOD_MASK_RCAG (MOD_MASK_RCTRL | MOD_MASK_RALT | MOD_MASK_RGUI)
#define MOD_MASK_RSAG (MOD_MASK_RSHIFT | MOD_MASK_RALT | MOD_MASK_RGUI)
#define MOD_MASK_RCSAG \
  (MOD_MASK_RCTRL | MOD_MASK_RSHIFT | MOD_MASK_RALT | MOD_MASK_RGUI)

#if defined(TAP_DANCE_ENABLE)
enum
{
  TD_NONE,
  TD_UNKNOWN,
  SINGLE_INT,
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS
};

enum
{
  TD_CODE_START,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  TD_CODE_END,
};

// Tap dance keycodes
# define TD_COMI TD(DANCE_1)
# define TD_DOEX TD(DANCE_2)
# define TD_SLPR TD(DANCE_3)
# define TD_SPCG TD(DANCE_4)
# define TD_GTO1 TD(DANCE_5)
# define TD_REST TD(DANCE_6)

#endif

// Custom keycodes
enum custom_keycodes
{
  // clang-format off
  CUSTOM_KEYCODE_START = SAFE_RANGE,
  /* Layer Keycodes */
  /* Home row mods */
  /* ALT_R, SFT_S, CRL_T, GUI_D, */
  /* ALT_I, SFT_E, CRL_N, GUI_H, */
  /* NAV_SFT, OS_MODS, MOD_SPC, */

  TG_OS, TG_MAC, TG_WIN, TG_LIN,
  /* SYM_RPT, SYM_REV, */
  /* NUM_REV, NUM_RPT, */

  REPEAT, SWAPKEY,
  GOTOBASE, LLOCK,

  BASETOGG, NW_TOGG,
  /* Linger Keys */
  /* LINBRC, LINPRN, LINCBR, LINQ, */
  /* Common shortcuts */
  /* XCUT, XCOPY, XPAST, XUNDO, XREDO, */
  /* XWFWD, XWBAK, XSRCH, XWTOG, */
  XMAX, XWMOV, XWMOVL,
  /* XMVR, XMVL, */
  /* XLOCK, XCLOSE, */

  CUSTOM_KEYCODE_END,
  // clang-format on
};

/* #define XCUT S(KC_DELETE) */
/* #define XCOPY C(KC_INSERT) */
/* #define XPAST S(KC_INSERT) */
#define XCUT LT(0, KC_DELETE)
#define XCOPY LT(0, KC_INSERT)
#define XPAST LT(0, KC_PAUSE)

// Custom Tap-Hold

#define XWFWD LT(0, KC_WWW_FORWARD)
#define XWBAK LT(0, KC_WWW_BACK)
#define XSRCH LT(0, KC_C)
#define XWTOG LT(0, KC_Y)
#define XWTOGL LT(0, KC_H)
#define XMAX LT(0, KC_W)
#define XMVR LT(0, KC_F)
#define XMVL LT(0, KC_G)
#define XWMOV LT(0, KC_V)
#define XWMOVL LT(0, KC_U)
#define XLOCK LT(0, KC_X)
#define XCLOSE LT(0, KC_J)
#define XUNDO LT(0, KC_K)
#define XREDO LT(0, KC_AGAIN)

#define ALT_R MT(MOD_LALT, KC_R)
#define SFT_S MT(MOD_LSFT, KC_S)
#define CRL_T MT(MOD_LCTL, KC_T)
#define GUI_D MT(MOD_LGUI, KC_D)

#define ALT_I MT(MOD_LALT, KC_I)
#define SFT_E MT(MOD_LSFT, KC_E)
#define CRL_N MT(MOD_LCTL, KC_N)
#define GUI_H MT(MOD_LGUI, KC_H)

/* Tap: One-Shot Shift | Hold: Layer */
#define NAV_SFT LT(L_NAV, KC_NO)
#define MED_SFT LT(L_MEDIA, KC_NO)
#define SYM_SFT LT(L_SYM, KC_NO)

/* Tap: Repeat | Hold: Layer */
#define SYM_RPT LT(L_SYM, REPEAT)
#define NUM_RPT LT(L_NUM, REPEAT)

/* Tap: Key | Hold: Layer */
#define MOD_T LT(L_MODS, KC_T)
#define MOD_SPC LT(L_MODS, KC_SPC)

/* Swapper */
#define SWAPKEY LT(0, KC_P)

#define WFWD LT(0, KC_WWW_FORWARD)
#define WBAK LT(0, KC_WWW_BACK)

/* Linger Keys  */
#define BASETOGG LT(0, KC_F1)
#define COMPAR LT(0, KC_COMM)
#define DOTMIN LT(0, KC_DOT)
#define SLSEXC LT(0, KC_SLASH)
#define LINBRC LT(0, KC_LBRC)
#define LINPRN LT(0, KC_LPRN)
#define LINQ LT(0, KC_Q)
#define LINCBR LT(0, KC_Z)

/* Safe Reset */
#define MYRESET LT(0, KC_F4)

/* Tap: One-Shot Layer | Hold: Layer */
#define OS_SYM LT(L_SYM, L_SYM)
#define OS_NUM LT(L_NUM, L_NUM)
#define OS_MODS LT(L_MODS, L_MODS)
#define OS_NAV LT(L_NAV, L_NAV)
#define OS_WNAV LT(L_WNAV, L_WNAV)
#define OS_MEDIA LT(L_MEDIA, L_MEDIA)
#define OS_FUNC LT(L_FUNC, L_FUNC)
#define MOD_NUM LT(L_MODS, L_NUM)
#define NUM_MOD LT(L_NUM, L_MODS)

enum
{
  DELAY_PRESS,
  DELAY_RELEASE,
  HOLD_PRESS,
  HOLD_RELEASE,
  TAP_PRESS,
  TAP_RELEASE,
  INT_PRESS,
  INT_RELEASE,
  DOUBLE_TAP_PRESS,
  DOUBLE_TAP_RELEASE,
  DOUBLE_INT_PRESS,
  DOUBLE_INT_RELEASE,
  TAP_HOLD_FUNCTION,
  DOUBLE_INT_FUNCTION,
  DOUBLE_TAP_FUNCTION,
  DOUBLE_TAP_HOLD_FUNCTION,
};
