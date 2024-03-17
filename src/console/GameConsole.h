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
    int menu(int gridIndex);
    void placePiece(int gridIndex, int x, int y);
    void playCard(int gridIndex, int cardIndex);
    // Game &getGame();
    // void setGame(Game game) { this->game = game; }
};

#endif // CONSOLE