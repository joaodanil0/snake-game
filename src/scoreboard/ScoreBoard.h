
#include <ncurses.h>

class ScoreBoard
{

    private:
        WINDOW *scoreWindow;
    protected:
    public:

    private:
    protected:
    public:
        ScoreBoard();
        ScoreBoard(int width, int x, int y);
        void initialize(int initialScore);
        void updateScore(long long score);
        void clear();
        void refresh();
};