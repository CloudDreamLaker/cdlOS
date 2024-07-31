#ifndef __CDL_tty_c
#define __CDL_tty_c

#include "cdl/tty/tty.h"

uint16 *buffer = VGA_BUFFER_HEAD;

const uint16 _bg = VGA_COLOR_BLACK;
const uint16 _fr = VGA_COLOR_WHITE;


uint16 tty_theme = SET_TTY_THEME(_bg, _fr);
uint32 tty_column = 0;
uint32 tty_row = 0;

void tty_set_theme(uint16 bg, uint16 fr) {
    tty_theme = SET_TTY_THEME(bg, fr);
}

void tty_set_default_theme() {
    tty_theme = SET_TTY_THEME(_bg, _fr);
}

void tty_put_char(char chr) {
    uint16 attr = tty_theme | chr;
    *(buffer + tty_column + tty_row * TTY_WIDTH) = attr;

    // move to nxt char
    tty_column++;
    if(tty_column >= TTY_WIDTH) {
        tty_column = 0;
        tty_row++;
        if(tty_row >= TTY_HEIGHT) {
            tty_scoll_up();
            tty_row--;
        }
    }
}

void tty_put_string(char* str) {
    while(*str != '\0') {
        tty_put_char(*str);
        str++;
    }
}

void tty_scoll_up() {
    // TODO(cdl): [depend] memcpy
}

void tty_clear() {
    for(uint32 x = 0; x < TTY_HEIGHT; x++) {
        for(uint32 y = 0; y < TTY_WIDTH; y++) {
            *(buffer + x * TTY_WIDTH + y) = tty_theme;
        }
    }
}

#endif