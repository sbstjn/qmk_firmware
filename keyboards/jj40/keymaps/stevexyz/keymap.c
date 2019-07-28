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
	LAYER_HOME, // home base layer
	LAYER_FUNC, // function keys and cursors
	LAYER_NUMS, // numbers and other characters
	LAYER_SYST, // media and other system keys
	LAYER_MOUS, // mouse layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_HOME] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, XXXXXXX,
		KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,  XXXXXXX, XXXXXXX,
		XXXXXXX, MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), LT(LAYER_FUNC, KC_C), LT(LAYER_NUMS, KC_V), MT(MOD_LSFT, KC_SPC), MT(MOD_RGUI,KC_B), MT(MOD_RALT, KC_N), MT(MOD_RCTL, KC_M), XXXXXXX, XXXXXXX ),

	[LAYER_FUNC] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, XXXXXXX,
		KC_ESC,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, XXXXXXX, XXXXXXX,
		XXXXXXX, KC_LCTL, KC_LALT, KC_TRNS, MO(LAYER_SYST), MT(MOD_LSFT, KC_SPC), KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX, XXXXXXX ),

	[LAYER_NUMS] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, XXXXXXX,
		KC_TAB,  KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, KC_DEL,  XXXXXXX, XXXXXXX,
		XXXXXXX, KC_LCTL, KC_LALT, MO(LAYER_SYST), KC_TRNS, MT(MOD_LSFT, KC_SPC), KC_COMM, KC_DOT, KC_SLSH, XXXXXXX, XXXXXXX ),

	[LAYER_SYST] = LAYOUT_ortho_4x12(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   TG(LAYER_FUNC), KC_PSCR, KC_SLCK,        KC_PAUS, KC_BSPC, XXXXXXX, XXXXXXX,
		KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_NO, MU_TOG,  TG(LAYER_MOUS), KC_INS,  XXXXXXX, XXXXXXX,
		XXXXXXX, KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, MT(MOD_LSFT, KC_SPC), BL_TOGG, BL_STEP, BL_BRTG, XXXXXXX, XXXXXXX ),

	[LAYER_MOUS] = LAYOUT_ortho_4x12(
		XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_MS_WH_UP,   KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_NO,          KC_NO,   KC_NO,   XXXXXXX, XXXXXXX,
		KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_NO,        KC_NO, KC_NO, KC_NO,        TG(LAYER_MOUS), KC_ENT,  XXXXXXX, XXXXXXX,
		XXXXXXX, KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, MT(MOD_LSFT, KC_SPC), KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX, XXXXXXX ),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
