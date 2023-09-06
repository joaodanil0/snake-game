
#include <ncurses.h>

#include "../board/Board.h"

class Game{

    private:
        bool isGameOver;
        Board board;
    protected:
    public:

    private:
    protected:
    public:
        Game(int height, int width);
        void processInput();
        void updateState();
        void redraw();
        bool isOver();

};