
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../board/Board.h"
#include "../apple/Apple.h"
#include "../empty/Empty.h"
#include "../snake/Snake.h"

class Game
{
    private:
        bool isGameOver;
        Board board;
        Apple *apple = NULL;
        Snake snake;
    protected:
    public:

    private:
        void initialize();
        void createApple();
        void handleNextPiece(SnakePiece piece);
        void destroyApple();
    protected:
    public:
        Game(int width, int height);
        ~Game();
        void processInput();
        void updateState();
        void redraw();
        bool isOver();

};