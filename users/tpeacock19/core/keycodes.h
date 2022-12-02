#pragma once

#include "keycodes.h"
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

uint16_t current_timer;

uint8_t current_mod_state;
uint8_t current_oneshot_mod_state;
uint8_t current_modifier;

uint8_t current_layer;

uint8_t last_mod_state;
uint8_t last_oneshot_mod_state;

// Initialize variables holding the bitfield
// representation of active modifiers.
layer_state_t last_layer_state;

struct key_mods
{
  uint16_t keycode;
  uint8_t modifier;
};

// Tap dance codes
#if defined(TAP_DANCE_ENABLE)
int cur_dance(qk_tap_dance_state_t *state);
int hold_cur_dance(qk_tap_dance_state_t *state);
bool is_key_on_tap(uint16_t keycode);

typedef struct
{
  bool is_press_action;
  int state;
} xtap;
#endif

// Custom Shortcuts

uint16_t extract_base_tapping_keycode(uint16_t keycode);
uint16_t extract_base_tapping_keycode16(uint16_t keycode);

uint8_t extract_keycode_from(uint16_t keycode);
uint8_t extract_mods_from(uint16_t keycode);
uint8_t extract_tap_layer(uint16_t keycode);
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
  CUSTOM_KEYCODE_START = SAFE_RANGE,
  CANCEL,
  TG_MAC,
  TG_WIN,
  TG_LIN,
  SYM_RPT,
  SYM_REV,
  NUM_REV,
  NUM_RPT,
  SWAPKEY,
  LLOCK,

  // repeat
  SWAP,
  REPEAT,
  REVRPT,
  NW_TOGG,
  GOTOBASE,
  BASETOGG,
  L_BASE,
  // Begin macros that can be shifted
  SFT_MACRO_START = SAFE_RANGE,
  RESET,
  TG_CASE,
  LIN_LBRC,
  LIN_LPRN,
  LIN_LBRK,
  LINBRC,
  LINPRN,
  LINCBR,
  LINQ,

  XCUT,
  XCOPY,
  XPAST,
  XWFWD,
  XWBAK,
  XSRCH,
  XWTOG,
  XMAX,
  XMVR,
  XMVL,
  XWMOV,
  XWMOVL,
  XLOCK,
  XCLOSE,
  XUNDO,
  XREDO,
  // clang-format off
  // Common shortcuts
  MC_SELC, MC_SAVE, MC_UNDO, MC_CTAB,
  MC_LOCK, MC_FULL, MC_FIND, MC_REF,

  // IDE shortcuts
  MC_QUIK, MC_AUCO,
  MC_QDOC, MC_FSYM, MC_RUN, MC_DBUG, MC_BUID,
  MC_PROJ, MC_RECE, MC_COMP, MC_FIUS, MC_REFC,
  MC_JOIN, MC_COMT,

  // Begin macros used to write text
  STR_MACRO_START,

  MC_BTIC, MC_DQUO, MC_SQUO,
  MC_UNDS, MC_ENT, MC_TAB, MC_ESC,
  MC_ESAV, MC_SENT, MC_CUR,
  MC_DAND, MC_DPIP,

  // End macros that can be shifted
  SFT_MACRO_END,

  // Accented letters
  MC_GV_A, MC_CR_A, MC_TL_A, MC_SQ_A,
  MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
  MC_CR_E, MC_TL_O, MC_SQ_C, MC_SQ_E,
  MC_AO, MC_CAO, MC_OES, MC_COES,

  // End macros used to write text
  STR_MACRO_END,
  // clang-format on

  CUSTOM_KEYCODE_END,
};

#define XCUT S(KC_DELETE)
#define XCOPY C(KC_INSERT)
#define XPAST S(KC_INSERT)

// Custom Tap-Hold

#define XWFWD LT(0, KC_A)
#define XWBAK LT(0, KC_B)
#define XSRCH LT(0, KC_C)
#define XWTOG LT(0, KC_D)
#define XMAX LT(0, KC_E)
#define XMVR LT(0, KC_F)
#define XMVL LT(0, KC_G)
#define XWMOV LT(0, KC_H)
#define XLOCK LT(0, KC_I)
#define XCLOSE LT(0, KC_J)
#define XUNDO LT(0, KC_K)
#define XREDO LT(0, KC_UNDO)

/* Tap: One-Shot Shift | Hold: Layer */
#define NAV_SFT LT(L_NAV, TG_CASE)
#define MED_SFT LT(L_MEDIA, TG_CASE)
#define SYM_SFT LT(L_SYM, TG_CASE)

/* Tap: Repeat | Hold: Layer */
#define SYM_RPT LT(L_SYM, REPEAT)
#define NUM_RPT LT(L_NUM, REPEAT)

/* Tap: Key | Hold: Layer */
#define MOD_T LT(L_MODS, KC_T)
#define MOD_SPC LT(L_MODS, KC_SPC)

/* Swapper */
#define SWAPKEY LT(0, SWAP)

#define WFWD LT(0, KC_WWW_FORWARD)
#define WBAK LT(0, KC_WWW_BACK)

/* Linger Keys  */
#define BASETOGG LT(0, L_BASE)
#define COMPAR LT(0, KC_COMM)
#define DOTMIN LT(0, KC_DOT)
#define SLSEXC LT(0, KC_SLASH)
#define LINBRC LT(0, KC_LBRC)
#define LINPRN LT(0, KC_LPRN)
#define LINCBR LT(0, LIN_LBRC)
#define LINQ LT(0, KC_Q)

/* Safe Reset */
#define MYRESET LT(0, RESET)

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
