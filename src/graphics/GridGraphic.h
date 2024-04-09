#ifndef GRAPHIC_GRID
#define GRAPHIC_GRID

/**
 * @class GridGraphic
 * @brief This class is responsible for the graphical rendering of the grid in the game.
 */

#include <SDL2/SDL.h>
#include "../core/Game.h"

class Graphic;
class GridGraphic
{
private:
    Game game;     /**< The game of the grid. */
    int gridX = 0; /**< The x and y coordinates of the grid. */
    int gridY = 0; /**< The x and y coordinates of the grid. */
    int initialGridWidth;
    int initialGridHeight;
    int initialGridX;
    int initialGridY;

    std::vector<SDL_Texture *> playerTextures, cardsTextures;
    SDL_Texture *deckTexture;
    SDL_Texture *caseTexture;
    SDL_Texture *backgroundTexture;

    SDL_Texture *arrowUpTexture;
    SDL_Texture *arrowDownTexture;
    SDL_Texture *arrowLeftTexture;
    SDL_Texture *arrowRightTexture;
    SDL_Texture *arrowTurnLeftTexture;
    SDL_Texture *arrowTurnRightTexture;

    SDL_Texture *addToRulesTexture;
    SDL_Texture *logo;
    SDL_Texture *score;

public:
    /**
     * @brief Constructor for the GridGraphic class.
     */
    GridGraphic(/* args */);

    GridGraphic(SDL_Renderer *renderer, Player player1, Player player2);
    /**
     * @brief Destructor for the GridGraphic class.
     */
    ~GridGraphic();

    /**
     * @brief Shows the grid on the screen.
     *
     * @param renderer The renderer of the game.
     * @param graphic The graphic of the game.
     */
    void showGrid(SDL_Renderer *renderer, Graphic &graphic);

    /**
     * @brief Moves the grid on the screen.
     *
     * @param dx The change in the x coordinate of the grid.
     * @param dy The change in the y coordinate of the grid.
     */
    void moveGrid(int dx, int dy);

    /**
     * @brief Gets the x coordinate of the grid.
     *
     * @return The x coordinate of the grid.
     */
    int getGridX() { return gridX; }

    /**
     * @brief Gets the y coordinate of the grid.
     *
     * @return The y coordinate of the grid.
     */
    int getGridY() { return gridY; }

    /**
     * @brief Gets the width of a case in the grid.
     *
     * @return The width of a case in the grid.
     */
    int getCaseWidth() { return 100; }

    /**
     * @brief Gets the height of a case in the grid.
     *
     * @return The height of a case in the grid.
     */
    int getCaseHeight() { return 100; }

    /**
     * @brief Gets the game of the grid.
     *
     * @return The game of the grid.
     */
    Game &getGame();

    /**
     * @brief Sets the game of the grid.
     *
     * @param game The game of the grid.
     */
    void setGame(Game game) { this->game = game; }

    /**
     * @brief Draws the deck on the screen.
     *
     * @param renderer The renderer of the game.
     * @param graphic The graphic of the game.
     */
    void drawDeck(SDL_Renderer *renderer, Graphic &graphic);
    void drawGlobalrules(SDL_Renderer *renderer, Graphic &graphic);
    void setInitialGridSize(int width, int height);
    void drawPartInterface(SDL_Renderer *renderer, Graphic &graphic);
    void drawPioche(SDL_Renderer *renderer, Graphic &graphic);
    void drawArrowDirection(SDL_Renderer *renderer, Graphic &graphic);
    void drawGlobalRuleButton(SDL_Renderer *renderer, Graphic &graphic);
    void initCardTexture(SDL_Renderer *renderer);
    void drawInfoPart(SDL_Renderer *renderer, Graphic &graphic);
};

#endif // GRAPHIC_GRID