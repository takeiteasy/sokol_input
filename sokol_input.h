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

 /*!
 @header sokol_input.h
 @copyright George Watson GPLv3
 @updated 2025-07-20
 @abstract Input handling for sokol_app
 @discussion Provides an input manager for sokol_app, handling keyboard, mouse, and gamepad input.
 */

#ifndef SOKOL_INPUT_HEADER
#define SOKOL_INPUT_HEADER
#ifdef __cplusplus
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
#include <stdbool.h>

/*!
 @function sapp_input_event
 @param event The input event to process.
 @abstract Call this function to handle input events.
 @discussion This function should be called in the sapp event callback to process input events.
             Or it can be used directly by passing it as the event handler in sapp_run.
 */
void sapp_input_event(const sapp_event *event);
/*!
 @function sapp_input_flush
 @abstract Flush the input state.
 @discussion Call this function at the end of each frame to update the input state.
 */
void sapp_input_flush(void);
/*!
 @function sapp_input_init
 @abstract Initialize the input system.
 @discussion Call this function to initialize the input system. Either before sapp_run or in the sapp init callback.
 */
void sapp_input_init(void);

/*!
 @function sapp_is_key_down
 @param key The key code to check.
 @return True if the key is currently pressed down.
 @abstract Check if a key is currently pressed down.
 */
bool sapp_is_key_down(int key);
/*!
 @function sapp_was_key_pressed
 @param key The key code to check.
 @return True if the key was pressed down in the last frame.
 @abstract Check if a key was pressed down in the last frame.
 */
bool sapp_was_key_pressed(int key);
/*!
 @function sapp_was_key_released
 @param key The key code to check.
 @return True if the key was released in the last frame.
 @abstract Check if a key was released in the last frame.
 */
bool sapp_was_key_released(int key);
/*!
 @function sapp_are_keys_down
 @param n The number of keys to check.
 @param ... The key codes to check.
 @return True if all the keys are currently pressed down.
 @abstract Check if multiple keys are currently pressed down.
 */
bool sapp_are_keys_down(int n, ...);
/*!
 @function sapp_any_keys_down
 @param n The number of keys to check.
 @param ... The key codes to check.
 @return True if any of the keys are currently pressed down.
 @abstract Check if any of the keys are currently pressed down.
 */
bool sapp_any_keys_down(int n, ...);
/*!
 @function sapp_is_button_down
 @param button The mouse button to check.
 @return True if the mouse button is currently pressed down.
 @abstract Check if a mouse button is currently pressed down.
 */
bool sapp_is_button_down(int button);
/*!
 @function sapp_was_button_pressed
 @param button The mouse button to check.
 @return True if the mouse button was pressed down in the last frame.
 @abstract Check if a mouse button was pressed down in the last frame.
 */
bool sapp_was_button_pressed(int button);
/*!
 @function sapp_was_button_released
 @param button The mouse button to check.
 @return True if the mouse button was released in the last frame.
 @abstract Check if a mouse button was released in the last frame.
 */
bool sapp_was_button_released(int button);
/*!
 @function sapp_are_buttons_down
 @param n The number of buttons to check.
 @param ... The mouse button codes to check.
 @return True if all the buttons are currently pressed down.
 @abstract Check if multiple mouse buttons are currently pressed down.
 */
bool sapp_are_buttons_down(int n, ...);
/*!
 @function sapp_any_buttons_down
 @param n The number of buttons to check.
 @param ... The mouse button codes to check.
 @return True if any of the buttons are currently pressed down.
 @abstract Check if any of the mouse buttons are currently pressed down.
 */
bool sapp_any_buttons_down(int n, ...);
/*!
 @function sapp_has_mouse_move
 @return True if the mouse has moved since the last frame.
 @abstract Check if the mouse has moved since the last frame.
 */
bool sapp_has_mouse_move(void);
/*!
 @function sapp_modifier_equals
 @param mods The modifier keys to check.
 @return True if the current modifiers match the specified ones.
 @abstract Check if the current modifier keys match the specified ones.
 */
bool sapp_modifier_equals(int mods);
/*!
 @function sapp_modifier_down
 @param mod The modifier key to check.
 @return True if the specified modifier key is currently pressed down.
 @abstract Check if a specific modifier key is currently pressed down.
 */
bool sapp_modifier_down(int mod);
/*!
 @function sapp_cursor_x
 @return The current x position of the mouse cursor.
 @abstract Get the current x position of the mouse cursor.
 */
int sapp_cursor_x(void);
/*!
 @function sapp_cursor_y
 @return The current y position of the mouse cursor.
 @abstract Get the current y position of the mouse cursor.
 */
int sapp_cursor_y(void);
/*!
 @function sapp_cursor_delta_x
 @return The change in x position of the mouse cursor since the last frame.
 @abstract Get the change in x position of the mouse cursor since the last frame.
 */
int sapp_cursor_delta_x(void);
/*!
 @function sapp_cursor_delta_y
 @return The change in y position of the mouse cursor since the last frame.
 @abstract Get the change in y position of the mouse cursor since the last frame.
 */
int sapp_cursor_delta_y(void);
/*!
 @function sapp_was_mouse_scrolled
 @return True if the mouse wheel has been scrolled since the last frame.
 @abstract Check if the mouse wheel has been scrolled since the last frame.
 */
bool sapp_was_mouse_scrolled(void);
/*!
 @function sapp_scroll_x
 @return The amount the mouse wheel has been scrolled in the x direction since the last frame.
 @abstract Get the amount the mouse wheel has been scrolled in the x direction since the last frame.
 */
float sapp_scroll_x(void);
/*!
 @function sapp_scroll_y
 @return The amount the mouse wheel has been scrolled in the y direction since the last frame.
 @abstract Get the amount the mouse wheel has been scrolled in the y direction since the last frame.
 */
float sapp_scroll_y(void);

#ifdef __cplusplus
}
#endif
#endif // SOKOL_INPUT_HEADER

#if defined(SOKOL_INPUT_IMPLEMENTATION) || defined(SOKOL_IMPL)
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

#ifndef SOKOL_KEY_HOLD_DELAY
#define SOKOL_KEY_HOLD_DELAY 1.f
#endif

#define _MAX(A, B)    ((A) > (B) ? (A) : (B))

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

void sapp_input_init(void) {
    memset(&_input_state.input_prev,    0, sizeof(_state));
    memset(&_input_state.input_current, 0, sizeof(_state));
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

int sapp_cursor_delta_x(void) {
    return _input_state.input_current.cursor.x - _input_state.input_prev.cursor.x;
}

int sapp_cursor_delta_y(void) {
    return _input_state.input_current.cursor.y - _input_state.input_prev.cursor.y;
}

bool sapp_was_mouse_scrolled(void) {
    return _input_state.input_current.scroll.x != 0 || _input_state.input_current.scroll.y != 0;
}

float sapp_scroll_x(void) {
    return _input_state.input_current.scroll.x;
}

float sapp_scroll_y(void) {
    return _input_state.input_current.scroll.y;
}
#endif // SOKOL_IMPL
