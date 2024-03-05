#include "Card.h"

Card::Card(std::string name, std::string description, int id, std::string pathCardImage, std::string pathCardSound) : name(name), description(description), id(id), pathCardImage(pathCardImage), pathCardSound(pathCardSound)
{
}

Card::~Card()
{
}

void Card::applyCard(void *allCards[5])
{
    FuncType func = (FuncType)allCards[this->id];
    func();
}
