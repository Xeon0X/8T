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
    CardEnd *card6 = new CardEnd("End", "Termine le tour", 14);
    card6->setUniqueId(uniqueIdCounter);
    uniqueIdCounter++;
    this->cards.push_back(card6);
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
    case GravityId:
    {
        CardGravity *card = new CardGravity("Gravity", "Pose une pièce sur le plateau", GravityId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case AddLineId:
    {
        CardAddLine *card = new CardAddLine("AddLine", "Ajoute une ligne au plateau", AddLineId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case AddColumnId:
    {
        CardAddColumn *card = new CardAddColumn("AddColumn", "Ajoute une colonne au plateau", AddColumnId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case TurnGridId:
    {
        CardTurnGrid *card = new CardTurnGrid("TurnGrid", "Tourne le plateau", TurnGridId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case RemoveLineId:
    {
        CardRemoveLine *card = new CardRemoveLine("RemoveLine", "Supprime une ligne du plateau", RemoveLineId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case RemoveColumnId:
    {
        CardRemoveColumn *card = new CardRemoveColumn("RemoveCol", "Supprime une colonne du plateau", RemoveColumnId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case PlacePieceId:
    {
        CardPlacePiece *card = new CardPlacePiece("PlacePiece", "Pose une pièce sur le plateau", PlacePieceId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case PlayCardId:
    {
        CardPlayCard *card = new CardPlayCard("PlayCard", "Joue une carte", PlayCardId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case DrawCardId:
    {
        CardDrawCard *card = new CardDrawCard("DrawCard", "Pioche une carte", DrawCardId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case AlignToWinId:
    {
        CardAlignToWin *card = new CardAlignToWin("AlignToWin", "Le nombre d'alignement pour gagner", AlignToWinId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case AlignToWinPlusOneId:
    {
        CardAlignToWinPlusOne *card = new CardAlignToWinPlusOne("AlignToWinPlusOne", "Le nombre d'alignement pour gagner +1", AlignToWinPlusOneId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }
    case AlignToWinMinusOneId:
    {
        CardAlignToWinMinusOne *card = new CardAlignToWinMinusOne("AlignToWinMinusOne", "Le nombre d'alignement pour gagner -1", AlignToWinMinusOneId);
        card->setUniqueId(uniqueIdCounter);
        uniqueIdCounter++;
        this->cards.push_back(card);
        break;
    }

    default:
        drawCard();
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