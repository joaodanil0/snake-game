#include "Game.h"



Game::Game(int width, int height)
{
    this->board = Board(width, height);
    this->initialize();

    SnakePiece piece = SnakePiece(14, 5);
    this->board.add(piece);
    this->snake.addPiece(piece);

    piece = this->snake.nextHead();
    this->board.add(piece);
    this->snake.addPiece(piece);

    piece = this->snake.nextHead();
    this->board.add(piece);
    this->snake.addPiece(piece);

    this->snake.setDirection(Snake::RIGHT);

    piece = this->snake.nextHead();
    this->board.add(piece);
    this->snake.addPiece(piece);

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

    if (this->apple == NULL)
    {
        int x, y;
        this->board.getEmptyCoordinates(x, y);
        apple = new Apple(x, y);
        this->board.add(*apple);
    }

    SnakePiece piece = snake.nextHead();

    if (piece.getX() != this->apple->getX() &&
        piece.getY() != this->apple->getY())
    {
            int emptyCol = snake.tail().getX();
            int emptyRow = snake.tail().getY();

            this->board.add(Empty(emptyCol, emptyRow));
            this->snake.removePiece();
    }

    this->board.add(piece);
    this->snake.addPiece(piece);

    
}

void Game::redraw()
{
    this->board.refresh();
}

bool Game::isOver()
{
    return this->isGameOver;
}
