#include "Board.h"


Board::Board(){

    this->drawBoard(this->apple.getPosition());
}

Board::~Board(){

}

void Board::drawBoard(Apple::Pos applePos){

    for(int i = 0; i < this->heigth; i++){
        std::cout << "|";
        for(int j = 0; j < this->width; j++){

            if( (i == applePos.xPos) && (j == applePos.yPos))
                std::cout << "@";       
            else if(i == 0 || i == (this->heigth - 1))
                std::cout << "-";
            else
                std::cout << " ";
        }
        std::cout << "|\n";
    }
}

int Board::getHeigth(){
    return this->heigth;
}

int Board::getWidth(){
    return this->width;
}
