#ifndef GRID
#define GRID

#include <vector>
#include "Player.h"
#include "Case.h"
#include "Card.h"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Piece.h"

class Grid
{
private:
    std::vector<std::vector<Case>> cases;
    std::vector<Card> globalRules;

public:
    Grid();
    ~Grid();
    void addGlobalRule(Card card);
    std::vector<std::vector<Case>> getCases();
    int getGridWidth();
    int getGridHeight();

    void setCase(int x, int y, Case c);
};

#endif