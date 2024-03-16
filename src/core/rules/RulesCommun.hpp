#include "Card.h"
#include "Game.h"
#include "Player.h"

#include "Grid.h"
#include <iostream>
#include <vector>

class CardAddLine : public Card
{

public:
    CardAddLine(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardAddLine(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game) override
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        std::vector<Case *> row;
        for (int i = 0; i < cases[0].size(); i++)
        {
            row.push_back(new Case());
        }
        cases.push_back(row);
        currentGrid.setCases(cases);
        game.setGrid(CurrentGrid, currentGrid);
    }
};

class CardAddColumn : public Card
{

public:
    CardAddColumn(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardAddColumn(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game) override
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        for (int i = 0; i < cases.size(); i++)
        {
            cases[i].push_back(new Case());
        }
        currentGrid.setCases(cases);
        game.setGrid(CurrentGrid, currentGrid);
    }
};