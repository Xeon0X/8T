#include "Console.h"
#include "Case.h"
#include "Piece.h"
#include <iostream>

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
    for (unsigned int y = 0; y < game.getGrid(gridIndex).getGridHeight(); y++) {
        for (unsigned int x = 0; x < game.getGrid(gridIndex).getGridWidth(); x++) {
            std::string symbol = game.getGrid(0).getCase(x, y)->getPieces()[0].getSymbol();
            // std::vector<Piece> pieces = grid[x][y]->getPieces();
            // std::cout << pieces[0].getSymbol();
        }
        std::cout << std::endl;
    }
}