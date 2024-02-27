#ifndef GAME
#define GAME

#include <vector>
#include "Grid.h"
#include "Player.h"

class Game
{
private:
    std::vector<Grid> grids;
    std::vector<Player> players;
    Player currentPlayer;

public:
    Game(/* args */);
    ~Game();
    Grid getGrid(int index);
    Player getCurrentPlayer();
    void addGrid(const Grid &grid);
};

#endif // Game
