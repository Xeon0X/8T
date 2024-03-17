#include "Console.h"
#include <iostream>
#include "../core/Piece.h"
#include "../core/Case.h"

GameConsole::GameConsole()
{
}

GameConsole::~GameConsole()
{
}

void GameConsole::printGrid()
{

    int gridIndex = 0;
    std::vector<std::vector<Case *>> grid = this->game.getGrid(gridIndex).getCases();

    std::string symbol = grid[0][0]->getPieces()[0].getSymbol();

    for (unsigned int y = 0; y < game.getGrid(gridIndex).getGridHeight(); y++)
    {
        for (unsigned int x = 0; x < game.getGrid(gridIndex).getGridWidth(); x++)
        {
            Case *c = this->game.getGrid(0).getCase(x, y);
            std::vector<Piece> pieces = c->getPieces();
            if (pieces.size() > 0)
            {
                std::cout << pieces[0].getSymbol();
            }
            else
            {
                std::cout << ".";
            }

            // std::vector<Piece> pieces = grid[x][y]->getPieces();
            // std::cout << pieces[0].getSymbol();
        }
        std::cout << std::endl;
    }
}