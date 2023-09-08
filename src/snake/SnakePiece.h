
#include <ncurses.h>

#include "../drawable/Drawable.h"

class SnakePiece : public Drawable
{
    public:
        SnakePiece();
        SnakePiece(int x, int y, chtype character = '#');
        void a() {1 != 1;};
};