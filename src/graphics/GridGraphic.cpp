#include "GridGraphic.h"
#include "Graphic.h"
#include "Piece.h"
#include "Case.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <string>

GridGraphic::GridGraphic(/* args */)
{
}

GridGraphic::~GridGraphic()
{
}

void addTexturePlayer(SDL_Renderer *renderer, std::vector<SDL_Texture *> &playerTextures, Player player1)
{
    if (player1.getSymbol() == "X")
    {
        if (player1.getColor() == "Rouge")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_cross_red.png");
            if (surface == nullptr)
            {
                printf("Error: %s\n", IMG_GetError());
            }
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            if (texture == nullptr)
            {
                printf("Error: %s\n", SDL_GetError());
            }
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Bleu")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_cross_blue.png");
            if (surface == nullptr)
            {
                printf("Error: %s\n", IMG_GetError());
            }
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Vert")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_cross_green.png");
            if (surface == nullptr)
            {
                printf("Error: %s\n", IMG_GetError());
            }
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Jaune")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_cross_yellow.png");
            if (surface == nullptr)
            {
                printf("Error: %s\n", IMG_GetError());
            }
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
    }
    else if (player1.getSymbol() == "O")
    {
        if (player1.getColor() == "Rouge")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_circle_red.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Bleu")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_circle_blue.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Vert")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_circle_green.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Jaune")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_circle_yellow.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
    }
    else if (player1.getSymbol() == "T")
    {
        if (player1.getColor() == "Rouge")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_triangle_red.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Bleu")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_triangle_blue.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Vert")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_triangle_green.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Jaune")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_triangle_yellow.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
    }
    else
    {
        if (player1.getColor() == "Rouge")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_cube_red.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Bleu")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_cube_blue.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Vert")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_cube_green.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            playerTextures.push_back(texture);
        }
        else if (player1.getColor() == "Jaune")
        {
            SDL_Surface *surface = IMG_Load("../data/images/piece_cube_yellow.png");
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            playerTextures.push_back(texture);
        }
    }

    std::cout << playerTextures.size() << std::endl;
}

GridGraphic::GridGraphic(SDL_Renderer *renderer, Player player1, Player player2)
{
    std::vector<Player> players;
    players.push_back(player1);
    players.push_back(player2);
    this->game = Game(players);

    addTexturePlayer(renderer, this->playerTextures, player1);
    std::cout << playerTextures.size() << std::endl;

    addTexturePlayer(renderer, this->playerTextures, player2);
    std::cout << playerTextures.size() << std::endl;

    SDL_Surface *surface = IMG_Load("../data/images/card_draw.png");
    this->deckTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/case.png");
    this->caseTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/deck.png");
    this->backgroundTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/arrow_up.png");
    this->arrowUpTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/arrow_down.png");
    this->arrowDownTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/arrow_left.png");
    this->arrowLeftTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/arrow_right.png");
    this->arrowRightTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/arrow_turn_left.png");
    this->arrowTurnLeftTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/arrow_turn_right.png");
    this->arrowTurnRightTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_addRule.png");
    this->addToRulesTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/logo_big.png");
    this->logo = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/score.png");
    this->score = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_shadow.png");
    this->shadowCard = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
}

