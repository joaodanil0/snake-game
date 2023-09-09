#include "Board.h"

Board::Board()
{
    this->contruct(0, 0, 300);
}

Board::Board(int width, int height, int speed)
{
    this->contruct(width, height, speed);
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
    time_t timeLastInput = Time::milliseconds();

    chtype input = wgetch(this->boardWindow);
    chtype newInput = ERR;

    wtimeout(this->boardWindow, 0);
    while (timeLastInput + this->speed >= Time::milliseconds())
    {
        newInput = wgetch(this->boardWindow);
    }
    wtimeout(this->boardWindow, this->speed);

    if (newInput != ((chtype) ERR))
        input = newInput;

    return input;
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

chtype Board::getCharacterAt(int x, int y)
{
    return mvwinch(this->boardWindow, y, x);
}

int Board::getStartRow()
{
    return this->startRow;
}

int Board::getStartCol()
{
    return this->startCol;
}

void Board::increaseSpeed()
{
    this->speed -= 20;
}

void Board::contruct(int width, int height, int speed)
{
    int xMax;
    int yMax;

    this->height = height;
    this->width = width;

    getmaxyx(stdscr, yMax, xMax);

    this->startRow = (yMax / 2) - (height / 2);
    this->startCol = (xMax / 2) - (width / 2);

    this->boardWindow = newwin(height, width, this->startRow, this->startCol);

    this->speed = speed;

    wtimeout(this->boardWindow, speed);
    keypad(this->boardWindow, true);
}