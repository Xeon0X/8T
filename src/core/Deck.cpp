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

void Deck::addCard(const Card &card)
{
    this->cards.push_back(new Card(card));
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

void Deck::piocheCart()
{
    int randomIndex = rand() % 4 + 1;
    switch (randomIndex)
    {
    case 1:
        this->cards.push_back(new CardGravity("Gravity", "Pose une pièce sur le plateau", 1));
        break;

    case 2:
        this->cards.push_back(new CardAddLine("AddLine", "Ajoute une ligne au plateau", 2));
        break;

    case 3:
        this->cards.push_back(new CardAddColumn("AddColumn", "Ajoute une colonne au plateau", 3));
        break;

    case 4:
        this->cards.push_back(new CardTurnGrid("TurnGrid", "Tourne le plateau", 4));
        break;
    default:
        break;
    }
}

void Deck::createNewCard(int id, std::string name, std::string description)
{
    switch (id)
    {
    case 1:
        this->cards.push_back(new CardGravity(name, description, id));
        break;

    case 2:
        this->cards.push_back(new CardAddLine(name, description, id));
        break;

    case 3:
        this->cards.push_back(new CardAddColumn(name, description, id));
        break;

    case 4:
        this->cards.push_back(new CardTurnGrid(name, description, id));
        break;
    default:
        break;
    }
}
