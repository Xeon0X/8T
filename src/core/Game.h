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

    void switchPlayer();
    void addGrid(const Grid &grid);

    void setGrid(int index, const Grid &grid);
};

#endif // Game
