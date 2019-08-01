/* Copyright 2019 Stefano Marago'
 *
 * This program is free software: you can redistribute it and/or modify
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

#include QMK_KEYBOARD_H

enum layers {
	LAYER_HOME,    // home base layer
	LAYER_FUNC,    // function keys and cursors
	LAYER_NUMS,    // numbers and other characters
	LAYER_SYST,    // media and other system keys
        LAYER_NUMONLY, // numeric keypad
        LAYER_LIGHTS,  // numeric keypad
	LAYER_MOUS,    // mouse layer
};

/*
enum {
  TD_ENT_BSPC = 0,
  TD_KPENT_BSPC = 0,
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ENT_BSPC]  = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_BSPC),
  [TD_KPENT_BSPC]  = ACTION_TAP_DANCE_DOUBLE(KC_KP_ENTER, KC_BSPC),
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_HOME] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, 
                XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,  XXXXXXX,
                XXXXXXX, XXXXXXX, MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), LT(LAYER_FUNC, KC_C), LT(LAYER_NUMS, KC_V), MT(MOD_LSFT, KC_SPC), MT(MOD_RGUI,KC_B), MT(MOD_RALT, KC_N), MT(MOD_RCTL, KC_M), XXXXXXX, XXXXXXX ),

	[LAYER_FUNC] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,                KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, 
                XXXXXXX, KC_ESC,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,         KC_LEFT,              KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, XXXXXXX, 
                XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, KC_TRNS, MO(LAYER_SYST), MT(MOD_LSFT, KC_SPC), KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX, XXXXXXX ),

	[LAYER_NUMS] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,           KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
                XXXXXXX, KC_TAB,  KC_GRV,  KC_MINS, KC_EQL,         KC_LBRC, KC_RBRC,              KC_BSLS, KC_SCLN, KC_QUOT, KC_DEL,  XXXXXXX,
                XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, MO(LAYER_SYST), KC_TRNS, MT(MOD_LSFT, KC_SPC), KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, XXXXXXX ),

	[LAYER_SYST] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,          XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,
                XXXXXXX, KC_F11,  KC_F12,  TG(LAYER_NUMONLY), TG(LAYER_LIGHTS), KC_NO,   KC_NO,                KC_NO,   KC_NO,   TG(LAYER_MOUS),  KC_BSPC, XXXXXXX, 
                XXXXXXX, KC_CAPS, KC_MUTE, KC_VOLD,           KC_VOLU,          KC_MPLY, KC_MNXT,              KC_NO,   KC_NO,   KC_NLCK,         KC_INS,  XXXXXXX,
                XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT,           KC_TRNS,          KC_TRNS, MT(MOD_LSFT, KC_SPC), KC_PSCR, KC_SLCK, KC_PAUS,         XXXXXXX, XXXXXXX ),

        [LAYER_NUMONLY] = LAYOUT_ortho_4x12(
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,     XXXXXXX,        XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,
                XXXXXXX, KC_NO,   KC_NO,   TG(LAYER_NUMONLY), KC_KP_EQUAL, KC_KP_ASTERISK, KC_KP_PLUS,  KC_P7,   KC_P8,   KC_P9,   KC_P0,       XXXXXXX,
                XXXXXXX, KC_TAB,  KC_LPRN, KC_RPRN,           KC_KP_COMMA, KC_KP_SLASH,    KC_KP_MINUS, KC_P4,   KC_P5,   KC_P6,   KC_KP_ENTER, XXXXXXX,
                XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT,           KC_NO,       KC_NO,          KC_KP_DOT,   KC_P1,   KC_P2,   KC_P3,   XXXXXXX,     XXXXXXX ),

        [LAYER_LIGHTS] = LAYOUT_ortho_4x12(
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                XXXXXXX, KC_NO,   KC_NO,   KC_NO,   TG(LAYER_LIGHTS), KC_NO,   RGB_HUI, RGB_SAI,  RGB_VAI, KC_NO,   KC_NO,   XXXXXXX, 
                XXXXXXX, KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   RGB_HUD, RGB_SAD,  RGB_VAD, KC_NO,   RGB_TOG, XXXXXXX,
                XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, KC_NO,            KC_NO,   RGB_MOD, RGB_RMOD, RGB_M_B, RGB_M_P, XXXXXXX, XXXXXXX ),

	[LAYER_MOUS] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,      XXXXXXX,              XXXXXXX,      XXXXXXX,  XXXXXXX,        XXXXXXX, XXXXXXX, 
                XXXXXXX, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_MS_WH_UP,   KC_MS_ACCEL0, KC_MS_ACCEL1,         KC_MS_ACCEL2, KC_NO,    TG(LAYER_MOUS), KC_NO,   XXXXXXX, 
                XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_NO,        KC_NO,                KC_NO,        KC_NO,    KC_NO,          KC_ENT,  XXXXXXX, 
                XXXXXXX, XXXXXXX,    KC_LCTL,    KC_LALT,     KC_NO,         KC_NO,        MT(MOD_LSFT, KC_SPC), KC_RGUI,      KC_RALT,  KC_RCTL,        XXXXXXX, XXXXXXX ),

};

void matrix_init_user(void) {
  // set num lock on at start independently of state (for numonly layer to work)
  if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
      register_code(KC_NUMLOCK);

      unregister_code(KC_NUMLOCK);
  }
}

void matrix_scan_user(void) {
}
