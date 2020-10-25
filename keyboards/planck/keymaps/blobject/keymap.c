// github.com/agarick/qmk_firmware

#include QMK_KEYBOARD_H

#define _____ KC_TRNS
#define __x__ KC_NO

enum custom_keycodes { MK_NW = SAFE_RANGE, MK_NE, MK_SW, MK_SE, };

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
  switch (keycode)
  {
    case MK_NW:
      if (record->event.pressed)
      { register_code(KC_MS_U); register_code(KC_MS_L); }
      else
      { unregister_code(KC_MS_U); unregister_code(KC_MS_L); }
      break;
    case MK_NE:
      if (record->event.pressed)
      { register_code(KC_MS_U); register_code(KC_MS_R); }
      else
      { unregister_code(KC_MS_U); unregister_code(KC_MS_R); }
      break;
    case MK_SW:
      if (record->event.pressed)
      { register_code(KC_MS_D); register_code(KC_MS_L); }
      else
      { unregister_code(KC_MS_D); unregister_code(KC_MS_L); }
      break;
    case MK_SE:
      if (record->event.pressed)
      { register_code(KC_MS_D); register_code(KC_MS_R); }
      else
      { unregister_code(KC_MS_D); unregister_code(KC_MS_R); }
      break;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
  [0] = LAYOUT_planck_grid(
    /* base layer
     * .-----------------------------------------------------------.
     * | L3 |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | L2 |
     * | tab|  q |  w |  e |  r |  t |  y |  u |  i |  o |  p | bsp|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * | SFT|  A |  S |  D |  F |  G |  H |  J |  K |  L |  : | SFT|
     * |  ( |  a |  s |  d |  f |  g |  h |  j |  k |  l |  ; |  ) |
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * | GUI|  Z |  X |  C |  V |  B |  N |  M |  < |  > |  ? | GUI|
     * | { [|  z |  x |  c |  v |  b |  n |  m |  , |  . |  / | ] }|
     * |----+----+----+----+----+----'----+----+----+----+----+----|
     * |  " |  ~ | HYP| ALT| CTL|  space  | L1 | AGr| CTL|  + |  _ |
     * |  ' |  ` |    | del| esc|         | ret|    |    |  = |  - |
     * '-----------------------------------------------------------'
     */
    LT(3,KC_TAB)   ,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I   ,KC_O  ,KC_P   ,LT(2,KC_BSPC),
    KC_LSPO        ,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K   ,KC_L  ,KC_SCLN,KC_RSPC,
    LGUI_T(KC_LBRC),KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,RGUI_T(KC_RBRC),
    KC_QUOT,KC_GRV,KC_HYPR,LALT_T(KC_DEL),LCTL_T(KC_ESC),KC_SPC,KC_SPC,LT(1,KC_ENT),KC_RALT,KC_RCTL,KC_EQL,KC_MINS
  ),

  [1] = LAYOUT_planck_grid(
    /* base extension layer
     * .-----------------------------------------------------------.
     * |////|  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  O |////|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * |////|  ! |  @ |  # |  $ |  % |  ^ |  & |  * |  | |  \ |////|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * |////| f1 | f2 | f3 | f4 | f5 | f6 | f7 | f8 | f9 | f10|////|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * | f11| f12|////|////|////|/////////|XXXX|////|////|    |    |
     * '-----------------------------------------------------------'
     */
    _____ ,KC_1   ,KC_2 ,KC_3   ,KC_4  ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_____,
    _____ ,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_PIPE,KC_BSLS,_____,
    _____ ,KC_F1  ,KC_F2,KC_F3  ,KC_F4 ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_____,
    KC_F11,KC_F12 ,_____,_____  ,_____ ,_____  ,_____  ,_____  ,_____  ,_____  ,__x__  ,__x__
  ),

  [2] = LAYOUT_planck_grid(
    /* nav + device layer
     * .-----------------------------------------------------------.
     * |////| hom| up | end|pgup|    |    |    |volx|vol-|vol+|XXXX|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * |////| lf | dn | rt |pgdn|    |    |    | up |pgup|lum+|////|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * |////|    |    |    |    |    |    |    | dn |pgdn|lum-|////|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * | ins| prt|////|////|////|/////////|////|////|////| lf | rt |
     * '-----------------------------------------------------------'
     */
    _____ ,KC_HOME,KC_UP  ,KC_END ,KC_PGUP,__x__,__x__,__x__,KC_MUTE,KC_VOLD,KC_VOLU,_____,
    _____ ,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,__x__,__x__,__x__,KC_UP  ,KC_PGUP,KC_BRIU,_____,
    _____ ,__x__  ,__x__  ,__x__  ,__x__  ,__x__,__x__,__x__,KC_DOWN,KC_PGDN,KC_BRID,_____,
    KC_INS,KC_PSCR,__x__  ,_____  ,_____  ,_____,_____,_____,_____  ,_____  ,KC_LEFT,KC_RGHT
  ),

  [3] = LAYOUT_planck_grid(
    /* mouse
     * .-----------------------------------------------------------.
     * |XXXX|    |    |    |    |    |  2 | nw |  n | ne | ^^ |////|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * |////|    |    |    |    |    |  3 |  w |  1 |  e | vv |////|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * |////|    |    |    |    |    |    | sw |  s | se |    |////|
     * |----+----+----+----+----+----+----+----+----+----+----+----|
     * |    |    |////|////|////|/////////|////|////|////|    |    |
     * '-----------------------------------------------------------'
     */
    _____,__x__,__x__,__x__,__x__,__x__,KC_BTN2,MK_NW  ,KC_MS_U,MK_NE  ,KC_WH_U,_____,
    _____,__x__,__x__,__x__,__x__,__x__,KC_BTN3,KC_MS_L,KC_BTN1,KC_MS_R,KC_WH_D,_____,
    _____,__x__,__x__,__x__,__x__,__x__,__x__  ,MK_SW  ,KC_MS_D,MK_SE  ,__x__  ,_____,
    __x__,__x__,_____,_____,_____,_____,_____  ,_____  ,_____  ,_____  ,__x__  ,__x__
  ),
};
