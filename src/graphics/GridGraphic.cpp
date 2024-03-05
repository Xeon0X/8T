#include "GridGraphic.h"
#include "Graphic.h"

GridGraphic::GridGraphic(/* args */)
{
}

GridGraphic::~GridGraphic()
{
}

void GridGraphic::showGrid(SDL_Renderer *renderer, Graphic &graphic)
{
    std::vector<std::vector<Case>> grid = this->game.getGrid(0).getCases();
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    std::vector<Player> players = this->game.getPlayer();

    int totalGridWidth = grid[0].size() * 100;
    int totalGridHeight = grid.size() * 100;

    int startX = (windowWidth - totalGridWidth) / 2;
    int startY = (windowHeight - totalGridHeight) / 2;

    int thickness = 5;

    for (unsigned int i = 0; i < grid.size(); i++)
    {
        for (unsigned int j = 0; j < grid[i].size(); j++)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

            for (int t = 0; t < thickness; t++)
            {
                std::vector<Piece> pieces = grid[i][j].getPieces();
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                SDL_Rect rect = {(int)(startX + j * 100 + this->gridX - t), (int)(startY + i * 100 + this->gridY - t), 100 + 2 * t, 100 + 2 * t};
                SDL_RenderDrawRect(renderer, &rect);
                if (pieces.size() > 0)
                {
                    for (unsigned int k = 0; k < pieces.size(); k++)
                    {
                        graphic.drawPlayer(startX + j * 100 + 50 + this->gridX, startY + i * 100 + 50 + this->gridY, 40, 5, player);
                    }
                }
            }
        }
    }
}

void GridGraphic::moveGrid(int dx, int dy)
{
    gridX += dx;
    gridY += dy;
}
