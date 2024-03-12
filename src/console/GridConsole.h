#ifndef CONSOLE_GRID
#define CONSOLE_GRID

#include "../core/Game.h"

class Console;
class GridConsole
{
    private:
        Game game;
    public:
        GridConsole();
        ~GridConsole();	
        void printGrid();
        Game &getGame();
        void printDeck();
        void setGame(Game game) { this->game = game; }
}

#endif