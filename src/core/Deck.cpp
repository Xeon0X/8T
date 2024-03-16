#include "Deck.h"
#include "./rules/RulesRare.hpp"
#include "./rules/RulesCommun.hpp"

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
    CardGravity *card = new CardGravity("Gravity", "Pose une pièce sur le plateau", 1);
    this->cards.push_back(card);
    CardAddLine *card2 = new CardAddLine("AddLine", "Ajoute une ligne au plateau", 2);
    this->cards.push_back(card2);
    CardAddColumn *card3 = new CardAddColumn("AddColumn", "Ajoute une colonne au plateau", 3);
    this->cards.push_back(card3);
    CardTurnGrid *card4 = new CardTurnGrid("TurnGrid", "Tourne le plateau", 4);
    this->cards.push_back(card4);
}

std::vector<Card *> Deck::getCards()
{
    return this->cards;
}