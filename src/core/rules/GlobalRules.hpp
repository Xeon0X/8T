#include "../Card.h"
#include "../Game.h"
#include "../Player.h"
#include "../Case.h"
#include "../Grid.h"
#include <iostream>
#include <vector>

class CardAlignToWin : public Card // TODO
{
public:
    CardAlignToWin(std::string name, std::string description, int id) : Card(name, description, id)
    {

    };
    ~CardAlignToWin(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        Grid grid = game.getGrid(CurrentGrid);
        std::cout << "Applying...\n";
        game.getGrid(CurrentGrid);
        game.setGrid(CurrentGrid, grid);
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
        Grid grid = game.getGrid(CurrentGrid);
        GridRules rules = grid.getRules();
        rules.canDrawCard = true;
        // grid.nextGlobalRule(); // Wait for player input
        grid.setRules(rules);
        game.setGrid(CurrentGrid, grid);
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
        std::cout << "Switching...\n";
        Grid grid = game.getGrid(CurrentGrid);
        game.switchPlayer();
        grid.nextGlobalRule();
        game.setGrid(CurrentGrid, grid);
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
        Grid grid = game.getGrid(CurrentGrid);
        GridRules rules = grid.getRules();
        rules.canPlacePiece = true;
        if (grid.isGridFull()) {
            grid.nextGlobalRule(); // Do not wait for player input
            rules.canPlacePiece = false;
        }
        
        grid.setRules(rules);
        game.setGrid(CurrentGrid, grid);
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
        Grid grid = game.getGrid(CurrentGrid);
        GridRules rules = grid.getRules();
        rules.canPlayCard = true;
        if(game.getCurrentPlayer().getDeck(CurrentGrid).getCards().empty()) {
            grid.nextGlobalRule(); // Do not wait for player input
            rules.canPlayCard = false;
        }
        grid.setRules(rules);
        game.setGrid(CurrentGrid, grid);
    }
};