#ifndef DECK
#define DECK

#include <vector>
#include "Card.h"

/**
 * @class Deck
 * @brief This class is used to represent a deck of cards
 */

class Deck
{
private:
    std::vector<Card *> cards; /**< Cards in the deck */

public:
    /**
     * @brief Construct a new Deck object
     *
     */
    Deck();

    /**
     * @brief Construct a new Deck object
     *
     * @param cards
     */
    Deck(std::vector<Card *> cards);

    /**
     * @brief Destroy the Deck object
     *
     */
    ~Deck();

    /**
     * @brief Add a card to the deck
     *
     * @param card
     */
    void addCard(const Card &card);
    /**
     * @brief Get the cards in the deck
     *
     * @return std::vector<Card>
     */
    std::vector<Card *> getCards();

    /**
     * @brief Set the base card of the deck
     *
     */
    void setBaseCard();
    void piocheCart();

    void createNewCard(int id);
};

#endif // DECK