/* defines the hex code (and if the Shift key should be held)
* for all the "main" keyboard keys
*/


#ifndef __KEYS_H__
#define __KEYS_H__

/* Modifiers */
#define KEY_MOD_NONE	0x00
#define KEY_MOD_LCTRL	0x01
#define KEY_MOD_LSHIFT	0x02
#define KEY_MOD_LALT	0x04
#define KEY_MOD_LMETA	0x08
#define KEY_MOD_RCTRL	0x10
#define KEY_MOD_RSHIFT	0x20
#define KEY_MOD_RALT	0x40
#define KEY_MOD_RMETA	0x80

#define KEY_ESC		0x29 // Keyboard ESCAPE
#define KEY_ENTER	0x28 // Keyboard Return (ENTER)
#define KEY_TAB		0x2b // Keyboard Tab
#define KEY_BACKSPACE	0x2a // Keyboard DELETE (Backspace)
#define KEY_DELETE	0x4c // Keyboard Delete Forward
#define KEY_CAPSLOCK	0x39 // Keyboard Caps Lock
#define KEY_SCROLLLOCK	0x47 // Keyboard Scroll Lock
#define KEY_NUMLOCK	0x53 // Keyboard Num Lock and Clear
#define KEY_SYSRQ	0x46 // Keyboard Print Screen
#define KEY_F1		0x3a // Keyboard F1
#define KEY_F2		0x3b // Keyboard F2
#define KEY_F3		0x3c // Keyboard F3
#define KEY_F4		0x3d // Keyboard F4
#define KEY_F5		0x3e // Keyboard F5
#define KEY_F6		0x3f // Keyboard F6
#define KEY_F7		0x40 // Keyboard F7
#define KEY_F8		0x41 // Keyboard F8
#define KEY_F9		0x42 // Keyboard F9
#define KEY_F10		0x43 // Keyboard F10
#define KEY_F11		0x44 // Keyboard F11
#define KEY_F12		0x45 // Keyboard F12
#define KEY_HOME	0x4a // Keyboard Home
#define KEY_END		0x4d // Keyboard End
#define KEY_PAGEUP	0x4b // Keyboard Page Up
#define KEY_PAGEDOWN	0x4e // Keyboard Page Down
#define KEY_RIGHT	0x4f // Keyboard Right Arrow
#define KEY_LEFT	0x50 // Keyboard Left Arrow
#define KEY_DOWN	0x51 // Keyboard Down Arrow
#define KEY_UP		0x52 // Keyboard Up Arrow


struct Key {
	char modifier;
	char keytowrite;
	short unsigned int is_dead;
};

struct Keys {
	/* 0 - en_US */
	/* 1 - pt_PT */
	struct Key keys[2];
};

/* ['x'] = {KEY_MOD_NONE , ...} shift not held */
/* ['x'] = {KEY_MOD_LSHIFT , ...} shift held */
/* ['x'] = {KEY_MOD_RALT , ...} ralt held */

