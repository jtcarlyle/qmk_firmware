#include QMK_KEYBOARD_H

#include "features/select_word.h"
#include "layout.h"

enum layer_number {
  _DVORAK = 0,
  _QWERTY,
  _KANA,
  _NAV,
  _SYM,
};

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  // input method and layout change macros
  LANG_EN,
  LANG_ZH,
  LANG_JA,
  // macros for kana
  KN_A , KN_I,  KN_U , KN_E , KN_O ,
  KN_KA, KN_KI, KN_KU, KN_KE, KN_KO,
  KN_SA, KN_SI, KN_SU, KN_SE, KN_SO,
  KN_TA, KN_TI, KN_TU, KN_TE, KN_TO,
  KN_NA, KN_NI, KN_NU, KN_NE, KN_NO,
  KN_HA, KN_HI, KN_HU, KN_HE, KN_HO,
  KN_MA, KN_MI, KN_MU, KN_ME, KN_MO,
  KN_YA,        KN_YU,        KN_YO,
  KN_RA, KN_RI, KN_RU, KN_RE, KN_RO,
  KN_WA, KN_WI,        KN_WE, KN_WO,
  KN_BIKI,
  KN_Q,
  KN_N,
  KN_GA, KN_GI, KN_GU, KN_GE, KN_GO,
  KN_ZA, KN_ZI, KN_ZU, KN_ZE, KN_ZO,
  KN_DA, KN_DI, KN_DU, KN_DE, KN_DO,
  KN_BA, KN_BI, KN_BU, KN_BE, KN_BO,
  KN_PA, KN_PI, KN_PU, KN_PE, KN_PO,
  KN_XA, KN_XI, KN_XU, KN_XE, KN_XO,
  KN_XYA,
  KN_XYO,
  KN_XYU,
  KN_XKA,
  KN_XKE,
  KN_XWA,
  KN_KUT,
  KN_TOUT
};

/* dual purpose mod/layer-tap keys */
#define ST_SPC  LSFT_T(KC_SPC)
#define ST_ENT RSFT_T(KC_ENT)
#define NAV_TAB LT(_NAV, KC_TAB)
#define SM_BSPC LT(_SYM, KC_BSPC)
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

/* custom shift */
#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
  {KN_BIKI, KC_SLSH},
  {KN_NI  , KN_ME},
  {KC_KUT , KC_EQL },
  {KC_COLN, KC_SCLN},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

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
      SM_BSPC, ST_ENT , KC_RCTL, LANG_JA
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
      SM_BSPC, KC_ENT, KC_RALT, KC_EQL
    ),

