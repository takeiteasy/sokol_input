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
 @function sapp_scrolled
 @return True if the mouse wheel has been scrolled since the last frame.
 @abstract Check if the mouse wheel has been scrolled since the last frame.
 */
bool sapp_scrolled(void);
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

#if defined(__ANDROID__) || defined(__EMSCRIPTEN__) || (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE == 1)
/*!
 @define SOKOL_INPUT_NO_GAMEPADS
 @abstract Disable gamepad support.
 @discussion This macro can be defined to disable gamepad support in the sokol_input.h header.
             It is useful for platforms where gamepad support is not available or not needed.
             This is automatically defined for Android, Emscripten, and iOS platforms.
 */
#define SOKOL_INPUT_NO_GAMEPADS
#endif

#ifndef SOKOL_INPUT_NO_GAMEPADS
#ifndef SOKOL_GAMEPAD_MAX
/*!
 @define SOKOL_GAMEPAD_MAX
 @abstract The maximum number of gamepads supported.
 @discussion This defines the maximum number of gamepads that can be connected at the same time.
             The default value is 1, but it can be changed to support more gamepads.
 */
#define SOKOL_GAMEPAD_MAX 1
#endif

/*!
 @function sapp_gamepad_count
 @return The number of connected gamepads.
 @abstract Get the number of connected gamepads.
 */
int sapp_gamepad_count(void);
/*!
 @function sapp_gamepad_is_connected
 @return True if a gamepad is connected.
 @abstract Check if any gamepad is connected.
 */
bool sapp_gamepad_is_connected(void);
/*!
 @function sapp_gamepad_disconnect
 @abstract Disconnect the first gamepad.
 @discussion This function disconnects the first gamepad. It can be used to reset the gamepad state.
 */
void sapp_gamepad_disconnect(void);
/*!
 @function sapp_gamepad_disconnect_id
 @param gid The gamepad ID to disconnect.
 @abstract Disconnect a specific gamepad by ID.
 @discussion This function disconnects a gamepad by its ID. It can be used to reset the state of a specific gamepad.
 */
void sapp_gamepad_disconnect_id(int gid);
/*!
 @function sapp_gamepad_is_connected_id
 @param gid The gamepad ID to check.
 @return True if the specified gamepad is connected.
 @abstract Check if a specific gamepad is connected by ID.
 */
bool sapp_gamepad_is_connected_id(int gid);
/*!
 @function sapp_gamepad_is_button_down
 @param button The gamepad button to check.
 @return True if the specified gamepad button is currently pressed down.
 @abstract Check if a gamepad button is currently pressed down.
 */
bool sapp_gamepad_is_button_down(int button);
/*!
 @function sapp_gamepad_is_button_down_id
 @param gid The gamepad ID to check.
 @param button The gamepad button to check.
 @return True if the specified gamepad button is currently pressed down.
 @abstract Check if a specific gamepad button is currently pressed down by ID.
 */
bool sapp_gamepad_is_button_down_id(int gid, int button);
/*!
 @function sapp_gamepad_is_button_up
 @param button The gamepad button to check.
 @return True if the specified gamepad button is not currently pressed down.
 @abstract Check if a gamepad button is not currently pressed down.
 */
bool sapp_gamepad_is_button_up(int button);
/*!
 @function sapp_gamepad_is_button_up_id
 @param gid The gamepad ID to check.
 @param button The gamepad button to check.
 @return True if the specified gamepad button is not currently pressed down.
 @abstract Check if a specific gamepad button is not currently pressed down by ID.
 */
bool sapp_gamepad_is_button_up_id(int gid, int button);
/*!
 @function sapp_gamepad_was_button_pressed
 @param button The gamepad button to check.
 @return True if the specified gamepad button was pressed down in the last frame.
 @abstract Check if a gamepad button was pressed down in the last frame.
 */
bool sapp_gamepad_was_button_pressed(int button);
/*!
 @function sapp_gamepad_was_button_pressed_id
 @param gid The gamepad ID to check.
 @param button The gamepad button to check.
 @return True if the specified gamepad button was pressed down in the last frame.
 @abstract Check if a specific gamepad button was pressed down in the last frame by ID.
 */
bool sapp_gamepad_was_button_pressed_id(int gid, int button);
/*!
 @function sapp_gamepad_was_button_released
 @param button The gamepad button to check.
 @return True if the specified gamepad button was released in the last frame.
 @abstract Check if a gamepad button was released in the last frame.
 */
bool sapp_gamepad_was_button_released(int button);
/*!
 @function sapp_gamepad_was_button_released_id
 @param gid The gamepad ID to check.
 @param button The gamepad button to check.
 @return True if the specified gamepad button was released in the last frame.
 @abstract Check if a specific gamepad button was released in the last frame by ID.
 */
bool sapp_gamepad_was_button_released_id(int gid, int button);
/*!
 @function sapp_gamepad_axis_x
 @return The x-axis value of the first gamepad.
 @abstract Get the x-axis value of the first gamepad.
 */
float sapp_gamepad_axis_x(void);
/*!
 @function sapp_gamepad_axis_x_id
 @param gid The gamepad ID to check.
 @return The x-axis value of the specified gamepad.
 @abstract Get the x-axis value of a specific gamepad by ID.
 */
float sapp_gamepad_axis_x_id(int gid);
/*!
 @function sapp_gamepad_axis_y
 @return The y-axis value of the first gamepad.
 @abstract Get the y-axis value of the first gamepad.
 */
float sapp_gamepad_axis_y(void);
/*!
 @function sapp_gamepad_axis_y_id
 @param gid The gamepad ID to check.
 @return The y-axis value of the specified gamepad.
 @abstract Get the y-axis value of a specific gamepad by ID.
 */
float sapp_gamepad_axis_y_id(int gid);
/*!
 @function sapp_gamepad_axis_delta_x
 @return The change in x-axis value of the first gamepad since the last frame.
 @abstract Get the change in x-axis value of the first gamepad since the last frame.
 */
float sapp_gamepad_axis_delta_x(void);
/*!
 @function sapp_gamepad_axis_delta_x_id
 @param gid The gamepad ID to check.
 @return The change in x-axis value of the specified gamepad since the last frame.
 @abstract Get the change in x-axis value of a specific gamepad by ID since the last frame.
 */
float sapp_gamepad_axis_delta_x_id(int gid);
/*!
 @function sapp_gamepad_axis_delta_y
 @return The change in y-axis value of the first gamepad since the last frame.
 @abstract Get the change in y-axis value of the first gamepad since the last frame.
 */
float sapp_gamepad_axis_delta_y(void);
/*!
 @function sapp_gamepad_axis_delta_y_id
 @param gid The gamepad ID to check.
 @return The change in y-axis value of the specified gamepad since the last frame.
 @abstract Get the change in y-axis value of a specific gamepad by ID since the last frame.
 */
float sapp_gamepad_axis_delta_y_id(int gid);
#endif

/*!
 @function sapp_input_is_str_down
 @param str The string to check.
 @return True if the string is currently pressed down.
 @abstract Check if a string of keys is currently pressed down.
 @discussion The string should be formatted as a sequence of key codes and modifier keys separated by commas or addition signs.
             For example: "CTRL+A or CTRL+A,B or CTRL+SHIFT,C"
 */
bool sapp_input_is_str_down(const char *str);
/*!
 @function sapp_input_is_down
 @param modifiers The modifier keys to check.
 @param n The number of keys to check.
 @param ... The key codes to check.
 @return True if all the specified keys are currently pressed down with the given modifiers.
 @abstract Check if multiple keys are currently pressed down with specific modifiers.
 */
bool sapp_input_is_down(int modifiers, int n, ...);
/*!
 @function sapp_parse_input_str
 @param str The string to parse.
 @param modifiers Pointer to an integer to store the modifiers.
 @return A pointer to an array of integers representing the key codes.
 @abstract Parse a string of input keys and modifiers.
 */
int* sapp_parse_input_str(const char *str, int *modifiers);

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
#ifndef SOKOL_INPUT_NO_GAMEPADS
/*
  Copyright (c) 2014 Alex Diener
  
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.
  
  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:
  
  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
  
  Alex Diener alex@ludobloom.com
*/

#ifndef __GAMEPAD_H__
#define __GAMEPAD_H__
#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER) && (_MSC_VER <= 1600)
#define bool int
#define true 1
#define false 0
#else
#include <stdbool.h>
#endif

struct Gamepad_device {
	// Unique device identifier for application session, starting at 0 for the first device attached and
	// incrementing by 1 for each additional device. If a device is removed and subsequently reattached
	// during the same application session, it will have a new deviceID.
	unsigned int deviceID;
	
	// Human-readable device name
	const char * description;
	
	// USB vendor/product IDs as returned by the driver. Can be used to determine the particular model of device represented.
	int vendorID;
	int productID;
	
	// Number of axis elements belonging to the device
	unsigned int numAxes;
	
	// Number of button elements belonging to the device
	unsigned int numButtons;
	
	// Array[numAxes] of values representing the current state of each axis, in the range [-1..1]
	float * axisStates;
	
	// Array[numButtons] of values representing the current state of each button
	bool * buttonStates;
	
	// Platform-specific device data storage. Don't touch unless you know what you're doing and don't
	// mind your code breaking in future versions of this library.
	void * privateData;
};

/* Initializes gamepad library and detects initial devices. Call this before any other Gamepad_*()
   function, other than callback registration functions. If you want to receive deviceAttachFunc
   callbacks from devices detected in Gamepad_init(), you must call Gamepad_deviceAttachFunc()
   before calling Gamepad_init().
   
   This function must be called from the same thread that will be calling Gamepad_processEvents()
   and Gamepad_detectDevices(). */
void Gamepad_init();

/* Tears down all data structures created by the gamepad library and releases any memory that was
   allocated. It is not necessary to call this function at application termination, but it's
   provided in case you want to free memory associated with gamepads at some earlier time. */
void Gamepad_shutdown();

/* Returns the number of currently attached gamepad devices. */
unsigned int Gamepad_numDevices();

/* Returns the specified Gamepad_device struct, or NULL if deviceIndex is out of bounds. */
struct Gamepad_device * Gamepad_deviceAtIndex(unsigned int deviceIndex);

/* Polls for any devices that have been attached since the last call to Gamepad_detectDevices() or
   Gamepad_init(). If any new devices are found, the callback registered with
   Gamepad_deviceAttachFunc() (if any) will be called once per newly detected device.
   
   Note that depending on implementation, you may receive button and axis event callbacks for
   devices that have not yet been detected with Gamepad_detectDevices(). You can safely ignore
   these events, but be aware that your callbacks might receive a device ID that hasn't been seen
   by your deviceAttachFunc. */
void Gamepad_detectDevices();

/* Reads pending input from all attached devices and calls the appropriate input callbacks, if any
   have been registered. */
void Gamepad_processEvents();

/* Registers a function to be called whenever a device is attached. The specified function will be
   called only during calls to Gamepad_init() and Gamepad_detectDevices(), in the thread from
   which those functions were called. Calling this function with a NULL argument will stop any
   previously registered callback from being called subsequently. */
void Gamepad_deviceAttachFunc(void (* callback)(struct Gamepad_device * device, void * context), void * context);

/* Registers a function to be called whenever a device is detached. The specified function can be
   called at any time, and will not necessarily be called from the main thread. Calling this
   function with a NULL argument will stop any previously registered callback from being called
   subsequently. */
void Gamepad_deviceRemoveFunc(void (* callback)(struct Gamepad_device * device, void * context), void * context);

/* Registers a function to be called whenever a button on any attached device is pressed. The
   specified function will be called only during calls to Gamepad_processEvents(), in the
   thread from which Gamepad_processEvents() was called. Calling this function with a NULL
   argument will stop any previously registered callback from being called subsequently.  */
void Gamepad_buttonDownFunc(void (* callback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context), void * context);

/* Registers a function to be called whenever a button on any attached device is released. The
   specified function will be called only during calls to Gamepad_processEvents(), in the
   thread from which Gamepad_processEvents() was called. Calling this function with a NULL
   argument will stop any previously registered callback from being called subsequently.  */
void Gamepad_buttonUpFunc(void (* callback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context), void * context);

/* Registers a function to be called whenever an axis on any attached device is moved. The
   specified function will be called only during calls to Gamepad_processEvents(), in the
   thread from which Gamepad_processEvents() was called. Calling this function with a NULL
   argument will stop any previously registered callback from being called subsequently.  */
void Gamepad_axisMoveFunc(void (* callback)(struct Gamepad_device * device, unsigned int axisID, float value, float lastValue, double timestamp, void * context), void * context);

#ifdef __cplusplus
}
#endif
#endif
/*
  Copyright (c) 2014 Alex Diener
  
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.
  
  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:
  
  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
  
  Alex Diener alex@ludobloom.com
*/

#ifndef __GAMEPAD_PRIVATE_H__
#define __GAMEPAD_PRIVATE_H__

enum Gamepad_eventType {
	GAMEPAD_EVENT_DEVICE_ATTACHED,
	GAMEPAD_EVENT_DEVICE_REMOVED,
	GAMEPAD_EVENT_BUTTON_DOWN,
	GAMEPAD_EVENT_BUTTON_UP,
	GAMEPAD_EVENT_AXIS_MOVED
};

struct Gamepad_buttonEvent {
	// Device that generated the event
	struct Gamepad_device * device;
	
	// Relative time of the event, in seconds
	double timestamp;
	
	// Button being pushed or released
	unsigned int buttonID;
	
	// True if button is down
	bool down;
};

struct Gamepad_axisEvent {
	// Device that generated the event
	struct Gamepad_device * device;
	
	// Relative time of the event, in seconds
	double timestamp;
	
	// Axis being moved
	unsigned int axisID;
	
	// Axis position value, in the range [-1..1]
	float value;
	
	// Previous axis position value, in the range [-1..1]
	float lastValue;
};

extern void (* Gamepad_deviceAttachCallback)(struct Gamepad_device * device, void * context);
extern void (* Gamepad_deviceRemoveCallback)(struct Gamepad_device * device, void * context);
extern void (* Gamepad_buttonDownCallback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context);
extern void (* Gamepad_buttonUpCallback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context);
extern void (* Gamepad_axisMoveCallback)(struct Gamepad_device * device, unsigned int axisID, float value, float lastValue, double timestamp, void * context);
extern void * Gamepad_deviceAttachContext;
extern void * Gamepad_deviceRemoveContext;
extern void * Gamepad_buttonDownContext;
extern void * Gamepad_buttonUpContext;
extern void * Gamepad_axisMoveContext;

#endif
/*
  Copyright (c) 2014 Alex Diener
  
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.
  
  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:
  
  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
  
  Alex Diener alex@ludobloom.com
*/

#include <stdlib.h>

void (* Gamepad_deviceAttachCallback)(struct Gamepad_device * device, void * context) = NULL;
void (* Gamepad_deviceRemoveCallback)(struct Gamepad_device * device, void * context) = NULL;
void (* Gamepad_buttonDownCallback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context) = NULL;
void (* Gamepad_buttonUpCallback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context) = NULL;
void (* Gamepad_axisMoveCallback)(struct Gamepad_device * device, unsigned int buttonID, float value, float lastValue, double timestamp, void * context) = NULL;
void * Gamepad_deviceAttachContext = NULL;
void * Gamepad_deviceRemoveContext = NULL;
void * Gamepad_buttonDownContext = NULL;
void * Gamepad_buttonUpContext = NULL;
void * Gamepad_axisMoveContext = NULL;

