#include QMK_KEYBOARD_H

#define BASE 0
#define LOWER 1
#define UPPER 2
#define SUPER 3

enum custom_keycodes {
SEL = SAFE_RANGE
,UPD
,WALK
,MARON
,CLAP
,ADS
,AGREE
,AINT
,POPCRN
,SADMJ
,CTRL3
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
    KC_LCTL, KC_LGUI, KC_LALT, MO(SUPER), MO(LOWER), KC_SPC,  MO(UPPER),   KC_LEFT, KC_RGHT, KC_DOWN,   KC_UP  \
  ),

  [LOWER]   = LAYOUT(
    KC_DEL, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,\
		KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS,\
		KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_NUHS), LSFT(KC_NUBS), KC_HOME, KC_END, KC_TRNS,\
		KC_RCTL, KC_RGUI, KC_RALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_PGDN, KC_PGUP\
  ),

  [UPPER]   = LAYOUT(
    KC_DEL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,\
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,\
		KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_PGUP, KC_PGDN\
  ),

  [SUPER]   = LAYOUT(
  RESET, SEL, UPD, CTRL3, ADS, KC_P7, KC_P8, KC_P9, CLAP, MARON, WALK, BL_TOGG,\
		BL_DEC, BL_INC, BL_STEP, KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, AGREE, AINT, POPCRN, SADMJ,\
		KC_CAPS, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_P0, KC_P1, KC_P2, KC_P3, KC_MSTP, KC_MPLY, KC_TRNS, KC_TRNS,\
		KC_NUMLOCK, KC_KP_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU\
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        switch(keycode) {
            case SEL:
                SEND_STRING("SELECT TOP 1000 * FROM ");
                return false;
            case UPD:
                SEND_STRING("UPDATE "SS_TAP(X_ENTER)" SET "SS_TAP(X_ENTER)"WHERE "); // UPDATE STATEMENT
                return false;
            case WALK:
                SEND_STRING("https://i.imgur.com/mWQRAFU.gifv"SS_TAP(X_ENTER)); //walking into work
                return false;
            case MARON:
                SEND_STRING("https://i.imgur.com/7xweg.jpg"SS_TAP(X_ENTER)); //Maroney face
                return false;
            case CLAP:
                SEND_STRING("https://i.imgur.com/i6r5VDO.gifv"SS_TAP(X_ENTER)) ; // Clapping Intensifies
                return false;
            case ADS:
                SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_C)SS_UP(X_LCTRL)SS_TAP(X_END)SS_TAP(X_ENTER)"SELECT TOP 1000 * FROM "SS_DOWN(X_LCTRL)SS_TAP(X_V)SS_UP(X_LCTRL)SS_TAP(X_END)SS_DOWN(X_LSHIFT)SS_TAP(X_HOME)SS_UP(X_LSHIFT)SS_TAP(X_F5)SS_TAP(X_BSPACE)SS_TAP(X_HOME)SS_TAP(X_BSPACE)); //SEL TOP 1K FOR ADS
                return false;
            case AGREE:
                SEND_STRING("https://i.imgur.com/EucIfYY.gifv"SS_TAP(X_ENTER)); // Agreement
                return false;
            case AINT:
                SEND_STRING("https://i.imgur.com/nTXnixm.jpg"SS_TAP(X_ENTER)); // Ain't nobody got time for that
                return false;
            case POPCRN:
                SEND_STRING("https://i.imgur.com/0hQyd5L.gifv"SS_TAP(X_ENTER)); // Popcorn
                return false;
            case SADMJ:
                SEND_STRING("https://i.imgur.com/YLyEJB7.jpg"SS_TAP(X_ENTER)); // Sad MJ
                return false;
            case CTRL3:
                SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_3)SS_UP(X_LCTRL)); // CTRL+3
                return false;

        }
    }
    return true;
};  