struct Keys layout[] = {
	/* Majuscule letters */
	['A'] = {
			{
				{KEY_MOD_LSHIFT, 0x04, 0},
				{KEY_MOD_LSHIFT, 0x04, 0},
			}
		},
	['B'] = {
			{
				{KEY_MOD_LSHIFT, 0x05, 0},
				{KEY_MOD_LSHIFT, 0x05, 0},
			}
		},
	['C'] = {
			{
				{KEY_MOD_LSHIFT, 0x06, 0},
				{KEY_MOD_LSHIFT, 0x06, 0},
			}
		},
	['D'] = {
			{
				{KEY_MOD_LSHIFT, 0x07, 0},
				{KEY_MOD_LSHIFT, 0x07, 0},
			}
		},
	['E'] = {
			{
				{KEY_MOD_LSHIFT, 0x08, 0},
				{KEY_MOD_LSHIFT, 0x08, 0},
			}
		},
	['F'] = {
			{
				{KEY_MOD_LSHIFT, 0x09, 0},
				{KEY_MOD_LSHIFT, 0x09, 0},
			}
		},
	['G'] = {
			{
				{KEY_MOD_LSHIFT, 0x0a, 0},
				{KEY_MOD_LSHIFT, 0x0a, 0},
			}
		},
	['H'] = {
			{
				{KEY_MOD_LSHIFT, 0x0b, 0},
				{KEY_MOD_LSHIFT, 0x0b, 0},
			}
		},
	['I'] = {
			{
				{KEY_MOD_LSHIFT, 0x0c, 0},
				{KEY_MOD_LSHIFT, 0x0c, 0},
			}
		},
	['J'] = {
			{
				{KEY_MOD_LSHIFT, 0x0d, 0},
				{KEY_MOD_LSHIFT, 0x0d, 0},
			}
		},
	['K'] = {
			{
				{KEY_MOD_LSHIFT, 0x0e, 0},
				{KEY_MOD_LSHIFT, 0x0e, 0},
			}
		},
	['L'] = {
			{
				{KEY_MOD_LSHIFT, 0x0f, 0},
				{KEY_MOD_LSHIFT, 0x0f, 0},
			}
		},
	['M'] = {
			{
				{KEY_MOD_LSHIFT, 0x10, 0},
				{KEY_MOD_LSHIFT, 0x10, 0},
			}
		},
	['N'] = {
			{
				{KEY_MOD_LSHIFT, 0x11, 0},
				{KEY_MOD_LSHIFT, 0x11, 0},
			}
		},
	['O'] = {
			{
				{KEY_MOD_LSHIFT, 0x12, 0},
				{KEY_MOD_LSHIFT, 0x12, 0},
			}
		},
	['P'] = {
			{
				{KEY_MOD_LSHIFT, 0x13, 0},
				{KEY_MOD_LSHIFT, 0x13, 0},
			}
		},
	['Q'] = {
			{
				{KEY_MOD_LSHIFT, 0x14, 0},
				{KEY_MOD_LSHIFT, 0x14, 0},
			}
		},
	['R'] = {
			{
				{KEY_MOD_LSHIFT, 0x15, 0},
				{KEY_MOD_LSHIFT, 0x15, 0},
			}
		},
	['S'] = {
			{
				{KEY_MOD_LSHIFT, 0x16, 0},
				{KEY_MOD_LSHIFT, 0x16, 0},
			}
		},
	['T'] = {
			{
				{KEY_MOD_LSHIFT, 0x17, 0},
				{KEY_MOD_LSHIFT, 0x17, 0},
			}
		},
	['U'] = {
			{
				{KEY_MOD_LSHIFT, 0x18, 0},
				{KEY_MOD_LSHIFT, 0x18, 0},
			}
		},
	['V'] = {
			{
				{KEY_MOD_LSHIFT, 0x19, 0},
				{KEY_MOD_LSHIFT, 0x19, 0},
			}
		},
	['W'] = {
			{
				{KEY_MOD_LSHIFT, 0x1a, 0},
				{KEY_MOD_LSHIFT, 0x1a, 0},
			}
		},
	['X'] = {
			{
				{KEY_MOD_LSHIFT, 0x1b, 0},
				{KEY_MOD_LSHIFT, 0x1b, 0},
			}
		},
	['Y'] = {
			{
				{KEY_MOD_LSHIFT, 0x1c, 0},
				{KEY_MOD_LSHIFT, 0x1c, 0},
			}
		},
	['Z'] = {
			{
				{KEY_MOD_LSHIFT, 0x1d, 0},
				{KEY_MOD_LSHIFT, 0x1d, 0},
			}
		},

