#include "Card.h"

Card::Card(std::string name, std::string description, int id, std::string pathCardImage, std::string pathCardSound) : 
name(name), description(description), id(id), pathCardImage(pathCardImage), pathCardSound(pathCardSound)
{

}

Card::~Card()
{

}

