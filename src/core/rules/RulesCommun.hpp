#include "../Case.h"
#include "../Game.h"
#include "../Player.h"

#include "../Grid.h"
#include <vector>

class CardAddLine : public Card
{

public:
    CardAddLine(std::string name, std::string description, int id) : Card(name, description, id)
    {
        arrowDirection.push_back("up");
        arrowDirection.push_back("down");
    };
    ~CardAddLine(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        applyWhenGlobalRule(game, CurrentGrid);
        if (sens == "up" || sens == "default")
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
        for (unsigned int i = 0; i < cases[0].size(); i++)
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
        for (unsigned int i = 0; i < cases[0].size(); i++)
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
    CardAddColumn(std::string name, std::string description, int id) : Card(name, description, id)
    {
        arrowDirection.push_back("left");
        arrowDirection.push_back("right");
    };
    ~CardAddColumn(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        applyWhenGlobalRule(game, CurrentGrid);
        if (sens == "left" || sens == "default")
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
        for (unsigned int i = 0; i < cases.size(); i++)
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
        for (unsigned int i = 0; i < cases.size(); i++)
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
    CardRemoveLine(std::string name, std::string description, int id) : Card(name, description, id)
    {
        arrowDirection.push_back("up");
        arrowDirection.push_back("down");
    };
    ~CardRemoveLine(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        applyWhenGlobalRule(game, CurrentGrid);
        if (sens == "up" || sens == "default")
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
    CardRemoveColumn(std::string name, std::string description, int id) : Card(name, description, id)
    {
        arrowDirection.push_back("left");
        arrowDirection.push_back("right");
    };
    ~CardRemoveColumn(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        applyWhenGlobalRule(game, CurrentGrid);
        if (sens == "left" || sens == "default")
        {
            removeLeft(CurrentGrid, game);
        }
        else if (sens == "right")
        {
            removeRight(CurrentGrid, game);
        }
    }

    void removeRight(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        for (unsigned int i = 0; i < cases.size(); i++)
        {
            if (cases[i].size() > 1)
            {
                cases[i].pop_back();
            }
        }
        currentGrid.setCases(cases);
        game.setGrid(CurrentGrid, currentGrid);
    }

    void removeLeft(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        for (unsigned int i = 0; i < cases.size(); i++)
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
    CardTurnGrid(std::string name, std::string description, int id) : Card(name, description, id)
    {
        this->canBeGlobalRules = true;
        arrowDirection.push_back("left");
        arrowDirection.push_back("right");
    };
    ~CardTurnGrid(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        applyWhenGlobalRule(game, CurrentGrid);
        if (sens == "left" || sens == "default")
        {
            turnLeft(CurrentGrid, game);
        }
        else if (sens == "right")
        {
            turnRight(CurrentGrid, game);
        }
    }

    void turnRight(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        std::vector<std::vector<Case *>> newCases;

        for (int i = cases[0].size() - 1; i >= 0; i--)
        {
            std::vector<Case *> newRow;
            for (unsigned int j = 0; j < cases.size(); j++)
            {
                newRow.push_back(cases[j][i]);
            }
            newCases.push_back(newRow);
        }

        currentGrid.setCases(newCases);
        game.setGrid(CurrentGrid, currentGrid);
    }

    void turnLeft(int CurrentGrid, Game &game)
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        std::vector<std::vector<Case *>> newCases;

        for (unsigned int i = 0; i < cases[0].size(); i++)
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
        applyWhenGlobalRule(game, CurrentGrid);
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

class CardAlignToWinPlusOne : public Card
{
public:
    CardAlignToWinPlusOne(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardAlignToWinPlusOne(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        applyWhenGlobalRule(game, CurrentGrid);
        Grid grid = game.getGrid(CurrentGrid);
        grid.setNbAlignToWin(grid.getNbAlignToWin() + 1);
        game.setGrid(CurrentGrid, grid);
    }
};

class CardAlignToWinMinusOne : public Card
{
public:
    CardAlignToWinMinusOne(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardAlignToWinMinusOne(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {
        applyWhenGlobalRule(game, CurrentGrid);
        Grid grid = game.getGrid(CurrentGrid);
        grid.setNbAlignToWin(grid.getNbAlignToWin() - 1);
        game.setGrid(CurrentGrid, grid);
    }
};