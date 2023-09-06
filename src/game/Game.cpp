#include "Game.h"


Game::Game(int height, int width)
{
    this->board = Board(height, width);
    this->board.initialize();
    this->isGameOver = false;

    srand(time(NULL));
}

Game::~Game()
{
    delete this->apple;
}

void Game::processInput()
{
    chtype input = this->board.getInput();
}

void Game::updateState()
{   
    int x, y;
    
    this->board.getEmptyCoordinates(x, y);

    if(this->apple != NULL)
        this->board.add(Empty(apple->getX(), apple->getY()));
    apple = new Apple(x, y);
    this->board.add(*apple);
    this->board.add(Drawable(3, 3, '#'));
}

void Game::redraw()
{
    this->board.refresh();
}

bool Game::isOver()
{
    return this->isGameOver;
}
