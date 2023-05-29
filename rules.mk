BOOTLOADER = qmk-hid
BOOTLOADER_SIZE = 512
MCU = atmega32u4
LTO_ENABLE = yes

#Disable unused features
VIA_ENABLE = no
NKRO_ENABLE = no
AUDIO_ENABLE = no
MAGIC_ENABLE = no
STENO_ENABLE = no
DEBUG_ENABLE = no
LEADER_ENABLE = no
ENCODER_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
UNICODE_ENABLE = no
TERMINAL_ENABLE = no
KEY_LOCK_ENABLE = no
SPACE_CADET_ENABLE = no

#Enable common
WAIT_FOR_USB = yes
BOOTMAGIC_ENABLE= no
CAPS_WORD_ENABLE = yes      # Enable shift+shift for caps word
EXTRAKEY_ENABLE = yes       # Audio control and System control

ifeq ($(strip $(KEYBOARD)), splitkb/aurora/corne/rev1)
	SPLIT_KEYBOARD = yes

	RGB_MATRIX_ENABLE =  yes
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_CUSTOM_USER = no

	OLED_ENABLE = yes
	MOUSEKEY_ENABLE = yes
	AUTO_SHIFT_ENABLE = no
	COMBO_ENABLE = yes

	WPM_ENABLE = no
endif