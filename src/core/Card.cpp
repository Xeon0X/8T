#include "Card.h"

Card::Card(/* args */)
{
    this->description = "";
    this->name = "";
    this->id = -1;
    this->pathCardImage = "";
    this->pathCardSound = "";
}

Card::Card(std::string name, std::string description, int id, std::string pathCardImage, std::string pathCardSound)
{
    this->description = description;
    this->name = name;
    this->id = id;
    this->pathCardImage = pathCardImage;
    this->pathCardSound = pathCardSound;
}

Card::~Card()
{
}