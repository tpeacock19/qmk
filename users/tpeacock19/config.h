#pragma once

#ifndef NO_DEBUG
# define NO_DEBUG
#endif
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
# define NO_PRINT
#endif

// Optimization to save memory
#ifndef NO_ACTION_MACRO
# define NO_ACTION_MACRO
#endif
#ifndef NO_ACTION_FUNCTION
# define NO_ACTION_FUNCTION
#endif
/* #ifndef NO_ACTION_ONESHOT */
/* #define NO_ACTION_ONESHOT */
/* #endif */
#ifndef NO_MUSIC_MODE
# define NO_MUSIC_MODE
#endif
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// Less than 8 layers in total
/* #define LAYER_STATE_8BIT */

/*****************************************************************************
 *                                  Tapping
 *****************************************************************************/

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#if defined(TAPPING_TERM)
# undef TAPPING_TERM
#endif

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
// Prevent auto-repeat when using Home Row Mods
/* #define TAPPING_FORCE_HOLD_PER_KEY */
#define QUICK_TAP_TERM TAPPING_TERM

// Prevent normal rollover on alphas from accidentally triggering mods.
/* #define IGNORE_MOD_TAP_INTERRUPT */
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Permissive hold only for Shift Home Row Mods
#define PERMISSIVE_HOLD_PER_KEY

// Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TAP_TOGGLE 3
#define TAPPING_TOGGLE 2

// Time (in ms) before the one shot code is released
#define ONESHOT_TIMEOUT 2000
#define CUSTOM_TAPHOLD_TIMEOUT 2000

// Layer Lock
#define LAYER_LOCK_IDLE_TIMEOUT 60000

// Auto Shift
#if defined(AUTO_SHIFT_ENABLE)
/* #define NO_AUTO_SHIFT_ALPHA */
# define NO_AUTO_SHIFT_NUMERIC
# define NO_AUTO_SHIFT_SPECIAL
/* #define AUTO_SHIFT_REPEAT */
# define AUTO_SHIFT_TIMEOUT TAPPING_TERM
/* #define AUTO_SHIFT_TIMEOUT TAPPING_TERM - 50 */
# define AUTO_SHIFT_NO_SETUP
# define RETRO_SHIFT
#endif

// Configure combos
#if defined(COMBO_ENABLE)
# if defined(COMBO_COUNT)
#  undef COMBO_COUNT
# endif

# define COMBO_VARIABLE_LEN
# define COMBO_ALLOW_ACTION_KEYS
# define COMBO_STRICT_TIMER
# define EXTRA_SHORT_COMBOS

# if defined(COMBO_TERM)
#  undef COMBO_TERM
# endif
# define COMBO_TERM (TAPPING_TERM / 5) // time to get all combo keys down
# define COMBO_TERM_PER_COMBO

# if defined(COMBO_HOLD_TERM)
#  undef COMBO_HOLD_TERM
# endif
# define COMBO_MUST_TAP_PER_COMBO
# define COMBO_HOLD_TERM TAPPING_TERM
#endif

#if defined(ADAPTIVE_KEYS_ENABLE)
# define ADAPTIVE_TERM (TAPPING_TERM / 2)
#endif

/*****************************************************************************
 *                                  unused                                   *
 *****************************************************************************/

// Dynamic macros
/* #define DYNAMIC_MACRO_NO_NESTING */

// Disable RGB effects
#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_LAYERS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE

#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN

#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
