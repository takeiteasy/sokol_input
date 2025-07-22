# sokol_input.h

> [!WARNING]
> Work in progress, but functional

Input handler for [sokol](https://github.com/floooh/sokol/). Instead of manually managing events, this library will keep track of the keyboard and mouse state. Also includes gamepad support, provided by [ThemsAllTook/libstem_gamepad](https://github.com/ThemsAllTook/libstem_gamepad/) (disable by defining `SOKOL_INPUT_NO_GAMEPADS`). 

## Documentation

[https://takeiteasy.github.io/sokol_input/](https://takeiteasy.github.io/sokol_input/)

## TODO

- [ ] Expand on input parser
- [ ] Input record + playback
- [ ] Time since functions 

## LICENSE
```
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
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```
