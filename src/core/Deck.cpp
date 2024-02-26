#include "Deck.h"

Deck::Deck(std::vector<Card> cards) : cards(cards)
{

}

Deck::~Deck()
{
    
}

void Deck::addCard(Card card)
{
    this->cards.push_back(card);
}