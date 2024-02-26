#include "Case.h"

Case::Case(int posX, int posY)
{
    this->pieces.push_back(Piece());
    this->dimX = 50;
    this->dimY = 50;
    this->rect.x = posX;
    this->rect.y = posY;
    this->rect.w = this->dimX;
    this->rect.h = this->dimY;
}

Case::~Case()
{
}

void Case::showCase(SDL_Renderer *renderer, int x, int y)
{

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &this->rect);
}

SDL_Rect Case::getRect()
{
    return this->rect;
}
