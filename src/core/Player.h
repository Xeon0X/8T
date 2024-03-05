#ifndef PLAYER
#define PLAYER

#include <vector>
#include <map>
#include <tuple>
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
    Player();
    Player(std::string symbol, std::string color);
    ~Player();
    std::string getSymbol();
    int getCurrentGrid();
    std::string getColor();
    std::tuple<int, int, int> stringToRgb();
};

#endif // PLAYER