#include "Deck.h"
#include "./rules/RulesRare.cpp"

Deck::Deck()
{
}

Deck::Deck(std::vector<Card *> cards) : cards(cards)
{
}

Deck::~Deck()
{
}

void Deck::addCard(Card &card)
{
    this->cards.push_back(&card);
}

void Deck::setBaseCard()
{
    CardGravity *card = new CardGravity("PlacePiece", "Pose une pièce sur le plateau", 1);
    this->cards.push_back(card);
}

std::vector<Card *> Deck::getCards()
{
    return this->cards;
}