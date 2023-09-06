
#include <ncurses.h>

#include "src/board/Board.h"


#define ROWS 20
#define COLS ROWS * 2.5


int main(){


    initscr();
    refresh();

    Board board(ROWS, COLS);
    board.initialize();
    getch();
    endwin();


    return 0;
}