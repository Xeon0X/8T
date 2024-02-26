#ifndef GAME
#define GAME

#include <vector>
#include "Grid.h"
#include "Player.h"
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
class Game
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool stop = false;
    std::vector<Grid> grids;
    std::vector<Player> players;

public:
    Game(/* args */);
    ~Game();
    void start();
};

#endif // Game
