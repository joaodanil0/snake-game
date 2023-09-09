#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
{

}

ScoreBoard::ScoreBoard(int width, int x, int y)
{
    this->scoreWindow = newwin(1, width, y, x);
}

void ScoreBoard::initialize(int initialScore)
{
    this->clear();
    mvwprintw(this->scoreWindow, 0, 0, "Score: ");
    this->updateScore(initialScore);
    this->refresh();
}

void ScoreBoard::updateScore(long long score)
{
    mvwprintw(this->scoreWindow, 0, this->scoreWindow->_maxx - 10, "%11llu", score);
}

void ScoreBoard::clear()
{
    wclear(this->scoreWindow);
}

void ScoreBoard::refresh()
{
    wrefresh(this->scoreWindow);
}
