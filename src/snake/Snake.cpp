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
    return this->previousPiece.back();
}

SnakePiece Snake::head()
{
    return this->previousPiece.front();
}
