#include "Graphic.h"

void Graphic::animatePLayerGravity(int x1, int y1, int x2, int y2, int r, int thickness, Player player)
{
    int actualX = x1;
    int actualY = y1;
    SDL_Rect whiteRect = {x1 - 45, y1 - 45, 90, 90};

    std ::cout << "Drawing player" << std::endl;
    std::cout << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << std::endl;
    drawPlayer(actualX, actualY, r, thickness, player);
    while (actualY < y2)
    {
        this->clear();

        this->grid.showGrid(renderer, *this);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &whiteRect);
        this->grid.drawDeck(renderer, *this);
        drawPlayer(actualX, actualY, r, thickness, player);
        actualY += 1;
        this->present();
    }
}

void Graphic::applyGravityAnimation()
{
}
