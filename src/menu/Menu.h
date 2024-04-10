#ifndef MENU
#define MENU

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include "../graphics/Graphic.h"

class Menu
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    ImGuiIO *io;

    GameState gamestate = GameState::Menu;
    SDL_Event event;
    SDL_GLContext gl_context;

public:
    Menu(/* args */);
    ~Menu();

    void start();
    void gameCreation(Graphic &graphic);
    void drawGameCreation(Graphic &graphic);
    void pauseMenu();
    void drawPauseMenu();
    void chooseGameModeMenu();
    void drawChooseGameModeMenu();
    void menu();
    void drawMenu();
    void drawEndMenu();
    void endMenu();
};

#endif // MENU