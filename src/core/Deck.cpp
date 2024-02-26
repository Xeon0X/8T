#include "Deck.h"

Deck::Deck(/* args */)
{
}

Deck::~Deck()
{
}

void Deck::addCard(Card card)
{
    this->cards.push_back(card);
}