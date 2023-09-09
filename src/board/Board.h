
#include <ncurses.h>
#include <stdlib.h>

#include "../drawable/Drawable.h"

class Board{

    private:
        WINDOW *boardWindow;
        int height;
        int width;
        int startRow;
        int startCol;
    protected:
    public:

    private:
        void contruct(int width, int height, int speed);
    protected:
    public:
        Board();
        Board(int width, int height, int speed);
        void addBorder();
        void clear();
        void refresh();
        void initialize();
        void addCharacterAt(int x, int y, chtype charater);
        chtype getInput();
        void add(Drawable drawable);
        void getEmptyCoordinates(int &x, int &y);
        chtype getCharacterAt(int x, int y);
        int getStartRow();
        int getStartCol();


};