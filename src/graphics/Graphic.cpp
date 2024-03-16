#include "Graphic.h"
#include "Case.h"
#include <iostream>

Graphic::Graphic()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (TTF_Init() != 0)
    {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        exit(1);
    }

    int screenWidth, screenHeight;
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
    {
        std::cout << "SDL_GetDesktopDisplayMode Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    screenWidth = dm.w;
    screenHeight = dm.h;

    window = SDL_CreateWindow("8T", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);

    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    color = {0, 0, 0, 255};
    this->font = TTF_OpenFont("../font/dogica.ttf", 10);
    if (font == nullptr)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        // exit(1);
    }

    fontColor = {0, 0, 0, 255};
    fontSize = 10;
    fontStyle = TTF_STYLE_NORMAL;
    this->grid = GridGraphic();
    this->grid.setInitialGridSize(3, 3);
}

Graphic::~Graphic()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

void Graphic::drawRect(int x, int y, int w, int h)
{
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Graphic::drawLine(int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Graphic::drawCircle(int x, int y, int r, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);
    for (int z = 0; z < thickness; z++)
    {
        for (int w = 0; w < 360; w++)
        {
            SDL_RenderDrawPoint(renderer, x + (r - z) * cos(w), y + (r - z) * sin(w));
        }
    }
}

void Graphic::drawCross(int x, int y, int r, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);
    for (int z = 0; z < thickness; z++)
    {
        SDL_RenderDrawLine(renderer, x - r, y - r + z, x + r, y + r + z);
        SDL_RenderDrawLine(renderer, x - r, y + r + z, x + r, y - r + z);
    }
}

