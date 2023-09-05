
#include <iostream>

#include "../apple/Apple.h"

class Board{

    private:
        const int width = 50;
        const int heigth = 10;

        Apple apple = Apple(this->getWidth(), this->getHeigth());
    protected:
    public:

    private:
        void drawBoard(Apple::Pos applePos);
    protected:
    public:
        Board();
        ~Board();

        int getWidth();
        int getHeigth();

};