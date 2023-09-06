
#include <ncurses.h>

class Board{

    private:
        WINDOW *boardWindow;
    protected:
    public:

    private:
        
    protected:
    public:
        Board(int height, int width);
        void addBorder();
        void clear();
        void refresh();
        void initialize();
        void addCharacterAt(int x, int y, chtype charater);
        chtype getInput();
        


};