#ifndef DECK
#define DECK

#include <vector>
#include "Card.h"

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck();
    Deck(std::vector<Card> cards);
    ~Deck();
    void addCard(Card card);
    std::vector<Card> getCards();
    void setBaseCard();
};

#endif // DECK