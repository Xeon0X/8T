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
    void *allCard[5];

public:
    Game();
    Game(std::vector<Grid> grids, std::vector<Player> players);
    ~Game();
    Grid getGrid(int index);
    Player getCurrentPlayer();

    void switchPlayer();
    void addGrid(const Grid &grid);
    std::vector<Player> getPlayer();

    void setGrid(int index, const Grid &grid);
    void createAndSetPiece(int cellX, int cellY, int CurrentGrid);
    void **getAllCard();
    void setAllCard();
};

#endif // Game