void Gamepad_deviceAttachFunc(void (* callback)(struct Gamepad_device * device, void * context), void * context) {
	Gamepad_deviceAttachCallback = callback;
	Gamepad_deviceAttachContext = context;
}

void Gamepad_deviceRemoveFunc(void (* callback)(struct Gamepad_device * device, void * context), void * context) {
	Gamepad_deviceRemoveCallback = callback;
	Gamepad_deviceRemoveContext = context;
}

void Gamepad_buttonDownFunc(void (* callback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context), void * context) {
	Gamepad_buttonDownCallback = callback;
	Gamepad_buttonDownContext = context;
}

void Gamepad_buttonUpFunc(void (* callback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context), void * context) {
	Gamepad_buttonUpCallback = callback;
	Gamepad_buttonUpContext = context;
}

void Gamepad_axisMoveFunc(void (* callback)(struct Gamepad_device * device, unsigned int axisID, float value, float lastValue, double timestamp, void * context), void * context) {
	Gamepad_axisMoveCallback = callback;
	Gamepad_axisMoveContext = context;
}
#include <stdlib.h>

void (* Gamepad_deviceAttachCallback)(struct Gamepad_device * device, void * context) = NULL;
void (* Gamepad_deviceRemoveCallback)(struct Gamepad_device * device, void * context) = NULL;
void (* Gamepad_buttonDownCallback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context) = NULL;
void (* Gamepad_buttonUpCallback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context) = NULL;
void (* Gamepad_axisMoveCallback)(struct Gamepad_device * device, unsigned int buttonID, float value, float lastValue, double timestamp, void * context) = NULL;
void * Gamepad_deviceAttachContext = NULL;
void * Gamepad_deviceRemoveContext = NULL;
void * Gamepad_buttonDownContext = NULL;
void * Gamepad_buttonUpContext = NULL;
void * Gamepad_axisMoveContext = NULL;

void Gamepad_deviceAttachFunc(void (* callback)(struct Gamepad_device * device, void * context), void * context) {
	Gamepad_deviceAttachCallback = callback;
	Gamepad_deviceAttachContext = context;
}

void Gamepad_deviceRemoveFunc(void (* callback)(struct Gamepad_device * device, void * context), void * context) {
	Gamepad_deviceRemoveCallback = callback;
	Gamepad_deviceRemoveContext = context;
}

void Gamepad_buttonDownFunc(void (* callback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context), void * context) {
	Gamepad_buttonDownCallback = callback;
	Gamepad_buttonDownContext = context;
}

void Gamepad_buttonUpFunc(void (* callback)(struct Gamepad_device * device, unsigned int buttonID, double timestamp, void * context), void * context) {
	Gamepad_buttonUpCallback = callback;
	Gamepad_buttonUpContext = context;
}

void Gamepad_axisMoveFunc(void (* callback)(struct Gamepad_device * device, unsigned int axisID, float value, float lastValue, double timestamp, void * context), void * context) {
	Gamepad_axisMoveCallback = callback;
	Gamepad_axisMoveContext = context;
}
#if defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#include <IOKit/hid/IOHIDLib.h>
#include <limits.h>
#include <mach/mach.h>
#include <mach/mach_time.h>

#define GAMEPAD_RUN_LOOP_MODE CFSTR("GamepadRunLoopMode")

struct HIDGamepadAxis {
	IOHIDElementCookie cookie;
	CFIndex logicalMin;
	CFIndex logicalMax;
	bool hasNullState;
	bool isHatSwitch;
	bool isHatSwitchSecondAxis;
};

struct HIDGamepadButton {
	IOHIDElementCookie cookie;
};

struct Gamepad_devicePrivate {
	IOHIDDeviceRef deviceRef;
	struct HIDGamepadAxis * axisElements;
	struct HIDGamepadButton * buttonElements;
};

struct Gamepad_queuedEvent {
	unsigned int deviceID;
	enum Gamepad_eventType eventType;
	void * eventData;
};

static IOHIDManagerRef hidManager = NULL;
static struct Gamepad_device ** devices = NULL;
static unsigned int numDevices = 0;
static unsigned int nextDeviceID = 0;

static struct Gamepad_queuedEvent * inputEventQueue = NULL;
static size_t inputEventQueueSize = 0;
static size_t inputEventCount = 0;

static struct Gamepad_queuedEvent * deviceEventQueue = NULL;
static size_t deviceEventQueueSize = 0;
static size_t deviceEventCount = 0;

static void hatValueToXY(CFIndex value, CFIndex range, int * outX, int * outY) {
	if (value == range) {
		*outX = *outY = 0;
		
	} else {
		if (value > 0 && value < range / 2) {
			*outX = 1;
			
		} else if (value > range / 2) {
			*outX = -1;
			
		} else {
			*outX = 0;
		}
		
		if (value > range / 4 * 3 || value < range / 4) {
			*outY = -1;
			
		} else if (value > range / 4 && value < range / 4 * 3) {
			*outY = 1;
			
		} else {
			*outY = 0;
		}
	}
}

static void queueInputEvent(unsigned int deviceID, enum Gamepad_eventType eventType, void * eventData) {
	struct Gamepad_queuedEvent queuedEvent;
	
	queuedEvent.deviceID = deviceID;
	queuedEvent.eventType = eventType;
	queuedEvent.eventData = eventData;
	
	if (inputEventCount >= inputEventQueueSize) {
		inputEventQueueSize = inputEventQueueSize == 0 ? 1 : inputEventQueueSize * 2;
		inputEventQueue = realloc(inputEventQueue, sizeof(struct Gamepad_queuedEvent) * inputEventQueueSize);
	}
	inputEventQueue[inputEventCount++] = queuedEvent;
}

static void queueAxisEvent(struct Gamepad_device * device, double timestamp, unsigned int axisID, float value, float lastValue) {
	struct Gamepad_axisEvent * axisEvent;
	
	axisEvent = malloc(sizeof(struct Gamepad_axisEvent));
	axisEvent->device = device;
	axisEvent->timestamp = timestamp;
	axisEvent->axisID = axisID;
	axisEvent->value = value;
	axisEvent->lastValue = lastValue;
	
	queueInputEvent(device->deviceID, GAMEPAD_EVENT_AXIS_MOVED, axisEvent);
}

static void queueButtonEvent(struct Gamepad_device * device, double timestamp, unsigned int buttonID, bool down) {
	struct Gamepad_buttonEvent * buttonEvent;
	
	buttonEvent = malloc(sizeof(struct Gamepad_buttonEvent));
	buttonEvent->device = device;
	buttonEvent->timestamp = timestamp;
	buttonEvent->buttonID = buttonID;
	buttonEvent->down = down;
	
	queueInputEvent(device->deviceID, down ? GAMEPAD_EVENT_BUTTON_DOWN : GAMEPAD_EVENT_BUTTON_UP, buttonEvent);
}

static void onDeviceValueChanged(void * context, IOReturn result, void * sender, IOHIDValueRef value) {
	struct Gamepad_device * deviceRecord;
	struct Gamepad_devicePrivate * hidDeviceRecord;
	IOHIDElementRef element;
	IOHIDElementCookie cookie;
	unsigned int axisIndex, buttonIndex;
	static mach_timebase_info_data_t timebaseInfo;
	
	if (timebaseInfo.denom == 0) {
		mach_timebase_info(&timebaseInfo);
	}
	
	deviceRecord = context;
	hidDeviceRecord = deviceRecord->privateData;
	element = IOHIDValueGetElement(value);
	cookie = IOHIDElementGetCookie(element);
	
	for (axisIndex = 0; axisIndex < deviceRecord->numAxes; axisIndex++) {
		if (!hidDeviceRecord->axisElements[axisIndex].isHatSwitchSecondAxis &&
		    hidDeviceRecord->axisElements[axisIndex].cookie == cookie) {
			CFIndex integerValue;
			
			if (IOHIDValueGetLength(value) > 4) {
				// Workaround for a strange crash that occurs with PS3 controller; was getting lengths of 39 (!)
				continue;
			}
			integerValue = IOHIDValueGetIntegerValue(value);
			
			if (hidDeviceRecord->axisElements[axisIndex].isHatSwitch) {
				int x, y;
				
				// Fix for Saitek X52
				if (!hidDeviceRecord->axisElements[axisIndex].hasNullState) {
					if (integerValue < hidDeviceRecord->axisElements[axisIndex].logicalMin) {
						integerValue = hidDeviceRecord->axisElements[axisIndex].logicalMax - hidDeviceRecord->axisElements[axisIndex].logicalMin + 1;
					} else {
						integerValue--;
					}
				}
				
				hatValueToXY(integerValue, hidDeviceRecord->axisElements[axisIndex].logicalMax - hidDeviceRecord->axisElements[axisIndex].logicalMin + 1, &x, &y);
				
				if (x != deviceRecord->axisStates[axisIndex]) {
					queueAxisEvent(deviceRecord,
					               IOHIDValueGetTimeStamp(value) * timebaseInfo.numer / timebaseInfo.denom * 0.000000001,
					               axisIndex,
					               x,
					               deviceRecord->axisStates[axisIndex]);
					
					deviceRecord->axisStates[axisIndex] = x;
				}
				
				if (y != deviceRecord->axisStates[axisIndex + 1]) {
					queueAxisEvent(deviceRecord,
					               IOHIDValueGetTimeStamp(value) * timebaseInfo.numer / timebaseInfo.denom * 0.000000001,
					               axisIndex + 1,
					               y,
					               deviceRecord->axisStates[axisIndex + 1]);
					
					deviceRecord->axisStates[axisIndex + 1] = y;
				}
				
			} else {
				float floatValue;
				
				if (integerValue < hidDeviceRecord->axisElements[axisIndex].logicalMin) {
					hidDeviceRecord->axisElements[axisIndex].logicalMin = integerValue;
				}
				if (integerValue > hidDeviceRecord->axisElements[axisIndex].logicalMax) {
					hidDeviceRecord->axisElements[axisIndex].logicalMax = integerValue;
				}
				floatValue = (integerValue - hidDeviceRecord->axisElements[axisIndex].logicalMin) / (float) (hidDeviceRecord->axisElements[axisIndex].logicalMax - hidDeviceRecord->axisElements[axisIndex].logicalMin) * 2.0f - 1.0f;
				
				queueAxisEvent(deviceRecord,
				               IOHIDValueGetTimeStamp(value) * timebaseInfo.numer / timebaseInfo.denom * 0.000000001,
				               axisIndex,
				               floatValue,
				               deviceRecord->axisStates[axisIndex]);
				
				deviceRecord->axisStates[axisIndex] = floatValue;
			}
			
			return;
		}
	}
	
	for (buttonIndex = 0; buttonIndex < deviceRecord->numButtons; buttonIndex++) {
		if (hidDeviceRecord->buttonElements[buttonIndex].cookie == cookie) {
			bool down;
			
			down = IOHIDValueGetIntegerValue(value);
			queueButtonEvent(deviceRecord,
			                 IOHIDValueGetTimeStamp(value) * timebaseInfo.numer / timebaseInfo.denom * 0.000000001,
			                 buttonIndex,
			                 down);
			
			deviceRecord->buttonStates[buttonIndex] = down;
			
			return;
		}
	}
}

static int IOHIDDeviceGetIntProperty(IOHIDDeviceRef deviceRef, CFStringRef key) {
	CFTypeRef typeRef;
	int value;
	
	typeRef = IOHIDDeviceGetProperty(deviceRef, key);
	if (typeRef == NULL || CFGetTypeID(typeRef) != CFNumberGetTypeID()) {
		return 0;
	}
	
	CFNumberGetValue((CFNumberRef) typeRef, kCFNumberSInt32Type, &value);
	return value;
}

static int IOHIDDeviceGetVendorID(IOHIDDeviceRef deviceRef) {
	return IOHIDDeviceGetIntProperty(deviceRef, CFSTR(kIOHIDVendorIDKey));
}

static int IOHIDDeviceGetProductID(IOHIDDeviceRef deviceRef) {
	return IOHIDDeviceGetIntProperty(deviceRef, CFSTR(kIOHIDProductIDKey));
}

static void onDeviceMatched(void * context, IOReturn result, void * sender, IOHIDDeviceRef device) {
	CFArrayRef elements;
	CFIndex elementIndex;
	IOHIDElementRef element;
	CFStringRef cfProductName;
	struct Gamepad_device * deviceRecord;
	struct Gamepad_devicePrivate * hidDeviceRecord;
	IOHIDElementType type;
	char * description;
	struct Gamepad_queuedEvent queuedEvent;
	
	deviceRecord = malloc(sizeof(struct Gamepad_device));
	deviceRecord->deviceID = nextDeviceID++;
	deviceRecord->vendorID = IOHIDDeviceGetVendorID(device);
	deviceRecord->productID = IOHIDDeviceGetProductID(device);
	deviceRecord->numAxes = 0;
	deviceRecord->numButtons = 0;
	devices = realloc(devices, sizeof(struct Gamepad_device *) * (numDevices + 1));
	devices[numDevices++] = deviceRecord;
	
	hidDeviceRecord = malloc(sizeof(struct Gamepad_devicePrivate));
	hidDeviceRecord->deviceRef = device;
	hidDeviceRecord->axisElements = NULL;
	hidDeviceRecord->buttonElements = NULL;
	deviceRecord->privateData = hidDeviceRecord;
	
	cfProductName = IOHIDDeviceGetProperty(device, CFSTR(kIOHIDProductKey));
	if (cfProductName == NULL || CFGetTypeID(cfProductName) != CFStringGetTypeID()) {
		description = malloc(strlen("[Unknown]") + 1);
		strcpy(description, "[Unknown]");
		
	} else {
		CFIndex length;
		
		CFStringGetBytes(cfProductName, CFRangeMake(0, CFStringGetLength(cfProductName)), kCFStringEncodingUTF8, '?', false, NULL, 100, &length);
		description = malloc(length + 1);
		CFStringGetBytes(cfProductName, CFRangeMake(0, CFStringGetLength(cfProductName)), kCFStringEncodingUTF8, '?', false, (UInt8 *) description, length + 1, NULL);
		description[length] = '\x00';
	}
	deviceRecord->description = description;
	
	elements = IOHIDDeviceCopyMatchingElements(device, NULL, kIOHIDOptionsTypeNone);
	for (elementIndex = 0; elementIndex < CFArrayGetCount(elements); elementIndex++) {
		element = (IOHIDElementRef) CFArrayGetValueAtIndex(elements, elementIndex);
		type = IOHIDElementGetType(element);
		
		// All of the axis elements I've ever detected have been kIOHIDElementTypeInput_Misc. kIOHIDElementTypeInput_Axis is only included for good faith...
		if (type == kIOHIDElementTypeInput_Misc ||
		    type == kIOHIDElementTypeInput_Axis) {
			
			hidDeviceRecord->axisElements = realloc(hidDeviceRecord->axisElements, sizeof(struct HIDGamepadAxis) * (deviceRecord->numAxes + 1));
			hidDeviceRecord->axisElements[deviceRecord->numAxes].cookie = IOHIDElementGetCookie(element);
			hidDeviceRecord->axisElements[deviceRecord->numAxes].logicalMin = IOHIDElementGetLogicalMin(element);
			hidDeviceRecord->axisElements[deviceRecord->numAxes].logicalMax = IOHIDElementGetLogicalMax(element);
			hidDeviceRecord->axisElements[deviceRecord->numAxes].hasNullState = !!IOHIDElementHasNullState(element);
			hidDeviceRecord->axisElements[deviceRecord->numAxes].isHatSwitch = IOHIDElementGetUsage(element) == kHIDUsage_GD_Hatswitch;
			hidDeviceRecord->axisElements[deviceRecord->numAxes].isHatSwitchSecondAxis = false;
			deviceRecord->numAxes++;
			
			if (hidDeviceRecord->axisElements[deviceRecord->numAxes - 1].isHatSwitch) {
				hidDeviceRecord->axisElements = realloc(hidDeviceRecord->axisElements, sizeof(struct HIDGamepadAxis) * (deviceRecord->numAxes + 1));
				hidDeviceRecord->axisElements[deviceRecord->numAxes].isHatSwitchSecondAxis = true;
				deviceRecord->numAxes++;
			}
			
		} else if (type == kIOHIDElementTypeInput_Button) {
			hidDeviceRecord->buttonElements = realloc(hidDeviceRecord->buttonElements, sizeof(struct HIDGamepadButton) * (deviceRecord->numButtons + 1));
			hidDeviceRecord->buttonElements[deviceRecord->numButtons].cookie = IOHIDElementGetCookie(element);
			deviceRecord->numButtons++;
		}
	}
	CFRelease(elements);
	
	deviceRecord->axisStates = calloc(sizeof(float), deviceRecord->numAxes);
	deviceRecord->buttonStates = calloc(sizeof(bool), deviceRecord->numButtons);
	
	IOHIDDeviceRegisterInputValueCallback(device, onDeviceValueChanged, deviceRecord);
	
	queuedEvent.deviceID = deviceRecord->deviceID;
	queuedEvent.eventType = GAMEPAD_EVENT_DEVICE_ATTACHED;
	queuedEvent.eventData = deviceRecord;
	
	if (deviceEventCount >= deviceEventQueueSize) {
		deviceEventQueueSize = deviceEventQueueSize == 0 ? 1 : deviceEventQueueSize * 2;
		deviceEventQueue = realloc(deviceEventQueue, sizeof(struct Gamepad_queuedEvent) * deviceEventQueueSize);
	}
	deviceEventQueue[deviceEventCount++] = queuedEvent;
}

