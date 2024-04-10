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
        this->canBeGlobalRules = true;
    };
    ~CardAlignToWin(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        Grid grid = game.getGrid(CurrentGrid);
        GridRules rules = grid.getRules();

        grid.nextGlobalRule();
        grid.setRules(rules);
        game.setGrid(CurrentGrid, grid);
        int nbAlignToWin = grid.getNbAlignToWin();

        for (int x = 0; x < grid.getGridWidth(); x++) 
        {
            for (int y = 0; y < grid.getGridHeight(); y++)
            {
                if ((grid.getGridWidth() - x) > nbAlignToWin-1) // Enough spaces to win on the line
                {
                    if (y >= nbAlignToWin-1) // Enough space to win on the anti-diagonal from bottom to top from here, going right
                    {
                        game.computeAlignementScoreOnDirection(x, y, CurrentGrid, 0);
                    }
                    game.computeAlignementScoreOnDirection(x, y, CurrentGrid, 1);

                    if ((grid.getGridHeight() - y) > nbAlignToWin-1) // Enough space to win on the diagonal from top to bottom from here, going right
                    {
                        game.computeAlignementScoreOnDirection(x, y, CurrentGrid, 3);
                    }
                }

                if ((grid.getGridHeight() - y) > nbAlignToWin-1) // Enough spaces to win on the row
                {
                    game.computeAlignementScoreOnDirection(x, y, CurrentGrid, 2);
                }
            }
        }
    }
};

class CardDrawCard : public Card
{
public:
    CardDrawCard(std::string name, std::string description, int id) : Card(name, description, id)
    {
        this->canBeGlobalRules = true;
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
    CardSwitchPlayer(std::string name, std::string description, int id) : Card(name, description, id){};
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
        this->canBeGlobalRules = true;
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
    CardPlayCard(std::string name, std::string description, int id) : Card(name, description, id)
    {
        this->canBeGlobalRules = true;
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