	/* Minuscule Letters */
	['a'] = {
			{
				{KEY_MOD_NONE,	  0x04, 0},
				{KEY_MOD_NONE,	  0x04, 0},
			}
		},
	['b'] = {
			{
				{KEY_MOD_NONE,   0x05, 0},
				{KEY_MOD_NONE,   0x05, 0},
			}
		},
	['c'] = {
			{
				{KEY_MOD_NONE,   0x06, 0},
				{KEY_MOD_NONE,   0x06, 0},
			}
		},
	['d'] = {
			{
				{KEY_MOD_NONE,   0x07, 0},
				{KEY_MOD_NONE,   0x07, 0},
			}
		},
	['e'] = {
			{
				{KEY_MOD_NONE,   0x08, 0},
				{KEY_MOD_NONE,   0x08, 0},
			}
		},
	['f'] = {
			{
				{KEY_MOD_NONE,   0x09, 0},
				{KEY_MOD_NONE,   0x09, 0},
			}
		},
	['g'] = {
			{
				{KEY_MOD_NONE,   0x0a, 0},
				{KEY_MOD_NONE,   0x0a, 0},
			}
		},
	['h'] = {
			{
				{KEY_MOD_NONE,   0x0b, 0},
				{KEY_MOD_NONE,   0x0b, 0},
			}
		},
	['i'] = {
			{
				{KEY_MOD_NONE,   0x0c, 0},
				{KEY_MOD_NONE,   0x0c, 0},
			}
		},
	['j'] = {
			{
				{KEY_MOD_NONE,   0x0d, 0},
				{KEY_MOD_NONE,   0x0d, 0},
			}
		},
	['k'] = {
			{
				{KEY_MOD_NONE,   0x0e, 0},
				{KEY_MOD_NONE,   0x0e, 0},
			}
		},
	['l'] = {
			{
				{KEY_MOD_NONE,   0x0f, 0},
				{KEY_MOD_NONE,   0x0f, 0},
			}
		},
	['m'] = {
			{
				{KEY_MOD_NONE,   0x10, 0},
				{KEY_MOD_NONE,   0x10, 0},
			}
		},
	['n'] = {
			{
				{KEY_MOD_NONE,   0x11, 0},
				{KEY_MOD_NONE,   0x11, 0},
			}
		},
	['o'] = {
			{
				{KEY_MOD_NONE,   0x12, 0},
				{KEY_MOD_NONE,   0x12, 0},
			}
		},
	['p'] = {
			{
				{KEY_MOD_NONE,   0x13, 0},
				{KEY_MOD_NONE,   0x13, 0},
			}
		},
	['q'] = {
			{
				{KEY_MOD_NONE,   0x14, 0},
				{KEY_MOD_NONE,   0x14, 0},
			}
		},
	['r'] = {
			{
				{KEY_MOD_NONE,   0x15, 0},
				{KEY_MOD_NONE,   0x15, 0},
			}
		},
	['s'] = {
			{
				{KEY_MOD_NONE,   0x16, 0},
				{KEY_MOD_NONE,   0x16, 0},
			}
		},
	['t'] = {
			{
				{KEY_MOD_NONE,   0x17, 0},
				{KEY_MOD_NONE,   0x17, 0},
			}
		},
	['u'] = {
			{
				{KEY_MOD_NONE,   0x18, 0},
				{KEY_MOD_NONE,   0x18, 0},
			}
		},
	['v'] = {
			{
				{KEY_MOD_NONE,   0x19, 0},
				{KEY_MOD_NONE,   0x19, 0},
			}
		},
	['w'] = {
			{
				{KEY_MOD_NONE,   0x1a, 0},
				{KEY_MOD_NONE,   0x1a, 0},
			}
		},
	['x'] = {
			{
				{KEY_MOD_NONE,   0x1b, 0},
				{KEY_MOD_NONE,   0x1b, 0},
			}
		},
	['y'] = {
			{
				{KEY_MOD_NONE,   0x1c, 0},
				{KEY_MOD_NONE,   0x1c, 0},
			}
		},
	['z'] = {
			{
				{KEY_MOD_NONE,   0x1d, 0},
				{KEY_MOD_NONE,   0x1d, 0},
			}
		},

