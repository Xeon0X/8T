#ifndef DECK
#define DECK

#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.h"

/**
 * @class Deck
 * @brief This class is used to represent a deck of cards
 */

class Deck
{
private:
    std::vector<Card *> cards; /**< Cards in the deck */
    int uniqueIdCounter = 0;

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
    void drawCard();

    void createNewCard(int id);
    void removeCard(Card *card);
};

#endif // DECK