static void disposeDevice(struct Gamepad_device * deviceRecord) {
	unsigned int inputEventIndex, deviceEventIndex;
	
	IOHIDDeviceRegisterInputValueCallback(((struct Gamepad_devicePrivate *) deviceRecord->privateData)->deviceRef, NULL, NULL);
	
	for (inputEventIndex = 0; inputEventIndex < inputEventCount; inputEventIndex++) {
		if (inputEventQueue[inputEventIndex].deviceID == deviceRecord->deviceID) {
			unsigned int inputEventIndex2;
			
			free(inputEventQueue[inputEventIndex].eventData);
			inputEventCount--;
			for (inputEventIndex2 = inputEventIndex; inputEventIndex2 < inputEventCount; inputEventIndex2++) {
				inputEventQueue[inputEventIndex2] = inputEventQueue[inputEventIndex2 + 1];
			}
			inputEventIndex--;
		}
	}
	
	for (deviceEventIndex = 0; deviceEventIndex < deviceEventCount; deviceEventIndex++) {
		if (deviceEventQueue[deviceEventIndex].deviceID == deviceRecord->deviceID) {
			unsigned int deviceEventIndex2;
			
			deviceEventCount--;
			for (deviceEventIndex2 = deviceEventIndex; deviceEventIndex2 < deviceEventCount; deviceEventIndex2++) {
				deviceEventQueue[deviceEventIndex2] = deviceEventQueue[deviceEventIndex2 + 1];
			}
			deviceEventIndex--;
		}
	}
	
	free(((struct Gamepad_devicePrivate *) deviceRecord->privateData)->axisElements);
	free(((struct Gamepad_devicePrivate *) deviceRecord->privateData)->buttonElements);
	free(deviceRecord->privateData);
	
	free((void *) deviceRecord->description);
	free(deviceRecord->axisStates);
	free(deviceRecord->buttonStates);
	
	free(deviceRecord);
}

static void onDeviceRemoved(void * context, IOReturn result, void * sender, IOHIDDeviceRef device) {
	unsigned int deviceIndex;
	
	for (deviceIndex = 0; deviceIndex < numDevices; deviceIndex++) {
		if (((struct Gamepad_devicePrivate *) devices[deviceIndex]->privateData)->deviceRef == device) {
			if (Gamepad_deviceRemoveCallback != NULL) {
				Gamepad_deviceRemoveCallback(devices[deviceIndex], Gamepad_deviceRemoveContext);
			}
			
			disposeDevice(devices[deviceIndex]);
			numDevices--;
			for (; deviceIndex < numDevices; deviceIndex++) {
				devices[deviceIndex] = devices[deviceIndex + 1];
			}
			return;
		}
	}
}

void Gamepad_init() {
	if (hidManager == NULL) {
		CFStringRef keys[2];
		int value;
		CFNumberRef values[2];
		CFDictionaryRef dictionaries[3];
		CFArrayRef array;
		
		hidManager = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);
		
		keys[0] = CFSTR(kIOHIDDeviceUsagePageKey);
		keys[1] = CFSTR(kIOHIDDeviceUsageKey);
		
		value = kHIDPage_GenericDesktop;
		values[0] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &value);
		value = kHIDUsage_GD_Joystick;
		values[1] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &value);
		dictionaries[0] = CFDictionaryCreate(kCFAllocatorDefault, (const void **) keys, (const void **) values, 2, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
		CFRelease(values[0]);
		CFRelease(values[1]);
		
		value = kHIDPage_GenericDesktop;
		values[0] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &value);
		value = kHIDUsage_GD_GamePad;
		values[1] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &value);
		dictionaries[1] = CFDictionaryCreate(kCFAllocatorDefault, (const void **) keys, (const void **) values, 2, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
		CFRelease(values[0]);
		CFRelease(values[1]);
		
		value = kHIDPage_GenericDesktop;
		values[0] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &value);
		value = kHIDUsage_GD_MultiAxisController;
		values[1] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &value);
		dictionaries[2] = CFDictionaryCreate(kCFAllocatorDefault, (const void **) keys, (const void **) values, 2, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
		CFRelease(values[0]);
		CFRelease(values[1]);
		
		array = CFArrayCreate(kCFAllocatorDefault, (const void **) dictionaries, 3, &kCFTypeArrayCallBacks);
		CFRelease(dictionaries[0]);
		CFRelease(dictionaries[1]);
		CFRelease(dictionaries[2]);
		IOHIDManagerSetDeviceMatchingMultiple(hidManager, array);
		CFRelease(array);
		
		IOHIDManagerRegisterDeviceMatchingCallback(hidManager, onDeviceMatched, NULL);
		IOHIDManagerRegisterDeviceRemovalCallback(hidManager, onDeviceRemoved, NULL);
		
		IOHIDManagerOpen(hidManager, kIOHIDOptionsTypeNone);
		
		// Force gamepads to be recognized immediately. The normal run loop mode takes a few frames,
		// but we can run one iteration with a custom mode to do it without a delay.
		IOHIDManagerScheduleWithRunLoop(hidManager, CFRunLoopGetCurrent(), GAMEPAD_RUN_LOOP_MODE);
		CFRunLoopRunInMode(GAMEPAD_RUN_LOOP_MODE, 0, true);
	}
}

