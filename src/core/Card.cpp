#include "Card.h"
#include "Game.h"

Card::Card(std::string name, std::string description, int id) : name(name), description(description), id(id)
{
}

Card::~Card()
{
}

std::string Card::getName()
{
    return this->name;
}

Card::Card(const Card &other) : name(other.name), description(other.description), id(other.id)
{
}
