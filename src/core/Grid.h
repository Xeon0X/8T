#ifndef GRID
#define GRID

#include <vector>
#include "Player.h"
#include "Case.h"
#include "Card.h"
#include <string>
#include <iostream>
#include "Piece.h"

class Grid
{
private:
    std::vector<std::vector<Case>> cases;
    std::vector<Card> globalRules;

    int nbAlignToWin = 3;

public:
    Grid();
    ~Grid();
    void addGlobalRule(Card card);
    std::vector<std::vector<Case>> getCases();
    int getGridWidth();
    int getGridHeight();

    void setNbAlignToWin(int nb);
    int getNbAlignToWin();

    bool checkWin(Player player, int cellX, int cellY);

    void setCase(int x, int y, Case c);
    Case getCase(int x, int y);

    void resetGrid();
};

#endif // GRID