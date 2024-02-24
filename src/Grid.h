#ifndef GRID
#define GRID

#include <vector>
#include "Player.h"
#include "Case.h"
#include "Card.h"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Grid
{
private:
    Player currentPlayer;
    std::vector<std::vector<Case>> cases;
    std::vector<Card> globalRules;

public:
    Grid(Player player1, int SCREEN_HEIGHT, int SCREEN_WIDTH);
    ~Grid();
    void addGlobalRule(Card card);
    void showGrid(SDL_Renderer *renderer);
};

#endif