/* sokol_input.h -- https://github.com/takeiteasy/sokol_input

 sokol_input Copyright (C) 2025 George Watson

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef SOKOL_INPUT_HEADER
#define SOKOL_INPUT_HEADER
#if defined(__cplusplus)
extern "C" {
#endif

#ifndef __has_include
#define __has_include(x) 1
#endif

#ifndef SOKOL_APP_INCLUDED
#if __has_include("sokol_app.h")
#include "sokol_app.h"
#else
#error Please include sokol_app.h before the sokol_input.h implementation
#endif
#endif

#include <stdarg.h>

// Assign sapp_desc.event_cb = sapp_input_event
// Or just pass the event to it inside the callback
void sapp_input_event(const sapp_event *event);
// Call this at the end of sapp frame callback
void sapp_input_flush(void);
// Clear the input internal state
void sapp_input_init(void);

bool sapp_is_key_down(int key);
// Returns true if key is down this frame and was up last frame
bool sapp_was_key_pressed(int key);
// Returns true if key is up and key was down last frame
bool sapp_was_key_released(int key);
// If any of the keys passed are not down returns false
bool sapp_are_keys_down(int n, ...);
// If none of the keys passed are down returns false
bool sapp_any_keys_down(int n, ...);
bool sapp_is_button_down(int button);
bool sapp_was_button_pressed(int button);
bool sapp_was_button_released(int button);
bool sapp_are_buttons_down(int n, ...);
bool sapp_any_buttons_down(int n, ...);
bool sapp_has_mouse_move(void);
bool sapp_modifier_equals(int mods);
bool sapp_modifier_down(int mod);
int sapp_cursor_x(void);
int sapp_cursor_y(void);
bool sapp_cursor_delta_x(void);
bool sapp_cursor_delta_y(void);
bool sapp_scrolled(void);
float sapp_scroll_x(void);
float sapp_scroll_y(void);

#if defined(__ANDROID__) || \
    defined(__EMSCRIPTEN__) \
    (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE == 1)
#define SOKOL_INPUT_NO_GAMEPADS
#endif

#ifndef SOKOL_INPUT_NO_GAMEPADS
#ifndef SOKOL_GAMEPAD_MAX
#define SOKOL_GAMEPAD_MAX 1
#endif

int sapp_gamepad_count(void);
bool sapp_gamepad_is_connected(void);
void sapp_gamepad_disconnect(void);
void sapp_gamepad_disconnect_id(int gid);
bool sapp_gamepad_is_connected_id(int gid);
bool sapp_gamepad_is_button_down(int button);
bool sapp_gamepad_is_button_down_id(int gid, int button);
bool sapp_gamepad_is_button_up(int button);
bool sapp_gamepad_is_button_up_id(int gid, int button);
bool sapp_gamepad_was_button_pressed(int button);
bool sapp_gamepad_was_button_pressed_id(int gid, int button);
bool sapp_gamepad_was_button_released(int button);
bool sapp_gamepad_was_button_released_id(int gid, int button);
float sapp_gamepad_axis_x(void);
float sapp_gamepad_axis_x_id(int gid);
float sapp_gamepad_axis_y(void);
float sapp_gamepad_axis_y_id(int gid);
float sapp_gamepad_axis_delta_x(void);
float sapp_gamepad_axis_delta_x_id(int gid);
float sapp_gamepad_axis_delta_y(void);
float sapp_gamepad_axis_delta_y_id(int gid);
#endif

bool sapp_input_is_str_down(const char *str);
bool sapp_input_is_down(int modifiers, int n, ...);
int* sapp_parse_input_str(const char *str, int *modifiers);

#if defined(__cplusplus)
}
#endif
#endif // SOKOL_INPUT_HEADER

#ifdef SOKOL_INPUT_IMPL
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#ifndef SOKOL_INPUT_NO_GAMEPADS
// INCLUDES
#include "gamepad/Gamepad.h"
#include "gamepad/Gamepad_private.h"
#include "gamepad/Gamepad_private.c"
#if defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#include "gamepad/Gamepad_macosx.c"
#elif defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
#ifndef SOKOL_INPUT_GAMEPAD_WINDOWS_USE_MM
#include "gamepad/Gamepad_windows_dinput.c"
#else
#include "gamepad/Gamepad_windows_mm.c"
#endif
#elif defined(__gnu_linux__) || defined(__linux__) || defined(__unix__)
#include "gamepad/Gamepad_linux.c"
#else
#error This platform is not supported
#endif
#endif // SOKOL_INPUT_NO_GAMEPADS

#ifndef SOKOL_KEY_HOLD_DELAY
#define SOKOL_KEY_HOLD_DELAY 1.f
#endif

#ifndef FLT_EPSILON
#define FLT_EPSILON 0.000001f
#endif

static bool float_cmp(float a, float b) {
    return fabsf(a - b) <= FLT_EPSILON * fmaxf(1.f, fmaxf(fabsf(a), fabsf(b)));
}

#define _MAX(A, B)    ((A) > (B) ? (A) : (B))

#define __vector_raw(a)              ((int *) (a) - 2)
#define __vector_m(a)                __vector_raw(a)[0]
#define __vector_n(a)                __vector_raw(a)[1]

#define __vector_needgrow(a,n)       ((a)==0 || __vector_n(a)+n >= __vector_m(a))
#define __vector_grow(a,n)           __grow_vector((void **) &(a), (n), sizeof(*(a)))
#define __vector_maybegrow(a,n)      (__vector_needgrow(a,(n)) ? __vector_grow(a,n) : 0)

#define vector_free(a)               ((a) ? free(__vector_raw(a)),0 : 0)
#define vector_append(a, v)          (__vector_maybegrow(a,1), (a)[__vector_n(a)++] = (v))
#define vector_count(a)              ((a) ? __vector_n(a) : 0)

static void __grow_vector(void **arr, int increment, int itemsize) {
    int m = *arr ? 2 * __vector_m(*arr) + increment : increment + 1;
    void *p = (void*)realloc(*arr ? __vector_raw(*arr) : 0, itemsize * m + sizeof(int) * 2);
    assert(p);
    if (p) {
        if (!*arr)
            ((int *)p)[1] = 0;
        *arr = (void*)((int*)p + 2);
        __vector_m(*arr) = m;
    }
}

typedef struct {
    bool keys[SAPP_KEYCODE_MENU+1];
    bool buttons[3];
    int modifier;
    struct {
        int x, y;
    } cursor;
    struct {
        float x, y;
    } scroll;
} _state;

static struct {
    _state input_prev, input_current;
} _input_state;

#ifndef SOKOL_INPUT_NO_GAMEPADS
typedef struct {
    bool *buttons;
    float axis[2];
} _gamepad_state;

typedef struct {
    int button_count;
    int axis_count;
    bool attached;
    _gamepad_state current, previous;
} _gamepad_states;

static struct {
    struct Gamepad_device* devices[SOKOL_GAMEPAD_MAX];
    _gamepad_states states[SOKOL_GAMEPAD_MAX];
} _gstate;

static void _gamepad_attach(struct Gamepad_device *device, void *context) {
    _gstate.devices[device->deviceID] = device;
    _gamepad_states *_state = &_gstate.states[device->deviceID];
    memset(_state, 0, sizeof(_gamepad_states));
    _state->attached = true;
    _state->button_count = device->numButtons;
    _state->axis_count = device->numAxes;
    memcpy(&_state->previous, &_state->current, sizeof(_gamepad_state));
    size_t size = device->numButtons * sizeof(bool);
    _state->current.buttons = malloc(size);
    _state->previous.buttons = malloc(size);
    memset(_state->current.buttons, 0, size);
    memset(_state->previous.buttons, 0, size);
}

static void _gamepad_detach(struct Gamepad_device *device, void *context) {
    _gstate.devices[device->deviceID] = NULL;
    free(_gstate.states[device->deviceID].current.buttons);
    free(_gstate.states[device->deviceID].previous.buttons);
    memset(&_gstate.states[device->deviceID], 0, sizeof(_gamepad_states));
}

static void _gamepad_btn_down(struct Gamepad_device *device, unsigned int buttonID, double timestamp, void *context) {
    if (device->deviceID < SOKOL_GAMEPAD_MAX && buttonID < _gstate.states[device->deviceID].button_count)
        _gstate.states[device->deviceID].current.buttons[buttonID] = true;
}

static void _gamepad_btn_up(struct Gamepad_device *device, unsigned int buttonID, double timestamp, void *context) {
    if (device->deviceID < SOKOL_GAMEPAD_MAX && buttonID < _gstate.states[device->deviceID].button_count)
        _gstate.states[device->deviceID].current.buttons[buttonID] = false;
}

static void _gamepad_axis_move(struct Gamepad_device *device, unsigned int axisID, float value, float lastValue, double timestamp, void *context) {
    if (device->deviceID < SOKOL_GAMEPAD_MAX && axisID < _MAX(2, _gstate.states[device->deviceID].axis_count))
        _gstate.states[device->deviceID].current.axis[axisID] = value;
}

int sapp_gamepad_count(void) {
    return Gamepad_numDevices();
}

bool sapp_gamepad_is_connected(void) {
    return sapp_gamepad_is_connected_id(0);
}

void sapp_gamepad_disconnect(void) {
    sapp_gamepad_disconnect_id(0);
}

void sapp_gamepad_disconnect_id(int gid) {
    if (gid >= 0 && gid < SOKOL_GAMEPAD_MAX && _gstate.devices[gid] != NULL) {
        _gstate.devices[gid] = NULL;
        free(_gstate.states[gid].current.buttons);
        free(_gstate.states[gid].previous.buttons);
        memset(&_gstate.states[gid], 0, sizeof(_gamepad_states));
    }
}

bool sapp_gamepad_is_connected_id(int gid) {
    return gid >= 0 && gid < SOKOL_GAMEPAD_MAX ? _gstate.states[gid].attached : false;
}

bool sapp_gamepad_is_button_down(int button) {
    return sapp_gamepad_is_button_down_id(0, button);
}

bool sapp_gamepad_is_button_down_id(int gid, int button) {
    return gid >= 0 && gid < SOKOL_GAMEPAD_MAX && button >= 0 && button < _gstate.states[gid].button_count ? _gstate.states[gid].current.buttons[button] : false;
}

bool sapp_gamepad_is_button_up(int button) {
    return sapp_gamepad_is_button_up_id(0, button);
}

bool sapp_gamepad_is_button_up_id(int gid, int button) {
    return !sapp_gamepad_is_button_down_id(0, button);
}

bool sapp_gamepad_was_button_pressed(int button) {
    return sapp_gamepad_was_button_pressed_id(0, button);
}

bool sapp_gamepad_was_button_pressed_id(int gid, int button) {
    if (gid >= 0 && gid < SOKOL_GAMEPAD_MAX && button >= 0 && button < _gstate.states[gid].button_count)
        return sapp_gamepad_is_button_down_id(gid, button) && !_gstate.states[gid].previous.buttons[button];
    else
        return false;
}

bool sapp_gamepad_was_button_released(int button) {
    return sapp_gamepad_was_button_released_id(0, button);
}

bool sapp_gamepad_was_button_released_id(int gid, int button) {
    if (gid >= 0 && gid < SOKOL_GAMEPAD_MAX && button >= 0 && button < _gstate.states[gid].button_count)
        return !sapp_gamepad_is_button_down_id(gid, button) && _gstate.states[gid].previous.buttons[button];
    else
        return false;
}

float sapp_gamepad_axis_x(void) {
    return sapp_gamepad_axis_x_id(0);
}

float sapp_gamepad_axis_x_id(int gid) {
    return gid >= 0 && gid < SOKOL_GAMEPAD_MAX ? _gstate.states[gid].current.axis[0] : 0.f;
}

float sapp_gamepad_axis_y(void) {
    return sapp_gamepad_axis_y_id(0);
}

float sapp_gamepad_axis_y_id(int gid) {
    return gid >= 0 && gid < SOKOL_GAMEPAD_MAX ? _gstate.states[gid].current.axis[1] : 0.f;
}

float sapp_gamepad_axis_delta_x(void) {
    return sapp_gamepad_axis_delta_x_id(0);
}

float sapp_gamepad_axis_delta_x_id(int gid) {
    return gid >= 0 && gid < SOKOL_GAMEPAD_MAX ? _gstate.states[gid].current.axis[0] - _gstate.states[gid].previous.axis[0] : 0.f;
}

float sapp_gamepad_axis_delta_y(void) {
    return sapp_gamepad_axis_delta_y_id(0);
}

float sapp_gamepad_axis_delta_y_id(int gid) {
    return gid >= 0 && gid < SOKOL_GAMEPAD_MAX ? _gstate.states[gid].current.axis[1] - _gstate.states[gid].previous.axis[1] : 0.f;
}
#endif

void sapp_input_init(void) {
    memset(&_input_state.input_prev,    0, sizeof(_state));
    memset(&_input_state.input_current, 0, sizeof(_state));
#ifndef SOKOL_INPUT_NO_GAMEPADS
    memset(&_gstate, 0, sizeof(_gstate));
    Gamepad_deviceAttachFunc(_gamepad_attach, NULL);
    Gamepad_deviceRemoveFunc(_gamepad_detach, NULL);
    Gamepad_buttonUpFunc(_gamepad_btn_up, NULL);
    Gamepad_buttonDownFunc(_gamepad_btn_down, NULL);
    Gamepad_axisMoveFunc(_gamepad_axis_move, NULL);
    Gamepad_init();
    Gamepad_detectDevices();
#endif
}

void sapp_input_event(const sapp_event* e) {
    switch (e->type) {
        case SAPP_EVENTTYPE_KEY_UP:
        case SAPP_EVENTTYPE_KEY_DOWN:
            _input_state.input_current.keys[e->key_code] = e->type == SAPP_EVENTTYPE_KEY_DOWN;
            _input_state.input_current.modifier = e->modifiers;
            break;
        case SAPP_EVENTTYPE_MOUSE_UP:
        case SAPP_EVENTTYPE_MOUSE_DOWN:
            _input_state.input_current.buttons[e->mouse_button] = e->type == SAPP_EVENTTYPE_MOUSE_DOWN;
            break;
        case SAPP_EVENTTYPE_MOUSE_MOVE:
            _input_state.input_current.cursor.x = e->mouse_x;
            _input_state.input_current.cursor.y = e->mouse_y;
            break;
        case SAPP_EVENTTYPE_MOUSE_SCROLL:
            _input_state.input_current.scroll.x = e->scroll_x;
            _input_state.input_current.scroll.y = e->scroll_y;
            break;
        default:
            _input_state.input_current.modifier = e->modifiers;
            break;
    }
}

void sapp_input_flush(void) {
    memcpy(&_input_state.input_prev, &_input_state.input_current, sizeof(_state));
    _input_state.input_current.scroll.x = _input_state.input_current.scroll.y = 0.f;
#ifndef SOKOL_INPUT_NO_GAMEPADS
    for (int i = 0; i < SOKOL_GAMEPAD_MAX; i++) {
        size_t size  = _gstate.states[i].button_count * sizeof(bool);
        memcpy(&_gstate.states[i].previous.buttons, &_gstate.states[i].current.buttons, size);
        memset(&_gstate.states[i].current.buttons, 0, size);
        memset(&_gstate.states[i].current.axis, 0, 2 * sizeof(float));
    }
    Gamepad_processEvents();
    Gamepad_detectDevices();
#endif
}

bool sapp_is_key_down(int key) {
    return _input_state.input_current.keys[key];
}

bool sapp_was_key_pressed(int key) {
    return sapp_is_key_down(key) && !_input_state.input_prev.keys[key];
}

bool sapp_was_key_released(int key) {
    return !sapp_is_key_down(key) && _input_state.input_prev.keys[key];
}

bool sapp_are_keys_down(int n, ...) {
    va_list args;
    va_start(args, n);
    int result = 1;
    for (int i = 0; i < n; i++)
        if (!_input_state.input_current.keys[va_arg(args, int)]) {
            result = 0;
            goto BAIL;
        }
BAIL:
    va_end(args);
    return result;
}

bool sapp_any_keys_down(int n, ...) {
    va_list args;
    va_start(args, n);
    int result = 0;
    for (int i = 0; i < n; i++)
        if (_input_state.input_current.keys[va_arg(args, int)]) {
            result = 1;
            goto BAIL;
        }
BAIL:
    va_end(args);
    return result;
}

bool sapp_is_button_down(int button) {
    return _input_state.input_current.buttons[button];
}

bool sapp_was_button_pressed(int button) {
    return sapp_is_button_down(button) && !_input_state.input_prev.buttons[button];
}

bool sapp_was_button_released(int button) {
    return !sapp_is_button_down(button) && _input_state.input_prev.buttons[button];
}

bool sapp_are_buttons_down(int n, ...) {
    va_list args;
    va_start(args, n);
    int result = 1;
    for (int i = 0; i < n; i++)
        if (!_input_state.input_current.buttons[va_arg(args, int)]) {
            result = 0;
            goto BAIL;
        }
BAIL:
    va_end(args);
    return result;
}

bool sapp_any_buttons_down(int n, ...) {
    va_list args;
    va_start(args, n);
    int result = 0;
    for (int i = 0; i < n; i++)
        if (_input_state.input_current.buttons[va_arg(args, int)]) {
            result = 1;
            goto BAIL;
        }
BAIL:
    va_end(args);
    return result;
}

bool sapp_modifier_equals(int mods) {
    return _input_state.input_current.modifier == mods;
}

bool sapp_modifier_down(int mod) {
    return _input_state.input_current.modifier & mod;
}

bool sapp_has_mouse_move(void) {
    return _input_state.input_current.cursor.x != _input_state.input_prev.cursor.x || _input_state.input_current.cursor.y != _input_state.input_prev.cursor.y;
}

int sapp_cursor_x(void) {
    return _input_state.input_current.cursor.x;
}

int sapp_cursor_y(void) {
    return _input_state.input_current.cursor.y;
}

bool sapp_cursor_delta_x(void) {
    return _input_state.input_current.cursor.x - _input_state.input_prev.cursor.x;
}

bool sapp_cursor_delta_y(void) {
    return _input_state.input_current.cursor.y - _input_state.input_prev.cursor.y;
}

bool sapp_scrolled(void) {
    return _input_state.input_current.scroll.x != 0 || _input_state.input_current.scroll.y != 0;
}

float sapp_scroll_x(void) {
    return _input_state.input_current.scroll.x;
}

float sapp_scroll_y(void) {
    return _input_state.input_current.scroll.y;
}

typedef struct input_str {
    const char *original;
    const char *offset;
    const char *cursor;
    int modifiers;
    int *keys;
} input_parser_t;

static bool parser_eof(input_parser_t *p) {
    return p->cursor || *p->cursor == '\0';
}

static char parser_advance(input_parser_t *p) {
    char c = *p->cursor;
    if (c != '\0')
        p->cursor++;
    return c;
}

static char parse_peek(input_parser_t *p) {
    return parser_eof(p) ? '\0' : *(p->cursor + 1);
}

static bool parser_is_whitespace(input_parser_t *p) {
    return *p->cursor == ' ';
}

static bool parse_word(input_parser_t *p) {
    p->offset = p->cursor;
    while (!parser_eof(p)) {
        switch (*p->cursor) {
            case 'a' ... 'z':
            case 'A' ... 'Z':
            case '0' ... '9':
                (void)parser_advance(p);
                break;
            default:
                if (!parser_is_whitespace(p))
                    return false;
            case '+':
            case ',':
            case ' ':
                return true;
        }
    }
    return true;
}

static int translate_char(input_parser_t *p) {
    switch (*p->offset) {
        case 'A' ... 'Z':
        case '0' ... '9':
            return (int)*p->offset;
        default:
            return -1;
    }
}

#define KEY_TESTS       \
    X(SPACE, 32),       \
    X(APOSTROPHE, 39),  \
    X(COMMA, 44),       \
    X(MINUS, 45),       \
    X(PERIOD, 46),      \
    X(SLASH, 47),       \
    X(SEMICOLON, 59),   \
    X(EQUAL, 61),       \
    X(LBRACKET, 91),    \
    X(BACKSLASH, 92),   \
    X(RBRACKET, 93),    \
    X(GRAVE, 96),       \
    X(WORLD1, 161),     \
    X(WORLD2, 162),     \
    X(ESCAPE, 256),     \
    X(ENTER, 257),      \
    X(TAB, 258),        \
    X(BACKSPACE, 259),  \
    X(INSERT, 260),     \
    X(DELETE, 261),     \
    X(RIGHT, 262),      \
    X(LEFT, 263),       \
    X(DOWN, 264),       \
    X(UP, 265),         \
    X(PGUP, 266),       \
    X(PGDN, 267),       \
    X(HOME, 268),       \
    X(END, 269),        \
    X(CAPSLOCK, 280),   \
    X(SCROLLLOCK, 281), \
    X(NUMLOCK, 282),    \
    X(PRNTSCRN, 283),   \
    X(PAUSE, 284),      \
    X(F1, 290),         \
    X(F2, 291),         \
    X(F3, 292),         \
    X(F4, 293),         \
    X(F5, 294),         \
    X(F6, 295),         \
    X(F7, 296),         \
    X(F8, 297),         \
    X(F9, 298),         \
    X(F10, 299),        \
    X(F11, 300),        \
    X(F12, 301),        \
    X(F13, 302),        \
    X(F14, 303),        \
    X(F15, 304),        \
    X(F16, 305),        \
    X(F17, 306),        \
    X(F18, 307),        \
    X(F19, 308),        \
    X(F20, 309),        \
    X(F21, 310),        \
    X(F22, 311),        \
    X(F23, 312),        \
    X(F24, 313),        \
    X(F25, 314),        \
    X(MENU, 348)

#define MOD_TESTS      \
    X(SHIFT, 340),     \
    X(CONTROL, 341),   \
    X(CTRL, 341),      \
    X(ALT, 342),       \
    X(SUPER, 343),     \
    X(CMD, 343),       \
    X(LSHIFT, 340),    \
    X(LCONTROL, 341),  \
    X(LCTRL, 341),     \
    X(LALT, 342),      \
    X(LSUPER, 343),    \
    X(LCMD, 343),      \
    X(RSHIFT, 344),    \
    X(RCONTROL, 345),  \
    X(RCTRL, 345),     \
    X(RALT, 346),      \
    X(RSUPER, 347),    \
    X(RCMD, 347)

static int translate_word(input_parser_t *p, bool *is_modifier) {
    int len = (int)(p->cursor - p->offset);
    char *buf = calloc(len + 1, sizeof(char));
    memcpy(buf, p->offset, sizeof(char));
    buf[len] = '\0';
    for (char *c = buf; *c != '\0'; c++)
        if (*c >= 'a' && *c <= 'z')
            *c -= 32;
#define X(NAME, VAL)               \
    if (!strncmp(buf, #NAME, len)) \
    {                              \
        if (is_modifier)           \
            *is_modifier = false;  \
        free(buf);                 \
        return VAL;                \
    }                              \
    KEY_TESTS
#undef X
#define X(NAME, VAL)               \
    if (!strncmp(buf, #NAME, len)) \
    {                              \
        if (is_modifier)           \
            *is_modifier = true;   \
        free(buf);                 \
        return VAL;                \
    }                              \
    MOD_TESTS
#undef X
    free(buf);
    return -1;
}

static void parser_add_key(input_parser_t *p, int key) {
    bool found = false;
    for (int i = 0; i < vector_count(p->keys); i++)
        if (p->keys[i] == key) {
            found = true;
            break;
        }
    if (!found)
        vector_append(p->keys, key);
}

static bool parse_input_str(input_parser_t *p) {
    while (!parser_eof(p)) {
        p->offset = p->cursor;
        while (parser_is_whitespace(p))
            if (parser_advance(p) == '\0')
                return true;
        switch (*p->cursor) {
            case 'a' ... 'z':
            case 'A' ... 'Z':
                if (!parse_word(p))
                    goto BAIL;
                switch ((int)(p->cursor - p->offset)) {
                    case 0:
                        goto BAIL;
                    case 1:;
                        int key = translate_char(p);
                        if (key == -1)
                            goto BAIL;
                        parser_add_key(p, key);
                        break;
                    default:;
                        bool is_modifier = false;
                        int wkey = translate_word(p, &is_modifier);
                        if (wkey == -1)
                            goto BAIL;
                        if (is_modifier)
                            p->modifiers |= wkey;
                        else
                            parser_add_key(p, wkey);
                        break;
                }
                break;
            case '0' ... '9':;
                int nkey = translate_char(p);
                if (nkey == -1)
                    goto BAIL;
                parser_add_key(p, nkey);
                break;
            case '+':
            case ',':
                (void)parser_advance(p);
                break;
            default:
                goto BAIL;
        }
    }
    return true;
BAIL:
    fprintf(stderr, "[FAILED TO PARSE INPUT STRING] parse_input_str cannot read '%s'\n", p->original);
    if (p->keys)
        vector_free(p->keys);
    return false;
}

static int* _vaargs(int n, va_list args) {
    int *result = NULL;
    for (int i = 0; i < n; i++) {
        bool found = false;
        int key = va_arg(args, int);
        for (int j = 0; j < vector_count(result); j++)
            if (key == result[j]) {
                found = true;
                break;
            }
        if (!found)
            vector_append(result, key);
    }
    va_end(args);
    return result;
}

bool sapp_input_is_str_down(const char *str) {
    input_parser_t p;
    memset(&p, 0, sizeof(input_parser_t));
    p.original = p.offset = p.cursor = str;
    if (!parse_input_str(&p) || (!p.modifiers && !p.keys))
        return false;
    bool mod_check = true;
    bool key_check = true;
    if (p.modifiers)
        mod_check = sapp_modifier_equals(p.modifiers);
    if (p.keys) {
        for (int i = 0; i < vector_count(p.keys); i++)
            if (!sapp_is_key_down(p.keys[i])) {
                key_check = false;
                break;
            }
        vector_free(p.keys);
    }
    return mod_check && key_check;
}

bool sapp_input_is_down(int modifiers, int n, ...) {
    int *tmp = NULL;
    bool result = false;
    if (modifiers != 0)
        if (!sapp_modifier_equals(modifiers))
            goto BAIL;
    if (!n)
        goto BAIL;
    va_list args;
    va_start(args, n);
    if (!(tmp = _vaargs(n, args)))
        goto BAIL;
    bool check = true;
    for (int i = 0; i < vector_count(args); i++)
        if (!sapp_is_key_down(tmp[i])) {
            check = false;
            break;
        }
    va_end(args);
    if (check)
        result = true;
BAIL:
    if (tmp)
        vector_free(tmp);
    return result;
}

int* sapp_parse_input_str(const char *str, int *modifiers) {
    input_parser_t p;
    memset(&p, 0, sizeof(input_parser_t));
    p.original = p.offset = p.cursor = str;
    if (!parse_input_str(&p) || (!p.modifiers && !p.keys))
        return false;
    if (p.modifiers && modifiers)
        *modifiers = p.modifiers ? p.modifiers : 0;
    int count = vector_count(p.keys);
    int *result = malloc(count * sizeof(int));
    memcpy(result, p.keys, count * sizeof(int));
    vector_free(p.keys);
    return result;
}
#endif // SOKOL_IMPL
