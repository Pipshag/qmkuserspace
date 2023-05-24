#Disable unused features
VIA_ENABLE = no
WPM_ENABLE = no
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
MOUSEKEY_ENABLE = no
TERMINAL_ENABLE = no
KEY_LOCK_ENABLE = no
RGBLIGHT_ENABLE = no
SLEEP_LED_ENABLE = no
TAP_DANCE_ENABLE = no
VELOCIKEY_ENABLE = no
SWAP_HANDS_ENABLE = no
SPACE_CADET_ENABLE = no

#Enable common
LTO_ENABLE = yes
WAIT_FOR_USB = yes
BOOTMAGIC_ENABLE= yes
AUTO_SHIFT_ENABLE = no		# Enable automatic shifted characters
CAPS_WORD_ENABLE = yes      # Enable shift+shift for caps word
EXTRAKEY_ENABLE = yes       # Audio control and System control

ifeq ($(strip $(KEYBOARD)), splitkb/aurora/corne/rev1)
	SPLIT_KEYBOARD = yes

	RGB_MATRIX_ENABLE =  yes
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_CUSTOM_USER = no

	MOUSEKEY_ENABLE = yes       # Mouse keys
	WPM_ENABLE = yes
	AUTO_SHIFT_ENABLE = no

	OLED_ENABLE = yes
    SRC += oled/corne_oled.c
endif

SRC += pipshag.c 				# Include code
SRC += rgb/rgb.c
