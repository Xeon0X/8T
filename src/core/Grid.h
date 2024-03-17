#ifndef GRID
#define GRID

#include <vector>
#include "Player.h"
#include "Card.h"
#include <string>
#include <iostream>

class Case;
struct GridRules
{
    bool gravity = false;
};

/**
 * @class Grid
 * @brief This class is used to represent the game grid
 */
class Grid
{
private:
    std::vector<std::vector<Case *>> cases; /**< Cases of the grid */
    std::vector<Card> globalRules;          /**< Global rules of the grid */
    GridRules rules;                        /**< Rules of the grid */

    int nbAlignToWin = 3; /**< Number of pieces to align to win */

public:
    /**
     * @brief Construct a new Grid object
     *
     */
    Grid();

    /**
     * @brief Construct a new Grid object
     *
     * @param cases
     */
    ~Grid();

    /**
     * @brief Add a global rule to the grid
     *
     * @param card
     */
    void addGlobalRule(Card card);

    /**
     * @brief Get the global rules of the grid
     *
     * @return std::vector<Card>
     */
    std::vector<std::vector<Case *>> getCases();

    /**
     * @brief Set the cases of the grid
     *
     * @param cases
     */
    void setCases(std::vector<std::vector<Case *>> cases);

    /**
     * @brief Get the width of the grid
     *
     * @return int
     */
    int getGridWidth();

    /**
     * @brief Get the height of the grid
     *
     * @return int
     */
    int getGridHeight();

    /**
     * @brief Set the number of pieces to align to win
     *
     * @param nb
     */
    void setNbAlignToWin(int nb);

    /**
     * @brief Get the number of pieces to align to win
     *
     * @return int
     */
    int getNbAlignToWin();

    /**
     * @brief Check if a player has won
     *
     * @param player
     * @param cellX
     * @param cellY
     * @return true
     * @return false
     */
    bool checkWin(Player player, int cellX, int cellY);

    /**
     * @brief Set the case at the given position
     *
     * @param x
     * @param y
     * @param c
     */
    void setCase(int x, int y, Case *c);

    /**
     * @brief Get the case at the given position
     *
     * @param x
     * @param y
     * @return Case
     */
    Case *getCase(int x, int y);

    /**
     * @brief Reset the grid
     *
     */
    void resetGrid();

    /**
     * @brief Create the global rules of the grid
     *
     */
    void createGlobalRules();

    /**
     * @brief Show the grid terminal
     *
     */
    void showGridTerminal();

    /**
     * @brief Get the rules of the grid
     *
     * @return GridRules
     */
    GridRules getRules();

    /**
     * @brief Set the rules of the grid
     *
     * @param rules
     */
    void setRules(GridRules rules);
};

#endif // GRID