void Gamepad_shutdown() {
	if (hidManager != NULL) {
		unsigned int deviceIndex;
		
		IOHIDManagerUnscheduleFromRunLoop(hidManager, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
		
		for (deviceIndex = 0; deviceIndex < numDevices; deviceIndex++) {
			disposeDevice(devices[deviceIndex]);
		}
		free(devices);
		devices = NULL;
		numDevices = 0;
		
		IOHIDManagerClose(hidManager, 0);
		CFRelease(hidManager);
		hidManager = NULL;
	}
}

unsigned int Gamepad_numDevices() {
	return numDevices;
}

struct Gamepad_device * Gamepad_deviceAtIndex(unsigned int deviceIndex) {
	if (deviceIndex >= numDevices) {
		return NULL;
	}
	return devices[deviceIndex];
}

static void processQueuedEvent(struct Gamepad_queuedEvent event) {
	switch (event.eventType) {
		case GAMEPAD_EVENT_DEVICE_ATTACHED:
			if (Gamepad_deviceAttachCallback != NULL) {
				Gamepad_deviceAttachCallback(event.eventData, Gamepad_deviceAttachContext);
			}
			break;
			
		case GAMEPAD_EVENT_DEVICE_REMOVED:
			if (Gamepad_deviceRemoveCallback != NULL) {
				Gamepad_deviceRemoveCallback(event.eventData, Gamepad_deviceRemoveContext);
			}
			break;
			
		case GAMEPAD_EVENT_BUTTON_DOWN:
			if (Gamepad_buttonDownCallback != NULL) {
				struct Gamepad_buttonEvent * buttonEvent = event.eventData;
				Gamepad_buttonDownCallback(buttonEvent->device, buttonEvent->buttonID, buttonEvent->timestamp, Gamepad_buttonDownContext);
			}
			break;
			
		case GAMEPAD_EVENT_BUTTON_UP:
			if (Gamepad_buttonUpCallback != NULL) {
				struct Gamepad_buttonEvent * buttonEvent = event.eventData;
				Gamepad_buttonUpCallback(buttonEvent->device, buttonEvent->buttonID, buttonEvent->timestamp, Gamepad_buttonUpContext);
			}
			break;
			
		case GAMEPAD_EVENT_AXIS_MOVED:
			if (Gamepad_axisMoveCallback != NULL) {
				struct Gamepad_axisEvent * axisEvent = event.eventData;
				Gamepad_axisMoveCallback(axisEvent->device, axisEvent->axisID, axisEvent->value, axisEvent->lastValue, axisEvent->timestamp, Gamepad_axisMoveContext);
			}
			break;
	}
}

void Gamepad_detectDevices() {
	unsigned int eventIndex;
	
	if (hidManager == NULL) {
		return;
	}
	
	CFRunLoopRunInMode(GAMEPAD_RUN_LOOP_MODE, 0, true);
	for (eventIndex = 0; eventIndex < deviceEventCount; eventIndex++) {
		processQueuedEvent(deviceEventQueue[eventIndex]);
	}
	deviceEventCount = 0;
}

void Gamepad_processEvents() {
	unsigned int eventIndex;
	static bool inProcessEvents;
	
	if (hidManager == NULL || inProcessEvents) {
		return;
	}
	
	inProcessEvents = true;
	CFRunLoopRunInMode(GAMEPAD_RUN_LOOP_MODE, 0, true);
	for (eventIndex = 0; eventIndex < inputEventCount; eventIndex++) {
		processQueuedEvent(inputEventQueue[eventIndex]);
		free(inputEventQueue[eventIndex].eventData);
	}
	inputEventCount = 0;
	inProcessEvents = false;
}
#elif defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
#ifndef SOKOL_INPUT_GAMEPAD_WINDOWS_USE_MM
#define _WIN32_WINNT 0x0501
#define INITGUID
#define DIRECTINPUT_VERSION 0x0800
#ifdef _MSC_VER
#define strdup _strdup
#undef UNICODE
#else
#define __in
#define __out
#define __reserved
#endif
  

#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <regstr.h>
#include <dinput.h>
#include <XInput.h>
#include <Dbt.h>

// The following code is from SDL2
// detects gamepad device remove/attach events without having to poll multiple times per second
static bool s_bWindowsDeviceChanged = false;

static LRESULT CALLBACK PrivateJoystickDetectProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DEVICECHANGE:
		switch (wParam) {
		case DBT_DEVICEARRIVAL:
			if (((DEV_BROADCAST_HDR*)lParam)->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE) {
				s_bWindowsDeviceChanged = true;
			}
			break;
		case DBT_DEVICEREMOVECOMPLETE:
			if (((DEV_BROADCAST_HDR*)lParam)->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE) {
				s_bWindowsDeviceChanged = true;
			}
			break;
		}
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

typedef struct {
	HRESULT coinitialized;
	WNDCLASSEX wincl;
	HWND messageWindow;
	HDEVNOTIFY hNotify;
} DeviceNotificationData;

static void CleanupDeviceNotification(DeviceNotificationData *data)
{
	if (data->hNotify)
		UnregisterDeviceNotification(data->hNotify);

	if (data->messageWindow)
		DestroyWindow(data->messageWindow);

	UnregisterClass(data->wincl.lpszClassName, data->wincl.hInstance);

	if (data->coinitialized == S_OK) {
		CoUninitialize();
	}
}

static int CreateDeviceNotification(DeviceNotificationData *data)
{
	DEV_BROADCAST_DEVICEINTERFACE dbh;
	GUID GUID_DEVINTERFACE_HID = { 0x4D1E55B2L, 0xF16F, 0x11CF, { 0x88, 0xCB, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30 } };

	memset(data, 0, sizeof(*data));

	data->coinitialized = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (data->coinitialized == RPC_E_CHANGED_MODE) {
		data->coinitialized = CoInitializeEx(NULL, COINIT_MULTITHREADED);
  }

	data->wincl.hInstance = GetModuleHandle(NULL);
	data->wincl.lpszClassName = "Message";
	data->wincl.lpfnWndProc = PrivateJoystickDetectProc;      /* This function is called by windows */
	data->wincl.cbSize = sizeof (WNDCLASSEX);

	if (!RegisterClassEx(&data->wincl)) {
		fprintf(stderr, "Failed to create register class for joystick autodetect");
		CleanupDeviceNotification(data);
		return -1;
	}

	data->messageWindow = (HWND)CreateWindowEx(0, "Message", NULL, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);
	if (!data->messageWindow) {
		fprintf(stderr, "Failed to create message window for joystick autodetect");
		CleanupDeviceNotification(data);
		return -1;
	}

	memset(&dbh, 0, sizeof(dbh));
	dbh.dbcc_size = sizeof(dbh);
	dbh.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
	dbh.dbcc_classguid = GUID_DEVINTERFACE_HID;

	data->hNotify = RegisterDeviceNotification(data->messageWindow, &dbh, DEVICE_NOTIFY_WINDOW_HANDLE);
	if (!data->hNotify) {
		fprintf(stderr, "Failed to create notify device for joystick autodetect");
		CleanupDeviceNotification(data);
		return -1;
	}
	return 0;
}


static void CheckDeviceNotification(DeviceNotificationData *data)
{
	MSG msg;

	if (!data->messageWindow) {
		return;
	}

	while (PeekMessage(&msg, data->messageWindow, 0, 0, PM_NOREMOVE)) {
		if (GetMessage(&msg, data->messageWindow, 0, 0) != 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

// Copy from MinGW-w64 to MinGW, along with wbemcli.h, wbemprov.h, wbemdisp.h, and wbemtran.h
#ifndef __MINGW_EXTENSION
#define __MINGW_EXTENSION
#endif
#define COBJMACROS 1
#include <wbemidl.h>
#include <oleauto.h>
// Super helpful info: http://www.wreckedgames.com/forum/index.php?topic=2584.0

#define INPUT_QUEUE_SIZE 32
#define XINPUT_GAMEPAD_GUIDE 0x400

typedef struct {
	WORD wButtons;
	BYTE bLeftTrigger;
	BYTE bRightTrigger;
	SHORT sThumbLX;
	SHORT sThumbLY;
	SHORT sThumbRX;
	SHORT sThumbRY;
	DWORD dwPaddingReserved;
} XINPUT_GAMEPAD_EX;

typedef struct {
	DWORD dwPacketNumber;
	XINPUT_GAMEPAD_EX Gamepad;
} XINPUT_STATE_EX;

struct diAxisInfo {
	DWORD offset;
	bool isPOV;
	bool isPOVSecondAxis;
};

struct Gamepad_devicePrivate {
	bool isXInput;
	
	// DInput only
	GUID guidInstance;
	IDirectInputDevice8 * deviceInterface;
	bool buffered;
	unsigned int sliderCount;
	unsigned int povCount;
	struct diAxisInfo * axisInfo;
	DWORD * buttonOffsets;
	
	// XInput only
	unsigned int playerIndex;
};

static DeviceNotificationData notificationData;
static struct Gamepad_device ** devices = NULL;
static unsigned int numDevices = 0;
static unsigned int nextDeviceID = 0;
static struct Gamepad_device * registeredXInputDevices[4];
static const char * xInputDeviceNames[4] = {
	"XInput Controller 1",
	"XInput Controller 2",
	"XInput Controller 3",
	"XInput Controller 4"
};
static DWORD (WINAPI * XInputGetStateEx_proc)(DWORD dwUserIndex, XINPUT_STATE_EX * pState);
static DWORD (WINAPI * XInputGetState_proc)(DWORD dwUserIndex, XINPUT_STATE * pState);
static DWORD (WINAPI * XInputGetCapabilities_proc)(DWORD dwUserIndex, DWORD dwFlags, XINPUT_CAPABILITIES * pCapabilities);

static LPDIRECTINPUT directInputInterface;
static bool inited = false;
static bool xInputAvailable;

void Gamepad_init() {
	if (!inited) {
		HRESULT result;
		HMODULE module;
		HRESULT (WINAPI * DirectInput8Create_proc)(HINSTANCE, DWORD, REFIID, LPVOID *, LPUNKNOWN);
		
		module = LoadLibrary("XInput1_4.dll");
		if (module == NULL) {
			module = LoadLibrary("XInput1_3.dll");
		}
		if (module == NULL) {
			module = LoadLibrary("bin\\XInput1_3.dll");
		}
		if (module == NULL) {
			fprintf(stderr, "Gamepad_init couldn't load XInput1_4.dll or XInput1_3.dll; proceeding with DInput only\n");
			xInputAvailable = false;
		} else {
			xInputAvailable = true;
			XInputGetStateEx_proc = (DWORD (WINAPI *)(DWORD, XINPUT_STATE_EX *)) GetProcAddress(module, (LPCSTR) 100);
			XInputGetState_proc = (DWORD (WINAPI *)(DWORD, XINPUT_STATE *)) GetProcAddress(module, "XInputGetState");
			XInputGetCapabilities_proc = (DWORD (WINAPI *)(DWORD, DWORD, XINPUT_CAPABILITIES *)) GetProcAddress(module, "XInputGetCapabilities");
		}
		
		//result = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, &IID_IDirectInput8, (void **) &directInputInterface, NULL);
		// Calling DirectInput8Create directly crashes in 64-bit builds for some reason. Loading it with GetProcAddress works though!
		
		module = LoadLibrary("DINPUT8.dll");
		if (module == NULL) {
			fprintf(stderr, "Gamepad_init fatal error: Couldn't load DINPUT8.dll\n");
			abort();
		}
		DirectInput8Create_proc = (HRESULT (WINAPI *)(HINSTANCE, DWORD, REFIID, LPVOID *, LPUNKNOWN)) GetProcAddress(module, "DirectInput8Create");
		result = DirectInput8Create_proc(GetModuleHandle(NULL), DIRECTINPUT_VERSION, &IID_IDirectInput8, (void **) &directInputInterface, NULL);
		
		if (result != DI_OK) {
			fprintf(stderr, "Warning: DirectInput8Create returned 0x%X\n", (unsigned int) result);
		}
		
		inited = true;
		s_bWindowsDeviceChanged = true;
		Gamepad_detectDevices();
		CreateDeviceNotification(&notificationData);
	}
}

static void disposeDevice(struct Gamepad_device * deviceRecord) {
	struct Gamepad_devicePrivate * deviceRecordPrivate = deviceRecord->privateData;
	
	if (!deviceRecordPrivate->isXInput) {
		IDirectInputDevice8_Release(deviceRecordPrivate->deviceInterface);
		free(deviceRecordPrivate->axisInfo);
		free(deviceRecordPrivate->buttonOffsets);
		free((void *) deviceRecord->description);
	}
	free(deviceRecordPrivate);
	
	free(deviceRecord->axisStates);
	free(deviceRecord->buttonStates);
	
	free(deviceRecord);
}

void Gamepad_shutdown() {
	unsigned int deviceIndex;
	
	if (inited) {
		for (deviceIndex = 0; deviceIndex < numDevices; deviceIndex++) {
			disposeDevice(devices[deviceIndex]);
		}
		free(devices);
		devices = NULL;
		numDevices = 0;
		inited = false;
		CleanupDeviceNotification(&notificationData);
	}
}

unsigned int Gamepad_numDevices() {
	return numDevices;
}

struct Gamepad_device * Gamepad_deviceAtIndex(unsigned int deviceIndex) {
	if (deviceIndex >= numDevices) {
		return NULL;
	}
	return devices[deviceIndex];
}

static double currentTime() {
	static LARGE_INTEGER frequency;
	LARGE_INTEGER currentTime;
	
	if (frequency.QuadPart == 0) {
		QueryPerformanceFrequency(&frequency);
	}
	QueryPerformanceCounter(&currentTime);
	
	return (double) currentTime.QuadPart / frequency.QuadPart;
}

#if 0
// This code from http://msdn.microsoft.com/en-us/library/windows/desktop/ee417014(v=vs.85).aspx is really really really slow
static bool isXInputDevice(const GUID * pGuidProductFromDirectInput) {
	IWbemLocator * pIWbemLocator = NULL;
	IEnumWbemClassObject * pEnumDevices = NULL;
	IWbemClassObject * pDevices[20] = {0};
	IWbemServices * pIWbemServices = NULL;
	BSTR bstrNamespace = NULL;
	BSTR bstrDeviceID = NULL;
	BSTR bstrClassName = NULL;
	DWORD uReturned = 0;
	bool bIsXinputDevice = false;
	UINT iDevice = 0;
	VARIANT var;
	HRESULT hr;
	
	hr = CoInitialize(NULL);
	bool bCleanupCOM = SUCCEEDED(hr);
	
	hr = CoCreateInstance(&CLSID_WbemLocator,
	                      NULL,
	                      CLSCTX_INPROC_SERVER,
	                      &IID_IWbemLocator,
	                      (LPVOID *) &pIWbemLocator);
	if (FAILED(hr) || pIWbemLocator == NULL) {
		goto LCleanup;
	}
	
	bstrNamespace = SysAllocString(L"\\\\.\\root\\cimv2"); if (bstrNamespace == NULL) {goto LCleanup;}
	bstrClassName = SysAllocString(L"Win32_PNPEntity");    if (bstrClassName == NULL) {goto LCleanup;}
	bstrDeviceID  = SysAllocString(L"DeviceID");           if (bstrDeviceID == NULL)  {goto LCleanup;}
	
	hr = IWbemLocator_ConnectServer(pIWbemLocator, bstrNamespace, NULL, NULL, 0L,
	                                0L, NULL, NULL, &pIWbemServices);
	if (FAILED(hr) || pIWbemServices == NULL) {
		goto LCleanup;
	}
	
	CoSetProxyBlanket((IUnknown *) pIWbemServices, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL,
	                  RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE);
	
	hr = IWbemServices_CreateInstanceEnum(pIWbemServices, bstrClassName, 0, NULL, &pEnumDevices);
	if (FAILED(hr) || pEnumDevices == NULL) {
		goto LCleanup;
	}
	
	for (;;) {
		hr = IEnumWbemClassObject_Next(pEnumDevices, 10000, 20, pDevices, &uReturned);
		if (FAILED(hr)) {
			goto LCleanup;
		}
		if (uReturned == 0) {
			break;
		}
		for (iDevice = 0; iDevice < uReturned; iDevice++) {
			hr = IWbemClassObject_Get(pDevices[iDevice], bstrDeviceID, 0L, &var, NULL, NULL);
			if (SUCCEEDED(hr) && var.vt == VT_BSTR && var.bstrVal != NULL) {
				if (wcsstr(var.bstrVal, L"IG_")) {
					DWORD dwPid = 0, dwVid = 0;
					WCHAR * strVid = wcsstr(var.bstrVal, L"VID_");
					if (strVid && swscanf(strVid, L"VID_%4X", &dwVid) != 1) {
						dwVid = 0;
					}
					WCHAR * strPid = wcsstr(var.bstrVal, L"PID_");
					if (strPid != NULL && swscanf(strPid, L"PID_%4X", &dwPid) != 1) {
						dwPid = 0;
					}
					DWORD dwVidPid = MAKELONG(dwVid, dwPid);
					if (dwVidPid == pGuidProductFromDirectInput->Data1) {
						bIsXinputDevice = true;
						goto LCleanup;
					}
				}
			}
			if (pDevices[iDevice] != NULL) {
				IWbemClassObject_Release(pDevices[iDevice]);
				pDevices[iDevice] = NULL;
			}
		}
	}
	
LCleanup:
	if (bstrNamespace != NULL) {
		SysFreeString(bstrNamespace);
	}
	if (bstrDeviceID != NULL) {
		SysFreeString(bstrDeviceID);
	}
	if (bstrClassName != NULL) {
		SysFreeString(bstrClassName);
	}
	for (iDevice = 0; iDevice < uReturned; iDevice++) {
		if (pDevices[iDevice] != NULL) {
			IWbemClassObject_Release(pDevices[iDevice]);
		}
	}
	if (pEnumDevices != NULL) {
		IEnumWbemClassObject_Release(pEnumDevices);
	}
	if (pIWbemLocator != NULL) {
		IWbemLocator_Release(pIWbemLocator);
	}
	if (pIWbemServices != NULL) {
		IWbemServices_Release(pIWbemServices);
	}
	
	if (bCleanupCOM) {
		CoUninitialize();
	}
	
	return bIsXinputDevice;
}
#else
// This code from SDL2 is much faster

DEFINE_GUID(IID_ValveStreamingGamepad, MAKELONG(0x28DE, 0x11FF),0x0000,0x0000,0x00,0x00,0x50,0x49,0x44,0x56,0x49,0x44);
DEFINE_GUID(IID_X360WiredGamepad, MAKELONG(0x045E, 0x02A1),0x0000,0x0000,0x00,0x00,0x50,0x49,0x44,0x56,0x49,0x44);
DEFINE_GUID(IID_X360WirelessGamepad, MAKELONG(0x045E, 0x028E),0x0000,0x0000,0x00,0x00,0x50,0x49,0x44,0x56,0x49,0x44);

static PRAWINPUTDEVICELIST rawDevList = NULL;
static UINT rawDevListCount = 0;

static bool isXInputDevice(const GUID * pGuidProductFromDirectInput) {
	static const GUID * s_XInputProductGUID[] = {
		&IID_ValveStreamingGamepad,
		&IID_X360WiredGamepad,   // Microsoft's wired X360 controller for Windows
		&IID_X360WirelessGamepad // Microsoft's wireless X360 controller for Windows
	};
	
	size_t iDevice;
	UINT i;
	
	// Check for well known XInput device GUIDs
	// This lets us skip RAWINPUT for popular devices. Also, we need to do this for the Valve Streaming Gamepad because it's virtualized and doesn't show up in the device list.
	for (iDevice = 0; iDevice < sizeof(s_XInputProductGUID) / sizeof(s_XInputProductGUID[0]); ++iDevice) {
		if (!memcmp(pGuidProductFromDirectInput, s_XInputProductGUID[iDevice], sizeof(GUID))) {
			return true;
		}
	}
	
	// Go through RAWINPUT (WinXP and later) to find HID devices.
	// Cache this if we end up using it.
	if (rawDevList == NULL) {
		if ((GetRawInputDeviceList(NULL, &rawDevListCount, sizeof(RAWINPUTDEVICELIST)) == (UINT) -1) || rawDevListCount == 0) {
			return false;
		}
		
		rawDevList = malloc(sizeof(RAWINPUTDEVICELIST) * rawDevListCount);
		
		if (GetRawInputDeviceList(rawDevList, &rawDevListCount, sizeof(RAWINPUTDEVICELIST)) == (UINT) -1) {
			free(rawDevList);
			rawDevList = NULL;
			return false;
		}
	}
	
	for (i = 0; i < rawDevListCount; i++) {
		RID_DEVICE_INFO rdi;
		char devName[128];
		UINT rdiSize = sizeof(rdi);
		UINT nameSize = sizeof(devName);
		
		rdi.cbSize = sizeof(rdi);
		if (rawDevList[i].dwType == RIM_TYPEHID &&
		    GetRawInputDeviceInfoA(rawDevList[i].hDevice, RIDI_DEVICEINFO, &rdi, &rdiSize) != (UINT) -1 &&
		    MAKELONG(rdi.hid.dwVendorId, rdi.hid.dwProductId) == (LONG) pGuidProductFromDirectInput->Data1 &&
		    GetRawInputDeviceInfoA(rawDevList[i].hDevice, RIDI_DEVICENAME, devName, &nameSize) != (UINT) -1 &&
		    strstr(devName, "IG_") != NULL) {
			return true;
		}
	}
	
	return false;
}
#endif

static BOOL CALLBACK countAxesCallback(LPCDIDEVICEOBJECTINSTANCE instance, LPVOID context) {
	struct Gamepad_device * deviceRecord = context;
	
	deviceRecord->numAxes++;
	if (instance->dwType & DIDFT_POV) {
		deviceRecord->numAxes++;
	}
	return DIENUM_CONTINUE;
}

static BOOL CALLBACK countButtonsCallback(LPCDIDEVICEOBJECTINSTANCE instance, LPVOID context) {
	struct Gamepad_device * deviceRecord = context;
	
	deviceRecord->numButtons++;
	return DIENUM_CONTINUE;
}

#define AXIS_MIN -32768
#define AXIS_MAX 32767

static BOOL CALLBACK enumAxesCallback(LPCDIDEVICEOBJECTINSTANCE instance, LPVOID context) {
	struct Gamepad_device * deviceRecord = context;
	struct Gamepad_devicePrivate * deviceRecordPrivate = deviceRecord->privateData;
	DWORD offset;
	
	deviceRecord->numAxes++;
	if (instance->dwType & DIDFT_POV) {
		offset = DIJOFS_POV(deviceRecordPrivate->povCount);
		deviceRecordPrivate->axisInfo[deviceRecord->numAxes - 1].offset = offset;
		deviceRecordPrivate->axisInfo[deviceRecord->numAxes - 1].isPOV = true;
		deviceRecord->numAxes++;
		deviceRecordPrivate->axisInfo[deviceRecord->numAxes - 1].offset = offset;
		deviceRecordPrivate->axisInfo[deviceRecord->numAxes - 1].isPOV = true;
		deviceRecordPrivate->povCount++;
		
	} else {
		DIPROPRANGE range;
		DIPROPDWORD deadZone;
		HRESULT result;
		
		if (!memcmp(&instance->guidType, &GUID_XAxis, sizeof(instance->guidType))) {
			offset = DIJOFS_X;
		} else if (!memcmp(&instance->guidType, &GUID_YAxis, sizeof(instance->guidType))) {
			offset = DIJOFS_Y;
		} else if (!memcmp(&instance->guidType, &GUID_ZAxis, sizeof(instance->guidType))) {
			offset = DIJOFS_Z;
		} else if (!memcmp(&instance->guidType, &GUID_RxAxis, sizeof(instance->guidType))) {
			offset = DIJOFS_RX;
		} else if (!memcmp(&instance->guidType, &GUID_RyAxis, sizeof(instance->guidType))) {
			offset = DIJOFS_RY;
		} else if (!memcmp(&instance->guidType, &GUID_RzAxis, sizeof(instance->guidType))) {
			offset = DIJOFS_RZ;
		} else if (!memcmp(&instance->guidType, &GUID_Slider, sizeof(instance->guidType))) {
			offset = DIJOFS_SLIDER(deviceRecordPrivate->sliderCount++);
		} else {
			offset = -1;
		}
		deviceRecordPrivate->axisInfo[deviceRecord->numAxes - 1].offset = offset;
		deviceRecordPrivate->axisInfo[deviceRecord->numAxes - 1].isPOV = false;
		
		range.diph.dwSize = sizeof(range);
		range.diph.dwHeaderSize = sizeof(range.diph);
		range.diph.dwObj = instance->dwType;
		range.diph.dwHow = DIPH_BYID;
		range.lMin = AXIS_MIN;
		range.lMax = AXIS_MAX;
		
		result = IDirectInputDevice8_SetProperty(deviceRecordPrivate->deviceInterface, DIPROP_RANGE, &range.diph);
		if (result != DI_OK) {
			fprintf(stderr, "Warning: IDIrectInputDevice8_SetProperty returned 0x%X\n", (unsigned int) result);
		}
		
		deadZone.diph.dwSize = sizeof(deadZone);
		deadZone.diph.dwHeaderSize = sizeof(deadZone.diph);
		deadZone.diph.dwObj = instance->dwType;
		deadZone.diph.dwHow = DIPH_BYID;
		deadZone.dwData = 0;
		result = IDirectInputDevice8_SetProperty(deviceRecordPrivate->deviceInterface, DIPROP_DEADZONE, &deadZone.diph);
		if (result != DI_OK) {
			fprintf(stderr, "Warning: IDIrectInputDevice8_SetProperty returned 0x%X\n", (unsigned int) result);
		}
	}
	return DIENUM_CONTINUE;
}

static BOOL CALLBACK enumButtonsCallback(LPCDIDEVICEOBJECTINSTANCE instance, LPVOID context) {
	struct Gamepad_device * deviceRecord = context;
	struct Gamepad_devicePrivate * deviceRecordPrivate = deviceRecord->privateData;
	
	deviceRecordPrivate->buttonOffsets[deviceRecord->numButtons] = DIJOFS_BUTTON(deviceRecord->numButtons);
	deviceRecord->numButtons++;
	return DIENUM_CONTINUE;
}

#ifdef _MSC_VER
#ifndef DIDFT_OPTIONAL
#define DIDFT_OPTIONAL      0x80000000
#endif

/* Taken from Wine - Thanks! */
DIOBJECTDATAFORMAT dfDIJoystick2[] = {
	{ &GUID_XAxis, DIJOFS_X, DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_YAxis, DIJOFS_Y, DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_ZAxis, DIJOFS_Z, DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RxAxis, DIJOFS_RX, DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RyAxis, DIJOFS_RY, DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RzAxis, DIJOFS_RZ, DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_Slider, DIJOFS_SLIDER(0), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_Slider, DIJOFS_SLIDER(1), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_POV, DIJOFS_POV(0), DIDFT_OPTIONAL | DIDFT_POV | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_POV, DIJOFS_POV(1), DIDFT_OPTIONAL | DIDFT_POV | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_POV, DIJOFS_POV(2), DIDFT_OPTIONAL | DIDFT_POV | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_POV, DIJOFS_POV(3), DIDFT_OPTIONAL | DIDFT_POV | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(0), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(1), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(2), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(3), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(4), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(5), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(6), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(7), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(8), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(9), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(10), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(11), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(12), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(13), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(14), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(15), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(16), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(17), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(18), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(19), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(20), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(21), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(22), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(23), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(24), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(25), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(26), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(27), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(28), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(29), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(30), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(31), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(32), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(33), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(34), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(35), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(36), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(37), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(38), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(39), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(40), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(41), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(42), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(43), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(44), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(45), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(46), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(47), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(48), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(49), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(50), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(51), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(52), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(53), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(54), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(55), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(56), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(57), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(58), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(59), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(60), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(61), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(62), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(63), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(64), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(65), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(66), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(67), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(68), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(69), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(70), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(71), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(72), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(73), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(74), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(75), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(76), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(77), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(78), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(79), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(80), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(81), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(82), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(83), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(84), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(85), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(86), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(87), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(88), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(89), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(90), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(91), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(92), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(93), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(94), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(95), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(96), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(97), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(98), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(99), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(100), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(101), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(102), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(103), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(104), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(105), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(106), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(107), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(108), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(109), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(110), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(111), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(112), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(113), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(114), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(115), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(116), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(117), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(118), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(119), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(120), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(121), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(122), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(123), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(124), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(125), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(126), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ NULL, DIJOFS_BUTTON(127), DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_XAxis, FIELD_OFFSET(DIJOYSTATE2, lVX), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_YAxis, FIELD_OFFSET(DIJOYSTATE2, lVY), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_ZAxis, FIELD_OFFSET(DIJOYSTATE2, lVZ), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RxAxis, FIELD_OFFSET(DIJOYSTATE2, lVRx), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RyAxis, FIELD_OFFSET(DIJOYSTATE2, lVRy), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RzAxis, FIELD_OFFSET(DIJOYSTATE2, lVRz), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_Slider, FIELD_OFFSET(DIJOYSTATE2, rglVSlider[0]), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_Slider, FIELD_OFFSET(DIJOYSTATE2, rglVSlider[1]), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_XAxis, FIELD_OFFSET(DIJOYSTATE2, lAX), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_YAxis, FIELD_OFFSET(DIJOYSTATE2, lAY), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_ZAxis, FIELD_OFFSET(DIJOYSTATE2, lAZ), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RxAxis, FIELD_OFFSET(DIJOYSTATE2, lARx), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RyAxis, FIELD_OFFSET(DIJOYSTATE2, lARy), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RzAxis, FIELD_OFFSET(DIJOYSTATE2, lARz), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_Slider, FIELD_OFFSET(DIJOYSTATE2, rglASlider[0]), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_Slider, FIELD_OFFSET(DIJOYSTATE2, rglASlider[1]), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_XAxis, FIELD_OFFSET(DIJOYSTATE2, lFX), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_YAxis, FIELD_OFFSET(DIJOYSTATE2, lFY), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_ZAxis, FIELD_OFFSET(DIJOYSTATE2, lFZ), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RxAxis, FIELD_OFFSET(DIJOYSTATE2, lFRx), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RyAxis, FIELD_OFFSET(DIJOYSTATE2, lFRy), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_RzAxis, FIELD_OFFSET(DIJOYSTATE2, lFRz), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_Slider, FIELD_OFFSET(DIJOYSTATE2, rglFSlider[0]), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
	{ &GUID_Slider, FIELD_OFFSET(DIJOYSTATE2, rglFSlider[1]), DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE, 0 },
};

const DIDATAFORMAT c_dfDIJoystick2 = {
	sizeof(DIDATAFORMAT),
	sizeof(DIOBJECTDATAFORMAT),
	DIDF_ABSAXIS,
	sizeof(DIJOYSTATE2),
	sizeof(dfDIJoystick2) / sizeof(dfDIJoystick2[0]),
	dfDIJoystick2
};
#endif

static BOOL CALLBACK enumDevicesCallback(const DIDEVICEINSTANCE * instance, LPVOID context) {
	struct Gamepad_device * deviceRecord;
	struct Gamepad_devicePrivate * deviceRecordPrivate;
	unsigned int deviceIndex;
	IDirectInputDevice * diDevice;
	IDirectInputDevice8 * di8Device;
	HRESULT result;
	DIPROPDWORD bufferSizeProp;
	bool buffered = true;
	
	if (xInputAvailable && isXInputDevice(&instance->guidProduct)) {
		return DIENUM_CONTINUE;
	}
	
	for (deviceIndex = 0; deviceIndex < numDevices; deviceIndex++) {
		if (!memcmp(&((struct Gamepad_devicePrivate *) devices[deviceIndex]->privateData)->guidInstance, &instance->guidInstance, sizeof(GUID))) {
			return DIENUM_CONTINUE;
		}
	}
	
	result = IDirectInput8_CreateDevice(directInputInterface, &instance->guidInstance, &diDevice, NULL);
	if (result != DI_OK) {
		fprintf(stderr, "Warning: IDirectInput8_CreateDevice returned 0x%X\n", (unsigned int) result);
	}
	result = IDirectInputDevice8_QueryInterface(diDevice, &IID_IDirectInputDevice8, (LPVOID *) &di8Device);
	if (result != DI_OK) {
		fprintf(stderr, "Warning: IDirectInputDevice8_QueryInterface returned 0x%X\n", (unsigned int) result);
	}
	IDirectInputDevice8_Release(diDevice);
	
	result = IDirectInputDevice8_SetCooperativeLevel(di8Device, GetActiveWindow(), DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
	if (result != DI_OK) {
		fprintf(stderr, "Warning: IDirectInputDevice8_SetCooperativeLevel returned 0x%X\n", (unsigned int) result);
	}
	
	result = IDirectInputDevice8_SetDataFormat(di8Device, &c_dfDIJoystick2);
	if (result != DI_OK) {
		fprintf(stderr, "Warning: IDirectInputDevice8_SetDataFormat returned 0x%X\n", (unsigned int) result);
	}
	
	bufferSizeProp.diph.dwSize = sizeof(DIPROPDWORD);
	bufferSizeProp.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	bufferSizeProp.diph.dwObj = 0;
	bufferSizeProp.diph.dwHow = DIPH_DEVICE;
	bufferSizeProp.dwData = INPUT_QUEUE_SIZE;
	result = IDirectInputDevice8_SetProperty(di8Device, DIPROP_BUFFERSIZE, &bufferSizeProp.diph);
	if (result == DI_POLLEDDEVICE) {
		buffered = false;
	} else if (result != DI_OK) {
		fprintf(stderr, "Warning: IDirectInputDevice8_SetProperty returned 0x%X\n", (unsigned int) result);
	}
	
	deviceRecord = malloc(sizeof(struct Gamepad_device));
	deviceRecordPrivate = malloc(sizeof(struct Gamepad_devicePrivate));
	deviceRecordPrivate->guidInstance = instance->guidInstance;
	deviceRecordPrivate->isXInput = false;
	deviceRecordPrivate->deviceInterface = di8Device;
	deviceRecordPrivate->buffered = buffered;
	deviceRecordPrivate->sliderCount = 0;
	deviceRecordPrivate->povCount = 0;
	deviceRecord->privateData = deviceRecordPrivate;
	deviceRecord->deviceID = nextDeviceID++;
	deviceRecord->description = strdup(instance->tszProductName);
	deviceRecord->vendorID = instance->guidProduct.Data1 & 0xFFFF;
	deviceRecord->productID = instance->guidProduct.Data1 >> 16 & 0xFFFF;
	deviceRecord->numAxes = 0;
	IDirectInputDevice_EnumObjects(di8Device, countAxesCallback, deviceRecord, DIDFT_AXIS | DIDFT_POV);
	deviceRecord->numButtons = 0;
	IDirectInputDevice_EnumObjects(di8Device, countButtonsCallback, deviceRecord, DIDFT_BUTTON);
	deviceRecord->axisStates = calloc(sizeof(float), deviceRecord->numAxes);
	deviceRecord->buttonStates = calloc(sizeof(bool), deviceRecord->numButtons);
	deviceRecordPrivate->axisInfo = calloc(sizeof(struct diAxisInfo), deviceRecord->numAxes);
	deviceRecordPrivate->buttonOffsets = calloc(sizeof(DWORD), deviceRecord->numButtons);
	deviceRecord->numAxes = 0;
	IDirectInputDevice_EnumObjects(di8Device, enumAxesCallback, deviceRecord, DIDFT_AXIS | DIDFT_POV);
	deviceRecord->numButtons = 0;
	IDirectInputDevice_EnumObjects(di8Device, enumButtonsCallback, deviceRecord, DIDFT_BUTTON);
	devices = realloc(devices, sizeof(struct Gamepad_device *) * (numDevices + 1));
	devices[numDevices++] = deviceRecord;
	
	if (Gamepad_deviceAttachCallback != NULL) {
		Gamepad_deviceAttachCallback(deviceRecord, Gamepad_deviceAttachContext);
	}
	
	return DIENUM_CONTINUE;
}

static void removeDevice(unsigned int deviceIndex) {
	if (Gamepad_deviceRemoveCallback != NULL) {
		Gamepad_deviceRemoveCallback(devices[deviceIndex], Gamepad_deviceRemoveContext);
	}
	
	disposeDevice(devices[deviceIndex]);
	numDevices--;
	for (; deviceIndex < numDevices; deviceIndex++) {
		devices[deviceIndex] = devices[deviceIndex + 1];
	}
}

void Gamepad_detectDevices() {
	HRESULT result;
	DWORD xResult;
	XINPUT_CAPABILITIES capabilities;
	unsigned int playerIndex, deviceIndex;
	
	if (!inited) {
		return;
	}
	
	CheckDeviceNotification(&notificationData);
	if (s_bWindowsDeviceChanged) {
		result = IDirectInput_EnumDevices(directInputInterface, DI8DEVCLASS_GAMECTRL, enumDevicesCallback, NULL, DIEDFL_ALLDEVICES);
		if (result != DI_OK) {
			fprintf(stderr, "Warning: IDirectInput_EnumDevices returned 0x%X\n", (unsigned int) result);
		}
		s_bWindowsDeviceChanged = false;
	}
	
	if (xInputAvailable) {
		for (playerIndex = 0; playerIndex < 4; playerIndex++) {
			xResult = XInputGetCapabilities_proc(playerIndex, 0, &capabilities);
			if (xResult == ERROR_SUCCESS && registeredXInputDevices[playerIndex] == NULL) {
				struct Gamepad_device * deviceRecord;
				struct Gamepad_devicePrivate * deviceRecordPrivate;
				
				deviceRecord = malloc(sizeof(struct Gamepad_device));
				deviceRecordPrivate = malloc(sizeof(struct Gamepad_devicePrivate));
				deviceRecordPrivate->isXInput = true;
				deviceRecordPrivate->playerIndex = playerIndex;
				deviceRecord->privateData = deviceRecordPrivate;
				deviceRecord->deviceID = nextDeviceID++;
				deviceRecord->description = xInputDeviceNames[playerIndex];
				// HACK: XInput doesn't provide any way to get vendor and product ID, nor any way to map player index to
				// DirectInput device enumeration. All we can do is assume all XInput devices are XBox 360 controllers.
				deviceRecord->vendorID = 0x45E;
				deviceRecord->productID = 0x28E;
				deviceRecord->numAxes = 6;
				deviceRecord->numButtons = 15;
				deviceRecord->axisStates = calloc(sizeof(float), deviceRecord->numAxes);
				deviceRecord->buttonStates = calloc(sizeof(bool), deviceRecord->numButtons);
				devices = realloc(devices, sizeof(struct Gamepad_device *) * (numDevices + 1));
				devices[numDevices++] = deviceRecord;
				registeredXInputDevices[playerIndex] = deviceRecord;
				if (Gamepad_deviceAttachCallback != NULL) {
					Gamepad_deviceAttachCallback(deviceRecord, Gamepad_deviceAttachContext);
				}
				
			} else if (xResult != ERROR_SUCCESS && registeredXInputDevices[playerIndex] != NULL) {
				for (deviceIndex = 0; deviceIndex < numDevices; deviceIndex++) {
					if (devices[deviceIndex] == registeredXInputDevices[playerIndex]) {
						removeDevice(deviceIndex);
						break;
					}
				}
				registeredXInputDevices[playerIndex] = NULL;
			}
		}
	}
}

static void updateButtonValue(struct Gamepad_device * device, unsigned int buttonIndex, bool down, double timestamp) {
	if (down != device->buttonStates[buttonIndex]) {
		device->buttonStates[buttonIndex] = down;
		if (down && Gamepad_buttonDownCallback != NULL) {
			Gamepad_buttonDownCallback(device, buttonIndex, timestamp, Gamepad_buttonDownContext);
		} else if (!down && Gamepad_buttonUpCallback != NULL) {
			Gamepad_buttonUpCallback(device, buttonIndex, timestamp, Gamepad_buttonUpContext);
		}
	}
}

static void updateAxisValueFloat(struct Gamepad_device * device, unsigned int axisIndex, float value, double timestamp) {
	float lastValue;
	
	lastValue = device->axisStates[axisIndex];
	device->axisStates[axisIndex] = value;
	if (value != lastValue && Gamepad_axisMoveCallback != NULL) {
		Gamepad_axisMoveCallback(device, axisIndex, value, lastValue, timestamp, Gamepad_axisMoveContext);
	}
}

static void updateAxisValue(struct Gamepad_device * device, unsigned int axisIndex, LONG ivalue, double timestamp) {
	updateAxisValueFloat(device, axisIndex, (ivalue - AXIS_MIN) / (float) (AXIS_MAX - AXIS_MIN) * 2.0f - 1.0f, timestamp);
}

#define POV_UP 0
#define POV_RIGHT 9000
#define POV_DOWN 18000
#define POV_LEFT 27000

static void povToXY(DWORD pov, float * outX, float * outY) {
	if (LOWORD(pov) == 0xFFFF) {
		*outX = *outY = 0.0f;
		
	} else {
		if (pov > POV_UP && pov < POV_DOWN) {
			*outX = 1.0f;
			
		} else if (pov > POV_DOWN) {
			*outX = -1.0f;
			
		} else {
			*outX = 0.0f;
		}
		
		if (pov > POV_LEFT || pov < POV_RIGHT) {
			*outY = -1.0f;
			
		} else if (pov > POV_RIGHT && pov < POV_LEFT) {
			*outY = 1.0f;
			
		} else {
			*outY = 0.0f;
		}
	}
}

static void updatePOVAxisValues(struct Gamepad_device * device, unsigned int axisIndex, DWORD ivalue, double timestamp) {
	float x = 0.0f, y = 0.0f;
	
	povToXY(ivalue, &x, &y);
	updateAxisValueFloat(device, axisIndex, x, timestamp);
	updateAxisValueFloat(device, axisIndex + 1, y, timestamp);
}

void Gamepad_processEvents() {
	static bool inProcessEvents;
	unsigned int deviceIndex, buttonIndex, axisIndex;
	struct Gamepad_device * device;
	struct Gamepad_devicePrivate * devicePrivate;
	HRESULT result;
	
	if (!inited || inProcessEvents) {
		return;
	}
	
	inProcessEvents = true;
	for (deviceIndex = 0; deviceIndex < numDevices; deviceIndex++) {
		device = devices[deviceIndex];
		devicePrivate = device->privateData;
		
		if (devicePrivate->isXInput) {
			XINPUT_STATE state;
			DWORD xResult;
			
			if (XInputGetStateEx_proc != NULL) {
				XINPUT_STATE_EX stateEx;
				
				xResult = XInputGetStateEx_proc(devicePrivate->playerIndex, &stateEx);
				state.Gamepad.wButtons = stateEx.Gamepad.wButtons;
				state.Gamepad.sThumbLX = stateEx.Gamepad.sThumbLX;
				state.Gamepad.sThumbLY = stateEx.Gamepad.sThumbLY;
				state.Gamepad.sThumbRX = stateEx.Gamepad.sThumbRX;
				state.Gamepad.sThumbRY = stateEx.Gamepad.sThumbRY;
				state.Gamepad.bLeftTrigger = stateEx.Gamepad.bLeftTrigger;
				state.Gamepad.bRightTrigger = stateEx.Gamepad.bRightTrigger;
			} else {
				xResult = XInputGetState_proc(devicePrivate->playerIndex, &state);
			}
			if (xResult == ERROR_SUCCESS) {
				updateButtonValue(device, 0, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP), currentTime());
				updateButtonValue(device, 1, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN), currentTime());
				updateButtonValue(device, 2, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT), currentTime());
				updateButtonValue(device, 3, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT), currentTime());
				updateButtonValue(device, 4, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_START), currentTime());
				updateButtonValue(device, 5, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK), currentTime());
				updateButtonValue(device, 6, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB), currentTime());
				updateButtonValue(device, 7, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB), currentTime());
				updateButtonValue(device, 8, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER), currentTime());
				updateButtonValue(device, 9, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER), currentTime());
				updateButtonValue(device, 10, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_A), currentTime());
				updateButtonValue(device, 11, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_B), currentTime());
				updateButtonValue(device, 12, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_X), currentTime());
				updateButtonValue(device, 13, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_Y), currentTime());
				updateButtonValue(device, 14, !!(state.Gamepad.wButtons & XINPUT_GAMEPAD_GUIDE), currentTime());
				updateAxisValue(device, 0, state.Gamepad.sThumbLX, currentTime());
				updateAxisValue(device, 1, state.Gamepad.sThumbLY, currentTime());
				updateAxisValue(device, 2, state.Gamepad.sThumbRX, currentTime());
				updateAxisValue(device, 3, state.Gamepad.sThumbRY, currentTime());
				updateAxisValueFloat(device, 4, state.Gamepad.bLeftTrigger / 127.5f - 1.0f, currentTime());
				updateAxisValueFloat(device, 5, state.Gamepad.bRightTrigger / 127.5f - 1.0f, currentTime());
				
			} else {
				registeredXInputDevices[devicePrivate->playerIndex] = NULL;
				removeDevice(deviceIndex);
				deviceIndex--;
				continue;
			}
			
		} else {
			result = IDirectInputDevice8_Poll(devicePrivate->deviceInterface);
			if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED) {
				IDirectInputDevice8_Acquire(devicePrivate->deviceInterface);
				IDirectInputDevice8_Poll(devicePrivate->deviceInterface);
			}
			
			if (devicePrivate->buffered) {
				DWORD eventCount = INPUT_QUEUE_SIZE;
				DIDEVICEOBJECTDATA events[INPUT_QUEUE_SIZE];
				unsigned int eventIndex;
				
				result = IDirectInputDevice8_GetDeviceData(devicePrivate->deviceInterface, sizeof(DIDEVICEOBJECTDATA), events, &eventCount, 0);
				if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED) {
					IDirectInputDevice8_Acquire(devicePrivate->deviceInterface);
					result = IDirectInputDevice8_GetDeviceData(devicePrivate->deviceInterface, sizeof(DIDEVICEOBJECTDATA), events, &eventCount, 0);
				}
				if (!SUCCEEDED(result)) {
					removeDevice(deviceIndex);
					deviceIndex--;
					continue;
				}
				
				for (eventIndex = 0; eventIndex < eventCount; eventIndex++) {
					for (buttonIndex = 0; buttonIndex < device->numButtons; buttonIndex++) {
						if (events[eventIndex].dwOfs == devicePrivate->buttonOffsets[buttonIndex]) {
							updateButtonValue(device, buttonIndex, !!events[eventIndex].dwData, events[eventIndex].dwTimeStamp / 1000.0);
						}
					}
					for (axisIndex = 0; axisIndex < device->numAxes; axisIndex++) {
						if (events[eventIndex].dwOfs == devicePrivate->axisInfo[axisIndex].offset) {
							if (devicePrivate->axisInfo[axisIndex].isPOV) {
								updatePOVAxisValues(device, axisIndex, events[eventIndex].dwData, events[eventIndex].dwTimeStamp / 1000.0);
								axisIndex++;
							} else {
								updateAxisValue(device, axisIndex, events[eventIndex].dwData, events[eventIndex].dwTimeStamp / 1000.0);
							}
						}
					}
				}
				
			} else {
				DIJOYSTATE2 state;
				
				result = IDirectInputDevice8_GetDeviceState(devicePrivate->deviceInterface, sizeof(DIJOYSTATE2), &state);
				if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED) {
					IDirectInputDevice8_Acquire(devicePrivate->deviceInterface);
					result = IDirectInputDevice8_GetDeviceState(devicePrivate->deviceInterface, sizeof(DIJOYSTATE2), &state);
				}
				
				if (result != DI_OK) {
					removeDevice(deviceIndex);
					deviceIndex--;
					continue;
				}
				
				for (buttonIndex = 0; buttonIndex < device->numButtons; buttonIndex++) {
					updateButtonValue(device, buttonIndex, !!state.rgbButtons[buttonIndex], currentTime());
				}
				
				for (axisIndex = 0; axisIndex < device->numAxes; axisIndex++) {
					switch (devicePrivate->axisInfo[axisIndex].offset) {
						case DIJOFS_X:
							updateAxisValue(device, axisIndex, state.lX, currentTime());
							break;
						case DIJOFS_Y:
							updateAxisValue(device, axisIndex, state.lY, currentTime());
							break;
						case DIJOFS_Z:
							updateAxisValue(device, axisIndex, state.lZ, currentTime());
							break;
						case DIJOFS_RX:
							updateAxisValue(device, axisIndex, state.lRx, currentTime());
							break;
						case DIJOFS_RY:
							updateAxisValue(device, axisIndex, state.lRy, currentTime());
							break;
						case DIJOFS_RZ:
							updateAxisValue(device, axisIndex, state.lRz, currentTime());
							break;
						case DIJOFS_SLIDER(0):
							updateAxisValue(device, axisIndex, state.rglSlider[0], currentTime());
							break;
						case DIJOFS_SLIDER(1):
							updateAxisValue(device, axisIndex, state.rglSlider[1], currentTime());
							break;
						case DIJOFS_POV(0):
							updatePOVAxisValues(device, axisIndex, state.rgdwPOV[0], currentTime());
							axisIndex++;
							break;
						case DIJOFS_POV(1):
							updatePOVAxisValues(device, axisIndex, state.rgdwPOV[1], currentTime());
							axisIndex++;
							break;
						case DIJOFS_POV(2):
							updatePOVAxisValues(device, axisIndex, state.rgdwPOV[2], currentTime());
							axisIndex++;
							break;
						case DIJOFS_POV(3):
							updatePOVAxisValues(device, axisIndex, state.rgdwPOV[3], currentTime());
							axisIndex++;
							break;
					}
				}
			}
		}
	}
	inProcessEvents = false;
}

