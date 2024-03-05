#include "Player.h"

Player::Player()
{
    this->symbol = "";
    this->color = "";
    this->currentGrid = 0;
    this->decks = {};
    this->playerEffects = {};
}

Player::Player(std::string symbol, std::string color)
    : symbol(symbol), color(color), currentGrid(0), decks{}, playerEffects{}
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
