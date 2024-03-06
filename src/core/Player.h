#ifndef PLAYER
#define PLAYER

#include <vector>
#include <map>
#include <tuple>
#include "Deck.h"

struct PlayerEffects
{
    bool posePiece;
};
class Player
{
private:
    std::string symbol;
    std::string color;
    int currentGrid;
    std::vector<Deck> decks;
    PlayerEffects playerEffects;

public:
    Player();
    Player(std::string symbol, std::string color);
    ~Player();
    std::string getSymbol();
    int getCurrentGrid();
    std::string getColor();
    std::tuple<int, int, int> stringToRgb();
    Deck getDeck(int index);

    PlayerEffects &getPlayerEffects();
    void setPlayerEffects(PlayerEffects playerEffects);
};

#endif // PLAYER