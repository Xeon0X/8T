#include "Game.h"
#include <iostream>

Game::Game()
{

    this->players.push_back(Player("X", "red"));
    this->players.push_back(Player("O", "blue"));

    this->grids.push_back(Grid());
    this->currentPlayer = this->players[0];
}

Game::~Game()
{
}

Grid Game::getGrid(int index)
{
    return this->grids[index];
}

Player Game::getCurrentPlayer()
{
    return this->currentPlayer;
}

void Game::addGrid(const Grid &grid)
{
    this->grids.push_back(grid);
}

void Game::setGrid(int index, const Grid &grid)
{
    this->grids[index] = grid;
}

void Game::switchPlayer()
{
    if (this->currentPlayer.getSymbol() == "X")
    {
        this->currentPlayer = this->players[1];
    }
    else
    {
        this->currentPlayer = this->players[0];
    }
}

std::vector<Player> Game::getPlayer()
{
    return this->players;
}

void Game::createAndSetPiece(int cellX, int cellY, int CurrentGrid)
{
    PieceEffects pieceEffects;
    CaseEffects caseEffects;
    Piece piece = Piece(this->currentPlayer.getSymbol(), this->currentPlayer.getColor(), pieceEffects);
    std::vector<Piece> pieces;
    pieces.push_back(piece);
    Case c = Case(pieces, caseEffects);
    Grid grid = this->getGrid(CurrentGrid);
    grid.setCase(cellX, cellY, c);
    this->setGrid(CurrentGrid, grid);
    std::cout << "Case " << cellX << " " << cellY << " clicked" << std::endl;
}

void func()
{
    std::cout << "Hello" << std::endl;
}

void func2()
{
    std::cout << "Hello2" << std::endl;
}

void func3()
{
    std::cout << "Hello3" << std::endl;
}

void func4()
{
    std::cout << "Hello4" << std::endl;
}

void Game::setAllCard()
{
    this->allCard[0] = (void *)func;
    this->allCard[1] = (void *)func2;
    this->allCard[2] = (void *)func3;
    this->allCard[3] = (void *)func4;
}

void **Game::getAllCard()
{
    return this->allCard;
}