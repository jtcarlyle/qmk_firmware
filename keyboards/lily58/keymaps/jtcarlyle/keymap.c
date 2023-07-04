#include QMK_KEYBOARD_H

#include "features/select_word.h"
#include "layout.h"

enum layer_number {
  _DVORAK = 0,
  _QWERTY,
  _SINGETA,
  _NAV,
  _SYM,

};

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  // input method and layout change macros
  LANG_EN,
  LANG_ZH,
  LANG_JA,
  // singeta homerow
  KN_NO,
  KN_TO,
  KN_KA,
  KN_N, // ん
  KN_Q, // っ
  KN_KU,
  KN_U,
  KN_I,
  KN_SI,
  KN_NA,
  // singeta top row
  KN_BOU, // ー
  KN_NI,
  KN_HA,
  KN_TOU, // 、
  KN_TI,
  KN_GU,
  KN_BA,
  KN_KO,
  KN_GA,
  KN_HI,
  KN_GE,
  // singeta bottom row
  KN_SU,
  KN_MA,
  KN_KI,
  KN_RU,
  KN_TU,
  KN_TE,
  KN_TA,
  KN_DE,
  KN_TEN, // 。
  KN_BU
};

#include "g/keymap_combo.h" // combo definition marcos

/* dual purpose mod/layer-tap keys */
#define ST_SPC  LSFT_T(KC_SPC)
#define ST_BSPC RSFT_T(KC_BSPC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define AT_ESC  LALT_T(KC_ESC)
#define AT_MINS RALT_T(KC_MINS)

/* one shot modifiers */
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

/* base layer change */
#define DVORAK  DF(_DVORAK)
#define QWERTY  DF(_QWERTY)
#define SINGETA DF(_SINGETA)

/* others, make macros later */
#define DELWORD C(KC_BSPC)
#define NXTWORD C(KC_RGHT)
#define PRVWORD C(KC_LEFT)
#define HOME    KC_HOME
#define END     KC_END
#define NXTPARA C(KC_DOWN)
#define PRVPARA C(KC_UP)
#define REDO    C(KC_Y)
#define ZOOMIN  C(KC_EQL)
#define ZOOMOUT C(KC_MINS)
#define CTL_ENT C(KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVO - Base Layer DVORAK with changed numbers
 * ESC, - double as CTRL
 * [, ] double as ALT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   7  |   8  |   9  |   0  |   5  |                    |   6  |   1  |   2  |   3  |   4  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  \   |   "  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|  F11  |    |  F12  |------+------+------+------+------+------|
 * |  [   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |  ]   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Down |  Up  | Tab  | /  RET  /       \ SPC  \  | BKSPC |  <-  |  ->  |
 *                   |      | GUI  | EXT  |/ Shift /         \ Shift\ | EXT   | GUI  |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_DVORAK] = LAYOUT_LR(
      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
      KC_BSLS, KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,
      AT_ESC , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,
      KC_LGUI, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_LBRC,
                                 LANG_ZH, KC_LCTL, ST_SPC , NAV_TAB,

               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
               KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH,
               KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , AT_MINS,
      KC_RBRC, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_RGUI,
      SYM_ENT, ST_BSPC , KC_RCTL, LANG_JA
),

/* QWE - QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   \   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  | LALT | Space | /CTRL  /       \ ESC  \  | Enter | RALT |  =  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 * For gaming and lending to others
 * Full keyboard functionality in a semi-sane usable layout
 * Note that ESC is where Capslock normally is. I hope that this
 * can be reprogrammed in games
 * need to change the tab layer-tap at some point
 *
 */
    [_QWERTY] = LAYOUT_LR(
      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
      NAV_TAB, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,
      KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,
      KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_BSLS,
                              KC_LGUI , KC_LALT  , KC_SPC , KC_LCTL,

               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
               KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
               KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
      KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
      SYM_ENT, KC_BSPC, KC_RALT, KC_EQL
    ),

/* Singeta chorded Japanese layout
 * implemented with QMK macros and combos
 */

    [_SINGETA] = LAYOUT_LR( // singeta layout
       KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
       KC_BSLS, KN_BOU , KN_NI  , KN_HA  , KN_TOU , KN_TI  ,
       AT_ESC , KN_NO  , KN_TO  , KN_KA  , KN_N   , KN_Q   ,
       KC_LGUI, KN_SU  , KN_MA  , KN_KI  , KN_RU  , KN_TU  , KC_LBRC,
                                  LANG_ZH, KC_LCTL, ST_SPC , NAV_TAB,

                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
                         KN_GU  , KN_BA  , KN_KO  , KN_GA  , KN_HI  , KN_GE  ,
                         KN_KU  , KN_U   , KN_I   , KN_SI  , KN_NA  , AT_MINS,
                KC_RBRC, KN_TE  , KN_TA  , KN_DE  , KN_TEN , KN_BU  , KC_RGUI,
                SYM_ENT, ST_BSPC, KC_RCTL, LANG_EN
    ),

