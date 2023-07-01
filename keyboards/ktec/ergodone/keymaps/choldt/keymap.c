#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  VRSN = SAFE_RANGE,
};

// Define combos
const uint16_t PROGMEM alt_combo[] = {KC_A, KC_D, COMBO_END};
const uint16_t PROGMEM change_workspace_combo[] = {KC_F, KC_J, COMBO_END};

combo_t key_combos[] = {
    COMBO(alt_combo, KC_LALT),
    COMBO(change_workspace_combo, OSL(5))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[0] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,     KC_3,    KC_4,    KC_5,   KC_LEFT,
        KC_TAB,         KC_Q,         KC_W,     KC_E,    KC_R,    KC_T,   TG(SYMB),
        CTL_T(KC_ESC),  KC_A,         KC_S,     KC_D,    KC_F,    KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,    KC_V,    KC_B,   ALL_T(KC_NO),
                        KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, MO(2),
                                                                          KC_TRNS,   KC_TRNS,
                                                                                     KC_TRNS,
                                                                    KC_SPC, KC_BSPC, KC_TRNS,
        // right hand
                    KC_TRNS, KC_6,   KC_7,             KC_8,    KC_9,    KC_0,      KC_MINS,
                    KC_TRNS, KC_Y,   KC_U,             KC_I,    KC_O,    KC_P,      KC_BSLS,
                             KC_H,   KC_J,             KC_K,    KC_L,    KC_SCLN,   LT(3, KC_NUBS),
                    KC_TRNS, KC_N,   KC_M,             KC_COMM, KC_DOT,  KC_SLSH,   KC_QUOT,
                                     KC_LT(1, KC_ENT), KC_LGUI, KC_TRNS, KC_TRNS,   KC_TRNS,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_BSPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EE_CLR  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[1] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
       KC_TRNS,   KC_CIRC, KC_0,    KC_DLR,  KC_PERC, KC_TRNS, KC_TRNS,
       KC_TRNS,   KC_EXLM, S(KC_2), S(KC_3), KC_DLR,  KC_PERC,
       KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                KC_TRNS, KC_TRNS,
                                                                         KC_TRNS,
                                                       KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
                  KC_TRNS, KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,
                  KC_TRNS, KC_6,    KC_7,    KC_8,     KC_9,     KC_10,   KC_TRNS,
                  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, KC_TRNS, KC_TRNS,
                           KC_CIRC, KC_AMPR, KC_ASTR,  KC_TRNS,  KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[2] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), KC_TRNS,
       CM_TOGG, KC_TRNS,    KC_TRNS,    KC_LPRN,    KC_LCBR,    KC_LBRC,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_GRV,     KC_MINS,    KC_UNDS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                         KC_TRNS, KC_TRNS,
                                                                                  KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, LGUI(KC_E), LGUI(KC_W), LGUI(KC_R), KC_TRNS, KC_TRNS,
                 KC_RBRC, KC_RCBR,    KC_RPRN,    KC_NUHS,    KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_EQL,  KC_PLUS,    KC_LT,      KC_GT,      KC_TRNS, KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[3] = LAYOUT_ergodox(
       QK_BOOT, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_SLEP,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                         KC_TRNS, KC_TRNS,
                                                                                  KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                 KC_MPRV, KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_MPLY, KC_MUTE,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[4] = LAYOUT_ergodox(
       KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_TRNS,
       KC_F13,  KC_F14,     KC_F15,     KC_F16,     KC_F17,     KC_F18,     KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                         KC_TRNS, KC_TRNS,
                                                                                  KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_F7,   KC_F8,      KC_F9,      KC_F10,     KC_F11,  KC_F12,
       KC_TRNS,  KC_F19,  KC_F20,     KC_F21,     KC_F22,     KC_F23,  KC_F24,
                 KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[5] = LAYOUT_ergodox(
       KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                         KC_TRNS, KC_TRNS,
                                                                                  KC_TRNS,
                                                                KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  LGUI(KC_6), LGUI(KC_7),    LGUI(KC_8),    LGUI(KC_9),    KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS,
                 KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS,
                             KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
  }
  return true;
}

bool led_update_user(led_t led_state) {
    // stub any kb level behaviour
    return false;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(layer_state)) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
