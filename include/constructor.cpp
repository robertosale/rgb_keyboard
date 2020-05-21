/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include "rgb_keyboard.h"

//constructor
rgb_keyboard::keyboard::keyboard(){
	
	
	// default settings
	_direction.fill( d_undefined );
	_mode.fill( m_fixed );
	_variant.fill( v_undefined );
	_speed.fill( 1 );
	_profile = 1;
	_active_profile = 1;
	
	//keycodes for custom key color
	_keycodes["Esc"] = { 0x57, 0x03, 0x00 };
	_keycodes["F1"] = { 0x5a, 0x06, 0x00 };
	_keycodes["F2"] = { 0x5d, 0x09, 0x00 };
	_keycodes["F3"] = { 0x60, 0x0c, 0x00 };
	_keycodes["F4"] = { 0x63, 0x0f, 0x00 };
	_keycodes["F5"] = { 0x66, 0x12, 0x00 };
	_keycodes["F6"] = { 0x69, 0x15, 0x00 };
	_keycodes["F7"] = { 0x6c, 0x18, 0x00 };
	_keycodes["F8"] = { 0x6f, 0x1b, 0x00 };
	_keycodes["F9"] = { 0x72, 0x1e, 0x00 };
	_keycodes["F10"] = { 0x75, 0x21, 0x00 };
	_keycodes["F11"] = { 0x78, 0x24, 0x00 };
	_keycodes["F12"] = { 0x7b, 0x27, 0x00 };
	_keycodes["PrtSc"] = { 0x93, 0x3e, 0x01 };
	_keycodes["ScrLk"] = { 0x96, 0x41, 0x01 };
	_keycodes["Pause"] = { 0x99, 0x44, 0x01 };
	_keycodes["Tilde"] = { 0x8a, 0x36, 0x00 };
	_keycodes["1"] = { 0x8d, 0x39, 0x00 };
	_keycodes["2"] = { 0x90, 0x3c, 0x00 };
	_keycodes["3"] = { 0x93, 0x3f, 0x00 };
	_keycodes["4"] = { 0x96, 0x42, 0x00 };
	_keycodes["5"] = { 0x99, 0x45, 0x00 };
	_keycodes["6"] = { 0x9c, 0x48, 0x00 };
	_keycodes["7"] = { 0x9f, 0x4b, 0x00 };
	_keycodes["8"] = { 0xa2, 0x4e, 0x00 };
	_keycodes["9"] = { 0xa5, 0x51, 0x00 };
	_keycodes["0"] = { 0xa8, 0x54, 0x00 };
	_keycodes["Minus"] = { 0xab, 0x57, 0x00 };
	_keycodes["Equals"] = { 0xae, 0x5a, 0x00 };
	_keycodes["Backspace"] = { 0x7b, 0x26, 0x01 };
	_keycodes["Insert"] = { 0x9f, 0x4a, 0x01 };
	_keycodes["Home"] = { 0xa2, 0x4d, 0x01 };
	_keycodes["PgUp"] = { 0xa5, 0x50, 0x01 };
	_keycodes["Delete"] = { 0xa8, 0x53, 0x01 };
	_keycodes["End"] = { 0xab, 0x56, 0x01 };
	_keycodes["PgDn"] = { 0xae, 0x59, 0x01 };
	_keycodes["Tab"] = { 0xbd, 0x69, 0x00 };
	_keycodes["q"] = { 0xc0, 0x6c, 0x00 };
	_keycodes["w"] = { 0xc3, 0x6f, 0x00 };
	_keycodes["e"] = { 0xc6, 0x72, 0x00 };
	_keycodes["r"] = { 0xc9, 0x75, 0x00 };
	_keycodes["t"] = { 0xcc, 0x78, 0x00 };
	_keycodes["y"] = { 0xcf, 0x7b, 0x00 };
	_keycodes["u"] = { 0xd2, 0x7e, 0x00 };
	_keycodes["i"] = { 0xd5, 0x81, 0x00 };
	_keycodes["o"] = { 0xd8, 0x84, 0x00 };
	_keycodes["p"] = { 0xdb, 0x87, 0x00 };
	_keycodes["Bracket_l"] = { 0xde, 0x8a, 0x00 };
	_keycodes["Bracket_r"] = { 0xe1, 0x8d, 0x00 };
	_keycodes["Backslash"] = { 0x14, 0xc0, 0x00 };
	_keycodes["Up"] = { 0x75, 0x20, 0x01 };
	_keycodes["Left"] = { 0x6f, 0x1a, 0x01 };
	_keycodes["Down"] = { 0x72, 0x1d, 0x01 };
	_keycodes["Right"] = { 0x78, 0x23, 0x01 };
	_keycodes["Caps_Lock"] = { 0xf0, 0x9c, 0x00 };
	_keycodes["a"] = { 0xf3, 0x9f, 0x00 };
	_keycodes["s"] = { 0xf6, 0xa2, 0x00 };
	_keycodes["d"] = { 0xf9, 0xa5, 0x00 };
	_keycodes["f"] = { 0xfc, 0xa8, 0x00 };
	_keycodes["g"] = { 0xff, 0xab, 0x00 };
	_keycodes["h"] = { 0x02, 0xae, 0x00 };
	_keycodes["j"] = { 0x05, 0xb1, 0x00 };
	_keycodes["k"] = { 0x08, 0xb4, 0x00 };
	_keycodes["l"] = { 0x0b, 0xb7, 0x00 };
	_keycodes["Semicolon"] = { 0x0e, 0xba, 0x00 };
	_keycodes["Apostrophe"] = { 0x11, 0xbd, 0x00 };
	_keycodes["Return"] = { 0x47, 0xf3, 0x00 };
	_keycodes["Shift_l"] = { 0x23, 0xcf, 0x00 };
	_keycodes["z"] = { 0x26, 0xd2, 0x00 };
	_keycodes["x"] = { 0x29, 0xd5, 0x00 };
	_keycodes["c"] = { 0x2c, 0xd8, 0x00 };
	_keycodes["v"] = { 0x2f, 0xdb, 0x00 };
	_keycodes["b"] = { 0x32, 0xde, 0x00 };
	_keycodes["n"] = { 0x35, 0xe1, 0x00 };
	_keycodes["m"] = { 0x38, 0xe4, 0x00 };
	_keycodes["Comma"] = { 0x3b, 0xe7, 0x00 };
	_keycodes["Period"] = { 0x3e, 0xea, 0x00 };
	_keycodes["Slash"] = { 0x41, 0xed, 0x00 };
	_keycodes["Shift_r"] = { 0x44, 0xf0, 0x00 };
	_keycodes["Ctrl_l"] = { 0x57, 0x02, 0x01 };
	_keycodes["Super_l"] = { 0x5a, 0x05, 0x01 };
	_keycodes["Alt_l"] = { 0x5d, 0x08, 0x01 };
	_keycodes["Space"] = { 0x60, 0x0b, 0x01 };
	_keycodes["Alt_r"] = { 0x63, 0x0e, 0x01 };
	_keycodes["Fn"] = { 0x66, 0x11, 0x01 };
	_keycodes["Menu"] = { 0x69, 0x14, 0x01 };
	_keycodes["Ctrl_r"] = { 0x6c, 0x17, 0x01 };
	_keycodes["Num_Lock"] = { 0xb1, 0x5d, 0x00 };
	_keycodes["Num_Slash"] = { 0xb4, 0x60, 0x00 };
	_keycodes["Num_Asterisk"] = { 0xb7, 0x63, 0x00 };
	_keycodes["Num_Minus"] = { 0xb1, 0x5c, 0x01 };
	_keycodes["Num_7"] = { 0xe4, 0x90, 0x00 };
	_keycodes["Num_8"] = { 0xe7, 0x93, 0x00 };
	_keycodes["Num_9"] = { 0xea, 0x96, 0x00 };
	_keycodes["Num_Plus"] = { 0xb4, 0x5f, 0x01 };
	_keycodes["Num_4"] = { 0x17, 0xc3, 0x00 };
	_keycodes["Num_5"] = { 0x1a, 0xc6, 0x00 };
	_keycodes["Num_6"] = { 0x1d, 0xc9, 0x00 };
	_keycodes["Num_1"] = { 0x4a, 0xf6, 0x00 };
	_keycodes["Num_2"] = { 0x4d, 0xf9, 0x00 };
	_keycodes["Num_3"] = { 0x50, 0xfc, 0x00 };
	_keycodes["Num_0"] = { 0x7e, 0x29, 0x01 };
	_keycodes["Num_Period"] = { 0x81, 0x2c, 0x01 };
	_keycodes["Num_Return"] = { 0x84, 0x2f, 0x01 };
	_keycodes["Int_Key"] = { 0x4f, 0x3b, 0x01 };
	
	//offsets for key remapping
	_keymap_offsets["Esc"] = {{ { 1, 11 }, { 1, 12 }, { 1, 13 } }};
	_keymap_offsets["F1"] = {{ { 1, 14 }, { 1, 15 }, { 1, 16 } }};
	_keymap_offsets["F2"] = {{ { 1, 17 }, { 1, 18 }, { 1, 19 } }};
	_keymap_offsets["F3"] = {{ { 1, 20 }, { 1, 21 }, { 1, 22 } }};
	_keymap_offsets["F4"] = {{ { 1, 23 }, { 1, 24 }, { 1, 25 } }};
	_keymap_offsets["F5"] = {{ { 1, 26 }, { 1, 27 }, { 1, 28 } }};
	_keymap_offsets["F6"] = {{ { 1, 29 }, { 1, 30 }, { 1, 31 } }};
	_keymap_offsets["F7"] = {{ { 1, 32 }, { 1, 33 }, { 1, 34 } }};
	_keymap_offsets["F8"] = {{ { 1, 35 }, { 1, 36 }, { 1, 37 } }};
	_keymap_offsets["F9"] = {{ { 1, 38 }, { 1, 39 }, { 1, 40 } }};
	_keymap_offsets["F10"] = {{ { 1, 41 }, { 1, 42 }, { 1, 43 } }};
	_keymap_offsets["F11"] = {{ { 1, 44 }, { 1, 45 }, { 1, 46 } }};
	_keymap_offsets["F12"] = {{ { 1, 47 }, { 1, 48 }, { 1, 49 } }};
	_keymap_offsets["PrtSc"] = {{ { 6, 46 }, { 6, 47 }, { 6, 48 } }};
	_keymap_offsets["ScrLk"] = {{ { 6, 49 }, { 6, 50 }, { 6, 51 } }};
	_keymap_offsets["Pause"] = {{ { 6, 52 }, { 6, 53 }, { 6, 54 } }};
	_keymap_offsets["Tilde"] = {{ { 1, 62 }, { 1, 63 }, { 2, 8 } }};
	_keymap_offsets["1"] = {{ { 2, 9  }, { 2, 10 }, { 2, 11 } }};
	_keymap_offsets["2"] = {{ { 2, 12 }, { 2, 13 }, { 2, 14 } }};
	_keymap_offsets["3"] = {{ { 2, 15 }, { 2, 16 }, { 2, 17 } }};
	_keymap_offsets["4"] = {{ { 2, 18 }, { 2, 19 }, { 2, 20 } }};
	_keymap_offsets["5"] = {{ { 2, 21 }, { 2, 22 }, { 2, 23 } }};
	_keymap_offsets["6"] = {{ { 2, 24 }, { 2, 25 }, { 2, 26 } }};
	_keymap_offsets["7"] = {{ { 2, 27 }, { 2, 28 }, { 2, 29 } }};
	_keymap_offsets["8"] = {{ { 2, 30 }, { 2, 31 }, { 2, 32 } }};
	_keymap_offsets["9"] = {{ { 2, 33 }, { 2, 34 }, { 2, 35 } }};
	_keymap_offsets["0"] = {{ { 2, 36 }, { 2, 37 }, { 2, 38 } }};
	_keymap_offsets["Minus"] = {{ { 2, 39 }, { 2, 40 }, { 2, 41 } }};
	_keymap_offsets["Equals"] = {{ { 2, 42 }, { 2, 43 }, { 2, 44 } }};
	_keymap_offsets["Backspace"] = {{ { 6, 22 }, { 6, 23 }, { 6, 24 } }};
	_keymap_offsets["Insert"] = {{ { 6, 58 }, { 6, 59 }, { 6, 60 } }};
	_keymap_offsets["Home"] = {{ { 6, 61 }, { 6, 62 }, { 6, 63 } }};
	_keymap_offsets["PgUp"] = {{ { 7, 8 }, { 7, 9 }, { 7, 10 } }};
	_keymap_offsets["Delete"] = {{ { 7, 11 }, { 7, 12 }, { 7, 13 } }};
	_keymap_offsets["End"] = {{ { 7, 14 }, { 7, 15 }, { 7, 16 } }};
	_keymap_offsets["PgDn"] = {{ { 7, 17 }, { 7, 18 }, { 7, 19 } }};
	_keymap_offsets["Tab"] = {{ { 2, 57 }, { 2, 58 }, { 2, 59 } }};
	_keymap_offsets["q"] = {{ { 2, 60 }, { 2, 61 }, { 2, 62 } }};
	_keymap_offsets["w"] = {{ { 3, 7 }, { 3, 8 }, { 3, 9 } }};
	_keymap_offsets["e"] = {{ { 3, 10 }, { 3, 11 }, { 3, 12 } }};
	_keymap_offsets["r"] = {{ { 3, 13 }, { 3, 14 }, { 3, 15 } }};
	_keymap_offsets["t"] = {{ { 3, 16 }, { 3, 17 }, { 3, 18 } }};
	_keymap_offsets["y"] = {{ { 3, 19 }, { 3, 20 }, { 3, 21 } }};
	_keymap_offsets["u"] = {{ { 3, 22 }, { 3, 23 }, { 3, 24 } }};
	_keymap_offsets["i"] = {{ { 3, 25 }, { 3, 26 }, { 3, 27 } }};
	_keymap_offsets["o"] = {{ { 3, 28 }, { 3, 29 }, { 3, 30 } }};
	_keymap_offsets["p"] = {{ { 3, 31 }, { 3, 32 }, { 3, 33 } }};
	_keymap_offsets["Bracket_l"] = {{ { 3, 34 }, { 3, 35 }, { 3, 36 } }};
	_keymap_offsets["Bracket_r"] = {{ { 3, 37 }, { 3, 38 }, { 1, 39 } }};
	_keymap_offsets["Backslash"] = {{ { 4, 32 }, { 4, 33 }, { 4, 34 } }};
	_keymap_offsets["Up"] = {{ { 6, 16 }, { 6, 17 }, { 6, 18 } }};
	_keymap_offsets["Left"] = {{ { 6, 10 }, { 6, 11 }, { 6, 12 } }};
	_keymap_offsets["Down"] = {{ { 6, 13 }, { 6, 14 }, { 6, 15 } }};
	_keymap_offsets["Right"] = {{ { 6, 19 }, { 6, 20 }, { 6, 21 } }};
	_keymap_offsets["Caps_Lock"] = {{ { 3, 52 }, { 3, 53 }, { 3, 54 } }};
	_keymap_offsets["a"] = {{ { 3, 55 }, { 3, 56 }, { 3, 57 } }};
	_keymap_offsets["s"] = {{ { 3, 58 }, { 3, 59 }, { 3, 60 } }};
	_keymap_offsets["d"] = {{ { 3, 61 }, { 3, 62 }, { 3, 63 } }};
	_keymap_offsets["f"] = {{ { 4, 8 }, { 4, 9 }, { 4, 10 } }};
	_keymap_offsets["g"] = {{ { 4, 11 }, { 4, 12 }, { 4, 13 } }};
	_keymap_offsets["h"] = {{ { 4, 14 }, { 4, 15 }, { 4, 16 } }};
	_keymap_offsets["j"] = {{ { 4, 17 }, { 4, 18 }, { 4, 19 } }};
	_keymap_offsets["k"] = {{ { 4, 20 }, { 4, 21 }, { 4, 22 } }};
	_keymap_offsets["l"] = {{ { 4, 23 }, { 4, 24 }, { 4, 25 } }};
	_keymap_offsets["Semicolon"] = {{ { 4, 26 }, { 4, 27 }, { 4, 28 } }};
	_keymap_offsets["Apostrophe"] = {{ { 4, 29 }, { 4, 30 }, { 4, 31 } }};
	_keymap_offsets["Return"] = {{ { 5, 27 }, { 5, 28 }, { 5, 29 } }};
	_keymap_offsets["z"] = {{ { 4, 50 }, { 4, 51 }, { 4, 52 } }};
	_keymap_offsets["x"] = {{ { 4, 53 }, { 4, 54 }, { 4, 55 } }};
	_keymap_offsets["c"] = {{ { 4, 56 }, { 4, 57 }, { 4, 58 } }};
	_keymap_offsets["v"] = {{ { 4, 59 }, { 4, 60 }, { 4, 61 } }};
	_keymap_offsets["b"] = {{ { 4, 62 }, { 4, 63 }, { 5, 8 } }};
	_keymap_offsets["n"] = {{ { 5, 9 }, { 5, 10 }, { 5, 11 } }};
	_keymap_offsets["m"] = {{ { 5, 12 }, { 5, 13 }, { 5, 14 } }};
	_keymap_offsets["Comma"] = {{ { 5, 15 }, { 5, 16 }, { 5, 17 } }};
	_keymap_offsets["Period"] = {{ { 5, 18 }, { 5, 19 }, { 5, 20 } }};
	_keymap_offsets["Slash"] = {{ { 5, 21 }, { 5, 22 }, { 5, 23 } }};
	_keymap_offsets["Shift_l"] = {{ { 4, 47 }, { 4, 48 }, { 4, 49 } }};
	_keymap_offsets["Shift_r"] = {{ { 5, 24 }, { 5, 25 }, { 5, 26 } }};
	_keymap_offsets["Ctrl_l"] = {{ { 5, 42 }, { 5, 43 }, { 5, 44 } }};
	_keymap_offsets["Super_l"] = {{ { 5, 45 }, { 5, 46 }, { 5, 47 } }};
	_keymap_offsets["Alt_l"] = {{ { 5, 48 }, { 5, 49 }, { 5, 50 } }};
	_keymap_offsets["Space"] = {{ { 5, 51 }, { 5, 52 }, { 5, 53 } }};
	_keymap_offsets["Alt_r"] = {{ { 5, 54 }, { 5, 55 }, { 5, 56 } }};
	_keymap_offsets["Fn"] = {{ { 5, 57 }, { 5, 58 }, { 5, 59 } }};
	_keymap_offsets["Menu"] = {{ { 5, 60 }, { 5, 61 }, { 5, 62 } }};
	_keymap_offsets["Ctrl_r"] = {{ { 5, 63 }, { 6, 8 }, { 6, 9 } }};
	_keymap_offsets["Num_Lock"] = {{ { 2, 45 }, { 2, 46 }, { 2, 47 } }};
	_keymap_offsets["Num_Slash"] = {{ { 2, 48 }, { 2, 49 }, { 2, 50 } }};
	_keymap_offsets["Num_Asterisk"] = {{ { 2, 51 }, { 2, 52 }, { 2, 53 } }};
	_keymap_offsets["Num_Minus"] = {{ { 7, 20 }, { 7, 21 }, { 7, 22 } }};
	_keymap_offsets["Num_Plus"] = {{ { 7, 23 }, { 7, 24 }, { 7, 25 } }};
	_keymap_offsets["Num_1"] = {{ { 5, 30 }, { 5, 31 }, { 5, 32 } }};
	_keymap_offsets["Num_2"] = {{ { 5, 33 }, { 5, 34 }, { 5, 35 } }};
	_keymap_offsets["Num_3"] = {{ { 5, 36 }, { 5, 37 }, { 5, 38 } }};
	_keymap_offsets["Num_4"] = {{ { 4, 35 }, { 4, 36 }, { 4, 37 } }};
	_keymap_offsets["Num_5"] = {{ { 4, 38 }, { 4, 39 }, { 4, 40 } }};
	_keymap_offsets["Num_6"] = {{ { 4, 41 }, { 4, 42 }, { 4, 43 } }};
	_keymap_offsets["Num_7"] = {{ { 3, 40 }, { 3, 41 }, { 3, 42 } }};
	_keymap_offsets["Num_8"] = {{ { 3, 43 }, { 3, 44 }, { 3, 45 } }};
	_keymap_offsets["Num_9"] = {{ { 3, 46 }, { 3, 47 }, { 3, 48 } }};
	_keymap_offsets["Num_0"] = {{ { 6, 25 }, { 6, 26 }, { 6, 27 } }};
	_keymap_offsets["Num_Period"] = {{ { 6, 28 }, { 6, 29 }, { 6, 30 } }};
	_keymap_offsets["Num_Return"] = {{ { 6, 31 }, { 6, 32 }, { 6, 33 } }};
	_keymap_offsets["Int_Key"] = {{ { 7, 44 }, { 7, 45 }, { 7, 46 } }};
	
	//keymap options (what a key can do when pressed)
	//top row
	_keymap_options["Esc"] = { 0x02, 0x02, 0x29 };
	_keymap_options["F1"] = { 0x02, 0x02, 0x3a };
	_keymap_options["F2"] = { 0x02, 0x02, 0x3b };
	_keymap_options["F3"] = { 0x02, 0x02, 0x3c };
	_keymap_options["F4"] = { 0x02, 0x02, 0x3d };
	_keymap_options["F5"] = { 0x02, 0x02, 0x3e };
	_keymap_options["F6"] = { 0x02, 0x02, 0x3f };
	_keymap_options["F7"] = { 0x02, 0x02, 0x40 };
	_keymap_options["F8"] = { 0x02, 0x02, 0x41 };
	_keymap_options["F9"] = { 0x02, 0x02, 0x42 };
	_keymap_options["F10"] = { 0x02, 0x02, 0x43 };
	_keymap_options["F11"] = { 0x02, 0x02, 0x44 };
	_keymap_options["F12"] = { 0x02, 0x02, 0x45 };
	_keymap_options["PrtSc"] = { 0x02, 0x02, 0x46 };
	_keymap_options["ScrLk"] = { 0x02, 0x02, 0x47 };
	_keymap_options["Pause"] = { 0x02, 0x02, 0x48 };
	//alphanumeric
	_keymap_options["a"] = { 0x02, 0x02, 0x04 };
	_keymap_options["b"] = { 0x02, 0x02, 0x05 };
	_keymap_options["c"] = { 0x02, 0x02, 0x06 };
	_keymap_options["d"] = { 0x02, 0x02, 0x07 };
	_keymap_options["e"] = { 0x02, 0x02, 0x08 };
	_keymap_options["f"] = { 0x02, 0x02, 0x09 };
	_keymap_options["g"] = { 0x02, 0x02, 0x0a };
	_keymap_options["h"] = { 0x02, 0x02, 0x0b };
	_keymap_options["i"] = { 0x02, 0x02, 0x0c };
	_keymap_options["j"] = { 0x02, 0x02, 0x0d };
	_keymap_options["k"] = { 0x02, 0x02, 0x0e };
	_keymap_options["l"] = { 0x02, 0x02, 0x0f };
	_keymap_options["m"] = { 0x02, 0x02, 0x10 };
	_keymap_options["n"] = { 0x02, 0x02, 0x11 };
	_keymap_options["o"] = { 0x02, 0x02, 0x12 };
	_keymap_options["p"] = { 0x02, 0x02, 0x13 };
	_keymap_options["q"] = { 0x02, 0x02, 0x14 };
	_keymap_options["r"] = { 0x02, 0x02, 0x15 };
	_keymap_options["s"] = { 0x02, 0x02, 0x16 };
	_keymap_options["t"] = { 0x02, 0x02, 0x17 };
	_keymap_options["u"] = { 0x02, 0x02, 0x18 };
	_keymap_options["v"] = { 0x02, 0x02, 0x19 };
	_keymap_options["w"] = { 0x02, 0x02, 0x1a };
	_keymap_options["x"] = { 0x02, 0x02, 0x1b };
	_keymap_options["y"] = { 0x02, 0x02, 0x1c };
	_keymap_options["z"] = { 0x02, 0x02, 0x1d };
	_keymap_options["1"] = { 0x02, 0x02, 0x1e };
	_keymap_options["2"] = { 0x02, 0x02, 0x1f };
	_keymap_options["3"] = { 0x02, 0x02, 0x20 };
	_keymap_options["4"] = { 0x02, 0x02, 0x21 };
	_keymap_options["5"] = { 0x02, 0x02, 0x22 };
	_keymap_options["6"] = { 0x02, 0x02, 0x23 };
	_keymap_options["7"] = { 0x02, 0x02, 0x24 };
	_keymap_options["8"] = { 0x02, 0x02, 0x25 };
	_keymap_options["9"] = { 0x02, 0x02, 0x26 };
	_keymap_options["0"] = { 0x02, 0x02, 0x27 };
	//modifiers
	_keymap_options["Tab"] = { 0x02, 0x02, 0x2b };
	_keymap_options["Caps_Lock"] = { 0x02, 0x02, 0x39 };
	_keymap_options["Shift_l"] = { 0x02, 0x02, 0xe1 };
	_keymap_options["Ctrl_l"] = { 0x02, 0x02, 0xe0 };
	_keymap_options["Alt_l"] = { 0x02, 0x02, 0xe2 };
	_keymap_options["Super_l"] = { 0x02, 0x02, 0xe3 };
	_keymap_options["Super_r"] = { 0x02, 0x02, 0xe7 };
	_keymap_options["Alt_r"] = { 0x02, 0x02, 0xe6 };
	_keymap_options["Menu"] = { 0x02, 0x02, 0x65 };
	_keymap_options["Ctrl_r"] = { 0x02, 0x02, 0xe4 };
	_keymap_options["Shift_r"] = { 0x02, 0x02, 0xe5 };
	_keymap_options["Return"] = { 0x02, 0x02, 0x28 };
	_keymap_options["Backspace"] = { 0x02, 0x02, 0x2a };
	_keymap_options["Caps_Lock"] = { 0x02, 0x02, 0x39 };
	_keymap_options["Fn"] = { 0x05, 0x02, 0x02 };
	//special characters
	_keymap_options["Space"] = { 0x02, 0x02, 0x2b };
	_keymap_options["Tilde"] = { 0x02, 0x02, 0x35 };
	_keymap_options["Minus"] = { 0x02, 0x02, 0x2d };
	_keymap_options["Equals"] = { 0x02, 0x02, 0x2e };
	_keymap_options["Bracket_l"] = { 0x02, 0x02, 0x2f };
	_keymap_options["Bracket_r"] = { 0x02, 0x02, 0x30 };
	_keymap_options["Backslash"] = { 0x02, 0x02, 0x31 };
	_keymap_options["Semicolon"] = { 0x02, 0x02, 0x33 };
	_keymap_options["Apostrophe"] = { 0x02, 0x02, 0x34 };
	_keymap_options["Comma"] = { 0x02, 0x02, 0x36 };
	_keymap_options["Period"] = { 0x02, 0x02, 0x37 };
	_keymap_options["Slash"] = { 0x02, 0x02, 0x38 };
	_keymap_options["Int_Key"] = { 0x02, 0x02, 0x64 };
	//navigation
	_keymap_options["Right"] = { 0x02, 0x02, 0x4f };
	_keymap_options["Left"] = { 0x02, 0x02, 0x50 };
	_keymap_options["Down"] = { 0x02, 0x02, 0x51 };
	_keymap_options["Up"] = { 0x02, 0x02, 0x52 };
	_keymap_options["Insert"] = { 0x02, 0x02, 0x49 };
	_keymap_options["Home"] = { 0x02, 0x02, 0x4a };
	_keymap_options["PgUp"] = { 0x02, 0x02, 0x4b };
	_keymap_options["Delete"] = { 0x02, 0x02, 0x4c };
	_keymap_options["End"] = { 0x02, 0x02, 0x4d };
	_keymap_options["PgDown"] = { 0x02, 0x02, 0x4e };
	//numpad
	_keymap_options["Num_Slash"] = { 0x02, 0x02, 0x54 };
	_keymap_options["Num_Asterisk"] = { 0x02, 0x02, 0x55 };
	_keymap_options["Num_Minus"] = { 0x02, 0x02, 0x56 };
	_keymap_options["Num_Plus"] = { 0x02, 0x02, 0x57 };
	_keymap_options["Num_Return"] = { 0x02, 0x02, 0x58 };
	_keymap_options["Num_1"] = { 0x02, 0x02, 0x59 };
	_keymap_options["Num_2"] = { 0x02, 0x02, 0x5a };
	_keymap_options["Num_3"] = { 0x02, 0x02, 0x5b };
	_keymap_options["Num_4"] = { 0x02, 0x02, 0x5c };
	_keymap_options["Num_5"] = { 0x02, 0x02, 0x5d };
	_keymap_options["Num_6"] = { 0x02, 0x02, 0x5e };
	_keymap_options["Num_7"] = { 0x02, 0x02, 0x5f };
	_keymap_options["Num_8"] = { 0x02, 0x02, 0x60 };
	_keymap_options["Num_9"] = { 0x02, 0x02, 0x61 };
	_keymap_options["Num_0"] = { 0x02, 0x02, 0x62 };
	_keymap_options["Num_Period"] = { 0x02, 0x02, 0x63 };
	_keymap_options["Num_Lock"] = { 0x02, 0x02, 0x53 };
	//media controls, etc.
	_keymap_options["Mediaplayer"] = { 0x03, 0x83, 0x01 };
	_keymap_options["PlayPause"] = { 0x03, 0xcd, 0x00 };
	_keymap_options["Stop"] = { 0x03, 0xb7, 0x00 };
	_keymap_options["Previous"] = { 0x03, 0xb6, 0x00 };
	_keymap_options["Next"] = { 0x03, 0xb5, 0x00 };
	_keymap_options["Volume-"] = { 0x03, 0xea, 0x00 };
	_keymap_options["Volume+"] = { 0x03, 0xe9, 0x00 };
	_keymap_options["Mute"] = { 0x03, 0xe2, 0x00 };
	_keymap_options["BrowserHome"] = { 0x03, 0x23, 0x02 };
	_keymap_options["BrowserRefresh"] = { 0x03, 0x27, 0x02 };
	_keymap_options["BrowserStop"] = { 0x03, 0x26, 0x02 };
	_keymap_options["BrowserBack"] = { 0x03, 0x24, 0x02 };
	_keymap_options["BrowserForward"] = { 0x03, 0x25, 0x02 };
	_keymap_options["BrowserFavorite"] = { 0x03, 0x2a, 0x02 };
	_keymap_options["BrowserSearch"] = { 0x03, 0x21, 0x02 };
	_keymap_options["FileExplorer"] = { 0x03, 0x94, 0x01 };
	_keymap_options["Calculator"] = { 0x03, 0x92, 0x01 };
	_keymap_options["Email"] = { 0x03, 0x8a, 0x01 };
	//special keys
	_keymap_options["Lang1"] = { 0x02, 0x02, 0x90 };
	_keymap_options["Lang2"] = { 0x02, 0x02, 0x91 };
	_keymap_options["Lang3"] = { 0x02, 0x02, 0x92 };
	_keymap_options["Lang4"] = { 0x02, 0x02, 0x93 };
	_keymap_options["Lang5"] = { 0x02, 0x02, 0x94 };
	_keymap_options["Lang6"] = { 0x02, 0x02, 0x95 };
	_keymap_options["Lang7"] = { 0x02, 0x02, 0x96 };
	_keymap_options["Lang8"] = { 0x02, 0x02, 0x97 };
	_keymap_options["Lang9"] = { 0x02, 0x02, 0x98 };
	_keymap_options["F13"] = { 0x02, 0x02, 0x68 };
	_keymap_options["F14"] = { 0x02, 0x02, 0x69 };
	_keymap_options["F15"] = { 0x02, 0x02, 0x6a };
	_keymap_options["F16"] = { 0x02, 0x02, 0x6b };
	_keymap_options["F17"] = { 0x02, 0x02, 0x6c };
	_keymap_options["F18"] = { 0x02, 0x02, 0x6d };
	_keymap_options["F19"] = { 0x02, 0x02, 0x6e };
	_keymap_options["F20"] = { 0x02, 0x02, 0x6f };
	_keymap_options["F21"] = { 0x02, 0x02, 0x70 };
	_keymap_options["F22"] = { 0x02, 0x02, 0x71 };
	_keymap_options["F23"] = { 0x02, 0x02, 0x72 };
	_keymap_options["F24"] = { 0x02, 0x02, 0x73 };
}
