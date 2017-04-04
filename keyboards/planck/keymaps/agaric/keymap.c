#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"
extern keymap_config_t keymap_config;

// legibility
#define _____ KC_TRNS
#define __x__ KC_NO

// layers
#define L_ZERO   0 // base
#define L_ONE    1 // base extension
#define L_TWO    2 // directional + device
#define L_THREE  3 // num + symbol

// macros
#define M_LPRN 0 // lsft + lprn
#define M_RPRN 1 // rsft + rprn

// sounds
#ifdef AUDIO_ENABLE
#define S_ONE   E__NOTE(_B3), E__NOTE(_A3)
#define S_TWO   E__NOTE(_A3), E__NOTE(_B3)
#define S_THREE E__NOTE(_B3), E__NOTE(_A3), E__NOTE(_B3)
#define S_FOUR  E__NOTE(_A3), E__NOTE(_B3), E__NOTE(_A3), E__NOTE(_B3)
#endif

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_KEY(L_ONE,   KC_ENT),
  [2] = ACTION_LAYER_TAP_KEY(L_TWO,   KC_BSPC),
  [3] = ACTION_LAYER_TAP_KEY(L_THREE, KC_TAB),
  [4] = ACTION_MACRO_TAP(M_LPRN),
  [5] = ACTION_MACRO_TAP(M_RPRN),
  [6] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_LBRC),
  [7] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_RBRC),
  [8] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_DEL),
  [9] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC)
};

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
  [L_ZERO] = {
    {F(3)   ,KC_Q  ,KC_W   ,KC_E,KC_R,KC_T  ,KC_Y  ,KC_U,KC_I   ,KC_O   ,KC_P   ,F(2)},
    {F(4)   ,KC_A  ,KC_S   ,KC_D,KC_F,KC_G  ,KC_H  ,KC_J,KC_K   ,KC_L   ,KC_SCLN,F(5)},
    {F(6)   ,KC_Z  ,KC_X   ,KC_C,KC_V,KC_B  ,KC_N  ,KC_M,KC_COMM,KC_DOT ,KC_SLSH,F(7)},
    {KC_QUOT,KC_GRV,KC_HYPR,F(8),F(9),KC_SPC,KC_SPC,F(1),KC_RALT,KC_RCTL,KC_EQL ,KC_MINS}
  },

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
  [L_ONE] = {
    {_____,KC_1   ,KC_2 ,KC_3   ,KC_4  ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_____},
    {_____,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_PIPE,KC_BSLS,_____},
    {_____,KC_F1  ,KC_F2,KC_F3  ,KC_F4 ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_____},
    {__x__,__x__  ,_____,_____  ,_____ ,_____  ,_____  ,_____  ,_____  ,_____  ,KC_F11 ,KC_F12}
  },

  /* 2. directional + device layer
   * ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
   * ┃/////┃ hom ┃ up  ┃ end ┃pgup ┃     ┃     ┃     ┃volx ┃vol- ┃vol+ ┃XXXXX┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃/////┃ lf  ┃ dn  ┃ rt  ┃pgdn ┃     ┃     ┃     ┃ up  ┃lum- ┃lum+ ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃/////┃     ┃     ┃     ┃     ┃     ┃     ┃     ┃ dn  ┃     ┃     ┃/////┃
   * ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┻━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫
   * ┃ ins ┃ prt ┃/////┃/////┃/////┃///////////┃/////┃/////┃/////┃ lf  ┃ rt  ┃
   * ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
   */
  [L_TWO] = {
    {_____ ,KC_HOME,KC_UP  ,KC_END ,KC_PGUP,__x__,__x__,__x__,KC_MUTE,KC_VOLD,KC_VOLU,_____},
    {_____ ,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,__x__,__x__,__x__,KC_UP  ,KC_MRWD,KC_MFFD,_____},
    {_____ ,__x__  ,__x__  ,__x__  ,__x__  ,__x__,__x__,__x__,KC_DOWN,__x__  ,__x__  ,_____},
    {KC_INS,KC_PSCR,__x__  ,_____  ,_____  ,_____,_____,_____,_____  ,_____  ,KC_LEFT,KC_RGHT}
  },

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
  [L_THREE] = {
    {_____,__x__,__x__,__x__,__x__,__x__,KC_ASTR,KC_PLUS,KC_7 ,KC_8,KC_9  ,_____},
    {_____,__x__,__x__,__x__,__x__,__x__,KC_SLSH,KC_MINS,KC_4 ,KC_5,KC_6  ,_____},
    {_____,__x__,__x__,__x__,__x__,__x__,KC_ESC ,KC_TAB ,KC_1 ,KC_2,KC_3  ,_____},
    {__x__,__x__,_____,_____,_____,_____,_____  ,_____  ,_____,KC_0,KC_DOT,KC_ENT}
  },
};

#ifdef AUDIO_ENABLE
float song_one[][2]   = SONG(S_ONE);
float song_two[][2]   = SONG(S_TWO);
float song_three[][2] = SONG(S_THREE);
float song_four[][2]  = SONG(S_FOUR);
#endif

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

void matrix_init_user(void) {
#ifdef AUDIO_ENABLE
  startup_user();
#endif
}
