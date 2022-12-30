#include QMK_KEYBOARD_H


enum layer_names {
    _BASE,
    _NUM,
    _EXT,
    _SYM,
    _FUN,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  NUM,
  EXT,
  SYM,
  FUN,
};

// #define _BASE 0
// #define _EXT  1
// #define _NUM  2
// #define _SYM  3
// #define _FUN  4

#define NAK  KC_NO

// FUN for MAC
#define KC_CUT KC_F22
#define KC_CPY KC_F23
#define KC_PST KC_F24
#define KC_UNDO KC_F20
#define KC_REDO KC_F21

#define VOLUP KC_KB_VOLUME_UP
#define VOLDN KC_KB_VOLUME_DOWN
#define MUTE  KC_KB_MUTE
#define PLAY  KC_MEDIA_PLAY_PAUSE

// #define MY_2SYM MO(_SYM)
// #define MY_2NUM MO(_NUM)
// #define MY_2EXT MO(_EXT)
#define NUM MO(_NUM)

#define MY_CUT  LGUI(KC_X)
#define MY_COPY LGUI(KC_C)
#define MY_PSTE LGUI(KC_V)
#define MY_UNDO LGUI(KC_Z)
#define MY_SAVE LGUI(KC_S)
#define MY_ATAB LGUI(KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Dvorak
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC`~|  :;  |  ,<  |  .>  |   P  |   Y  |  [{  |                    |  ]}  |   F  |   G  |   C  |   R  |   L  |  /?  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |   A  |   O  |   I  |   E  |   U  |   (  |                    |   )  |   D  |   H  |   T  |   N  |   S  |  -_  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|  '"  |   Q  |   J  |   K  |   X  |  =+  |                    | Del  |   B  |   M  |   W  |   V  |   Z  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl | Alt  |  NUM | Gui  ||||||||  EXT | Space| Enter|||||||| Bspc | Enter|SYMFUN|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_BASE] = LAYOUT(
    QK_GESC, KC_SCLN, KC_COMM,  KC_DOT,   KC_P,   KC_Y,  KC_LBRC,                           KC_RBRC, KC_F,  KC_G,    KC_C,    KC_R,    KC_L,   KC_SLSH, 
		KC_TAB,  KC_A,    KC_O,     KC_E,     KC_U,   KC_I,  KC_LPRN,                           KC_RPRN, KC_D,  KC_H,    KC_T,    KC_N,    KC_S,   KC_MINS, 
		KC_LSFT, KC_QUOT, KC_Q,     KC_J,     KC_K,   KC_X,  KC_EQL,                            KC_DEL,  KC_B,  KC_M,    KC_W,    KC_V,    KC_Z,   KC_RSFT, 
		KC_LCTL, KC_LALT, NUM,      KC_LGUI,          EXT,   KC_SPC,  KC_ENT,         KC_BSPC,  KC_ENT,  SYM,            KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT
  ),
  
  /* NUM
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |   1  |  2   |  3   |  4   |  5   |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |   4  |   5  |   6  |   -  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |      |                    |      |      |   1  |   2  |   3  |   +  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl | Alt  |(HOLD)| Gui  ||||||||      |      |      |||||||| TRNS | TRNS | TRNS ||||||||   0  |  .   |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_NUM] = LAYOUT(
    NAK,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    NAK,                   NAK,     KC_6,   KC_P7,  KC_P8,  KC_P9,   KC_P0,   NAK,
    NAK,      NAK,     NAK,     NAK,     NAK,     NAK,     NAK,                   NAK,     NAK,    KC_P4,  KC_P5,  KC_P6,   KC_PMNS, NAK,
    KC_LSFT,  NAK,     NAK,     NAK,     NAK,     NAK,     NAK,                   NAK,     NAK,    KC_P1,  KC_P2,  KC_P3,   KC_PPLS, KC_RSFT,
    KC_LCTL, KC_LALT,  NUM,     KC_LGUI,          NAK,     NAK,  NAK,       NAK,  NAK,     NAK,            KC_P0,  KC_PDOT, KC_ENT,  NAK
  ),
  
  /* EXT
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |  7   |  5   |  3   |   1  |   9  | Play |                    | Vol+ |   0  |  2   |  4   |  6   |  8   |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |AltTAB|      |      |      |      | PgUp | Mute |                    | Vol- |      | Home |  Up  |  End | Save |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift| Undo | Cut  | Copy | Paste| PgDn |      |                    | TRNS |      | Left | Down | Right| Undo | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl | Alt  |  NUM | Gui  ||||||||(HOLD)| TRNS | TRNS |||||||| TRNS | TRNS |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_EXT] = LAYOUT(
    KC_ESC,  KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    PLAY,                       VOLUP,   KC_0,    KC_2,    KC_4,    KC_6,    KC_8,     NAK,
    MY_ATAB, NAK,     NAK,     NAK,     NAK,     KC_PGUP, MUTE,                       VOLDN,   NAK,     KC_HOME, KC_UP,   KC_END,  MY_SAVE,  NAK,
    KC_LSFT, MY_UNDO, MY_CUT,  MY_COPY, MY_PSTE, KC_PGDN, NAK,                        KC_TRNS, NAK,     KC_LEFT, KC_DOWN, KC_RGHT, MY_UNDO,  KC_RSFT,
    KC_LCTL, KC_LALT, NUM,      KC_LGUI,          EXT,     KC_TRNS,  NAK,    KC_TRNS, KC_TRNS, SYM,              NAK,     NAK,     NAK,      NAK 
  ),

  /* SYM
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |  %   |  {   |                    |  }   |   ^  |   &  |   *  |      |      |  \|  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |  =   |      |                    |      |      | Home |  Up  | End  |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      | Left | Down | Right|      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |||||||| EXT  | SPC  | TAB  ||||||||      |(HOLD)|      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_SYM] = LAYOUT(
    KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH, KC_DLR,  KC_PERC,  KC_LCBR,                    KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, NAK,     NAK,     KC_BSLS,
    NAK,      NAK,      NAK,      NAK,     KC_EQL,  NAK,      NAK,                        NAK,     NAK,     KC_TRNS, KC_TRNS, KC_TRNS, NAK,     NAK,
    KC_LSFT,  NAK,      NAK,      NAK,     NAK,     NAK,      NAK,                        NAK,     NAK,     KC_TRNS, KC_TRNS, KC_TRNS, NAK,     NAK,
    KC_LCTL, KC_LALT,   NUM,      KC_LGUI,          EXT,      NAK,  NAK,           NAK,   SYM,     NAK,              NAK,     NAK,     NAK,     NAK 
  ),

  /* FUN
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F5  |  F6  |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    | Mute |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    | Mute |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||(HOLD)| SPC  | TAB  ||||||||      |      |(HOLD)||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_FUN] = LAYOUT(
    NAK,      NAK,     KC_F7,   KC_F8,   KC_F9,   NAK,  NAK,                        NAK,     NAK,     NAK,     NAK,     NAK,     NAK,     NAK,
    NAK,      NAK,     KC_F4,   KC_F5,   KC_F6,   NAK,  NAK,                        NAK,     NAK,     KC_TRNS, KC_TRNS, KC_TRNS, NAK,     NAK,
    KC_LSFT,  NAK,     KC_F1,   KC_F2,   KC_F3,   NAK,  NAK,                        NAK,     NAK,     KC_TRNS, KC_TRNS, KC_TRNS, NAK,     NAK,
    KC_LCTL,  KC_LALT, NUM,     KC_LGUI,          EXT,  KC_SPC, KC_TAB,    KC_BSPC, KC_TRNS, EXT,              NAK,     NAK,     NAK,     NAK 
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case WINDOWS:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_WINDOWS);
    //   }
    //   return false;
    //   break;
    // case LINUX:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_LINUX);
    //   }
    //   return false;
    //   break;
    case EXT:
      if (record->event.pressed) {
        layer_on(_EXT);
        update_tri_layer(_EXT, _SYM, _FUN);
      } else {
        layer_off(_EXT);
        update_tri_layer(_EXT, _SYM, _FUN);
      }
      return false;
      break;
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
        update_tri_layer(_EXT, _SYM, _FUN);
      } else {
        layer_off(_SYM);
        update_tri_layer(_EXT, _SYM, _FUN);
      }
      return false;
      break;
    case FUN:
      if (record->event.pressed) {
        layer_on(_FUN);
      } else {
        layer_off(_FUN);
      }
      return false;
      break;
  }
  return true;
}

/* NAV
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */

// /* Adjust
//  * ,----------------------------------------------------------------------------------------------------------------------.
//  * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
//  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
//  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
//  * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
//  * ,----------------------------------------------------------------------------------------------------------------------.
//  */
// [_ADJUST] = LAYOUT(
//   _______, QK_BOOT  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
//   _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
// )