/* NAV - Text editing/navigation layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |dmenu | IME  | ⌫w  |  ⌦w |      |                    | undo |  ←w  |   ↑  |  →w  | redo | zoom+|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  | Alt  | Ctrl |Shift |      |-------.    ,-------|  |←  |   ←  |   ↓  |   →  |  →|  | zoom-|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  cut | copy | paste|      |-------|    |-------| find | ←¶  | PgDn  | PgUp |  →¶  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \←find \  | find→ | Del |      |
 *                   |      |      |      |/       /         \      \ |       |     |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_NAV] = LAYOUT_LR(
      _______, _______, _______, _______, _______, _______,
      QWERTY , KC_MPRV, KC_MPLY, DELWORD, KC_MNXT, _______,
      DVORAK , OS_LGUI, OS_LALT, OS_LSFT, OS_LCTL, _______,
      SINGETA, _______, C(KC_X), C(KC_C), C(KC_V), _______, _______,
                                 _______, _______, _______, _______,

               _______, _______, SELWORD, _______, _______, _______,
               C(KC_Z), PRVWORD, KC_UP  , NXTWORD, REDO   , ZOOMIN ,
               HOME   , KC_LEFT, KC_DOWN, KC_RGHT, END    , ZOOMOUT,
      _______, C(KC_F), NXTPARA, KC_PGUP, KC_PGDN, PRVPARA, _______,
      DELWORD, CTL_ENT, _______, _______
    ),

/* SYML - function keys and symbols on the left hand (intended for cross hand use)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |  F6  |  F1  | F2   |  F3   | F4   |     |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   &  |   %  |  [   |   ]  |   ^  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  | ALT  | CTRL | SHIFT|      |-------.    ,-------|   |  |   :  |  (   |   )  |   \  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE|      |-------|    |-------|   ~  |  $   |  {   |  }   |  @  |       |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |       |     | /       /       \   _  \  |  DEL | HOME | END  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_SYM] = LAYOUT_LR(
       _______, KC_F1  , KC_F2  , KC_F3  , KC_F4 , KC_F5  ,
       _______, _______, KC_LABK, KC_RABK, KC_ASTR, _______,
       _______, KC_PLUS, KC_SLSH, KC_MINS, KC_EQL , KC_HASH,
       _______, KC_EXLM, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_F11 ,
                                  _______, _______, KC_UNDS, KC_DEL ,

                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
                         KC_AMPR, KC_AT  , KC_LBRC, KC_RBRC, KC_CIRC, _______,
                         KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_BSLS, _______,
                KC_F12 , KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, _______, _______,
                _______ , _______, _______, _______
    ),

/* SYMR - function keys and symbols on the left hand (intended for cross hand use)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |       |     |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  <   |  >   |  *   |      |                    |      |      |  DVO | QWE  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  +   |  /   |  -   |  =   |      |-------.    ,-------|      | SHIFT| CTRL |  ALT | GUI  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  !   | Mute | Vol- | Vol+ |      |-------|    |-------|      | Prev | Play | Stop | Next |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | PgDn  | PgUp |     | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

};

/* layer_state_t layer_state_set_user(layer_state_t state) {
 *   return update_tri_layer_state(state, _FUN, _NAV, _ADJUST);
 * }
 */

// I don't use any of this junk since my OLED's don't work
//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
    switch (keycode) {
      // Singeta macros
      // home
      case KN_NO:      SEND_STRING("no"); break;
      case KN_TO:      SEND_STRING("to"); break;
      case KN_KA:      SEND_STRING("ka"); break;
      case KN_N:       SEND_STRING("nn"); break;
      case KN_Q:       SEND_STRING("xtu"); break;
      case KN_KU:      SEND_STRING("ku"); break;
      case KN_U:       SEND_STRING("u"); break;
      case KN_I:       SEND_STRING("i"); break;
      case KN_SI:      SEND_STRING("si"); break;
      case KN_NA:      SEND_STRING("na"); break;
      // top
      case KN_BOU:     SEND_STRING("-"); break;
      case KN_NI:      SEND_STRING("ni"); break;
      case KN_HA:      SEND_STRING("ha"); break;
      case KN_TOU:     SEND_STRING(","); break;
      case KN_TI:      SEND_STRING("ti"); break;
      case KN_GU:      SEND_STRING("gu"); break;
      case KN_BA:      SEND_STRING("ba"); break;
      case KN_KO:      SEND_STRING("ko"); break;
      case KN_GA:      SEND_STRING("ga"); break;
      case KN_HI:      SEND_STRING("hi"); break;
      case KN_GE:      SEND_STRING("ge"); break;
      // bottom
      case KN_SU:      SEND_STRING("su"); break;
      case KN_MA:      SEND_STRING("ma"); break;
      case KN_KI:      SEND_STRING("ki"); break;
      case KN_RU:      SEND_STRING("ru"); break;
      case KN_TU:      SEND_STRING("tu"); break;
      case KN_TE:      SEND_STRING("te"); break;
      case KN_TA:      SEND_STRING("ta"); break;
      case KN_DE:      SEND_STRING("de"); break;
      case KN_TEN:     SEND_STRING(".");  break;
      case KN_BU:      SEND_STRING("bu"); break;
    }
  }
  return true;
}

void matrix_scan_user(void) {
  select_word_task();
}
