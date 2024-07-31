#ifndef __CDL_tty
#define __CDL_tty

#define VGA_COLOR_BLACK     0
#define VGA_COLOR_BLUE      1
#define VGA_COLOR_GREEN     2
#define VGA_COLOR_CYAN      3
#define VGA_COLOR_RED       4
#define VGA_COLOR_MAGENTA   5
#define VGA_COLOR_BROWN     6
#define VGA_COLOR_LGREY     7
#define VGA_COLOR_DGREY     8
#define VGA_COLOR_LBLUE     9
#define VGA_COLOR_LGREEN    10
#define VGA_COLOR_LCYAN     11
#define VGA_COLOR_LRED      12
#define VGA_COLOR_LMAGENTA  13
#define VGA_COLOR_LBROWN    14
#define VGA_COLOR_WHITE     15
#define TTY_WIDTH 80
#define TTY_HEIGHT 25

#define VGA_BUFFER_HEAD 0xB8000

#define uint16 unsigned short
#define uint32 unsigned int

#define SET_TTY_THEME(x, y) (((x) << 4 | (y)) << 8)


void tty_set_theme(uint16 bg, uint16 fr);
void tty_set_default_theme();
void tty_put_char(char chr);
void tty_put_string(char* str);
void tty_scoll_up();
void tty_clear();

#endif