#else
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <regstr.h>

struct Gamepad_devicePrivate {
	UINT joystickID;
	JOYINFOEX lastState;
	int xAxisIndex;
	int yAxisIndex;
	int zAxisIndex;
	int rAxisIndex;
	int uAxisIndex;
	int vAxisIndex;
	int povXAxisIndex;
	int povYAxisIndex;
	UINT (* axisRanges)[2];
};

static struct Gamepad_device ** devices = NULL;
static unsigned int numDevices = 0;
static unsigned int nextDeviceID = 0;

static bool inited = false;

void Gamepad_init() {
	if (!inited) {
		inited = true;
		Gamepad_detectDevices();
	}
}

static void disposeDevice(struct Gamepad_device * deviceRecord) {
	free(((struct Gamepad_devicePrivate *) deviceRecord->privateData)->axisRanges);
	free(deviceRecord->privateData);
	
	free((void *) deviceRecord->description);
	free(deviceRecord->axisStates);
	free(deviceRecord->buttonStates);
	
	free(deviceRecord);
}

void Gamepad_shutdown() {
	unsigned int deviceIndex;
	
	if (inited) {
		for (deviceIndex = 0; deviceIndex < numDevices; deviceIndex++) {
			disposeDevice(devices[deviceIndex]);
		}
		free(devices);
		devices = NULL;
		numDevices = 0;
		inited = false;
	}
}

