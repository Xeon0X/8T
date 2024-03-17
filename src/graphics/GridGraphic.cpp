#include "GridGraphic.h"
#include "Graphic.h"
#include "Piece.h"
#include "Case.h"

GridGraphic::GridGraphic(/* args */)
{
}

GridGraphic::~GridGraphic()
{
}

void GridGraphic::showGrid(SDL_Renderer *renderer, Graphic &graphic)
{
    std::vector<std::vector<Case *>> grid = this->game.getGrid(0).getCases();
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    std::vector<Player> players = this->game.getPlayer();

    int GridWidth = grid[0].size() * 100;
    int GridHeight = grid.size() * 100;

    int startX = (windowWidth - GridWidth) / 2;
    int startY = (windowHeight - GridHeight) / 2;

    int thickness = 5;

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    std::string mouseCoordinates = "MouseX: " + std::to_string(mouseX) + " MouseY: " + std::to_string(mouseY);
    graphic.drawText(mouseCoordinates.c_str(), 100, 100);

    for (unsigned int i = 0; i < grid.size(); i++)
    {
        for (unsigned int j = 0; j < grid[i].size(); j++)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

            for (int t = 0; t < thickness; t++)
            {
                std::vector<Piece> pieces = grid[i][j]->getPieces();
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                SDL_Rect rect = {(int)(startX + j * 100 + this->gridX - t), (int)(startY + i * 100 + this->gridY - t), 100 + 2 * t, 100 + 2 * t};
                SDL_RenderDrawRect(renderer, &rect);
                if (pieces.size() > 0)
                {
                    for (unsigned int k = 0; k < players.size(); k++)
                    {
                        if (players[k].getSymbol() == pieces[0].getSymbol())
                        {
                            graphic.drawPlayer(startX + j * 100 + 50 + this->gridX, startY + i * 100 + 50 + this->gridY, 40, 5, players[k]);
                        }
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

Game &GridGraphic::getGame()
{
    return this->game;
}

void GridGraphic::drawDeck(SDL_Renderer *renderer, Graphic &graphic)
{
    Player player = this->game.getCurrentPlayer();
    Deck deck = player.getDeck(player.getCurrentGrid());
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY); // Get mouse position
    for (unsigned int i = 0; i < deck.getCards().size(); i++)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        int cardX = (i + 1) * 110 + 500;
        int cardY = 875;
        int cardWidth = 100;
        int cardHeight = 150;
        if (mouseX >= cardX && mouseX <= cardX + cardWidth && mouseY >= cardY && mouseY <= cardY + cardHeight)
        {
            cardY -= 20;
            cardWidth += 10;
            cardHeight += 20;
        }
        SDL_Rect rect = {cardX, cardY, cardWidth, cardHeight};
        SDL_RenderDrawRect(renderer, &rect);
        std::string text = deck.getCards()[i]->getName();
        const char *cstr = text.c_str();
        graphic.drawText(cstr, cardX + 10, cardY + 50);
    }
}

void GridGraphic::setInitialGridSize(int width, int height)
{
    initialGridWidth = width;
    initialGridHeight = height;
}

void GridGraphic::drawPartInterface(SDL_Renderer *renderer, Graphic &graphic)
{

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &graphic.deckPart);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &graphic.deckPart);
}