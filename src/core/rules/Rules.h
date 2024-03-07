#ifndef RULES
#define RULES

/**
 * @class Rules
 * @brief This class is used to represent the rules of the game
 */
class Rules
{
private:
    void *allCard[5]; /**< All the cards of the game */

public:
    /**
     * @brief Construct a new Rules object
     *
     */
    Rules(/* args */);
    /**
     * @brief Destroy the Rules object
     *
     */
    ~Rules();

    /**
     * @brief Get all the cards of the game
     *
     * @return void**
     */
    void **getAllCard();

    /**
     * @brief Set all the cards of the game
     *
     */
    void setAllCard();
};

#endif // RULES
