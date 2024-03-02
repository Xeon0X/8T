#ifndef GAME
#define GAME

#include <vector>
#include "Grid.h"
#include "Player.h"

class Game
{
private:
    std::vector<Grid> grids = std::vector<Grid>();
    std::vector<Player> players = std::vector<Player>();
    Player currentPlayer;

public:
    Game();
    Game(std::vector<Grid> grids, std::vector<Player> players);
    ~Game();
    Grid getGrid(int index);
    Player getCurrentPlayer();

    void switchPlayer();
    void addGrid(const Grid &grid);

    void setGrid(int index, const Grid &grid);
};

#endif // Game
