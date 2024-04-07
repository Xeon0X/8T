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
    CardAlignToWin(std::string name, std::string description, int id) : Card(name, description, id){

                                                                        };
    ~CardAlignToWin(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        Grid grid = game.getGrid(CurrentGrid);
        Player player1 = game.getPlayer()[0];

        GridRules rules = grid.getRules();
        rules.checkWin = true;
        grid.nextGlobalRule();
        grid.setRules(rules);
        game.setGrid(CurrentGrid, grid);

        for (int i = 0; i < grid.getGridHeight(); i++)
        {
            for (int j = 0; j < grid.getGridWidth(); j++)
            {
                if (grid.checkWin(player1, i, j))
                {
                    // Victoire !
                    player1.setScore(player1.getScore() + 1);
                    game.replacePlayer(player1);
                }
            }
        }
        Player player2 = game.getPlayer()[1];
        for (int i = 0; i < grid.getGridHeight(); i++)
        {
            for (int j = 0; j < grid.getGridWidth(); j++)
            {
                if (grid.checkWin(player2, i, j))
                {
                    // Victoire !
                    player2.setScore(player2.getScore() + 1);

                    game.replacePlayer(player2);
                }
            }
        }
    }
};

class CardDrawCard : public Card
{
public:
    CardDrawCard(std::string name, std::string description, int id) : Card(name, description, id){

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
    CardSwitchPlayer(std::string name, std::string description, int id) : Card(name, description, id){

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
    CardPlacePiece(std::string name, std::string description, int id) : Card(name, description, id){

                                                                        };
    ~CardPlacePiece(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        Grid grid = game.getGrid(CurrentGrid);
        GridRules rules = grid.getRules();
        rules.canPlacePiece = true;
        if (grid.isGridFull())
        {
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
    CardPlayCard(std::string name, std::string description, int id) : Card(name, description, id){

                                                                      };
    ~CardPlayCard(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        Grid grid = game.getGrid(CurrentGrid);
        GridRules rules = grid.getRules();
        rules.canPlayCard = true;
        if (game.getCurrentPlayer().getDeck(CurrentGrid).getCards().empty())
        {
            grid.nextGlobalRule(); // Do not wait for player input
            rules.canPlayCard = false;
        }
        grid.setRules(rules);
        game.setGrid(CurrentGrid, grid);
    }
};