#include "Card.h"
#include "Game.h"

Card::Card(std::string name, std::string description, int id) : name(name), description(description), id(id)
{
}

Card::~Card()
{
}

void Card::applyCard(void *allCards[5], int posX, int posY, int currentGrid, Game &game)
{

    FuncType func = (FuncType)allCards[this->id];
    if (func == nullptr)
    {
        throw std::runtime_error("Function not found");
    }
    else
    {
        func(posX, posY, currentGrid, game);
    }
}

std::string Card::getName()
{
    return this->name;
}