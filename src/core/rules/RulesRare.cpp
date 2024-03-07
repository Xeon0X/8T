#include "Rules.h"
#include "Game.h"

inline void applyGravity(int cellX, int cellY, int CurrentGrid, Game &game)
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
                    std::cout << "Gravity" << std::endl;
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