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

public:
    Game(std::vector<Grid> grids, std::vector<Player> players);
    ~Game();
    void addGrid(const Grid& grid);
};

#endif // Game
