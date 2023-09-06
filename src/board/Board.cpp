#include "Board.h"

Board::Board()
{
    this->contruct(0, 0);
}

Board::Board(int height, int width)
{
    this->contruct(height, width);
}

void Board::addBorder()
{
    box(this->boardWindow, 0, 0);
}

void Board::clear()
{
    wclear(this->boardWindow);
    this->addBorder();
}

void Board::refresh()
{
    wrefresh(this->boardWindow);
}

void Board::initialize()
{
    this->clear();
    this->refresh();
}

void Board::addCharacterAt(int x, int y, chtype character)
{
    mvwaddch(this->boardWindow, y, x, character);
}

chtype Board::getInput()
{
    return wgetch(this->boardWindow);
}

void Board::add(Drawable drawable)
{
    this->addCharacterAt(drawable.getX(), drawable.getY(), drawable.getCharacter());
}

void Board::getEmptyCoordinates(int &x, int &y)
{
    while( ( mvwinch(this->boardWindow, 
                        y = rand() % this->height,
                        x = rand() % this->width)) != ' ');
}

void Board::contruct(int height, int width)
{
    int xMax;
    int yMax;

    this->height = height;
    this->width = width;

    getmaxyx(stdscr, yMax, xMax);

    this->boardWindow = newwin(height, width,
                                (yMax / 2) - (height / 2),
                                (xMax / 2) - (width / 2));
}