unsigned int Gamepad_numDevices() {
	return numDevices;
}

struct Gamepad_device * Gamepad_deviceAtIndex(unsigned int deviceIndex) {
	if (deviceIndex >= numDevices) {
		return NULL;
	}
	return devices[deviceIndex];
}

#define REG_STRING_MAX 256

static char * getDeviceDescription(UINT joystickID, JOYCAPS caps) {
	char * description = NULL;
	char subkey[REG_STRING_MAX];
	HKEY topKey, key;
	LONG result;
	
	snprintf(subkey, REG_STRING_MAX, "%s\\%s\\%s", REGSTR_PATH_JOYCONFIG, caps.szRegKey, REGSTR_KEY_JOYCURR);
	result = RegOpenKeyEx(topKey = HKEY_LOCAL_MACHINE, subkey, 0, KEY_READ, &key);
	if (result != ERROR_SUCCESS) {
		result = RegOpenKeyEx(topKey = HKEY_CURRENT_USER, subkey, 0, KEY_READ, &key);
	}
	if (result == ERROR_SUCCESS) {
		char value[REG_STRING_MAX];
		char name[REG_STRING_MAX];
		DWORD nameSize;
		
		snprintf(value, REG_STRING_MAX, "Joystick%d%s", joystickID + 1, REGSTR_VAL_JOYOEMNAME);
		nameSize = sizeof(name);
		result = RegQueryValueEx(key, value, NULL, NULL, (LPBYTE) name, &nameSize);
		RegCloseKey(key);
		
		if (result == ERROR_SUCCESS) {
			snprintf(subkey, REG_STRING_MAX, "%s\\%s", REGSTR_PATH_JOYOEM, name);
			result = RegOpenKeyEx(topKey, subkey, 0, KEY_READ, &key);
			
			if (result == ERROR_SUCCESS) {
				nameSize = sizeof(name);
				result = RegQueryValueEx(key, REGSTR_VAL_JOYOEMNAME, NULL, NULL, NULL, &nameSize);
				
				if (result == ERROR_SUCCESS) {
					description = malloc(nameSize);
					result = RegQueryValueEx(key, REGSTR_VAL_JOYOEMNAME, NULL, NULL, (LPBYTE) description, &nameSize);
				}
				RegCloseKey(key);
				
				if (result == ERROR_SUCCESS) {
					return description;
				}
				free(description);
			}
		}
	}
	
	description = malloc(strlen(caps.szPname) + 1);
	strcpy(description, caps.szPname);
	
	return description;
}

