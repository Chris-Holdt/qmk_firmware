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

// Define combos
const uint16_t PROGMEM alt_combo[] = {KC_A, KC_D, COMBO_END};
const uint16_t PROGMEM change_workspace_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM zellij_combo[] = {KC_S, KC_F, COMBO_END};

// Tap dance dfinitions
enum {
    TD_MS,
};

enum custom_keycodes {
    MAC_SES_SW = SAFE_RANGE,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_MS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, 6)
};

combo_t key_combos[] = {
    COMBO(alt_combo, KC_LALT),
    COMBO(change_workspace_combo, OSL(5)),
    COMBO(zellij_combo, TG(7))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------.                               ,-------------------------------------------------------------.
      KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                     KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_DEL,
  //|---------------+--------+--------+--------+--------+--------|                                |--------+--------+--------+--------+--------+----------------|
      CTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,  LT(3, KC_NUBS),
  //|---------------+--------+--------+--------+--------+--------|                                |--------+--------+--------+--------+--------+----------------|
      KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                     KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_QUOT,
  //|---------------+--------+--------+--------+--------+--------+-------------|    |-------------+--------+--------+--------+--------+--------+----------------|
                                                  LT(4, KC_GRV), TT(2), KC_SPC,      SFT_T(KC_BSPC), LT(1, KC_ENT), TD(TD_MS)
                                             //`-------------------------------'    `--------------------------------------'

  ),

    [1] = LAYOUT_split_3x6_3( // ^ = first char, $ = end of line, % = matching char e.g ({[]}), 0 = start of line
                              // Bottom row: ! " £ $ %    ^ & * ( )
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_TRNS,
  //|--------+--------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_CIRC, KC_0,    KC_DLR,  KC_PERC, KC_TRNS,                      KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_TRNS,KC_TRNS,
  //|--------+--------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_EXLM, S(KC_2),  S(KC_3), KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+---------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, TO(0),  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3( // Programming symbols. Right U, I, O: switch to screen left, middle, right
  //,--------------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,  LGUI(KC_E),  LGUI(KC_W),  LGUI(KC_R),  KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
    // Toggle combos
      CM_TOGG,    KC_TRNS,     KC_TRNS,     KC_LPRN,     KC_LCBR,     KC_LBRC,                        KC_RBRC,  KC_RCBR,     KC_RPRN,     KC_NUHS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_GRV,      KC_MINS,     KC_UNDS,                        KC_EQL,   KC_PLUS,     KC_LT,       KC_GT,       KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------+---------| |--------+---------+------------+------------+---------+--------+--------|
                                                         KC_TRNS,     TO(0),     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS
                                                    //`----------------------------------' `--------------------------------'
  ),


    [3] = LAYOUT_split_3x6_3( // Boot, Sleep, media control
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_MPLY, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, TO(0),  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),


    [4] = LAYOUT_split_3x6_3( // F keys
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_F12,  KC_F13,  KC_F14, KC_F15,  KC_F16,                       KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_F22,  KC_F23,  KC_F24, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, TO(0),  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [5] = LAYOUT_split_3x6_3( // Workspace switching
  //,--------------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
      KC_TRNS,   LGUI(KC_1),  LGUI(KC_2),  LGUI(KC_3),  LGUI(KC_4), LGUI(KC_5),                       LGUI(KC_6),  LGUI(KC_7),  LGUI(KC_8),  LGUI(KC_9),  KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------+---------| |--------+---------+------------+------------+---------+--------+--------|
                                                         KC_TRNS,     TO(0),     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS
                                                    //`----------------------------------' `--------------------------------'
  ),

    [6] = LAYOUT_split_3x6_3( // Mouse
  //,--------------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
      KC_TRNS,    KC_TRNS,     KC_MS_U,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_MS_L,     KC_MS_D,     KC_MS_R,     KC_TRNS,     KC_TRNS,                        KC_MS_L,     KC_MS_D,     KC_MS_U,     KC_MS_R,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_WH_D,     KC_WH_U,     KC_BTN1,     KC_BTN2,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------+---------| |--------+---------+------------+------------+---------+--------+--------|
                                                         KC_TRNS,     TO(0),     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS
                                                    //`----------------------------------' `--------------------------------'
  ),

    [7] = LAYOUT_split_3x6_3( // Macros
  //,--------------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
      KC_TRNS,    KC_TRNS,     MAC_SES_SW,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_TRNS,     KC_TRNS,     CW_TOGG,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------+---------| |--------+---------+------------+------------+---------+--------+--------|
                                                         KC_TRNS,     TO(0),     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS
                                                    //`----------------------------------' `--------------------------------'
  )

    /* [6] = LAYOUT_split_3x6_3( // Template
  //,--------------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------|                    |---------+------------+------------+------------+---------+--------|
      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
  //|----------+------------+------------+------------+------------+-----------+---------| |--------+---------+------------+------------+---------+--------+--------|
                                                         KC_TRNS,     TO(0),     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS
                                                    //`----------------------------------' `--------------------------------'
  ) */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC_SES_SW:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("go") "w" SS_LCTL("g"));
                layer_invert(7);
            }
            return false;

    }

    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }

    return rotation;
}

static void render_layer(void) {

    oled_clear();
    oled_write_P(PSTR("Layer"), false);

    switch(get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            break;

        case 1:
            oled_write_P(PSTR("Num & Move\n"), false);
            break;

        case 2:
            oled_write_P(PSTR("Code & Monitors\n"), false);
            break;

        case 3:
            oled_write_P(PSTR("Controls\n"), false);
            break;

        case 4:
            oled_write_P(PSTR("Fn Keys\n"), false);
            break;

        case 5:
            oled_write_P(PSTR("Workspace\n"), false);
            break;

        case 6:
            oled_write_P(PSTR("Mouse\n"), false);
            break;

        default:
            oled_write_ln_P(PSTR("No idea"), false);
    }
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        153,154,10,
        185,186,0
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer();
    } else {
        render_logo();
    }

    return false;
}
#endif
