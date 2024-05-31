// -*- buffer-read-only: t -*-
// Copyright 2022 Trey Peacock

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define USB_SUSPEND_WAKEUP_DELAY 200
#define SPLIT_USB_TIMEOUT 10000
#define SPLIT_USB_TIMEOUT_POLL 10

/*****************************************************************************
 *                                   Sweeq                                   *
 *****************************************************************************/

#undef MASTER_LEFT
#undef EE_HANDS
#undef MASTER_RIGHT

#define SERIAL_USART_TX_PIN GP1

#define PS2_MOUSE_X_MULTIPLIER 5
#define PS2_MOUSE_Y_MULTIPLIER 5
#define PS2_MOUSE_V_MULTIPLIER 2
#define PIMORONI_TRACKBALL_SCALE 5

#ifdef POINTING_DEVICE_TRACKPOINT_TRACKBALL
# define MASTER_LEFT
# define POINTING_DEVICE_ROTATION_90_RIGHT
#endif
#ifdef POINTING_DEVICE_TRACKBALL_TRACKPOINT
# define MASTER_RIGHT
# define POINTING_DEVICE_ROTATION_270
#endif

#ifdef POINTING_DEVICE_DRIVER_ps2
// The default streaming mode is flaky and doesn't always work. This setting
// doesn't seem to affect performance.
# define PS2_MOUSE_USE_REMOTE_MODE

// Serial uses PIO0, change PS2 to PIO1.
# define PS2_PIO_USE_PIO1

# if !defined(KEYBOARD_lily58_rev1)
#  define PS2_MOUSE_INVERT_X
#  define PS2_MOUSE_INVERT_Y
# endif

# define PS2_DATA_PIN GP2
# define PS2_CLOCK_PIN GP3

// Start faster when keyboard resets.
# define PS2_MOUSE_INIT_DELAY 500
#endif

// Sea-Picro bought with white LED use a different flash chip than the default
// QMK, uncomment this if flashing doesn't work properly. #define
// RP2040_FLASH_GD25Q64CS

/*****************************************************************************
 *                                   mugur                                   *
 *****************************************************************************/

// START-MUGUR-REGION

#undef TAPPING_TERM
#define TAPPING_TERM 180
#undef TAPPING_TERM_PER_KEY

#define LEADER_TIMEOUT 200
#undef LEADER_PER_KEY_TIMING
#define COMBO_COUNT 27
#define FORCE_NKRO
#undef RGBLIGHT_ANIMATIONS

// END-MUGUR-REGION

/* #define PERMISSIVE_HOLD */
/* #undef NO_AUTO_SHIFT_ALPHA */