void Gamepad_detectDevices() {
	unsigned int numPadsSupported;
	unsigned int deviceIndex, deviceIndex2;
	JOYINFOEX info;
	JOYCAPS caps;
	bool duplicate;
	struct Gamepad_device * deviceRecord;
	struct Gamepad_devicePrivate * deviceRecordPrivate;
	UINT joystickID;
	int axisIndex;
	
	if (!inited) {
		return;
	}
	
	numPadsSupported = joyGetNumDevs();
	for (deviceIndex = 0; deviceIndex < numPadsSupported; deviceIndex++) {
		info.dwSize = sizeof(info);
		info.dwFlags = JOY_RETURNALL;
		joystickID = JOYSTICKID1 + deviceIndex;
		if (joyGetPosEx(joystickID, &info) == JOYERR_NOERROR &&
		    joyGetDevCaps(joystickID, &caps, sizeof(JOYCAPS)) == JOYERR_NOERROR) {
			
			duplicate = false;
			for (deviceIndex2 = 0; deviceIndex2 < numDevices; deviceIndex2++) {
				if (((struct Gamepad_devicePrivate *) devices[deviceIndex2]->privateData)->joystickID == joystickID) {
					duplicate = true;
					break;
				}
			}
			if (duplicate) {
				continue;
			}
			
			deviceRecord = malloc(sizeof(struct Gamepad_device));
			deviceRecord->deviceID = nextDeviceID++;
			deviceRecord->description = getDeviceDescription(joystickID, caps);
			deviceRecord->vendorID = caps.wMid;
			deviceRecord->productID = caps.wPid;
			deviceRecord->numAxes = caps.wNumAxes + ((caps.wCaps & JOYCAPS_HASPOV) ? 2 : 0);
			deviceRecord->numButtons = caps.wNumButtons;
			deviceRecord->axisStates = calloc(sizeof(float), deviceRecord->numAxes);
			deviceRecord->buttonStates = calloc(sizeof(bool), deviceRecord->numButtons);
			devices = realloc(devices, sizeof(struct Gamepad_device *) * (numDevices + 1));
			devices[numDevices++] = deviceRecord;
			
			deviceRecordPrivate = malloc(sizeof(struct Gamepad_devicePrivate));
			deviceRecordPrivate->joystickID = joystickID;
			deviceRecordPrivate->lastState = info;
			
			deviceRecordPrivate->xAxisIndex = 0;
			deviceRecordPrivate->yAxisIndex = 1;
			axisIndex = 2;
			deviceRecordPrivate->zAxisIndex = (caps.wCaps & JOYCAPS_HASZ) ? axisIndex++ : -1;
			deviceRecordPrivate->rAxisIndex = (caps.wCaps & JOYCAPS_HASR) ? axisIndex++ : -1;
			deviceRecordPrivate->uAxisIndex = (caps.wCaps & JOYCAPS_HASU) ? axisIndex++ : -1;
			deviceRecordPrivate->vAxisIndex = (caps.wCaps & JOYCAPS_HASV) ? axisIndex++ : -1;
			
			deviceRecordPrivate->axisRanges = malloc(sizeof(UINT[2]) * axisIndex);
			deviceRecordPrivate->axisRanges[0][0] = caps.wXmin;
			deviceRecordPrivate->axisRanges[0][1] = caps.wXmax;
			deviceRecordPrivate->axisRanges[1][0] = caps.wYmin;
			deviceRecordPrivate->axisRanges[1][1] = caps.wYmax;
			if (deviceRecordPrivate->zAxisIndex != -1) {
				deviceRecordPrivate->axisRanges[deviceRecordPrivate->zAxisIndex][0] = caps.wZmin;
				deviceRecordPrivate->axisRanges[deviceRecordPrivate->zAxisIndex][1] = caps.wZmax;
			}
			if (deviceRecordPrivate->rAxisIndex != -1) {
				deviceRecordPrivate->axisRanges[deviceRecordPrivate->rAxisIndex][0] = caps.wRmin;
				deviceRecordPrivate->axisRanges[deviceRecordPrivate->rAxisIndex][1] = caps.wRmax;
			}
			if (deviceRecordPrivate->uAxisIndex != -1) {
				deviceRecordPrivate->axisRanges[deviceRecordPrivate->uAxisIndex][0] = caps.wUmin;
				deviceRecordPrivate->axisRanges[deviceRecordPrivate->uAxisIndex][1] = caps.wUmax;
			}
			if (deviceRecordPrivate->vAxisIndex != -1) {
				deviceRecordPrivate->axisRanges[deviceRecordPrivate->vAxisIndex][0] = caps.wVmin;
				deviceRecordPrivate->axisRanges[deviceRecordPrivate->vAxisIndex][1] = caps.wVmax;
			}
			
			deviceRecordPrivate->povXAxisIndex = (caps.wCaps & JOYCAPS_HASPOV) ? axisIndex++ : -1;
			deviceRecordPrivate->povYAxisIndex = (caps.wCaps & JOYCAPS_HASPOV) ? axisIndex++ : -1;
			
			deviceRecord->privateData = deviceRecordPrivate;
			
			if (Gamepad_deviceAttachCallback != NULL) {
				Gamepad_deviceAttachCallback(deviceRecord, Gamepad_deviceAttachContext);
			}
		}
	}
}

static double currentTime() {
	// HACK: No timestamp data from joyGetInfoEx, so we make it up
	static LARGE_INTEGER frequency;
	LARGE_INTEGER currentTime;
	
	if (frequency.QuadPart == 0) {
		QueryPerformanceFrequency(&frequency);
	}
	QueryPerformanceCounter(&currentTime);
	
	return (double) currentTime.QuadPart / frequency.QuadPart;
}

static void handleAxisChange(struct Gamepad_device * device, int axisIndex, DWORD ivalue) {
	float value, lastValue;
	struct Gamepad_devicePrivate * devicePrivate;
	
	if (axisIndex < 0 || axisIndex >= (int) device->numAxes) {
		return;
	}
	
	devicePrivate = device->privateData;
	value = (ivalue - devicePrivate->axisRanges[axisIndex][0]) / (float) (devicePrivate->axisRanges[axisIndex][1] - devicePrivate->axisRanges[axisIndex][0]) * 2.0f - 1.0f;
	
	lastValue = device->axisStates[axisIndex];
	device->axisStates[axisIndex] = value;
	if (Gamepad_axisMoveCallback != NULL) {
		Gamepad_axisMoveCallback(device, axisIndex, value, lastValue, currentTime(), Gamepad_axisMoveContext);
	}
}

static void handleButtonChange(struct Gamepad_device * device, DWORD lastValue, DWORD value) {
	bool down;
	unsigned int buttonIndex;
	
	for (buttonIndex = 0; buttonIndex < device->numButtons; buttonIndex++) {
		if ((lastValue ^ value) & (1 << buttonIndex)) {
			down = !!(value & (1 << buttonIndex));
			
			device->buttonStates[buttonIndex] = down;
			if (down && Gamepad_buttonDownCallback != NULL) {
				Gamepad_buttonDownCallback(device, buttonIndex, currentTime(), Gamepad_buttonDownContext);
			} else if (!down && Gamepad_buttonUpCallback != NULL) {
				Gamepad_buttonUpCallback(device, buttonIndex, currentTime(), Gamepad_buttonUpContext);
			}
		}
	}
}

static void povToXY(DWORD pov, int * outX, int * outY) {
	if (pov == JOY_POVCENTERED) {
		*outX = *outY = 0;
		
	} else {
		if (pov > JOY_POVFORWARD && pov < JOY_POVBACKWARD) {
			*outX = 1;
			
		} else if (pov > JOY_POVBACKWARD) {
			*outX = -1;
			
		} else {
			*outX = 0;
		}
		
		if (pov > JOY_POVLEFT || pov < JOY_POVRIGHT) {
			*outY = -1;
			
		} else if (pov > JOY_POVRIGHT && pov < JOY_POVLEFT) {
			*outY = 1;
			
		} else {
			*outY = 0;
		}
	}
}

static void handlePOVChange(struct Gamepad_device * device, DWORD lastValue, DWORD value) {
	struct Gamepad_devicePrivate * devicePrivate;
	int lastX, lastY, newX, newY;
	
	devicePrivate = device->privateData;
	
	if (devicePrivate->povXAxisIndex == -1 || devicePrivate->povYAxisIndex == -1) {
		return;
	}
	
	povToXY(lastValue, &lastX, &lastY);
	povToXY(value, &newX, &newY);
	
	if (newX != lastX) {
		device->axisStates[devicePrivate->povXAxisIndex] = newX;
		if (Gamepad_axisMoveCallback != NULL) {
			Gamepad_axisMoveCallback(device, devicePrivate->povXAxisIndex, newX, lastX, currentTime(), Gamepad_axisMoveContext);
		}
	}
	if (newY != lastY) {
		device->axisStates[devicePrivate->povYAxisIndex] = newY;
		if (Gamepad_axisMoveCallback != NULL) {
			Gamepad_axisMoveCallback(device, devicePrivate->povYAxisIndex, newY, lastY, currentTime(), Gamepad_axisMoveContext);
		}
	}
}

void Gamepad_processEvents() {
	unsigned int deviceIndex;
	static bool inProcessEvents;
	JOYINFOEX info;
	MMRESULT result;
	struct Gamepad_device * device;
	struct Gamepad_devicePrivate * devicePrivate;
	
	if (!inited || inProcessEvents) {
		return;
	}
	
	inProcessEvents = true;
	for (deviceIndex = 0; deviceIndex < numDevices; deviceIndex++) {
		device = devices[deviceIndex];
		devicePrivate = device->privateData;
		
		info.dwSize = sizeof(info);
		info.dwFlags = JOY_RETURNALL;
		result = joyGetPosEx(devicePrivate->joystickID, &info);
		if (result == JOYERR_UNPLUGGED) {
			if (Gamepad_deviceRemoveCallback != NULL) {
				Gamepad_deviceRemoveCallback(device, Gamepad_deviceRemoveContext);
			}
			
			disposeDevice(device);
			numDevices--;
			for (; deviceIndex < numDevices; deviceIndex++) {
				devices[deviceIndex] = devices[deviceIndex + 1];
			}
			
		} else if (result == JOYERR_NOERROR) {
			if (info.dwXpos != devicePrivate->lastState.dwXpos) {
				handleAxisChange(device, devicePrivate->xAxisIndex, info.dwXpos);
			}
			if (info.dwYpos != devicePrivate->lastState.dwYpos) {
				handleAxisChange(device, devicePrivate->yAxisIndex, info.dwYpos);
			}
			if (info.dwZpos != devicePrivate->lastState.dwZpos) {
				handleAxisChange(device, devicePrivate->zAxisIndex, info.dwZpos);
			}
			if (info.dwRpos != devicePrivate->lastState.dwRpos) {
				handleAxisChange(device, devicePrivate->rAxisIndex, info.dwRpos);
			}
			if (info.dwUpos != devicePrivate->lastState.dwUpos) {
				handleAxisChange(device, devicePrivate->uAxisIndex, info.dwUpos);
			}
			if (info.dwVpos != devicePrivate->lastState.dwVpos) {
				handleAxisChange(device, devicePrivate->vAxisIndex, info.dwVpos);
			}
			if (info.dwPOV != devicePrivate->lastState.dwPOV) {
				handlePOVChange(device, devicePrivate->lastState.dwPOV, info.dwPOV);
			}
			if (info.dwButtons != devicePrivate->lastState.dwButtons) {
				handleButtonChange(device, devicePrivate->lastState.dwButtons, info.dwButtons);
			}
			devicePrivate->lastState = info;
		}
	}
	inProcessEvents = false;
}

#endif
#elif defined(__gnu_linux__) || defined(__linux__) || defined(__unix__)
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <linux/input.h>
#define __USE_UNIX98
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>

struct Gamepad_devicePrivate {
	pthread_t thread;
	int fd;
	char * path;
	int buttonMap[KEY_CNT - BTN_MISC];
	int axisMap[ABS_CNT];
	struct input_absinfo axisInfo[ABS_CNT];
};

struct Gamepad_queuedEvent {
	unsigned int deviceID;
	enum Gamepad_eventType eventType;
	void * eventData;
};

static struct Gamepad_device ** devices = NULL;
static unsigned int numDevices = 0;
static unsigned int nextDeviceID = 0;
static time_t lastInputStatTime = 0;
static pthread_mutex_t devicesMutex;

static struct Gamepad_queuedEvent * eventQueue = NULL;
static size_t eventQueueSize = 0;
static size_t eventCount = 0;
static pthread_mutex_t eventQueueMutex;

static bool inited = false;

#define test_bit(bitIndex, array) \
	((array[(bitIndex) / (sizeof(int) * 8)] >> ((bitIndex) % (sizeof(int) * 8))) & 0x1)

void Gamepad_init() {
	if (!inited) {
		pthread_mutexattr_t recursiveLock;
		pthread_mutexattr_init(&recursiveLock);
		pthread_mutexattr_settype(&recursiveLock, PTHREAD_MUTEX_RECURSIVE);
		pthread_mutex_init(&devicesMutex, &recursiveLock);
		pthread_mutex_init(&eventQueueMutex, &recursiveLock);
		inited = true;
		Gamepad_detectDevices();
	}
}

static void disposeDevice(struct Gamepad_device * device) {
	close(((struct Gamepad_devicePrivate *) device->privateData)->fd);
	free(((struct Gamepad_devicePrivate *) device->privateData)->path);
	free(device->privateData);
	
	free((void *) device->description);
	free(device->axisStates);
	free(device->buttonStates);
	
	free(device);
}

