
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../board/Board.h"
#include "../apple/Apple.h"
#include "../empty/Empty.h"

class Game
{
    private:
        bool isGameOver;
        Board board;
        Apple *apple;
    protected:
    public:

    private:
    protected:
    public:
        Game(int height, int width);
        ~Game();
        void processInput();
        void updateState();
        void redraw();
        bool isOver();

};