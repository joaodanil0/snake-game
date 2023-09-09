#include "Game.h"

Game::Game(int width, int height, int speed)
{
    this->board = Board(width, height, speed);
    
    int scoreBoardRow = this->board.getStartRow() + height;
    int scoreBoardCol = this->board.getStartCol();

    this->scoreBoard = ScoreBoard(width, scoreBoardCol, scoreBoardRow);
    this->initialize();

}

Game::~Game()
{
    delete this->apple;
}

void Game::initialize()
{
    this->board.initialize();

    this->scoreBoard.initialize(this->score);
    this->isGameOver = false;

    srand(time(NULL));

    handleNextPiece(SnakePiece(14, 2));
    handleNextPiece(this->snake.nextHead());
    handleNextPiece(this->snake.nextHead());
    handleNextPiece(this->snake.nextHead());

    this->snake.setDirection(Snake::RIGHT);

    handleNextPiece(this->snake.nextHead());

    if (this->apple == NULL)
        this->createApple();
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
                this->eatApple();
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

void Game::eatApple()
{
    delete this->apple;
    this->apple = NULL;
    this->score += 100;
    this->scoreBoard.updateScore(this->score);
    this->board.increaseSpeed();
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
            //! Tutorial 09 - 11:45
            //! Tutorial 13 - 03:59
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
    this->scoreBoard.refresh();
}

bool Game::isOver()
{
    return this->isGameOver;
}

int Game::getScore()
{
    return this->score;
}
