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
    font = TTF_OpenFont("res/arial.ttf", 24);
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

void Graphic::drawCircle(int x, int y, int r)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int i = 0; i < 360; i++)
    {
        SDL_RenderDrawPoint(renderer, x + r * cos(i), y + r * sin(i));
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
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
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

        grid.showGrid(renderer);

        present();
    }
}

void Graphic::eventHolder()
{
    SDL_Event event;
    bool mouseDown = false;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            mouseDown = true;
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
                std::cout << "Cell clicked: " << cellX << " " << cellY << std::endl;
            }
        }
        else if (event.type == SDL_MOUSEBUTTONUP)
        {
            mouseDown = false;
        }
        else if (event.type == SDL_KEYDOWN)
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
            }
        }
    }
}