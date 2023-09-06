
#include <ncurses.h>

class Drawable{

    private:
    protected:
        int x;
        int y;
        chtype character;
    public:

    private:
    protected:
    public:
        Drawable();
        Drawable(int x, int y, chtype character);
        int getX();
        int getY();
        chtype getCharacter();
};