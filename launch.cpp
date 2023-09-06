
#include <ncurses.h>

#include "src/game/Game.h"


#define ROWS 20
#define COLS ROWS * 2.5


int main(){


    initscr();
    refresh();

    noecho();

    Game game(ROWS, COLS);

    while (!game.isOver()){

        game.processInput();

        game.updateState();

        game.redraw();
    }

    getch();
    endwin();


    return 0;
}