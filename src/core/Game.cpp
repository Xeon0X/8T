#include "Game.h"
#include <iostream>

Game::Game()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->window = SDL_CreateWindow("Just a TicTacToe...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!this->window)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    this->renderer = SDL_CreateRenderer(this->window, -1, render_flags);
    if (!this->renderer)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        exit(1);
    }
    this->players.push_back(Player("X"));
    this->players.push_back(Player("O"));

    this->grids.push_back(Grid(this->players[0], SCREEN_HEIGHT, SCREEN_WIDTH));
}

Game::~Game()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Game::start()
{
    while (!this->stop)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                this->stop = true;
            }
        }
        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
        SDL_RenderClear(this->renderer);

        this->grids[0].showGrid(this->renderer);

        SDL_RenderPresent(this->renderer);
    }
}