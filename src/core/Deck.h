#ifndef DECK
#define DECK

#include <vector>
#include "Card.h"

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck(/* args */);
    ~Deck();
    void addCard(Card card);
};

#endif // DECK