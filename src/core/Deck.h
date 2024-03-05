#ifndef DECK
#define DECK

#include <vector>
#include "Card.h"

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck(std::vector<Card> cards);
    ~Deck();
    void addCard(Card card);
};

#endif // DECK