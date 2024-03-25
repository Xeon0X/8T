#ifndef CARD
#define CARD

/**
 * @class Card
 * @brief This class is used to represent a card in the game
 */
#include <string>
#include <iostream>
class Game;
class Player;

enum
{
    GravityId,
    AddLineId,
    AddColumnId,
    TurnGridId,
    RemoveLineId,
    RemoveColumnId

};
class Card
{
protected:
    std::string name;
    std::string description;
    int id;

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
     * @brief Get the Name object
     *
     * @return std::string
     */
    std::string getName();
    int getId() { return id; }
    bool operator==(const Card &other) const;
    virtual void applyCard(int x, int y, int currentGrid, Player &currentPlayer, Game &game, std::string sens)
    {
        std::cout << "This is not supposed to show up" << std::endl;
    };
    Card(const Card &other);
    void createNewCardAndApply(int id, int x, int y, int currentGrid, Player &currentPlayer, Game &game, std::string sens);
};

#endif // CARD