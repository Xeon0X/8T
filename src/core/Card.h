#ifndef CARD
#define CARD

/**
 * @class Card
 * @brief This class is used to represent a card in the game
 */
#include <string>
#include <iostream>
#include <vector>
class Game;
class Player;

enum
{
    Id,
    GravityId,
    AddLineId,
    AddColumnId,
    TurnGridId,
    RemoveLineId,
    RemoveColumnId,
    PlacePieceId,
    PlayCardId,
    DrawCardId,
    SwitchPlayerId

};
class Card
{
protected:
    std::string name;
    std::string description;
    int id;
    int uniqueId;
    std::vector<std::string> arrowDirection;
    bool isGlobalRule;
    bool canBeGlobalRules = false;

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
    virtual ~Card(){};

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
    std::vector<std::string> getArrowDirection();
    void setUniqueId(int id) { uniqueId = id; };
    int getUniqueId() { return uniqueId; };
    bool isAGlobalRule() const;
    void setGlobalRuleState(bool state);
    void applyWhenGlobalRule(Game &game, int CurrentGrid);

    bool getCanBeGlobal() { return canBeGlobalRules; }
};

#endif // CARD