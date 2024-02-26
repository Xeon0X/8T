#ifndef PLAYER
#define PLAYER

#include <vector>
#include <map>
#include "Deck.h"

class Player
{
private:
    std::string symbol;
    int currentGrid;
    std::vector<Deck> decks;
    std::vector<std::map<std::string, float>> playerEffects;

public:
    Player();
    Player(std::string symbol);
    ~Player();
};

#endif