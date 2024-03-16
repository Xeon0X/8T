#ifndef CONSOLE_GRID
#define CONSOLE_GRID

#include "../core/Game.h"

class GameConsole
{
    private:
        Game game;
    public:
        GameConsole();
        ~GameConsole();	
        void printGrid();
        Game &getGame();
        void printDeck();
        void setGame(Game game) { this->game = game; }
};

#endif // CONSOLE