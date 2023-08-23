# Copyright 2022 Trey Peacock

# This program is free software : you can redistribute it and / or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.If not, see < http: // www.gnu.org/licenses/>.
# 5724 with custom 5934 without =  210 Custom Shift
# 5934 without autoshift 4736 with = 1198 Autoshift
# Optimize size but this may cause error "relocation truncated to fit"

LAYER_LOCK_ENABLE           = yes
CUSTOM_SHIFT_ENABLE         = yes
SWAP_KEYS_ENABLE            = yes
HISTORY_ENABLE              = yes
NUMWORD_ENABLE              = yes
REPEAT_KEYS_ENABLE          = yes
CUSTOM_TAPHOLD_ENABLE       = yes
ESC_MOD_ENABLE              = yes
OS_TOGGLE_ENABLE            = yes
ADAPTIVE_KEYS_ENABLE        = no
ACHORDION_ENABLE			= yes

EXTRALDFLAGS                = -Wl,--relax
SEND_STRING_ENABLE          = yes       # Enable Send String
BOOTMAGIC_ENABLE            = yes       # Enable Bootmagic Lite
LTO_ENABLE                  = yes       # link time optimization to shrink size
MOUSEKEY_ENABLE             = yes       # Emulate mouse using keyboard
EXTRAKEY_ENABLE             = yes       # Audio and System control
TAP_DANCE_ENABLE            = no        # Tap Dance
LEDER_ENABLE                = no        # Disable Leader by default
CONSOLE_ENABLE              = no		# Disable Console for debug
COMMAND_ENABLE              = no		# Deprecated magic commands
MAGIC_ENABLE                = no		# Magic commands after init
SPACE_CADET_ENABLE          = no		# Space Cadet Features
KEY_LOCK_ENABLE             = no		# Not using Key Lock
NKRO_ENABLE                 = no		# Disable N-Key Rollover
AUDIO_ENABLE                = no		# Audio direct from keyboard to speaker
MUSIC_ENABLE                = no		# Maps columns/rows to chromatic/octaves
RGBLIGHT_ENABLE             = no		# RGB LED controls
RGB_MATRIX_ENABLE           = no		# RGB Matrix lighting
OLED_ENABLE                 = no		# Oled capability
CAPS_WORD_ENABLE            = yes
GRAVE_ESC_ENABLE            = no
AUTO_SHIFT_ENABLE           = no
COMBO_ENABLE                = yes
DYNAMIC_TAPPING_TERM_ENABLE = no

SRC += $(USER_PATH)/core/keycodes.c
SRC += $(USER_PATH)/features/process_record.c
VPATH += $(USER_PATH)/features

ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	SRC += $(USER_PATH)/features/achordion.c
	OPT_DEFS += -DACHORDION_ENABLE
endif
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += $(USER_PATH)/features/combo.c
endif
ifndef NO_ACTION_TAPPING
	SRC += $(USER_PATH)/features/tapping.c
endif
ifeq ($(strip $(ESC_MOD_ENABLE)), yes)
	SRC += $(USER_PATH)/features/esc_mod.c
endif
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += quantum/caps_word.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += $(USER_PATH)/features/tap_dance.c
endif
ifeq ($(strip $(LAYER_LOCK_ENABLE)), yes)
	SRC += $(USER_PATH)/features/layer_lock.c
	OPT_DEFS += -DLAYER_LOCK_ENABLE
endif
ifeq ($(strip $(ADAPTIVE_KEYS_ENABLE)), yes)
	OPT_DEFS += -DADAPTIVE_KEYS_ENABLE
endif
ifeq ($(strip $(NUMWORD_ENABLE)), yes)
	SRC += $(USER_PATH)/features/num_word.c
	OPT_DEFS += -DNUMWORD_ENABLE
endif
ifeq ($(strip $(HISTORY_ENABLE)), yes)
	SRC += $(USER_PATH)/features/history.c
	OPT_DEFS += -DHISTORY_ENABLE
endif
ifeq ($(strip $(REPEAT_KEYS_ENABLE)), yes)
	SRC += $(USER_PATH)/features/repeat_key.c
	OPT_DEFS += -DREPEAT_KEYS_ENABLE
endif
ifeq ($(strip $(CUSTOM_TAPHOLD_ENABLE)), yes)
	SRC += $(USER_PATH)/features/custom_taphold.c
	OPT_DEFS += -DCUSTOM_TAPHOLD_ENABLE
endif
ifeq ($(strip $(CUSTOM_SHIFT_ENABLE)), yes)
	SRC += $(USER_PATH)/features/custom_shift_keys.c
	OPT_DEFS += -DCUSTOM_SHIFT_ENABLE
endif
ifeq ($(strip $(SWAP_KEYS_ENABLE)), yes)
	SRC += $(USER_PATH)/features/swap_keys.c
	OPT_DEFS += -DSWAP_KEYS_ENABLE
endif
ifeq ($(strip $(OS_TOGGLE_ENABLE)), yes)
	SRC += $(USER_PATH)/core/os_toggle.c
	OPT_DEFS += -DOS_TOGGLE_ENABLE
endif
