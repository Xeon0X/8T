#include "Graphic.h"
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
    font = TTF_OpenFont("font/arial.ttf", 24);

    fontColor = {255, 255, 255, 255};
    fontSize = 24;
    fontStyle = TTF_STYLE_NORMAL;
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

void Graphic::drawCircle(int x, int y, int r, int thickness)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int z = 0; z < thickness; z++)
    {
        for (int w = 0; w < 360; w++)
        {
            SDL_RenderDrawPoint(renderer, x + r * cos(w) - z, y + r * sin(w) - z);
        }
    }
}

void Graphic::drawCross(int x, int y, int r, int thickness)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
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
    std::cout << text << std::endl;
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

void Graphic::play()
{
    while (running)
    {
        eventHolder();
        clear();

        grid.showGrid(renderer, *this);

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

    int gridX = ((screenWidth - CasesHeight * this->grid.getCaseHeight()) / 2) + this->grid.getGridX();
    int gridY = ((screenHeight - CasesWidth * this->grid.getCaseHeight()) / 2) + this->grid.getGridY();

    mouseX -= gridX;
    mouseY -= gridY;

    int cellX = mouseX / 100;
    int cellY = mouseY / 100;

    if (cellX >= 0 && cellX < CasesWidth && cellY >= 0 && cellY < CasesHeight)
    {
        Game game = this->grid.getGame();
        Grid grid = game.getGrid(CurrentGrid);

        if (grid.getCase(cellX, cellY).getPieces().size() > 0)
        {
            if (grid.getCase(cellX, cellY).getPieces()[0].getSymbol() == game.getCurrentPlayer().getSymbol())
            {
                createAndSetPiece(cellX, cellY, CurrentGrid);
            }
        }
        else
        {
            createAndSetPiece(cellX, cellY, CurrentGrid);
        }
        handleCheckWin(cellX, cellY);

        game = this->grid.getGame();
        game.switchPlayer();
        this->grid.setGame(game);
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
        Game game = this->grid.getGame();
        Grid g = game.getGrid(game.getCurrentPlayer().getCurrentGrid());
        g.resetGrid();
        game.setGrid(game.getCurrentPlayer().getCurrentGrid(), g);
        this->grid.setGame(game);
    }
}

void Graphic::createAndSetPiece(int cellX, int cellY, int CurrentGrid)
{
    std::map<std::string, float> pieceEffects, caseEffects;
    Game game = this->grid.getGame();
    Piece piece = Piece(game.getCurrentPlayer().getSymbol(), game.getCurrentPlayer().getColor(), pieceEffects);
    std::vector<Piece> pieces;
    pieces.push_back(piece);
    Case c = Case(pieces, caseEffects);

    Grid grid = game.getGrid(CurrentGrid);
    grid.setCase(cellX, cellY, c);
    game.setGrid(CurrentGrid, grid);
    this->grid.setGame(game);

    std::cout << "Case " << cellX << " " << cellY << " clicked" << std::endl;
}

void Graphic::handleCheckWin(int cellX, int cellY)
{
    Game game = this->grid.getGame();
    Grid grid = game.getGrid(game.getCurrentPlayer().getCurrentGrid());
    std::cout << "Checking win" << std::endl;
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