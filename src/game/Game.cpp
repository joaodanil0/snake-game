#include "Game.h"



Game::Game(int width, int height)
{
    this->board = Board(width, height);
    this->initialize();

    handleNextPiece(SnakePiece(14, 2));
    handleNextPiece(this->snake.nextHead());
    handleNextPiece(this->snake.nextHead());
    handleNextPiece(this->snake.nextHead());

    this->snake.setDirection(Snake::RIGHT);

    handleNextPiece(this->snake.nextHead());

    if (this->apple == NULL)
        this->createApple();
}

Game::~Game()
{
    delete this->apple;
}

void Game::initialize()
{
    this->board.initialize();
    this->isGameOver = false;

    srand(time(NULL));
}

void Game::createApple()
{
    int x, y;
    this->board.getEmptyCoordinates(x, y);
    apple = new Apple(x, y);
    this->board.add(*apple);
}

void Game::handleNextPiece(SnakePiece piece)
{
    if (this->apple != NULL)
    {
        switch (this->board.getCharacterAt(piece.getX(), piece.getY()))
        {
            case 'A':
                this->destroyApple();
                break;
            case ' ':
            {
                int emptyCol = snake.tail().getX();
                int emptyRow = snake.tail().getY();

                this->board.add(Empty(emptyCol, emptyRow));
                this->snake.removePiece();
                break;
            }
            default:
                this->isGameOver = true;
                break;
        }
    }
    
    this->board.add(piece);
    this->snake.addPiece(piece);

}

void Game::destroyApple()
{
    delete this->apple;
    this->apple = NULL;
}

void Game::processInput()
{
    chtype input = this->board.getInput();

    switch (input)
    {
        case KEY_UP:
            this->snake.setDirection(Snake::UP);
            break;
        case KEY_DOWN:
            this->snake.setDirection(Snake::DOWN);
            break;
        case KEY_LEFT:
            this->snake.setDirection(Snake::LEFT);
            break;
        case KEY_RIGHT:
            this->snake.setDirection(Snake::RIGHT);
            break;
        case 'p':
            //! board.setTimeout not implemented 
            //! Tutorial 9 - 11:45
            while (board.getInput() != 'p');
            break;
        default:
            break;
    }
}

void Game::updateState()
{   

    this->handleNextPiece(this->snake.nextHead());
   
    if (this->apple == NULL)
        this->createApple();
}

void Game::redraw()
{
    this->board.refresh();
}

bool Game::isOver()
{
    return this->isGameOver;
}
