#include "Deck.h"

Deck::Deck()
{
}

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

void Deck::setBaseCard()
{
    Card card = Card("PlacePiece", "Pose une pièce sur le plateau", 0);
    this->cards.push_back(card);
}

std::vector<Card> Deck::getCards()
{
    return this->cards;
}