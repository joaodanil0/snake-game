
#include <queue>

#include "SnakePiece.h"

class Snake
{
public:
    enum Direction
    {
        UP = -1,
        DOWN = 1,
        LEFT = -2,
        RIGHT = 2
    };

private:
    std::queue<SnakePiece> previousPiece;
    Direction currentDirection = DOWN;

public:
    void addPiece(SnakePiece piece);
    void removePiece();
    SnakePiece tail();
    SnakePiece head();
    Direction getDirection();
    void setDirection(Direction direction);
    SnakePiece nextHead();
};