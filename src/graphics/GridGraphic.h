#ifndef GRAPHIC_GRID
#define GRAPHIC_GRID

#include <SDL2/SDL.h>
#include "../core/Game.h"

class Graphic;
class GridGraphic
{
private:
    Game game;
    int gridX = 0;
    int gridY = 0;

public:
    GridGraphic(/* args */);
    ~GridGraphic();
    void showGrid(SDL_Renderer *renderer, Graphic &graphic);
    void moveGrid(int dx, int dy);

    int getGridX() { return gridX; }
    int getGridY() { return gridY; }

    int getCaseWidth() { return 100; }
    int getCaseHeight() { return 100; }
    Game &getGame();

    void setGame(Game game) { this->game = game; }
    void drawDeck(SDL_Renderer *renderer, Graphic &graphic);
};

#endif // GRAPHIC_GRID