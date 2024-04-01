#include "../Card.h"
#include "../Game.h"
#include "../Player.h"
#include "../Case.h"
#include "../Grid.h"
#include <iostream>
#include <vector>

class CardDrawCard : public Card
{
public:
    CardDrawCard(std::string name, std::string description, int id) : Card(name, description, id)
    {
        arrowDirection.push_back("down");
    };
    ~CardDrawCard(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game, std::string sens) override
    {

        Grid currentGrid = game.getGrid(CurrentGrid);
        GridRules rules = currentGrid.getRules();
        rules.gravity = true;
        currentGrid.setRules(rules);
        std::vector<std::vector<Case *>> cases = currentGrid.getCases();
        for (int i = 0; i < cases[0].size(); i++)
        {
            for (int x = cases.size() - 1; x >= 0; x--)
            {
                if (cases[x][i]->getPieces().size() > 0)
                {
                    int nextEmpty = x;
                    while (nextEmpty + 1 < cases.size() && cases[nextEmpty + 1][i]->getPieces().size() == 0)
                    {
                        nextEmpty++;
                    }
                    if (x != nextEmpty)
                    {
                        std::cout << "Draw" << std::endl;
                        Case *c = cases[x][i];
                        cases[x][i] = cases[nextEmpty][i];
                        cases[nextEmpty][i] = c;
                        currentGrid.setCases(cases);
                        game.setGrid(CurrentGrid, currentGrid);
                    }
                }
            }
        }
    }
};
