#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// legibility
#define _____ KC_TRNS
#define __x__ KC_NO

// macros
#define M_LPRN 0 // lsft + lprn
#define M_RPRN 1 // rsft + rprn

enum planck_layers {
  _L_ZERO,  // base
  _L_ONE,   // base extension
  _L_TWO,   // directional + device
  _L_THREE, // num + symbol
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_KEY(_L_ONE,   KC_ENT),
  [2] = ACTION_LAYER_TAP_KEY(_L_TWO,   KC_BSPC),
  [3] = ACTION_LAYER_TAP_KEY(_L_THREE, KC_TAB),
  [4] = ACTION_MACRO_TAP(M_LPRN),
  [5] = ACTION_MACRO_TAP(M_RPRN),
  [6] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_LBRC),
  [7] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_RBRC),
  [8] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_DEL),
  [9] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC)
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* base layer
   * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
   * ┃ L3  ┃  Q  ┃  W  ┃  E  ┃  R  ┃  T  ┃  Y  ┃  U  ┃  I  ┃  O  ┃  P  ┃ L2  ┃
   * ┃ tab ┃  q  ┃  w  ┃  e  ┃  r  ┃  t  ┃  y  ┃  u  ┃  i  ┃  o  ┃  p  ┃ bsp ┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃ SFT ┃  A  ┃  S  ┃  D  ┃  F  ┃  G  ┃  H  ┃  J  ┃  K  ┃  L  ┃  :  ┃ SFT ┃
   * ┃  (  ┃  a  ┃  s  ┃  d  ┃  f  ┃  g  ┃  h  ┃  j  ┃  k  ┃  l  ┃  ;  ┃  )  ┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃ GUI ┃  Z  ┃  X  ┃  C  ┃  V  ┃  B  ┃  N  ┃  M  ┃  <  ┃  >  ┃  ?  ┃ GUI ┃
   * ┃ { [ ┃  z  ┃  x  ┃  c  ┃  v  ┃  b  ┃  n  ┃  m  ┃  ,  ┃  .  ┃  /  ┃ ] } ┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃  "  ┃  ~  ┃ HYP ┃ ALT ┃ CTL ┃           ┃ L1  ┃ AGr ┃ CTL ┃  +  ┃  _  ┃
   * ┃  '  ┃  `  ┃     ┃ del ┃ esc ┃   space   ┃ ret ┃     ┃     ┃  =  ┃  -  ┃
   * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
   */
  [_L_ZERO] = LAYOUT_planck_grid(
    F(3)   ,KC_Q  ,KC_W   ,KC_E,KC_R,KC_T  ,KC_Y  ,KC_U,KC_I   ,KC_O   ,KC_P   ,F(2),
    F(4)   ,KC_A  ,KC_S   ,KC_D,KC_F,KC_G  ,KC_H  ,KC_J,KC_K   ,KC_L   ,KC_SCLN,F(5),
    F(6)   ,KC_Z  ,KC_X   ,KC_C,KC_V,KC_B  ,KC_N  ,KC_M,KC_COMM,KC_DOT ,KC_SLSH,F(7),
    KC_QUOT,KC_GRV,KC_HYPR,F(8),F(9),KC_SPC,KC_SPC,F(1),KC_RALT,KC_RCTL,KC_EQL ,KC_MINS
  ),

  /* 1. base extension layer
   * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
   * ┃/////┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃  6  ┃  7  ┃  8  ┃  9  ┃  O  ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃/////┃  !  ┃  @  ┃  #  ┃  $  ┃  %  ┃  ^  ┃  &  ┃  *  ┃  |  ┃  \  ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃/////┃ f1  ┃ f2  ┃ f3  ┃ f4  ┃ f5  ┃ f6  ┃ f7  ┃ f8  ┃ f9  ┃ f10 ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃     ┃     ┃/////┃/////┃/////┃///////////┃XXXXX┃/////┃/////┃ f11 ┃ f12 ┃
   * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
   */
  [_L_ONE] = LAYOUT_planck_grid(
    _____,KC_1   ,KC_2 ,KC_3   ,KC_4  ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_____,
    _____,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_PIPE,KC_BSLS,_____,
    _____,KC_F1  ,KC_F2,KC_F3  ,KC_F4 ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_____,
    __x__,__x__  ,_____,_____  ,_____ ,_____  ,_____  ,_____  ,_____  ,_____  ,KC_F11 ,KC_F12
  ),

  /* 2. directional + device layer
   * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
   * ┃/////┃ hom ┃ up  ┃ end ┃pgup ┃     ┃     ┃     ┃volx ┃vol- ┃vol+ ┃XXXXX┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃/////┃ lf  ┃ dn  ┃ rt  ┃pgdn ┃     ┃     ┃     ┃ up  ┃pgup ┃lum+ ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃/////┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃ dn  ┃pgdn ┃lum- ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃ ins ┃ prt ┃/////┃/////┃/////┃///////////┃/////┃/////┃/////┃ lf  ┃ rt  ┃
   * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
   */
  [_L_TWO] = LAYOUT_planck_grid(
    _____ ,KC_HOME,KC_UP  ,KC_END ,KC_PGUP,__x__,__x__,__x__,KC_MUTE,KC_VOLD,KC_VOLU,_____,
    _____ ,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,__x__,__x__,__x__,KC_UP  ,KC_PGUP,KC_MFFD,_____,
    _____ ,__x__  ,__x__  ,__x__  ,__x__  ,__x__,__x__,__x__,KC_DOWN,KC_PGDN,KC_MRWD,_____,
    KC_INS,KC_PSCR,__x__  ,_____  ,_____  ,_____,_____,_____,_____  ,_____  ,KC_LEFT,KC_RGHT
  ),

  /* 3. num + symbol layer
   * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
   * ┃XXXXX┃     ┃     ┃     ┃     ┃     ┃  *  ┃  +  ┃  7  ┃  8  ┃  9  ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃/////┃     ┃     ┃     ┃     ┃     ┃  /  ┃  -  ┃  4  ┃  5  ┃  6  ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃/////┃     ┃     ┃     ┃     ┃     ┃ esc ┃ tab ┃  1  ┃  2  ┃  3  ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃     ┃     ┃/////┃/////┃/////┃///////////┃/////┃/////┃  0  ┃  .  ┃ ret ┃
   * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
   */
  [_L_THREE] = LAYOUT_planck_grid(
    _____,__x__,__x__,__x__,__x__,__x__,KC_ASTR,KC_PLUS,KC_7 ,KC_8,KC_9  ,_____,
    _____,__x__,__x__,__x__,__x__,__x__,KC_SLSH,KC_MINS,KC_4 ,KC_5,KC_6  ,_____,
    _____,__x__,__x__,__x__,__x__,__x__,KC_ESC ,KC_TAB ,KC_1 ,KC_2,KC_3  ,_____,
    __x__,__x__,_____,_____,_____,_____,_____  ,_____  ,_____,KC_0,KC_DOT,KC_ENT
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case M_LPRN:
      if (record->event.pressed) {
        register_mods(MOD_LSFT);
      } else {
        if (record->tap.count && !record->tap.interrupted) {
          register_code(KC_9);
          unregister_code(KC_9);
        }
        unregister_mods(MOD_LSFT);
        record->tap.count = 0;
      }
      break;
    case M_RPRN:
      if (record->event.pressed) {
        register_mods(MOD_LSFT);
      } else {
        if (record->tap.count && !record->tap.interrupted) {
          register_code(KC_0);
          unregister_code(KC_0);
        }
        unregister_mods(MOD_LSFT);
        record->tap.count = 0;
      }
      break;
  }
  return MACRO_NONE;
}

