#include "GridGraphic.h"
#include "Graphic.h"

void GridGraphic::drawPioche(SDL_Renderer *renderer, Graphic &graphic)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &graphic.pioche);

    std::string piocheText = "Pioche";
    graphic.drawText(piocheText.c_str(), 20, 520);
}