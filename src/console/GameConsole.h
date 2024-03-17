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
    void printGrid(int gridIndex);
    void printDeck(int gridIndex);
    Game &getGame();
    void setGame(Game game) { this->game = game; }
};

#endif // CONSOLE