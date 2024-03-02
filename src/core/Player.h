#ifndef PLAYER
#define PLAYER

#include <vector>
#include <map>
#include "Deck.h"

class Player
{
private:
    std::string symbol;
    std::string color;
    int currentGrid;
    std::vector<Deck> decks;
    std::vector<std::map<std::string, float>> playerEffects;

public:
    Player(std::string symbol);
    ~Player();
    std::string getSymbol();
    int getCurrentGrid();
    std::string getColor();
};

#endif // PLAYER