	/* Number Row */
	['1'] = {
			{
				{KEY_MOD_NONE,	 0x1e, 0},
				{KEY_MOD_NONE,   0x1e, 0},
			}
		},
        ['!'] = {
			{
				{KEY_MOD_LSHIFT, 0x1e, 0},
				{KEY_MOD_LSHIFT, 0x1e, 0},
			}
		},
        ['2'] = {
			{
				{KEY_MOD_NONE,   0x1f, 0},
				{KEY_MOD_NONE,   0x1f, 0},
			}
		},
        ['"'] = {
			{
				{KEY_MOD_LSHIFT, 0x34, 0},
				{KEY_MOD_LSHIFT, 0x1f, 0},
			}
		},
        ['@'] = {
			{
				{KEY_MOD_LSHIFT, 0x1f, 0},
				{KEY_MOD_RALT,   0x1f, 0},
			}
		},
        ['3'] = {
			{
				{KEY_MOD_NONE,   0x20, 0},
				{KEY_MOD_NONE,   0x20, 0},
			}
		},
        ['#'] = {
			{
				{KEY_MOD_LSHIFT, 0x20, 0},
				{KEY_MOD_LSHIFT, 0x20, 0},
			}
		},
        ['4'] = {
			{
				{KEY_MOD_NONE,   0x21, 0},
				{KEY_MOD_NONE,   0x21, 0},
			}
		},
        ['$'] = {
			{
				{KEY_MOD_LSHIFT, 0x21, 0},
				{KEY_MOD_LSHIFT, 0x21, 0},
			}
		},
        ['5'] = {
			{
				{KEY_MOD_NONE,   0x22, 0},
				{KEY_MOD_NONE,   0x22, 0},
			}
		},
        ['%'] = {
			{
				{KEY_MOD_LSHIFT, 0x22, 0},
				{KEY_MOD_LSHIFT, 0x22, 0},
			}
		},
        ['6'] = {
			{
				{KEY_MOD_NONE,   0x23, 0},
				{KEY_MOD_NONE,   0x23, 0},
			}
		},
        ['&'] = {
			{
				{KEY_MOD_LSHIFT, 0x24, 0},
				{KEY_MOD_LSHIFT, 0x23, 0},
			}
		},
        ['7'] = {
			{
				{KEY_MOD_NONE,   0x24, 0},
				{KEY_MOD_NONE,   0x24, 0},
			}
		},
        ['/'] = {
			{
				{KEY_MOD_NONE,   0x38, 0},
				{KEY_MOD_LSHIFT, 0x24, 0},
			}
		},
        ['{'] = {
			{
				{KEY_MOD_LSHIFT, 0x2f, 0},
				{KEY_MOD_RALT,   0x24, 0},
			}
		},
        ['8'] = {
			{
				{KEY_MOD_NONE,   0x25, 0},
				{KEY_MOD_NONE,   0x25, 0},
			}
		},
        ['('] = {
			{
				{KEY_MOD_LSHIFT, 0x26, 0},
				{KEY_MOD_LSHIFT, 0x25, 0},
			}
		},
        ['['] = {
			{
				{KEY_MOD_NONE,   0x2f, 0},
				{KEY_MOD_RALT,   0x25, 0},
			}
		},
        ['9'] = {
			{
				{KEY_MOD_NONE,   0x26, 0},
				{KEY_MOD_NONE,   0x26, 0},
			}
		},
        [')'] = {
			{
				{KEY_MOD_LSHIFT, 0x27, 0},
				{KEY_MOD_LSHIFT, 0x26, 0},
			}
		},
        [']'] = {
			{
				{KEY_MOD_NONE,   0x30, 0},
				{KEY_MOD_RALT,   0x26, 0},
			}
		},
        ['0'] = {
			{
				{KEY_MOD_NONE,   0x27, 0},
				{KEY_MOD_NONE,   0x27, 0},
			}
		},
        ['='] = {
			{
				{KEY_MOD_NONE,   0x2e, 0},
				{KEY_MOD_LSHIFT, 0x27, 0},
			}
		},
        ['}'] = {
			{
				{KEY_MOD_LSHIFT, 0x30, 0},
				{KEY_MOD_RALT,   0x27, 0},
			}
		},

