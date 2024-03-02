#include "Player.h"

Player::Player()
{
    this->symbol = "";
    this->currentGrid = 0;
    this->decks = {};
    this->playerEffects = {};
}

Player::Player(std::string symbol)
    : symbol(symbol), currentGrid(0), decks{}, playerEffects{}
{
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
