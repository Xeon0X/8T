#include "Player.h"

Player::Player()
{
    this->symbol = "";
    this->currentGrid = 0;
    Deck deck;
    this->decks.push_back(deck);
    std::map<std::string, float> playerEffect;
    this->playerEffects.push_back(playerEffect);
}
Player::Player(std::string symbol)
{
    this->symbol = symbol;
    this->currentGrid = 0;
    Deck deck;
    this->decks.push_back(deck);
    std::map<std::string, float> playerEffect;
    this->playerEffects.push_back(playerEffect);
}

Player::~Player()
{
}

std::string Player::getSymbol()
{
    return this->symbol;
}

int Player::getCurrentGrid()
{
    return this->currentGrid;
}

std::string Player::getColor()
{
    return this->color;
}