#include "Game.h"


Game::Game(int height, int width)
{
    this->board = Board(height, width);
    this->board.initialize();
    this->isGameOver = false;
}

void Game::processInput()
{
    chtype input = this->board.getInput();

}

void Game::updateState()
{
    
}

void Game::redraw()
{
    this->board.refresh();
}

bool Game::isOver()
{
    return this->isGameOver;
}
