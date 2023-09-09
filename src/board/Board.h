
#include <ncurses.h>
#include <stdlib.h>

#include "../drawable/Drawable.h"

class Board{

    private:
        WINDOW *boardWindow;
        int height;
        int width;
    protected:
    public:

    private:
        void contruct(int width, int height);
    protected:
    public:
        Board();
        Board(int width, int height);
        void addBorder();
        void clear();
        void refresh();
        void initialize();
        void addCharacterAt(int x, int y, chtype charater);
        chtype getInput();
        void add(Drawable drawable);
        void getEmptyCoordinates(int &x, int &y);
        chtype getCharacterAt(int x, int y);


};