void Graphic::drawPoint(int x, int y)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Graphic::drawText(const char *text, int x, int y)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, fontColor);
    if (!surface)
    {
        std::cout << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
    {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    }
    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Graphic::clear()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void Graphic::present()
{
    SDL_RenderPresent(renderer);
}

void Graphic::setColor(int r, int g, int b, int a)
{
    color = {(unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a};
}

void Graphic::setDrawColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(renderer, (unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a);
}

void Graphic::setFont(const char *font, int size)
{
    this->font = TTF_OpenFont(font, size);
}

void Graphic::setFontSize(int size)
{
    fontSize = size;
    TTF_CloseFont(font);
    font = TTF_OpenFont("res/arial.ttf", size);
}

void Graphic::setFontColor(int r, int g, int b, int a)
{
    fontColor = {(unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a};
}

void Graphic::setFontStyle(int style)
{
    fontStyle = style;
    TTF_SetFontStyle(font, style);
}

void Graphic::drawPlayer(int x, int y, int radius, int thickness, Player player)
{
    std::tuple<int, int, int> colorPlayer = player.stringToRgb();
    SDL_SetRenderDrawColor(renderer, std::get<0>(colorPlayer), std::get<1>(colorPlayer), std::get<2>(colorPlayer), 255);
    if (player.getSymbol() == "X")
    {
        drawCross(x, y, radius, thickness, player);
    }
    else
    {
        drawCircle(x, y, radius, thickness, player);
    }
}

void Graphic::play()
{
    while (running)
    {
        eventHolder();
        clear();

        grid.showGrid(renderer, *this);
        this->grid.drawDeck(renderer, *this);
        present();
    }
}

void Graphic::handleQuitEvent()
{
    running = false;
}

void Graphic::handleMouseButtonDownEvent(SDL_Event &event)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    int screenWidth, screenHeight;
    SDL_GetRendererOutputSize(renderer, &screenWidth, &screenHeight);

    int CurrentGrid = this->grid.getGame().getCurrentPlayer().getCurrentGrid();
    int CasesWidth = this->grid.getGame().getGrid(CurrentGrid).getGridWidth();
    int CasesHeight = this->grid.getGame().getGrid(CurrentGrid).getGridHeight();

    int gridX = ((screenWidth - CasesWidth * this->grid.getCaseWidth()) / 2) + this->grid.getGridX();
    int gridY = ((screenHeight - CasesHeight * this->grid.getCaseHeight()) / 2) + this->grid.getGridY();

    mouseX -= gridX;
    mouseY -= gridY;

    int cellX = std::floor(mouseX / 100);
    int cellY = std::floor(mouseY / 100);

    Player player = this->grid.getGame().getCurrentPlayer();

    if (cellX >= 0 && cellX < CasesWidth && cellY >= 0 && cellY < CasesHeight)
    {
        Game game = this->grid.getGame();
        Grid grid = game.getGrid(CurrentGrid);

        if (grid.getCase(cellX, cellY)->getPieces().size() > 0)
        {
            if (grid.getCase(cellX, cellY)->getPieces()[0].getSymbol() == game.getCurrentPlayer().getSymbol())
            {
                game.createAndSetPiece(cellX, cellY, CurrentGrid);
            }
        }
        else
        {
            game.createAndSetPiece(cellX, cellY, CurrentGrid);
            player.getPlayerEffects().posePiece = false;

            game.replacePlayer(player);
            game.setCurrentPlayer(player);

            handleCheckWin(cellX, cellY, game);
            this->grid.setGame(game);

            game = this->grid.getGame();
            game.switchPlayer();
            this->grid.setGame(game);
        }
        if (grid.getRules().gravity)
        {
            applyGravityAnimation();
            drawText("Gravity is on", 100, 100);
        }
    }
    Deck deck = player.getDeck(player.getCurrentGrid());
    SDL_GetMouseState(&mouseX, &mouseY); // Get mouse position

    for (unsigned int i = 0; i < deck.getCards().size(); i++)
    {
        int cardX = (i + 1) * 110 + 500;
        int cardY = 900;
        int cardWidth = 100;
        int cardHeight = 150;

        if (mouseX >= cardX && mouseX <= cardX + cardWidth && mouseY >= cardY && mouseY <= cardY + cardHeight)
        {
            std::cout << "Card clicked" << std::endl;
            (*deck.getCards()[i]).applyCard(mouseX, mouseY, player.getCurrentGrid(), player, this->grid.getGame());

            break;
        }
    }
}

void Graphic::handleKeyDownEvent(SDL_Event &event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
        this->grid.moveGrid(0, -10);
        break;
    case SDLK_DOWN:
        this->grid.moveGrid(0, 10);
        break;
    case SDLK_LEFT:
        this->grid.moveGrid(-10, 0);
        break;
    case SDLK_RIGHT:
        this->grid.moveGrid(10, 0);
        break;
    case SDLK_SPACE:

        /*
            Game game = this->grid.getGame();
            Grid g = game.getGrid(game.getCurrentPlayer().getCurrentGrid());
            g.resetGrid();
            game.setGrid(game.getCurrentPlayer().getCurrentGrid(), g);
            this->grid.setGame(game);*/

        std::cout << "Space clicked" << std::endl;
        Game game = this->grid.getGame();
        std::vector<Player> players = game.getPlayer();

        std::vector<std::vector<Case *>> grid = game.getGrid(0).getCases();

        int windowWidth, windowHeight;
        SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

        int totalGridWidth = grid[0].size() * 100;
        int totalGridHeight = grid.size() * 100;

        int startX = (windowWidth - totalGridWidth) / 2;
        int startY = (windowHeight - totalGridHeight) / 2;
        this->animatePLayerGravity(startX + 0 * 100 + 50, startY + 0 * 100 + 50, startX + 2 * 100 + 50, startY + 2 * 100 + 50, 40, 5, players[0]);
    }
}

void Graphic::handleCheckWin(int cellX, int cellY, Game game)
{
    Grid grid = game.getGrid(game.getCurrentPlayer().getCurrentGrid());
    grid.showGridTerminal();
    if (grid.checkWin(game.getCurrentPlayer(), cellX, cellY))
    {
        std::cout << "Player " << game.getCurrentPlayer().getSymbol() << " wins" << std::endl;
    }
}

void Graphic::eventHolder()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            handleQuitEvent();
            break;
        case SDL_MOUSEBUTTONDOWN:
            handleMouseButtonDownEvent(event);
            break;
        case SDL_KEYDOWN:
            handleKeyDownEvent(event);
            break;
        }
    }
}
