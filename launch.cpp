
#include <iostream>
#include <ncurses.h>

#include "src/game/Game.h"


#define COLS 30 // X
#define ROWS 10 // Y



int main(){


    initscr();
    refresh();
    noecho();
    curs_set(0);

    //* Print example
    printw("This is an example of print: ");
    printw("col: %d | row: %d\n", 1, 1);
    refresh();
    //* end Print example

    Game game(COLS, ROWS);

    while (!game.isOver()){

        game.processInput();

        game.updateState();

        game.redraw();
    }

    endwin();
    
    std::cout << "Game Over" << std::endl;
    


    return 0;
}