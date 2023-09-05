#include "Board.h"


Board::Board(){

    this->drawBoard();
}

Board::~Board(){

}

void Board::drawBoard(){

    for(int i = 0; i < HEIGTH; i++){
        std::cout << "|";
        for(int j = 0; j < WIDTH; j++){
                        
            if(i == 0 || i == (HEIGTH - 1))
                std::cout << "-";
            else
                std::cout << " ";
        }
        std::cout << "|\n";
    }
}