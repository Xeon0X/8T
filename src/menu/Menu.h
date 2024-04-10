#ifndef MENU
#define MENU

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include "../graphics/Graphic.h"

/**
 * @class Menu
 * @brief This class is responsible for all the menu rendering in the game.
 */
class Menu
{
private:
    SDL_Window *window;     /**< The window of the game. */
    SDL_Renderer *renderer; /**< The renderer of the game. */
    ImGuiIO *io;            /**< The io of the game. */

    GameState gamestate = GameState::Menu; /**< The state of the game. */
    SDL_Event event;                       /**< The event of the game. */
    SDL_GLContext gl_context;              /**< The gl context of the game. */

    SDL_Texture *logoTexture; /**< The texture of the logo. */

public:
    /**
     * @brief Constructor for the Menu class.
     *
     */
    Menu();

    /**
     * @brief Destructor for the Menu class.
     *
     */
    ~Menu();

    /**
     * @brief Start the menu.
     *
     */
    void start();

    /**
     * @brief Update the menu with the game creation page.
     *
     */
    void gameCreation(Graphic &graphic);

    /**
     * @brief Draw the game creation page.
     *
     */
    void drawGameCreation(Graphic &graphic);

    /**
     * @brief Update the menu with the pause page.
     *
     */
    void pauseMenu();

    /**
     * @brief Draw the pause page.
     *
     */
    void drawPauseMenu();

    /**
     * @brief Update the menu with the choose game mode menu page.
     *
     */
    void chooseGameModeMenu();

    /**
     * @brief Draw the choose game mode menu page.
     *
     */
    void drawChooseGameModeMenu();

    /**
     * @brief Update the menu with the choose menu page.
     *
     */
    void menu();

    /**
     * @brief Draw the menu page.
     *
     */
    void drawMenu();

    /**
     * @brief Draw the end menu page.
     *
     */
    void drawEndMenu(Graphic &graphic);

    /**
     * @brief Update the menu with the end menu page.
     *
     */
    void endMenu(Graphic &graphic);
};

#endif // MENU