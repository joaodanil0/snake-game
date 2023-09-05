#include "Apple.h"

Apple::Apple(int width, int heigth) {
    this->setBoardHeigth(heigth);
    this->setBoardWidth(width);

    unsigned seed = time(0);

    srand(seed);
}

Apple::~Apple() {
}

void Apple::setBoardHeigth(int heigth){
    this->boardHeigth = heigth;
}

void Apple::setBoardWidth(int width){
    this->boardWidth = width;
}

int Apple::getBoardHeigth(){
    return this->boardHeigth;
}

int Apple::getBoardWidth(){
    return this->boardWidth;
}

int Apple::getRandomXAxisPos(int max){
    int min = 1;
    return min + rand() % (( max + 1 ) - min);
}

int Apple::getRandomYAxisPos(int max){
    int min = 0;
    return min + rand() % (( max + 1 ) - min);
}

Apple::Pos Apple::getPosition(){
    this->position.xPos = this->getRandomXAxisPos(this->getBoardHeigth() + this->xPosOffset);
    this->position.yPos = this->getRandomYAxisPos(this->getBoardWidth()  + this->yPosOffset);
    return this->position;
}