# -*- buffer-read-only: t -*-
# Copyright 2022 Trey Peacock

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

USER_NAME := tpeacock19
SRC += tpeacock19.c

LAYER_LOCK_ENABLE           = yes
CUSTOM_SHIFT_ENABLE         = yes
SWAP_KEYS_ENABLE            = yes
HISTORY_ENABLE              = yes
NUMWORD_ENABLE              = yes
CUSTOM_REPEAT_KEY_ENABLE	= yes
REPEAT_KEY_ENABLE           = no
CUSTOM_TAPHOLD_ENABLE       = yes
ESC_MOD_ENABLE              = yes
OS_TOGGLE_ENABLE            = yes
ADAPTIVE_KEYS_ENABLE        = no
ACHORDION_ENABLE			= yes


######################################################################
#                               Elite-C                               #
######################################################################

# for Elite-C controller
undefine BOOTLOADER
BOOTLOADER = atmel-dfu

######################################################################
#                                mugur                                #
######################################################################

 # START-MUGUR-REGION

 FORCE_NKRO       = yes
LEADER_ENABLE    = no
RGBLIGHT_ENABLE  = no
TAP_DANCE_ENABLE = no
COMBO_ENABLE     = yes 

# END-MUGUR-REGION                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