void Gamepad_shutdown() {
	if (inited) {
		unsigned int eventIndex;
		unsigned int devicesLeft;
		unsigned int gamepadIndex;
		
		do {
			pthread_mutex_lock(&devicesMutex);
			devicesLeft = numDevices;
			if (devicesLeft > 0) {
				pthread_t thread;
				
				thread = ((struct Gamepad_devicePrivate *) devices[0]->privateData)->thread;
				pthread_cancel(thread);
				pthread_join(thread, NULL);
				disposeDevice(devices[0]);
				
				numDevices--;
				for (gamepadIndex = 0; gamepadIndex < numDevices; gamepadIndex++) {
					devices[gamepadIndex] = devices[gamepadIndex + 1];
				}
			}
			pthread_mutex_unlock(&devicesMutex);
		} while (devicesLeft > 0);
		
		pthread_mutex_destroy(&devicesMutex);
		pthread_mutex_destroy(&eventQueueMutex);
		free(devices);
		devices = NULL;
		lastInputStatTime = 0;
		
		for (eventIndex = 0; eventIndex < eventCount; eventIndex++) {
			if (eventQueue[eventIndex].eventType == GAMEPAD_EVENT_DEVICE_REMOVED) {
				disposeDevice(eventQueue[eventIndex].eventData);
			} else if (eventQueue[eventIndex].eventType == GAMEPAD_EVENT_BUTTON_DOWN ||
				   eventQueue[eventIndex].eventType == GAMEPAD_EVENT_BUTTON_UP ||
				   eventQueue[eventIndex].eventType == GAMEPAD_EVENT_AXIS_MOVED) {
				free(eventQueue[eventIndex].eventData);
			}
		}
		
		eventQueueSize = 0;
		eventCount = 0;
		free(eventQueue);
		eventQueue = NULL;
		
		inited = false;
	}
}

unsigned int Gamepad_numDevices() {
	unsigned int result;
	
	pthread_mutex_lock(&devicesMutex);
	result = numDevices;
	pthread_mutex_unlock(&devicesMutex);
	return result;
}

struct Gamepad_device * Gamepad_deviceAtIndex(unsigned int deviceIndex) {
	struct Gamepad_device * result;	
	
	pthread_mutex_lock(&devicesMutex);
	if (deviceIndex >= numDevices) {
		result = NULL;
	} else {
		result = devices[deviceIndex];
	}
	pthread_mutex_unlock(&devicesMutex);
	
	return result;
}

static void queueEvent(unsigned int deviceID, enum Gamepad_eventType eventType, void * eventData) {
	struct Gamepad_queuedEvent queuedEvent;
	
	queuedEvent.deviceID = deviceID;
	queuedEvent.eventType = eventType;
	queuedEvent.eventData = eventData;
	
	pthread_mutex_lock(&eventQueueMutex);
	if (eventCount >= eventQueueSize) {
		eventQueueSize = eventQueueSize == 0 ? 1 : eventQueueSize * 2;
		eventQueue = realloc(eventQueue, sizeof(struct Gamepad_queuedEvent) * eventQueueSize);
	}
	eventQueue[eventCount++] = queuedEvent;
	pthread_mutex_unlock(&eventQueueMutex);
}

static void queueAxisEvent(struct Gamepad_device * device, double timestamp, unsigned int axisID, float value, float lastValue) {
	struct Gamepad_axisEvent * axisEvent;
	
	axisEvent = malloc(sizeof(struct Gamepad_axisEvent));
	axisEvent->device = device;
	axisEvent->timestamp = timestamp;
	axisEvent->axisID = axisID;
	axisEvent->value = value;
	axisEvent->lastValue = lastValue;
	
	queueEvent(device->deviceID, GAMEPAD_EVENT_AXIS_MOVED, axisEvent);
}

static void queueButtonEvent(struct Gamepad_device * device, double timestamp, unsigned int buttonID, bool down) {
	struct Gamepad_buttonEvent * buttonEvent;
	
	buttonEvent = malloc(sizeof(struct Gamepad_buttonEvent));
	buttonEvent->device = device;
	buttonEvent->timestamp = timestamp;
	buttonEvent->buttonID = buttonID;
	buttonEvent->down = down;
	
	queueEvent(device->deviceID, down ? GAMEPAD_EVENT_BUTTON_DOWN : GAMEPAD_EVENT_BUTTON_UP, buttonEvent);
}

static void * deviceThread(void * context) {
	unsigned int gamepadIndex;
	struct Gamepad_device * device;
	struct Gamepad_devicePrivate * devicePrivate;
	struct input_event event;
	
	device = context;
	devicePrivate = device->privateData;
	
	while (read(devicePrivate->fd, &event, sizeof(struct input_event)) > 0) {
		if (event.type == EV_ABS) {
			float value;
			
			if (event.code > ABS_MAX || devicePrivate->axisMap[event.code] == -1) {
				continue;
			}
			
			value = (event.value - devicePrivate->axisInfo[event.code].minimum) / (float) (devicePrivate->axisInfo[event.code].maximum - devicePrivate->axisInfo[event.code].minimum) * 2.0f - 1.0f;
			queueAxisEvent(device,
			               event.time.tv_sec + event.time.tv_usec * 0.000001,
			               devicePrivate->axisMap[event.code],
			               value,
			               device->axisStates[devicePrivate->axisMap[event.code]]);
			
			device->axisStates[devicePrivate->axisMap[event.code]] = value;
			
		} else if (event.type == EV_KEY) {
			if (event.code < BTN_MISC || event.code > KEY_MAX || devicePrivate->buttonMap[event.code - BTN_MISC] == -1) {
				continue;
			}
			
			queueButtonEvent(device,
			                 event.time.tv_sec + event.time.tv_usec * 0.000001,
			                 devicePrivate->buttonMap[event.code - BTN_MISC],
			                 !!event.value);
			
			device->buttonStates[devicePrivate->buttonMap[event.code - BTN_MISC]] = !!event.value;
		}
	}
	
	queueEvent(device->deviceID, GAMEPAD_EVENT_DEVICE_REMOVED, device);
	
	pthread_mutex_lock(&devicesMutex);
	for (gamepadIndex = 0; gamepadIndex < numDevices; gamepadIndex++) {
		if (devices[gamepadIndex] == device) {
			unsigned int gamepadIndex2;
			
			numDevices--;
			for (gamepadIndex2 = gamepadIndex; gamepadIndex2 < numDevices; gamepadIndex2++) {
				devices[gamepadIndex2] = devices[gamepadIndex2 + 1];
			}
			gamepadIndex--;
		}
	}
	pthread_mutex_unlock(&devicesMutex);
	
	return NULL;
}

void Gamepad_detectDevices() {
	struct input_id id;
	DIR * dev_input;
	struct dirent * entity;
	unsigned int charsConsumed;
	int num;
	int fd;
	int evCapBits[(EV_CNT - 1) / sizeof(int) * 8 + 1];
	int evKeyBits[(KEY_CNT - 1) / sizeof(int) * 8 + 1];
	int evAbsBits[(ABS_CNT - 1) / sizeof(int) * 8 + 1];
	char fileName[PATH_MAX];
	bool duplicate;
	unsigned int gamepadIndex;
	struct stat statBuf;
	struct Gamepad_device * deviceRecord;
	struct Gamepad_devicePrivate * deviceRecordPrivate;
	char name[128];
	char * description;
	int bit;
	time_t currentTime;
	
	if (!inited) {
		return;
	}
	
	pthread_mutex_lock(&devicesMutex);
	
	dev_input = opendir("/dev/input");
	currentTime = time(NULL);
	if (dev_input != NULL) {
		while ((entity = readdir(dev_input)) != NULL) {
			charsConsumed = 0;
			if (sscanf(entity->d_name, "event%d%n", &num, &charsConsumed) && charsConsumed == strlen(entity->d_name)) {
				snprintf(fileName, PATH_MAX, "/dev/input/%s", entity->d_name);
				if (stat(fileName, &statBuf) || statBuf.st_mtime < lastInputStatTime) {
					continue;
				}
				
				duplicate = false;
				for (gamepadIndex = 0; gamepadIndex < numDevices; gamepadIndex++) {
					if (!strcmp(((struct Gamepad_devicePrivate *) devices[gamepadIndex]->privateData)->path, fileName)) {
						duplicate = true;
						break;
					}
				}
				if (duplicate) {
					continue;
				}
				
				fd = open(fileName, O_RDONLY, 0);
				memset(evCapBits, 0, sizeof(evCapBits));
				memset(evKeyBits, 0, sizeof(evKeyBits));
				memset(evAbsBits, 0, sizeof(evAbsBits));
				if (ioctl(fd, EVIOCGBIT(0, sizeof(evCapBits)), evCapBits) < 0 ||
				    ioctl(fd, EVIOCGBIT(EV_KEY, sizeof(evKeyBits)), evKeyBits) < 0 ||
				    ioctl(fd, EVIOCGBIT(EV_ABS, sizeof(evAbsBits)), evAbsBits) < 0) {
					close(fd);
					continue;
				}
				if (!test_bit(EV_KEY, evCapBits) || !test_bit(EV_ABS, evCapBits) ||
				    !test_bit(ABS_X, evAbsBits) || !test_bit(ABS_Y, evAbsBits) ||
				    (!test_bit(BTN_TRIGGER, evKeyBits) && !test_bit(BTN_A, evKeyBits) && !test_bit(BTN_1, evKeyBits))) {
					close(fd);
					continue;
				}
				
				deviceRecord = malloc(sizeof(struct Gamepad_device));
				deviceRecord->deviceID = nextDeviceID++;
				devices = realloc(devices, sizeof(struct Gamepad_device *) * (numDevices + 1));
				devices[numDevices++] = deviceRecord;
				
				deviceRecordPrivate = malloc(sizeof(struct Gamepad_devicePrivate));
				deviceRecordPrivate->fd = fd;
				deviceRecordPrivate->path = malloc(strlen(fileName) + 1);
				strcpy(deviceRecordPrivate->path, fileName);
				memset(deviceRecordPrivate->buttonMap, 0xFF, sizeof(deviceRecordPrivate->buttonMap));
				memset(deviceRecordPrivate->axisMap, 0xFF, sizeof(deviceRecordPrivate->axisMap));
				deviceRecord->privateData = deviceRecordPrivate;
				
				if (ioctl(fd, EVIOCGNAME(sizeof(name)), name) > 0) {
					description = malloc(strlen(name) + 1);
					strcpy(description, name);
				} else {
					description = malloc(strlen(fileName) + 1);
					strcpy(description, fileName);
				}
				deviceRecord->description = description;
				
				if (!ioctl(fd, EVIOCGID, &id)) {
					deviceRecord->vendorID = id.vendor;
					deviceRecord->productID = id.product;
				} else {
					deviceRecord->vendorID = deviceRecord->productID = 0;
				}
				
				memset(evKeyBits, 0, sizeof(evKeyBits));
				memset(evAbsBits, 0, sizeof(evAbsBits));
				ioctl(fd, EVIOCGBIT(EV_KEY, sizeof(evKeyBits)), evKeyBits);
				ioctl(fd, EVIOCGBIT(EV_ABS, sizeof(evAbsBits)), evAbsBits);
				
				deviceRecord->numAxes = 0;
				for (bit = 0; bit < ABS_CNT; bit++) {
					if (test_bit(bit, evAbsBits)) {
						if (ioctl(fd, EVIOCGABS(bit), &deviceRecordPrivate->axisInfo[bit]) < 0 ||
							  deviceRecordPrivate->axisInfo[bit].minimum == deviceRecordPrivate->axisInfo[bit].maximum) {
							continue;
						}
						deviceRecordPrivate->axisMap[bit] = deviceRecord->numAxes;
						deviceRecord->numAxes++;
					}
				}
				deviceRecord->numButtons = 0;
				for (bit = BTN_MISC; bit < KEY_CNT; bit++) {
					if (test_bit(bit, evKeyBits)) {
						deviceRecordPrivate->buttonMap[bit - BTN_MISC] = deviceRecord->numButtons;
						deviceRecord->numButtons++;
					}
				}
				
				deviceRecord->axisStates = calloc(sizeof(float), deviceRecord->numAxes);
				deviceRecord->buttonStates = calloc(sizeof(bool), deviceRecord->numButtons);
				
				if (Gamepad_deviceAttachCallback != NULL) {
					Gamepad_deviceAttachCallback(deviceRecord, Gamepad_deviceAttachContext);
				}
				
				pthread_create(&deviceRecordPrivate->thread, NULL, deviceThread, deviceRecord);
			}
		}
		closedir(dev_input);
	}
	
	lastInputStatTime = currentTime;
	pthread_mutex_unlock(&devicesMutex);
}

static void processQueuedEvent(struct Gamepad_queuedEvent event) {
	switch (event.eventType) {
		case GAMEPAD_EVENT_DEVICE_ATTACHED:
			if (Gamepad_deviceAttachCallback != NULL) {
				Gamepad_deviceAttachCallback(event.eventData, Gamepad_deviceAttachContext);
			}
			break;
			
		case GAMEPAD_EVENT_DEVICE_REMOVED:
			if (Gamepad_deviceRemoveCallback != NULL) {
				Gamepad_deviceRemoveCallback(event.eventData, Gamepad_deviceRemoveContext);
			}
			break;
			
		case GAMEPAD_EVENT_BUTTON_DOWN:
			if (Gamepad_buttonDownCallback != NULL) {
				struct Gamepad_buttonEvent * buttonEvent = event.eventData;
				Gamepad_buttonDownCallback(buttonEvent->device, buttonEvent->buttonID, buttonEvent->timestamp, Gamepad_buttonDownContext);
			}
			break;
			
		case GAMEPAD_EVENT_BUTTON_UP:
			if (Gamepad_buttonUpCallback != NULL) {
				struct Gamepad_buttonEvent * buttonEvent = event.eventData;
				Gamepad_buttonUpCallback(buttonEvent->device, buttonEvent->buttonID, buttonEvent->timestamp, Gamepad_buttonUpContext);
			}
			break;
			
		case GAMEPAD_EVENT_AXIS_MOVED:
			if (Gamepad_axisMoveCallback != NULL) {
				struct Gamepad_axisEvent * axisEvent = event.eventData;
				Gamepad_axisMoveCallback(axisEvent->device, axisEvent->axisID, axisEvent->value, axisEvent->lastValue, axisEvent->timestamp, Gamepad_axisMoveContext);
			}
			break;
	}
}

void Gamepad_processEvents() {
	unsigned int eventIndex;
	static bool inProcessEvents;
	
	if (!inited || inProcessEvents) {
		return;
	}
	
	inProcessEvents = true;
	pthread_mutex_lock(&eventQueueMutex);
	for (eventIndex = 0; eventIndex < eventCount; eventIndex++) {
		processQueuedEvent(eventQueue[eventIndex]);
		if (eventQueue[eventIndex].eventType == GAMEPAD_EVENT_DEVICE_REMOVED) {
			disposeDevice(eventQueue[eventIndex].eventData);
			
		} else if (eventQueue[eventIndex].eventType == GAMEPAD_EVENT_BUTTON_DOWN ||
		           eventQueue[eventIndex].eventType == GAMEPAD_EVENT_BUTTON_UP ||
		           eventQueue[eventIndex].eventType == GAMEPAD_EVENT_AXIS_MOVED) {
			free(eventQueue[eventIndex].eventData);
		}
	}
	eventCount = 0;
	pthread_mutex_unlock(&eventQueueMutex);
	inProcessEvents = false;
}

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

int sapp_cursor_delta_x(void) {
    return _input_state.input_current.cursor.x - _input_state.input_prev.cursor.x;
}

int sapp_cursor_delta_y(void) {
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