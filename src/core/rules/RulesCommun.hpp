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

class CardRemoveLine : public Card
{

public:
    CardRemoveLine(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardRemoveLine(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game) override
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        cases.pop_back();
        currentGrid.setCases(cases);
        game.setGrid(CurrentGrid, currentGrid);
    }
};

class CardRemoveColumn : public Card
{

public:
    CardRemoveColumn(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardRemoveColumn(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game) override
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        for (int i = 0; i < cases.size(); i++)
        {
            cases[i].pop_back();
        }
        currentGrid.setCases(cases);
        game.setGrid(CurrentGrid, currentGrid);
    }
};

class CardTurnGrid : public Card
{

public:
    CardTurnGrid(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardTurnGrid(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game) override
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        std::vector<std::vector<Case *>> newCases;

        for (int i = 0; i < cases[0].size(); i++)
        {
            std::vector<Case *> newRow;
            for (int j = cases.size() - 1; j >= 0; j--)
            {
                newRow.push_back(cases[j][i]);
            }
            newCases.push_back(newRow);
        }

        currentGrid.setCases(newCases);
        game.setGrid(CurrentGrid, currentGrid);
    }
};

class CardInvertColumnLine : public Card
{

public:
    CardInvertColumnLine(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardInvertColumnLine(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game) override
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        std::vector<std::vector<Case *>> newCases;

        for (int i = cases.size() - 1; i >= 0; i--)
        {
            std::vector<Case *> newRow;
            for (int j = cases[i].size() - 1; j >= 0; j--)
            {
                newRow.push_back(cases[i][j]);
            }
            newCases.push_back(newRow);
        }

        currentGrid.setCases(newCases);
        game.setGrid(CurrentGrid, currentGrid);
    }
};