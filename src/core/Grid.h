#ifndef GRID
#define GRID

#include <vector>
#include "Player.h"
#include "Case.h"
#include "Card.h"
#include <string>
#include <iostream>

class Grid
{
private:
    Player currentPlayer;
    std::vector<std::vector<Case>> grid;
    std::vector<Card> globalRules;

public:
    Grid(Player player, std::pair<int, int> size);
    ~Grid();
    void changeCurrentPlayer();
    void changeCurrentPlayer(Player player);
    void addGlobalRule(Card card);
    getPlayer() const;
    getGrid() const;
    getGlobalRules() const;
};

#endif