#ifndef CARD
#define CARD

/**
 * @class Card
 * @brief This class is used to represent a card in the game
 */
#include <string>

class Game;
typedef void (*FuncType)(int, int, int, Game &); // Function pointer type
class Card
{
private:
    std::string name;
    std::string description;
    int id;
    std::string pathCardImage;
    std::string pathCardSound;

public:
    /**
     * @brief Construct a new Card object
     *
     * @param name
     * @param description
     * @param id
     */
    Card(std::string name, std::string description, int id);

    /**
     * @brief Destroy the Card object
     *
     */
    ~Card();

    /**
     * @brief Apply the card effect
     *
     * @param allCards
     * @param posX
     * @param posY
     * @param currentGrid
     * @param game
     */
    void applyCard(void *allCards[5], int posX, int posY, int currentGrid, Game &game);

    /**
     * @brief Get the Name object
     *
     * @return std::string
     */
    std::string getName();
};

#endif // CARD