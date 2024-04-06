#ifndef GRAPHIC
#define GRAPHIC

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "GridGraphic.h"

/**
 * @class Graphic
 * @brief This class is responsible for all the graphical rendering in the game.
 */

class Graphic
{

private:
    SDL_Window *window;     /**< The window of the game. */
    SDL_Renderer *renderer; /**< The renderer of the game. */
    SDL_Color color;        /**< The color of the renderer. */
    TTF_Font *font;         /**< The font of the renderer. */
    SDL_Color fontColor;    /**< The color of the font. */
    int fontSize;           /**< The size of the font. */
    int fontStyle;          /**< The style of the font. */

    bool running = true; /**< The state of the game. */

    GridGraphic grid; /**< The grid of the game. */

    Card *cardClicked;          /**< The card of the game. */
    bool isCardClicked = false; /**< The state of the card. */
public:
    SDL_Rect deckPart;
    SDL_Rect pioche;
    SDL_Rect globalRuleButton;
    int time;
    /**
     * @brief Constructor for the Graphic class.
     *
     * Initializes the color, font, fontColor, fontSize, and fontStyle.
     */
    Graphic();

    /**
     * @brief Destructor for the Graphic class.
     *
     * Destroys the renderer and window.
     */
    ~Graphic();

    /**
     * @brief Draws a rectangle on the screen.
     *
     * @param x The x coordinate of the top-left corner of the rectangle.
     * @param y The y coordinate of the top-left corner of the rectangle.
     * @param w The width of the rectangle.
     * @param h The height of the rectangle.
     */
    void drawRect(int x, int y, int w, int h);

    /**
     * @brief Draws a line on the screen.
     *
     * @param x1 The x coordinate of the start of the line.
     * @param y1 The y coordinate of the start of the line.
     * @param x2 The x coordinate of the end of the line.
     * @param y2 The y coordinate of the end of the line.
     */
    void drawLine(int x1, int y1, int x2, int y2);

    /**
     * @brief Draws a circle on the screen.
     *
     * @param x The x coordinate of the center of the circle.
     * @param y The y coordinate of the center of the circle.
     * @param r The radius of the circle.
     * @param thickness The thickness of the circle.
     * @param player The player who owns the circle.
     */
    void drawCircle(int x, int y, int r, int thickness, Player player);

    /**
     * @brief Draws a cross on the screen.
     *
     * @param x The x coordinate of the center of the cross.
     * @param y The y coordinate of the center of the cross.
     * @param r The radius of the cross.
     * @param thickness The thickness of the cross.
     * @param player The player who owns the cross.
     */
    void drawCross(int x, int y, int r, int thickness, Player player);

    /**
     * @brief Draws a point on the screen.
     *
     * @param x The x coordinate of the point.
     * @param y The y coordinate of the point.
     */

    void animatePLayerGravity(int x1, int y1, int x2, int y2, int r, int thickness, Player player);
    void drawPoint(int x, int y);

    /**
     * @brief Draws text on the screen.
     *
     * @param text The text to be drawn.
     * @param x The x coordinate of the text.
     * @param y The y coordinate of the text.
     */
    void drawText(const char *text, int x, int y);

    /**
     * @brief Clears the screen.
     */
    void clear();

    /**
     * @brief Presents the screen.
     */
    void present();

    /**
     * @brief Sets the color of the renderer.
     *
     * @param r The red value of the color.
     * @param g The green value of the color.
     * @param b The blue value of the color.
     * @param a The alpha value of the color.
     */
    void setColor(int r, int g, int b, int a);

    /**
     * @brief Sets the draw color of the renderer.
     *
     * @param r The red value of the color.
     * @param g The green value of the color.
     * @param b The blue value of the color.
     * @param a The alpha value of the color.
     */
    void setDrawColor(int r, int g, int b, int a);

    /**
     * @brief Sets the font of the renderer.
     *
     * @param font The font to be set.
     * @param size The size of the font.
     */
    void setFont(const char *font, int size);

    /**
     * @brief Sets the font size of the renderer.
     *
     * @param size The size of the font.
     */
    void setFontSize(int size);

    /**
     * @brief Sets the font color of the renderer.
     *
     * @param r The red value of the color.
     * @param g The green value of the color.
     * @param b The blue value of the color.
     * @param a The alpha value of the color.
     */
    void setFontColor(int r, int g, int b, int a);

    /**
     * @brief Sets the font style of the renderer.
     *
     * @param style The style of the font.
     */
    void setFontStyle(int style);

    /**
     * @brief Draws a player on the screen.
     *
     * @param x The x coordinate of the player.
     * @param y The y coordinate of the player.
     * @param radius The radius of the player.
     * @param thickness The thickness of the player.
     * @param player The player to be drawn.
     */
    void drawPlayer(int x, int y, int radius, int thickness, Player player);

    /**
     * @brief Handle all the event of the game.
     */
    void eventHolder();

    /**
     * @brief Handle the quit event of the game.
     */
    void handleQuitEvent();

    /**
     * @brief Handle the mouse button down event of the game.
     *
     * @param event The event to be handled.
     */
    void handleMouseButtonDownEvent(SDL_Event &event);

    /**
     * @brief Handle the key down event of the game.
     *
     * @param event The event to be handled.
     */
    void handleKeyDownEvent(SDL_Event &event);

    /**
     * @brief Play the game.
     */
    void play();

    /**
     * @brief Apply global rules one by one.
     */
    void gameloop();

    /**
     * @brief Handle the check win event of the game.
     *
     * @param cellX The x coordinate of the cell to be checked.
     * @param cellY The y coordinate of the cell to be checked.
     * @param game The game to be checked.
     */
    void handleCheckWin(int cellX, int cellY, Game game);
    void applyGravityAnimation();
    bool MouseClickInterface(int x, int y);
    bool isCardEmpty();
    void deleteCard();
    void setCard(Card *card);
    Card *getCard(); // Get the card that is clicked
    void drawArrow(int x1, int y1, int x2, int y2, int size, int thickness, std::string sens);
    void handleArrowClick(int mouseX, int mouseY, int screenWidth, int screenHeight);
    void handleGlobalRuleButtonClick(int mouseX, int mouseY, int screenWidth, int screenHeight);
};

#endif // GRAPHIC
