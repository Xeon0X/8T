#include "GridGraphic.h"
#include "Graphic.h"
#include "Piece.h"
#include "Case.h"
#include <SDL2/SDL_render.h>
#include <string>

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

    std::string currentRule= "Current rule: " + std::to_string(this->game.getGrid(0).getCurrentGlobalRule());
    graphic.drawText(currentRule.c_str(), 100, 50);

    std::string mouseCoordinates = "MouseX: " + std::to_string(mouseX) + " MouseY: " + std::to_string(mouseY);
    graphic.drawText(mouseCoordinates.c_str(), 100, 100);

    std::string currentPlayer = "Current player: " + this->game.getCurrentPlayer().getSymbol();
    graphic.drawText(currentPlayer.c_str(), 100, 150);

    if (graphic.getCard() != nullptr)
    {
        std::string currendCard = "Current card: " + graphic.getCard()->getName();
        graphic.drawText(currendCard.c_str(), 100, 200);
    }

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
        int cardY = 775;
        int cardWidth = 100;
        int cardHeight = 150;
        if (graphic.getCard() != nullptr && graphic.getCard()->getUniqueId() == deck.getCards()[i]->getUniqueId())
        {
            cardY -= 10;
            cardX -= 5;
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

void GridGraphic::drawGamerules(SDL_Renderer *renderer, Graphic &graphic)
{
    Player player = this->game.getCurrentPlayer();
    Grid grid = this->game.getGrid(player.getCurrentGrid());
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY); // Get mouse position
    for (unsigned int i = 0; i < grid.getGlobalRules().size(); i++)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        int cardX = (i + 1) * 110 + 500;
        int cardY = 075;
        int cardWidth = 100;
        int cardHeight = 150;

        SDL_Rect rect = {cardX, cardY, cardWidth, cardHeight};
        SDL_RenderDrawRect(renderer, &rect);
        std::string text = grid.getGlobalRules()[i]->getName();
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

void GridGraphic::drawArrowDirection(SDL_Renderer *renderer, Graphic &graphic)
{
    std::vector<std::vector<Case *>> grid = this->game.getGrid(0).getCases();
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    int GridWidth = grid[0].size() * 100;
    int GridHeight = grid.size() * 100;

    int startX = (windowWidth - GridWidth) / 2;
    int startY = (windowHeight - GridHeight) / 2;

    int endX = startX + GridWidth;
    int endY = startY + GridHeight;

    if (graphic.getCard() != nullptr)
    {

        Card *card = graphic.getCard();
        std::vector<std::string> directions = card->getArrowDirection();
        for (int i = 0; i < directions.size(); i++)
        {
            if (directions[i] == "up")
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                for (int i = 0; i < 5; i++)
                {
                    SDL_RenderDrawLine(renderer, startX + GridWidth / 2 + this->gridX, startY - 20 - i + this->gridY, startX + GridWidth / 2 + this->gridX, startY - 50 - i + this->gridY);
                    SDL_RenderDrawLine(renderer, startX + GridWidth / 2 + this->gridX, startY - 50 - i + this->gridY, startX + GridWidth / 2 - 5 + this->gridX, startY - 45 - i + this->gridY);
                    SDL_RenderDrawLine(renderer, startX + GridWidth / 2 + this->gridX, startY - 50 - i + this->gridY, startX + GridWidth / 2 + 5 + this->gridX, startY - 45 - i + this->gridY);
                }
            }
            if (directions[i] == "down")
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                for (int i = 0; i < 5; i++)
                {
                    SDL_RenderDrawLine(renderer, startX + GridWidth / 2 + this->gridX, endY + 20 + i + this->gridY, startX + GridWidth / 2 + this->gridX, endY + 50 + i + this->gridY);
                    SDL_RenderDrawLine(renderer, startX + GridWidth / 2 + this->gridX, endY + 50 + i + this->gridY, startX + GridWidth / 2 - 5 + this->gridX, endY + 45 + i + this->gridY);
                    SDL_RenderDrawLine(renderer, startX + GridWidth / 2 + this->gridX, endY + 50 + i + this->gridY, startX + GridWidth / 2 + 5 + this->gridX, endY + 45 + i + this->gridY);
                }
            }
            if (directions[i] == "left")
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                for (int i = 0; i < 5; i++)
                {
                    SDL_RenderDrawLine(renderer, startX - 20 - i + this->gridX, startY + GridHeight / 2 + this->gridY, startX - 50 - i + this->gridX, startY + GridHeight / 2 + this->gridY);
                    SDL_RenderDrawLine(renderer, startX - 50 - i + this->gridX, startY + GridHeight / 2 + this->gridY, startX - 45 - i + this->gridX, startY + GridHeight / 2 - 5 + this->gridY);
                    SDL_RenderDrawLine(renderer, startX - 50 - i + this->gridX, startY + GridHeight / 2 + this->gridY, startX - 45 - i + this->gridX, startY + GridHeight / 2 + 5 + this->gridY);
                }
            }
            if (directions[i] == "right")
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                for (int i = 0; i < 5; i++)
                {
                    SDL_RenderDrawLine(renderer, endX + 20 + i + this->gridX, startY + GridHeight / 2 + this->gridY, endX + 50 + i + this->gridX, startY + GridHeight / 2 + this->gridY);
                    SDL_RenderDrawLine(renderer, endX + 50 + i + this->gridX, startY + GridHeight / 2 + this->gridY, endX + 45 + i + this->gridX, startY + GridHeight / 2 - 5 + this->gridY);
                    SDL_RenderDrawLine(renderer, endX + 50 + i + this->gridX, startY + GridHeight / 2 + this->gridY, endX + 45 + i + this->gridX, startY + GridHeight / 2 + 5 + this->gridY);
                }
            }
        }
    }
}

void GridGraphic::drawGlobalRuleButton(SDL_Renderer *renderer, Graphic &graphic)
{
    std::vector<std::vector<Case *>> grid = this->game.getGrid(0).getCases();
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    if (graphic.getCard() != nullptr)
    {

        Card *card = graphic.getCard();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &graphic.globalRuleButton);
        graphic.drawText("Add to globalRules", 110, 310);
    }
}