void GridGraphic::initCardTexture(SDL_Renderer *renderer)
{
    SDL_Surface *surface = IMG_Load("../data/images/card_gravity.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_addline.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_addrow.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_turn.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_removeLine.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_removeRow.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_place.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_play.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_draw.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_switch.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../data/images/card_align.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->cardsTextures.push_back(texture);
    SDL_FreeSurface(surface);
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
                SDL_RenderCopy(renderer, caseTexture, NULL, &rect);
                if (pieces.size() > 0)
                {
                    for (unsigned int k = 0; k < players.size(); k++)
                    {
                        if (players[k].getSymbol() == pieces[0].getSymbol())
                        {
                            SDL_RenderCopy(renderer, playerTextures[k], NULL, &rect);
                            // graphic.drawPlayer(startX + j * 100 + 50 + this->gridX, startY + i * 100 + 50 + this->gridY, 40, 5, players[k]);
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
        int cardY = graphic.background.y + 25;
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

        // SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderCopy(renderer, cardsTextures[deck.getCards()[i]->getId() - 1], NULL, &rect);

        // std::string text = deck.getCards()[i]->getName();
        // const char *cstr = text.c_str();
        // graphic.drawText(cstr, cardX + 10, cardY + 50);
    }
}

void GridGraphic::drawGlobalrules(SDL_Renderer *renderer, Graphic &graphic)
{
    Player player = this->game.getCurrentPlayer();
    Grid grid = this->game.getGrid(player.getCurrentGrid());
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    for (unsigned int i = 0; i < grid.getGlobalRules().size(); i++)
    {
        int cardX = (i + 1) * 110 + 500;
        int cardY = 25;
        int cardWidth = 100;
        int cardHeight = 150;

        if (grid.getCurrentGlobalRule() == static_cast<int>(i))
        {
            cardY -= 10;
            cardX -= 5;
            cardWidth += 10;
            cardHeight += 20;

            graphic.shadowRect.x = cardX - 50;
            graphic.shadowRect.y = cardY + 45;
            graphic.shadowRect.w = cardWidth + 100;
            graphic.shadowRect.h = cardHeight;

            SDL_RenderCopy(renderer, shadowCard, NULL, &graphic.shadowRect);
        }

        SDL_Rect rect = {cardX, cardY, cardWidth, cardHeight};
        SDL_RenderCopy(renderer, cardsTextures[grid.getGlobalRules()[i]->getId() - 1], NULL, &rect);
        // SDL_RenderDrawRect(renderer, &rect);
        // std::string text = grid.getGlobalRules()[i]->getName();
        // const char *cstr = text.c_str();
        // graphic.drawText(cstr, cardX + 10, cardY + 50);
    }
}

void GridGraphic::setInitialGridSize(int width, int height)
{
    initialGridWidth = width;
    initialGridHeight = height;
}

void GridGraphic::drawPartInterface(SDL_Renderer *renderer, Graphic &graphic)
{
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &graphic.background);
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
        for (unsigned int i = 0; i < directions.size(); i++)
        {
            if (directions[i] == "up")
            {
                SDL_Rect rect = {startX + GridWidth / 2 + this->gridX - 25, startY - 50 + this->gridY, 50, 50};

                SDL_RenderCopy(renderer, arrowUpTexture, NULL, &rect);
            }
            if (directions[i] == "down")
            {
                SDL_Rect rect = {startX + GridWidth / 2 + this->gridX - 25, endY + this->gridY, 50, 50};

                SDL_RenderCopy(renderer, arrowDownTexture, NULL, &rect);
            }
            if (directions[i] == "left")
            {
                SDL_Rect rect = {startX - 50 + this->gridX, startY + GridHeight / 2 + this->gridY - 25, 50, 50};

                SDL_RenderCopy(renderer, arrowLeftTexture, NULL, &rect);
            }
            if (directions[i] == "right")
            {

                SDL_Rect rect = {endX + this->gridX, startY + GridHeight / 2 + this->gridY - 25, 50, 50};

                SDL_RenderCopy(renderer, arrowRightTexture, NULL, &rect);
            }
        }
    }
}

void GridGraphic::drawGlobalRuleButton(SDL_Renderer *renderer, Graphic &graphic)
{
    std::vector<std::vector<Case *>> grid = this->game.getGrid(0).getCases();
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    if (graphic.getCard() != nullptr && graphic.getCard()->getCanBeGlobal())
    {
        SDL_RenderCopy(renderer, addToRulesTexture, NULL, &graphic.globalRuleButton);
    }
}

void GridGraphic::drawInfoPart(SDL_Renderer *renderer, Graphic &graphic)
{
    SDL_RenderCopy(renderer, this->logo, NULL, &graphic.logo);
    SDL_RenderCopy(renderer, this->caseTexture, NULL, &graphic.currentPlayerRect);
    std::vector<Player> players = this->game.getPlayer();
    Player current = this->game.getCurrentPlayer();

    for (unsigned int k = 0; k < players.size(); k++)
    {
        if (players[k].getSymbol() == current.getSymbol())
        {
            SDL_RenderCopy(renderer, playerTextures[k], NULL, &graphic.currentPlayerRect);
        }
    }

    SDL_RenderCopy(renderer, this->score, NULL, &graphic.scoreRect);
    for (unsigned int k = 0; k < players.size(); k++)
    {
        graphic.playerMiniRect.y = graphic.scoreRect.y + 30 + k * 50;
        SDL_RenderCopy(renderer, playerTextures[k], NULL, &graphic.playerMiniRect);
        graphic.drawText(std::to_string(players[k].getScore()).c_str(), graphic.playerMiniRect.x + 35, graphic.playerMiniRect.y + 10);
    }
}