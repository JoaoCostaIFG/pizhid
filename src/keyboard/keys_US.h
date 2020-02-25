/* defines the hex code (and if the Shift key should be held)
* for all the "main" keyboard keys
*/


#ifndef __KEYS_H__
#define __KEYS_H__

#define KEY_MOD_LCTRL  0x01
#define KEY_MOD_LSHIFT 0x02
#define KEY_MOD_LALT   0x04
#define KEY_MOD_LMETA  0x08
#define KEY_MOD_RCTRL  0x10
#define KEY_MOD_RSHIFT 0x20
#define KEY_MOD_RALT   0x40
#define KEY_MOD_RMETA  0x80

#define KEY_ENTER 0x28 // Keyboard Return (ENTER)
#define KEY_ESC 0x29 // Keyboard ESCAPE
#define KEY_BACKSPACE 0x2a // Keyboard DELETE (Backspace)
#define KEY_TAB 0x2b // Keyboard Tab
#define KEY_CAPSLOCK 0x39 // Keyboard Caps Lock
#define KEY_F1 0x3a // Keyboard F1
#define KEY_F2 0x3b // Keyboard F2
#define KEY_F3 0x3c // Keyboard F3
#define KEY_F4 0x3d // Keyboard F4
#define KEY_F5 0x3e // Keyboard F5
#define KEY_F6 0x3f // Keyboard F6
#define KEY_F7 0x40 // Keyboard F7
#define KEY_F8 0x41 // Keyboard F8
#define KEY_F9 0x42 // Keyboard F9
#define KEY_F10 0x43 // Keyboard F10
#define KEY_F11 0x44 // Keyboard F11
#define KEY_F12 0x45 // Keyboard F12
#define KEY_SYSRQ 0x46 // Keyboard Print Screen
#define KEY_SCRLOCK 0x47 // Keyboard Scroll Lock


struct Pair {
	char modifier;
	char keytowrite;
};

/* ['x'] = {'\0' , ...} shift not held */
/* ['x'] = {0x02 , ...} shift held */

struct Pair key_list[] = {
	['A'] = {0x02, 0x04},
	['B'] = {0x02, 0x05},
	['C'] = {0x02, 0x06},
	['D'] = {0x02, 0x07},
	['E'] = {0x02, 0x08},
	['F'] = {0x02, 0x09},
	['G'] = {0x02, 0x0a},
	['H'] = {0x02, 0x0b},
	['I'] = {0x02, 0x0c},
	['J'] = {0x02, 0x0d},
	['K'] = {0x02, 0x0e},
	['L'] = {0x02, 0x0f},
	['M'] = {0x02, 0x10},
	['N'] = {0x02, 0x11},
	['O'] = {0x02, 0x12},
	['P'] = {0x02, 0x13},
	['Q'] = {0x02, 0x14},
	['R'] = {0x02, 0x15},
	['S'] = {0x02, 0x16},
	['T'] = {0x02, 0x17},
	['U'] = {0x02, 0x18},
	['V'] = {0x02, 0x19},
	['W'] = {0x02, 0x1a},
	['X'] = {0x02, 0x1b},
	['Y'] = {0x02, 0x1c},
	['Z'] = {0x02, 0x1d},

	['a'] = {'\0', 0x04},
	['b'] = {'\0', 0x05},
	['c'] = {'\0', 0x06},
	['d'] = {'\0', 0x07},
	['e'] = {'\0', 0x08},
	['f'] = {'\0', 0x09},
	['g'] = {'\0', 0x0a},
	['h'] = {'\0', 0x0b},
	['i'] = {'\0', 0x0c},
	['j'] = {'\0', 0x0d},
	['k'] = {'\0', 0x0e},
	['l'] = {'\0', 0x0f},
	['m'] = {'\0', 0x10},
	['n'] = {'\0', 0x11},
	['o'] = {'\0', 0x12},
	['p'] = {'\0', 0x13},
	['q'] = {'\0', 0x14},
	['r'] = {'\0', 0x15},
	['s'] = {'\0', 0x16},
	['t'] = {'\0', 0x17},
	['u'] = {'\0', 0x18},
	['v'] = {'\0', 0x19},
	['w'] = {'\0', 0x1a},
	['x'] = {'\0', 0x1b},
	['y'] = {'\0', 0x1c},
	['z'] = {'\0', 0x1d},

	['1'] = {'\0', 0x1e},
	['!'] = {0x02, 0x1e},
	['2'] = {'\0', 0x1f},
	['@'] = {0x02, 0x1f},
	['3'] = {'\0', 0x20},
	['#'] = {0x02, 0x20},
	['4'] = {'\0', 0x21},
	['$'] = {0x02, 0x21},
	['5'] = {'\0', 0x22},
	['%'] = {0x02, 0x22},
	['6'] = {'\0', 0x23},
	['^'] = {0x02, 0x23},
	['7'] = {'\0', 0x24},
	['&'] = {0x02, 0x24},
	['8'] = {'\0', 0x25},
	['*'] = {0x02, 0x25},
	['9'] = {'\0', 0x26},
	['('] = {0x02, 0x26},
	['0'] = {'\0', 0x27},
	[')'] = {0x02, 0x27},

	[' '] = {'\0', 0x2c},
	['-'] = {'\0', 0x2d},
	['_'] = {0x02, 0x2d},
	['='] = {'\0', 0x2e},
	['+'] = {0x02, 0x2e},
	['['] = {'\0', 0x2f},
	['{'] = {0x02, 0x2f},
	[']'] = {'\0', 0x30},
	['}'] = {0x02, 0x30},
	['\\']= {'\0', 0x31},
	['|'] = {0x02, 0x31},
	//['#'] = {'\0', 0x32},
	//['~'] = {0x02, 0x32},
	[';'] = {'\0', 0x33},
	[':'] = {0x02, 0x33},
	['\'']= {'\0', 0x34},
	['"'] = {0x02, 0x34},
	['`'] = {'\0', 0x35},
	['~'] = {0x02, 0x35},
	[','] = {'\0', 0x36},
	['<'] = {0x02, 0x36},
	['.'] = {'\0', 0x37},
	['>'] = {0x02, 0x37},
	['/'] = {'\0', 0x38},
	['?'] = {0x02, 0x38}
};


#endif
