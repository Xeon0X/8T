#include "Deck.h"
#include "./rules/RulesRare.hpp"
#include "./rules/RulesCommun.hpp"
#include "./rules/GlobalRules.hpp"

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
    card->setUniqueId(uniqueIdCounter);
    uniqueIdCounter++;
    this->cards.push_back(card);
    CardAddLine *card2 = new CardAddLine("AddLine", "Ajoute une ligne au plateau", 2);
    card2->setUniqueId(uniqueIdCounter);
    uniqueIdCounter++;
    this->cards.push_back(card2);
    CardAddColumn *card3 = new CardAddColumn("AddColumn", "Ajoute une colonne au plateau", 3);
    card3->setUniqueId(uniqueIdCounter);
    uniqueIdCounter++;
    this->cards.push_back(card3);
    CardTurnGrid *card4 = new CardTurnGrid("TurnGrid", "Tourne le plateau", 4);
    card4->setUniqueId(uniqueIdCounter);
    uniqueIdCounter++;
    this->cards.push_back(card4);
    CardAlignToWinPlusOne *card5 = new CardAlignToWinPlusOne("AlignToWinPlusOne", "Le nombre d'alignement pour gagner +1", 12);
    card5->setUniqueId(uniqueIdCounter);
    uniqueIdCounter++;
    this->cards.push_back(card5);
}

std::vector<Card *> Deck::getCards()
{
    return this->cards;
}

void Deck::drawCard()
{
    int randomIndex = rand() % 13 + 1;
    switch (randomIndex)
    {
    case 1:
    {
        CardGravity *card = new CardGravity("Gravity", "Pose une pièce sur le plateau", 1);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 2:
    {
        CardAddLine *card = new CardAddLine("AddLine", "Ajoute une ligne au plateau", 2);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 3:
    {
        CardAddColumn *card = new CardAddColumn("AddColumn", "Ajoute une colonne au plateau", 3);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 4:
    {
        CardTurnGrid *card = new CardTurnGrid("TurnGrid", "Tourne le plateau", 4);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 5:
    {
        CardRemoveLine *card = new CardRemoveLine("RemoveLine", "Supprime une ligne du plateau", 5);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 6:
    {
        CardRemoveColumn *card = new CardRemoveColumn("RemoveCol", "Supprime une colonne du plateau", 6);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 7:
    {
        CardPlacePiece *card = new CardPlacePiece("PlacePiece", "Pose une pièce sur le plateau", 7);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 8:
    {
        CardPlayCard *card = new CardPlayCard("PlayCard", "Joue une carte", 8);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 9:
    {
        CardDrawCard *card = new CardDrawCard("DrawCard", "Pioche une carte", 9);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 10:
    {
        CardSwitchPlayer *card = new CardSwitchPlayer("SwitchPlayer", "Change de joueur", 10);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 11:
    {
        CardAlignToWin *card = new CardAlignToWin("AlignToWin", "Le nombre d'alignement pour gagner", 11);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case 12:
    {
        CardAlignToWinPlusOne *card = new CardAlignToWinPlusOne("AlignToWinPlusOne", "Le nombre d'alignement pour gagner +1", 12);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
    }
    case 13:
    {
        CardAlignToWinMinusOne *card = new CardAlignToWinMinusOne("AlignToWinMinusOne", "Le nombre d'alignement pour gagner -1", 13);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
    }

    default:
        break;
    }
}

void Deck::removeCard(Card *card)
{
    auto it = std::find(this->cards.begin(), this->cards.end(), card);
    if (it != this->cards.end())
    {
        this->cards.erase(it);
    }
}