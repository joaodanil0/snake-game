#include "Drawable.h"

Drawable::Drawable()
{
    this->x = 0;
    this->y = 0;
    this->character = ' ';
}

Drawable::Drawable(int x, int y, chtype character)
{
    this->x = x;
    this->y = y;
    this->character = character;
}

int Drawable::getX()
{
    return this->x;
}

int Drawable::getY()
{
    return this->y;
}

chtype Drawable::getCharacter()
{
    return this->character;
}
