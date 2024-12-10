/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "twpair_on_jis.h"
#include "os_detection.h"
#include "keymap_japanese.h"
#include <stdio.h>

// Left-hand home row mods
// layor0
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
// layor1
#define G_MINS LGUI_T(KC_MINS)
#define A_EQL LALT_T(KC_EQL)
#define C_LBRC LCTL_T(KC_LBRC)
#define S_RBRC LSFT_T(KC_RBRC)
// layor2
#define LG_XXXX LGUI_T(XXXXXXX)
#define A_XXXX LALT_T(XXXXXXX)
#define C_BTN1 LCTL_T(KC_BTN1)
#define S_BTN2 LSFT_T(KC_BTN2)

// Right-hand home row mods
// layor0
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)
// layor1
#define S_DOWN RSFT_T(KC_DOWN)
#define C_UP RCTL_T(KC_UP)
#define A_RIGHT LALT_T(KC_RIGHT)
#define G_QUOT RGUI_T(KC_QUOT)
// layor1
#define S_MS_D RSFT_T(KC_MS_D)
#define C_MS_U RCTL_T(KC_MS_U)
#define A_MS_R LALT_T(KC_MS_R)
#define RG_XXXX RGUI_T(XXXXXXX)

enum local_keycode {
  JIS_TGL = SAFE_RANGE,
  RGBRST
};

bool is_jis_mode = false;

void toggle_jis_mode(void) {
  is_jis_mode = !is_jis_mode;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   GUI_A,   ALT_S,   CTL_D,   SFT_F,    KC_G,                         KC_H,   SFT_J,   CTL_K,   ALT_L,GUI_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TAB, KC_BSPC,  RSFT_T(KC_SPC),     KC_ENT,   TO(1), KC_ESC
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  G_MINS,   A_EQL,  C_LBRC,  S_RBRC, KC_BSLS,                      KC_LEFT,  S_DOWN,    C_UP, A_RIGHT,  G_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_INT5, KC_INT4, _______, _______, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TAB, TO(0),  RSFT_T(KC_SPC),     KC_ENT,   TO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_GRAVE,                      XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LG_XXXX,  A_XXXX,  C_BTN1,  S_BTN2,  KC_DEL,                      KC_MS_L,  S_MS_D,  C_MS_U,  A_MS_R, RG_XXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX,   TO(3), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TAB,   TO(0),  RSFT_T(KC_SPC),     KC_ENT, TO(1), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, JIS_TGL,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TO(0),  KC_SPC,     KC_ENT,  TO(1), KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 1
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case 0:
	case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}

#ifdef RGB_MATRIX_ENABLE
void oled_render_rgb_matrix_state(void) {
  oled_write_P(PSTR("RGB: "), false);
  if (!rgb_matrix_is_enabled()) {
    oled_write_ln_P(PSTR("OFF"), false);
  } else {
    oled_write_ln_P(PSTR("ON"), false);
  }
}
#endif

void oled_render_jis_state(void) {
  if( is_jis_mode ) {
    oled_write_ln_P(PSTR("mode: jis"), false);
  } else {
    oled_write_ln_P(PSTR("mode: ansi"), false);
  }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
	oled_render_jis_state();
	#ifdef RGB_MATRIX_ENABLE
	oled_render_rgb_matrix_state();
	#endif
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case JIS_TGL:
      if (record->event.pressed) {
        toggle_jis_mode();
      }
      break;
    case RGBRST:
//      #ifdef RGBLIGHT_ENABLE
//        if (record->event.pressed) {
//          eeconfig_update_rgblight_default();
//          rgblight_enable();
//          rgb_current_mode = rgblight_config.mode;
//        }
//      #endif
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        }
      #endif
      break;

  }


  if (!is_jis_mode) {
    return true;
  }

  switch(keycode) {
	  case G_MINS:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_MINS, record);
		  } else {
			  tap_code16(KC_LGUI);
			  return false;
		 }
	  case A_EQL:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_EQL, record);
		  } else {
			  tap_code16(KC_LALT);
			  return false;
		 }
	  case C_LBRC:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_LBRC, record);
		  } else {
			  tap_code16(KC_LCTL);
			  return false;
		 }
	  case C_BTN1:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_BTN1, record);
		  } else {
			  tap_code16(KC_LCTL);
			  return false;
		 }
	  case S_BTN2:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_BTN2, record);
		  } else {
			  tap_code16(KC_LSFT);
			  return false;
		 }
	  case GUI_SCLN:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_SCLN, record);
		  } else {
			  tap_code16(KC_RGUI);
			  return false;
		 }
	  case S_DOWN:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_DOWN, record);
		  } else {
			  tap_code16(KC_RSFT);
			  return false;
		 }
	  case C_UP:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_UP, record);
		  } else {
			  tap_code16(KC_RCTL);
			  return false;
		 }
	  case A_RIGHT:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_RIGHT, record);
		  } else {
			  tap_code16(KC_LALT);
			  return false;
		 }
	  case G_QUOT:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_QUOT, record);
		  } else {
			  tap_code16(KC_RGUI);
			  return false;
		 }
	  case S_MS_D:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_MS_D, record);
		  } else {
			  tap_code16(KC_RSFT);
			  return false;
		 }
	  case C_MS_U:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_MS_U, record);
		  } else {
			  tap_code16(KC_RCTL);
			  return false;
		 }
	  case A_MS_R:
		  if (record->tap.count) {
			  return twpair_on_jis(KC_MS_R, record);
		  } else {
			  tap_code16(KC_LALT);
			  return false;
		 }
  }

  

  if (keycode == RGUI_T(KC_SCLN) && record->tap.count) {
    return twpair_on_jis(KC_SCLN, record);
  } else if (keycode == RGUI_T(KC_SCLN) && !record->tap.count) {
    tap_code16(KC_RGUI);
    return false;
  }

  return twpair_on_jis(keycode, record);
}
#endif // OLED_ENABLE

uint32_t startup_exec(uint32_t trigger_time, void *cb_arg) {
  os_variant_t os_type;
  if(is_keyboard_master()) {
    os_type = detected_host_os();
    switch (os_type) {
      case  OS_WINDOWS:
        is_jis_mode = true;
	break;
      default:
        is_jis_mode = false;
    }
  }

  return os_type ? 0 : 500;
}


void keyboard_post_init_user(void) {
  defer_exec(100, startup_exec, NULL);
  #ifdef DEBUG_ENABLE
   debug_enable=false;
   debug_matrix=false;
   debug_keyboard=false;
  #endif
}

