#include QMK_KEYBOARD_H

enum planck_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define LT_RAP0 LT(_RAISE, KC_P0)
#define LT_RASP LT(_RAISE, KC_SPC)

#define MT_LSCP MT(MOD_LSFT, KC_CAPS)
#define MT_RSEN MT(MOD_RSFT, KC_ENT)
#define MT_RSPE MT(MOD_RSFT, KC_PENT)

#define TT_LOWR TT(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*  QWERTY
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
        │ESC │Q   │W   │E   │R   │T   │Y   │U   │I   │O   │P   │BSPC│
        ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
        │TAB │A   │S   │D   │F   │G   │H   │J   │K   │L   │;   │'   │
        ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
        │LSCP│Z   │X   │C   │V   │B   │N   │M   │,   │.   │/   │RSEN│
        ├────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┤
        │LCTL│DEL │LGUI│LALT│LOWR│SPC      │RASP│←   │↓   │↑   │→   │
        └────┴────┴────┴────┴────┴─────────┴────┴────┴────┴────┴────┘ */

    [_QWERTY] = LAYOUT_planck_grid(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        MT_LSCP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSEN,
        KC_LCTL, KC_DEL,  KC_LGUI, KC_LALT, TT_LOWR, KC_SPC,  KC_SPC,  LT_RASP, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /*  LOWER
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
        │    │F1  │F2  │F3  │F4  │PSCR│CALC│P7  │P8  │P9  │P-  │    │
        ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
        │    │F5  │F6  │F7  │F8  │SLCK│    │P4  │P5  │P6  │P+  │DEL │
        ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
        │    │F9  │F10 │F11 │F12 │PAUS│NLCK│P1  │P2  │P3  │P/  │RSPE│
        ├────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┤
        │    │    │    │    │    │         │RAP0│P0  │P.  │P*  │PENT│
        └────┴────┴────┴────┴────┴─────────┴────┴────┴────┴────┴────┘ */

    [_LOWER] = LAYOUT_planck_grid(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR, KC_CALC, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_SLCK, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS, KC_NLCK, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, MT_RSPE,
        _______, _______, _______, _______, _______, _______, _______, LT_RAP0, KC_P0,   KC_PDOT, KC_PAST, KC_PENT
    ),

    /*  RAISE
        ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
        │`   │1   │2   │3   │4   │    │    │HOME│↑   │END │PGUP│INS │
        ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
        │    │5   │6   │7   │8   │\   │#   │←   │↓   │→   │PGDN│DEL │
        ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
        │    │9   │0   │-   │=   │[   │]   │MUTE│VOLD│VOLU│\   │    │
        ├────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┤
        │    │RSET│    │    │    │         │    │RALT│RGUI│APP │RCTL│
        └────┴────┴────┴────┴────┴─────────┴────┴────┴────┴────┴────┘ */
        
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_INS,
        _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_NUBS, KC_NUHS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_DEL,
        _______, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, _______,
        _______, RESET,   _______, _______, _______, _______, _______, _______, KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
    ),

};

#ifdef AUDIO_ENABLE

    #include "audio.h"
    #include "song_list.h"

    float tone_startup[][2]         = SONG(STARTUP_SOUND);
    float tone_goodbye[][2]         = SONG(GOODBYE_SOUND );
    float tone_layer_on[][2]        = SONG(AUDIO_ON_SOUND);
    float tone_default_layer[][2]   = SONG(AUDIO_OFF_SOUND);
    float tone_caps_on[][2]         = SONG(CAPS_LOCK_ON_SOUND);
    float tone_caps_off[][2]        = SONG(CAPS_LOCK_OFF_SOUND);
    float tone_numlk_on[][2]        = SONG(NUM_LOCK_ON_SOUND);
    float tone_numlk_off[][2]       = SONG(NUM_LOCK_OFF_SOUND);
    float tone_scroll_on[][2]       = SONG(SCROLL_LOCK_ON_SOUND);
    float tone_scroll_off[][2]      = SONG(SCROLL_LOCK_OFF_SOUND);

    void startup_user() {
        PLAY_SONG(tone_startup);
    }

    void shutdown_user() {
        PLAY_SONG(tone_goodbye);
        wait_ms(150);
        stop_all_notes();
    }

    void led_set_user(uint8_t usb_led) {
        static uint8_t old_usb_led = 0;
        if (!is_playing_notes()) {
            if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK))) {
                PLAY_SONG(tone_caps_on);
            } else if (!(usb_led & (1<<USB_LED_CAPS_LOCK)) && (old_usb_led & (1<<USB_LED_CAPS_LOCK))) {
                PLAY_SONG(tone_caps_off);
            } else if ((usb_led & (1<<USB_LED_NUM_LOCK)) && !(old_usb_led & (1<<USB_LED_NUM_LOCK))) {
                PLAY_SONG(tone_numlk_on);
            } else if (!(usb_led & (1<<USB_LED_NUM_LOCK)) && (old_usb_led & (1<<USB_LED_NUM_LOCK))) {
                PLAY_SONG(tone_numlk_off);
            } else if ((usb_led & (1<<USB_LED_SCROLL_LOCK)) && !(old_usb_led & (1<<USB_LED_SCROLL_LOCK))) {
                PLAY_SONG(tone_scroll_on);
            } else if (!(usb_led & (1<<USB_LED_SCROLL_LOCK)) && (old_usb_led & (1<<USB_LED_SCROLL_LOCK))) {
                PLAY_SONG(tone_scroll_off);
            }
        }
        old_usb_led = usb_led;
    }

    uint32_t layer_state_set_user(uint32_t state) {
        switch (biton32(state)) {
            case _QWERTY:
                PLAY_SONG(tone_default_layer);
                break;
            case _LOWER:
                PLAY_SONG(tone_layer_on);
                break;
            case _RAISE:
                PLAY_SONG(tone_layer_on);
                break;
        }
        return state;
    }

#endif