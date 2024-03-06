#include "Rules.h"
#include "../Game.h"
#include "../Grid.h"
#include "RulesCommun.cpp"

Rules::Rules(/* args */)
{
}

Rules::~Rules()
{
}

void **Rules::getAllCard()
{
    return this->allCard;
}

void Rules::setAllCard()
{
    this->allCard[0] = (void *)&EnablePosePiece;
    std::cout << this->allCard[0] << std::endl;
}
