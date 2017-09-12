#include QMK_KEYBOARD_H
#include "debug.h"
#include "led.h"
#include "action_layer.h"
#include "version.h"

#define MAC  0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define PC   3 // pc layer

#define FN_1 MT(KC_F1, KC_1)
#define FN_2 MT(KC_F2, KC_2)
#define FN_3 MT(KC_F3, KC_3)
#define FN_4 MT(KC_F4, KC_4)
#define FN_5 MT(KC_F5, KC_5)
#define FN_6 MT(KC_F6, KC_6)
#define FN_7 MT(KC_F7, KC_7)
#define FN_8 MT(KC_F8, KC_8)
#define FN_9 MT(KC_F9, KC_9)
#define FN_10 MT(KC_F10,KC_0)

/*
  Hold/tap: MT(hold/tap)
 */

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Mac layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |1/F1  |2/F2  |3/F3  |4/F4  |5/F5  | LEFT |           | RIGHT|6/F6  |7/F7  |8/F8  |9/F9  |0/F10 |-/F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | SYMB |           | PC   |   Y  |   U  |   I  |   O  |   P  |\/F12    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       | Down |  Up  |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LGui | LAlt |       | Ctrl | LGui   |
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Backsp|Delete|------|       |------|  Enter |Space |
 *                                 |ace   |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[MAC] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,            FN_1,           FN_2,             FN_3,           FN_4,          FN_5,           KC_LEFT,
        KC_TAB,            KC_Q,           KC_W,             KC_E,           KC_R,          KC_T,           TT(SYMB),
        KC_ESC,            KC_A,           KC_S,             KC_D,           KC_F,          KC_G,
        KC_LSFT,           CTL_T(KC_Z),    KC_X,             KC_C,           KC_V,          KC_B,           ALL_T(KC_NO),
        LT(SYMB,KC_GRV),   KC_QUOT,        LALT(KC_LSFT),    KC_LEFT,        KC_RGHT,
                                                                                              KC_LGUI,  KC_LALT,
                                                                                                        KC_HOME,
                                                                                         KC_BSPC,KC_DEL,KC_END,
        // right hand
              KC_RGHT,     FN_6,         FN_7,       FN_8,     FN_9,      FN_10,              MT(KC_F11,KC_MINS),
              TG(PC),      KC_Y,         KC_U,       KC_I,     KC_O,      KC_P,               MT(KC_F12,KC_BSLS),
                           KC_H,         KC_J,       KC_K,     KC_L,      LT(MDIA, KC_SCLN),  GUI_T(KC_QUOT),
        MEH_T(KC_NO),      KC_N,         KC_M,       KC_COMM,  KC_DOT,    CTL_T(KC_SLSH),     KC_RSFT,
                           KC_DOWN,      KC_UP,      KC_LBRC,  KC_RBRC,   KC_FN1,
        KC_RCTRL,          KC_LGUI,
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------| MAC  |           | PC   |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift   |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  | Shift  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
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
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,TO(MAC),
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_LSFT,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       TG(PC),  KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_RSFT,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
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
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: PC layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |1/F1  |2/F2  |3/F3  |4/F4  |5/F5  | LEFT |           | RIGHT|6/F6  |7/F7  |8/F8  |9/F9  |0/F10 |-/F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | SYMB |           | MAC  |   Y  |   U  |   I  |   O  |   P  |\/F12    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       | Down |  Up  |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LAlt | LGui |       | Ctrl |Ctrl/Esc|
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Backsp|Delete|------|       |------|  Enter |Space |
 *                                 |ace   |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[PC] = LAYOUT_ergodox(  // layer 3 : default
        // left hand
        KC_EQL,            FN_1,           FN_2,             FN_3,           FN_4,          FN_5,           KC_LEFT,
        KC_TAB,            KC_Q,           KC_W,             KC_E,           KC_R,          KC_T,           TO(SYMB),
        KC_ESC,            KC_A,           KC_S,             KC_D,           KC_F,          KC_G,
        KC_LSFT,           CTL_T(KC_Z),    KC_X,             KC_C,           KC_V,          KC_B,           ALL_T(KC_NO),
        LT(SYMB,KC_GRV),   KC_QUOT,        LALT(KC_LSFT),    KC_LEFT,        KC_RGHT,
                                                                                              KC_LALT,  KC_LGUI,
                                                                                                        KC_HOME,
                                                                                         KC_BSPC,KC_DEL,KC_END,
        // right hand
              KC_RGHT,     FN_6,         FN_7,       FN_8,     FN_9,      FN_10,              MT(KC_F11,KC_MINS),
              TO(MAC),     KC_Y,         KC_U,       KC_I,     KC_O,      KC_P,               MT(KC_F12,KC_BSLS),
                           KC_H,         KC_J,       KC_K,     KC_L,      LT(MDIA, KC_SCLN),  GUI_T(KC_QUOT),
        MEH_T(KC_NO),      KC_N,         KC_M,       KC_COMM,  KC_DOT,    CTL_T(KC_SLSH),     KC_RSFT,
                           KC_DOWN,      KC_UP,      KC_LBRC,  KC_RBRC,   KC_FN1,
        KC_RCTRL,          ALL_T(KC_NO),
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_SPC
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();

  if ((layer & 0b001) > 0) {
    ergodox_right_led_1_on();
  } else {
    ergodox_right_led_1_off();
  }
  if ((layer & 0b010) > 0) {
    ergodox_right_led_2_on();
  } else {
    ergodox_right_led_2_off();
  }
  if ((layer & 0b100) > 0) {
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
};
