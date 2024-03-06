#ifndef GAME
#define GAME

#include <vector>
#include "Grid.h"
#include "Player.h"
#include "./rules/Rules.h"

class Game
{
private:
    std::vector<Grid> grids = std::vector<Grid>();
    std::vector<Player> players = std::vector<Player>();
    Player currentPlayer;
    Rules rules;

    bool wait = false;
    bool haveNetwork = false;

public:
    Game();
    Game(std::vector<Grid> grids, std::vector<Player> players);
    ~Game();
    Grid getGrid(int index);
    Player getCurrentPlayer();
    void setCurrentPlayer(Player player);
    void replacePlayer(Player player);

    void switchPlayer();
    void addGrid(const Grid &grid);
    std::vector<Player> getPlayer();

    void setGrid(int index, const Grid &grid);
    void createAndSetPiece(int cellX, int cellY, int CurrentGrid);

    Rules getRules();
};

#endif // Game
