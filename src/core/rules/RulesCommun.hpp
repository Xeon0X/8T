#include "../Case.h"
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
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        if (sens == "up")
        {
            addUp(CurrentGrid, game);
        }
        else if (sens == "down")
        {
            addDown(CurrentGrid, game);
        }
    }

    void addUp(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        std::vector<Case *> row;
        for (int i = 0; i < cases[0].size(); i++)
        {
            row.push_back(new Case());
        }
        cases.insert(cases.begin(), row);
        currentGrid.setCases(cases);
        game.setGrid(CurrentGrid, currentGrid);
    }

    void addDown(int CurrentGrid, Game &game)
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
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        if (sens == "left")
        {
            addLeft(CurrentGrid, game);
        }
        else if (sens == "right")
        {
            addRight(CurrentGrid, game);
        }
    }

    void addLeft(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        for (int i = 0; i < cases.size(); i++)
        {
            cases[i].insert(cases[i].begin(), new Case());
        }
        currentGrid.setCases(cases);
        game.setGrid(CurrentGrid, currentGrid);
    }

    void addRight(int CurrentGrid, Game &game)
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
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        if (sens == "up")
        {
            removeUp(CurrentGrid, game);
        }
        else if (sens == "down")
        {
            removeDown(CurrentGrid, game);
        }
    }

    void removeUp(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        if (cases.size() > 1)
        {
            cases.erase(cases.begin());
            currentGrid.setCases(cases);
            game.setGrid(CurrentGrid, currentGrid);
        }
    }

    void removeDown(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        if (cases.size() > 1)
        {
            cases.pop_back();
            currentGrid.setCases(cases);
            game.setGrid(CurrentGrid, currentGrid);
        }
    }
};

class CardRemoveColumn : public Card
{

public:
    CardRemoveColumn(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardRemoveColumn(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        if (sens == "left")
        {
            removeLeft(CurrentGrid, game);
        }
        else if (sens == "right")
        {
            removeRight(CurrentGrid, game);
        }
    }

    void removeLeft(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        for (int i = 0; i < cases.size(); i++)
        {
            if (cases[i].size() > 1)
            {
                cases[i].pop_back();
            }
        }
        currentGrid.setCases(cases);
        game.setGrid(CurrentGrid, currentGrid);
    }

    void removeRight(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        for (int i = 0; i < cases.size(); i++)
        {
            if (cases[i].size() > 1)
            {
                cases[i].erase(cases[i].begin());
            }
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
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        if (sens == "left")
        {
            turnLeft(CurrentGrid, game);
        }
        else if (sens == "right")
        {
            turnRight(CurrentGrid, game);
        }
    }

    void turnLeft(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        std::vector<std::vector<Case *>> newCases;

        for (int i = cases[0].size() - 1; i >= 0; i--)
        {
            std::vector<Case *> newRow;
            for (int j = 0; j < cases.size(); j++)
            {
                newRow.push_back(cases[j][i]);
            }
            newCases.push_back(newRow);
        }

        currentGrid.setCases(newCases);
        game.setGrid(CurrentGrid, currentGrid);
    }

    void turnRight(int CurrentGrid, Game &game)
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
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
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

class Test : public Card
{

public:
    Test(std::string name, std::string description, int id) : Card(name, description, id){};
    ~Test(){};
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