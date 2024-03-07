#include "Rules.h"
#include "../Game.h"
#include "../Grid.h"
#include "RulesCommun.cpp"
#include "RulesRare.cpp"

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
    this->allCard[1] = (void *)&applyGravity;
}