	/* Other */
	[' '] = {
			{
				{KEY_MOD_NONE,   0x2c, 0},
				{KEY_MOD_NONE,   0x2c, 0},
			}
		},
	['\'']= {
			{
				{KEY_MOD_NONE,   0x34, 0},
				{KEY_MOD_NONE,   0x2d, 0},
			}
		},
	['?'] = {
			{
				{KEY_MOD_LSHIFT, 0x38, 0},
				{KEY_MOD_LSHIFT, 0x2d, 0},
			}
		},
	//['«'] = {KEY_MOD_NONE,   0x2e, 0},
	//['»'] = {KEY_MOD_LSHIFT, 0x2e, 0},
	['+'] = {
			{
				{KEY_MOD_LSHIFT, 0x2e, 0},
				{KEY_MOD_NONE,   0x2f, 0},
			}
		},
	['*'] = {
			{
				{KEY_MOD_LSHIFT, 0x25, 0},
				{KEY_MOD_LSHIFT, 0x2f, 0},
			}
		},
	//['´'] = {KEY_MOD_NONE,   0x30, 0},
	['`'] = {
			{
				{KEY_MOD_NONE,   0x35, 0},
				{KEY_MOD_LSHIFT, 0x30, 1},
			}
		},
	['~'] = {
			{
				{KEY_MOD_LSHIFT, 0x35, 0},
				{KEY_MOD_NONE,   0x31, 1},
			}
		},
	['^'] = {
			{
				{KEY_MOD_LSHIFT, 0x23, 0},
				{KEY_MOD_LSHIFT, 0x31, 1},
			}
		},
	//['º'] = {KEY_MOD_NONE,   0x34, 0},
	//['ª'] = {KEY_MOD_LSHIFT, 0x34, 0},
	['\\']= {
			{
				{KEY_MOD_NONE,   0x31, 0},
				{KEY_MOD_NONE,   0x35, 0},
			}
		},
	['|'] = {
			{
				{KEY_MOD_LSHIFT, 0x31, 0},
				{KEY_MOD_LSHIFT, 0x35, 0},
			}
		},
	//['¬'] = {KEY_MOD_RALT,   0x35, 0},
	[','] = {
			{
				{KEY_MOD_NONE,   0x36, 0},
				{KEY_MOD_NONE,   0x36, 0},
			}
		},
	[';'] = {
			{
				{KEY_MOD_NONE,   0x33, 0},
				{KEY_MOD_LSHIFT, 0x36, 0},
			}
		},
	['.'] = {
			{
				{KEY_MOD_NONE,   0x37, 0},
				{KEY_MOD_NONE,   0x37, 0},
			}
		},
	[':'] = {
			{
				{KEY_MOD_LSHIFT, 0x33, 0},
				{KEY_MOD_LSHIFT, 0x37, 0},
			}
		},
	//['·'] = {KEY_MOD_RALT,   0x37, 0},
	['-'] = {
			{
				{KEY_MOD_NONE,   0x2d, 0},
				{KEY_MOD_NONE,   0x38, 0},
			}
		},
	['_'] = {
			{
				{KEY_MOD_LSHIFT, 0x2d, 0},
				{KEY_MOD_LSHIFT, 0x38, 0},
			}
		},
	['<'] = {
			{
				{KEY_MOD_LSHIFT, 0x36, 0},
				{KEY_MOD_NONE,   0x64, 0},
			}
		},
	['>'] = {
			{
				{KEY_MOD_LSHIFT, 0x37, 0},
				{KEY_MOD_LSHIFT, 0x64, 0},

			}
		}
	};

#endif
