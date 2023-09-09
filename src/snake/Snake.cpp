#include "Snake.h"

void Snake::addPiece(SnakePiece piece)
{
    this->previousPiece.push(piece);
}

void Snake::removePiece()
{
    this->previousPiece.pop();
}

SnakePiece Snake::tail()
{
    return this->previousPiece.front();
}

SnakePiece Snake::head()
{
    return this->previousPiece.back();
}

Snake::Direction Snake::getDirection()
{
    return this->currentDirection;
}

void Snake::setDirection(Direction direction)
{
    if (this->currentDirection + direction)
        this->currentDirection = direction;
}

SnakePiece Snake::nextHead()
{
    //! This logic is confusing
    int col = this->head().getX();
    int row = this->head().getY();

    switch (this->currentDirection)
    {
    case DOWN:
        row++;
        break;
    case UP:
        row--;
        break;
    case LEFT:
        col--;
        break;
    case RIGHT:
        col++;
        break;
    
    default:
        break;
    }

    return SnakePiece(col, row);
}
