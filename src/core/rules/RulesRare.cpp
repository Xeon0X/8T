#include "Card.h"
#include "Game.h"
#include "Player.h"

#include "Grid.h"
#include <iostream>
#include <vector>
class CardGravity : public Card
{

public:
    CardGravity(std::string name, std::string description, int id) : Card(name, description, id){};
    ~CardGravity(){};
    void applyCard(int x, int y, int CurrentGrid, Player &currentPlayer, Game &game) override
    {
        Grid currentGrid = game.getGrid(CurrentGrid);
        std::vector<std::vector<Case>> cases = currentGrid.getCases();
        for (int i = 0; i < cases.size(); i++)
        {
            for (int y = cases[0].size() - 1; y >= 0; y--)
            {
                if (cases[i][y].getPieces().size() > 0)
                {
                    int nextEmpty = y;
                    while (nextEmpty + 1 < cases[i].size() && cases[i][nextEmpty + 1].getPieces().size() == 0)
                    {
                        nextEmpty++;
                    }
                    if (y != nextEmpty)
                    {
                        Case c = cases[i][y];
                        cases[i][y] = cases[i][nextEmpty];
                        cases[i][nextEmpty] = c;
                        currentGrid.setCases(cases);
                        game.setGrid(CurrentGrid, currentGrid);
                    }
                }
            }
        }
    }
};