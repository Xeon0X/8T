#include "Player.h"

Player::Player()
{
    this->symbol = "";
    this->color = "";
    this->currentGrid = 0;
    this->decks = {};
    this->playerEffects = PlayerEffects();
}

Player::Player(std::string symbol, std::string color)
    : symbol(symbol), color(color), currentGrid(0), decks{}, playerEffects{PlayerEffects()}
{
    Deck deck = Deck();
    deck.setBaseCard();
    this->decks.push_back(deck);
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

std::tuple<int, int, int> Player::stringToRgb()
{
    if (this->color == "red")
    {
        return std::make_tuple(255, 0, 0);
    }
    else if (this->color == "green")
    {
        return std::make_tuple(0, 255, 0);
    }
    else if (this->color == "blue")
    {
        return std::make_tuple(0, 0, 255);
    }
    else
    {
        return std::make_tuple(255, 255, 0);
    }
}

Deck Player::getDeck(int index)
{
    return this->decks[index];
}

PlayerEffects &Player::getPlayerEffects()
{
    return this->playerEffects;
}

void Player::setPlayerEffects(PlayerEffects playerEffects)
{
    this->playerEffects = playerEffects;
}