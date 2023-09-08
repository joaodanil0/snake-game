#include "SnakePiece.h"

SnakePiece::SnakePiece()
{
    this->x = 0;
    this->y = 0;
    this->character = '#';
}

SnakePiece::SnakePiece(int x, int y, chtype character)
{
    this->x = x;
    this->y = y;
    this->character = character;
}
