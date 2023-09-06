#include "Board.h"

Board::Board(int height, int width)
{
    int xMax;
    int yMax;

    getmaxyx(stdscr, yMax, xMax);

    this->boardWindow = newwin(height, width,
                                (yMax / 2) - (height / 2),
                                (xMax / 2) - (width / 2));
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
