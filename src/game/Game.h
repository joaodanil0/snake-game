
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../board/Board.h"
#include "../apple/Apple.h"
#include "../empty/Empty.h"
#include "../snake/Snake.h"
#include "../scoreboard/ScoreBoard.h"

class Game
{
    private:
        bool isGameOver;
        Board board;
        Apple *apple = NULL;
        Snake snake;
        ScoreBoard scoreBoard;
        int score = 0;
    protected:
    public:

    private:
        void initialize();
        void createApple();
        void handleNextPiece(SnakePiece piece);
        void eatApple();
    protected:
    public:
        Game(int width, int height, int speed = 300);
        ~Game();
        void processInput();
        void updateState();
        void redraw();
        bool isOver();
        int getScore();

};