/* Singeta chorded Japanese layout
 * implemented with QMK macros and combos
 */

    [_KANA] = LAYOUT_LR(
      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
      KC_BSLS, KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,
      AT_ESC , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,
      KC_LGUI, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_LBRC,
                                 LANG_ZH, KC_LCTL, ST_SPC , NAV_TAB,

               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
               KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH,
               KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , AT_MINS,
      KC_RBRC, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_RGUI,
      SM_BSPC, ST_ENT , KC_RCTL, LANG_JA
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
      // kana macros
      case KN_A:       SEND_STRING("i"); break;
      case KN_I:       SEND_STRING("i"); break;
      case KN_U:       SEND_STRING("u"); break;
      case KN_E:       SEND_STRING("e"); break;
      case KN_O:       SEND_STRING("o"); break;

      case KN_SA:      SEND_STRING("sa"); break;
      case KN_SI:      SEND_STRING("si"); break;
      case KN_SU:      SEND_STRING("su"); break;
      case KN_SE:      SEND_STRING("se"); break;
      case KN_SO:      SEND_STRING("so"); break;

      case KN_TA:      SEND_STRING("ta"); break;
      case KN_TI:      SEND_STRING("ti"); break;
      case KN_TU:      SEND_STRING("tu"); break;
      case KN_TE:      SEND_STRING("te"); break;
      case KN_TO:      SEND_STRING("to"); break;

      case KN_NA:      SEND_STRING("na"); break;
      case KN_NI:      SEND_STRING("ni"); break;
      case KN_NU:      SEND_STRING("nu"); break;
      case KN_NE:      SEND_STRING("ne"); break;
      case KN_NO:      SEND_STRING("no"); break;

      case KN_HA:      SEND_STRING("ha"); break;
      case KN_HI:      SEND_STRING("hi"); break;
      case KN_HU:      SEND_STRING("hu"); break;
      case KN_HE:      SEND_STRING("he"); break;
      case KN_HO:      SEND_STRING("ho"); break;

      case KN_MA:      SEND_STRING("ma"); break;
      case KN_MI:      SEND_STRING("mi"); break;
      case KN_MU:      SEND_STRING("mu"); break;
      case KN_ME:      SEND_STRING("me"); break;
      case KN_MO:      SEND_STRING("mo"); break;

      case KN_YA:      SEND_STRING("ya"); break;
      case KN_YU:      SEND_STRING("yu"); break;
      case KN_YO:      SEND_STRING("yo"); break;

      case KN_RA:      SEND_STRING("ta"); break;
      case KN_RI:      SEND_STRING("ti"); break;
      case KN_RU:      SEND_STRING("tu"); break;
      case KN_RE:      SEND_STRING("te"); break;
      case KN_RO:      SEND_STRING("to"); break;

      case KN_WA:      SEND_STRING("wa"); break;
      case KN_WI:      SEND_STRING("xwi"); break;
      case KN_WE:      SEND_STRING("xwe"); break;
      case KN_WO:      SEND_STRING("wo"); break;

      case KN_GA:      SEND_STRING("ga"); break;
      case KN_GI:      SEND_STRING("gi"); break;
      case KN_GU:      SEND_STRING("gu"); break;
      case KN_GE:      SEND_STRING("ge"); break;
      case KN_GO:      SEND_STRING("go"); break;

      case KN_ZA:      SEND_STRING("za"); break;
      case KN_ZI:      SEND_STRING("zi"); break;
      case KN_ZU:      SEND_STRING("zu"); break;
      case KN_ZE:      SEND_STRING("ze"); break;
      case KN_ZO:      SEND_STRING("zo"); break;

      case KN_DA:      SEND_STRING("da"); break;
      case KN_DI:      SEND_STRING("di"); break;
      case KN_DU:      SEND_STRING("du"); break;
      case KN_DE:      SEND_STRING("de"); break;
      case KN_DO:      SEND_STRING("do"); break;

      case KN_BA:      SEND_STRING("ba"); break;
      case KN_BI:      SEND_STRING("bi"); break;
      case KN_BU:      SEND_STRING("bu"); break;
      case KN_BE:      SEND_STRING("be"); break;
      case KN_BO:      SEND_STRING("bo"); break;

      case KN_PA:      SEND_STRING("pa"); break;
      case KN_PI:      SEND_STRING("pi"); break;
      case KN_PU:      SEND_STRING("pu"); break;
      case KN_PE:      SEND_STRING("pe"); break;
      case KN_PO:      SEND_STRING("po"); break;

      case KN_XA:      SEND_STRING("xa"); break;
      case KN_XI:      SEND_STRING("xi"); break;
      case KN_XU:      SEND_STRING("xu"); break;
      case KN_XE:      SEND_STRING("xe"); break;
      case KN_XO:      SEND_STRING("xo"); break;

      case KN_N:       SEND_STRING("nn"); break;
      case KN_Q:       SEND_STRING("xtu"); break;
      case KN_XYA:     SEND_STRING("xya"); break;
      case KN_XYU:     SEND_STRING("xyu"); break;
      case KN_XYO:     SEND_STRING("xyo"); break;
      case KN_XKA:     SEND_STRING("xka"); break;
      case KN_XKE:     SEND_STRING("xke"); break;
      case KN_XWA:     SEND_STRING("xwa"); break;
      case KN_BIKI:    SEND_STRING("-"); break;

      case KN_KUT:     SEND_STRING(","); break;
      case KN_TOUT:    SEND_STRING("."); break;
    }
  }
  return true;
}

void matrix_scan_user(void) {
  select_word_task();
}
