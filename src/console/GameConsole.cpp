#include "GameConsole.h"
#include <iostream>
#include "../core/Piece.h"
#include "../core/Case.h"

GameConsole::GameConsole()
{
}

GameConsole::~GameConsole()
{
}

void GameConsole::printGrid(int gridIndex)
{

    // std::vector<std::vector<Case *>> grid = this->game.getGrid(gridIndex).getCases();
    // std::string symbol = grid[0][0]->getPieces()[0].getSymbol();

    std::cout << "\n----- Grid " << gridIndex << " -----" <<std::endl;

    for (unsigned int y = 0; y < game.getGrid(gridIndex).getGridHeight(); y++)
    {
        for (unsigned int x = 0; x < game.getGrid(gridIndex).getGridWidth(); x++)
        {
            Case *c = this->game.getGrid(gridIndex).getCase(x, y);
            std::vector<Piece> pieces = c->getPieces();
            if (pieces.empty()) {
                std::cout << " ";
            } 
            else 
            {
                std::cout << pieces[0].getSymbol(); // Only one pieces limitation
            }

            if (x < game.getGrid(gridIndex).getGridWidth()-1)
            {
                std::cout << "|";
            }

            // std::vector<Piece> pieces = grid[x][y]->getPieces();
            // std::cout << pieces[0].getSymbol();
        }
        std::cout << std::endl;
    }
}

void GameConsole::printDeck(int gridIndex)
{
    std::cout << "\n----- Deck " << gridIndex << " -----" << std::endl;
    for (unsigned int i = 0; i < game.getCurrentPlayer().getDeck(gridIndex).getCards().size(); i++)
    {
        Card *card = this->game.getCurrentPlayer().getDeck(gridIndex).getCards()[i];
        if (card->getName().empty()) {
            std::cout << " ";
        } 
        else 
        {
            std::cout << card->getName();
        }

        if (i < game.getCurrentPlayer().getDeck(gridIndex).getCards().size()-1)
        {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}