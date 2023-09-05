
#include <iostream>
#include<cstdlib>


class Apple {

    public:
        typedef struct {
            int xPos;
            int yPos;
        } Pos;
    private:
        int boardWidth;
        int boardHeigth;
        Pos position;
        int xPosOffset = -2;
        int yPosOffset = -1;

    protected:
    

    private:
        int getRandomXAxisPos(int max);
        int getRandomYAxisPos(int max);
        void setBoardWidth(int width);
        void setBoardHeigth(int heigth);

        int getBoardWidth();
        int getBoardHeigth();
    protected:
    public:
        Apple(int width, int heiht);
        ~Apple();

        Pos getPosition();
        
        

};