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
    int currentPlayer;
    std::vector<Player> players;
    std::vector<std::vector<Case>> grid;
    std::vector<Card> cards;
public:
    Grid(int player, std::vector<Player> players, std::vector<Card> cards, std::pair<int, int> size = {3, 3});
    ~Grid();
    int nextPlayer(int next = 1);
    void setCurrentPlayer(int player);
    void addCard(Card card);
    int getCurrentPlayer() const;
    std::vector<std::vector<Case>> getGrid() const;
    std::vector<Card> getCards() const;
};

#endif // GRID