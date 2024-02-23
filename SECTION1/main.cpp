#include <defs.h>
#include <iostream>

int main(void) {
    
    initscr();
    raw();
    noecho();

    printw("ncurses test\n");
    getch();

    endwin();

    return 0;
}