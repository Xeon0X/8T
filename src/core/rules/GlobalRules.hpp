#include "../Card.h"
#include "../Game.h"
#include "../Player.h"
#include "../Case.h"
#include "../Grid.h"
#include <iostream>
#include <vector>

class CardAlignToWin : public Card
{
public:
    CardAlignToWin(std::string name, std::string description, int id) : Card(name, description, id)
    {

    };
    ~CardAlignToWin(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        std::cout << "nothing to applied yet";
    }
};

class CardDrawCard : public Card
{
public:
    CardDrawCard(std::string name, std::string description, int id) : Card(name, description, id)
    {

    };
    ~CardDrawCard(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        std::cout << "nothing to applied";
    }
};

class CardSwitchPlayer : public Card
{
public:
    CardSwitchPlayer(std::string name, std::string description, int id) : Card(name, description, id)
    {

    };
    ~CardSwitchPlayer(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        std::cout << "nothing to applied";
    }
};

class CardPlacePiece : public Card
{
public:
    CardPlacePiece(std::string name, std::string description, int id) : Card(name, description, id)
    {
        
    };
    ~CardPlacePiece(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        std::cout << "nothing to applied";
    }
};

class CardPlayCard : public Card
{
public:
    CardPlayCard(std::string name, std::string description, int id) : Card(name, description, id)
    {
        
    };
    ~CardPlayCard(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        std::cout << "nothing to applied";
    }
};