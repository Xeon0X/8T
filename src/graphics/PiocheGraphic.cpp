#include "GridGraphic.h"
#include "Graphic.h"

void GridGraphic::drawPioche(SDL_Renderer *renderer, Graphic &graphic)
{

    SDL_RenderCopy(renderer, deckTexture, NULL, &graphic.pioche);
}