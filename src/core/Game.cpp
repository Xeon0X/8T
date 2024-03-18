#include "Game.h"
#include "Case.h"
#include <iostream>
#include "Piece.h"

Game::Game()
{
    std::cout << "Game created" << std::endl;

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
    Player currentPlayer = this->getCurrentPlayer();
    Piece piece = Piece(currentPlayer.getSymbol(), currentPlayer.getColor(), pieceEffects);
    std::vector<Piece> pieces;
    pieces.push_back(piece);
    Case *c = new Case(pieces, caseEffects);
    Grid grid = this->getGrid(CurrentGrid);
    grid.setCase(cellX, cellY, c);
    this->setGrid(CurrentGrid, grid);
    std::cout << "Case " << cellX << " " << cellY << " clicked" << std::endl;
}

void Game::setCurrentPlayer(Player player)
{
    this->currentPlayer = player;
}

void Game::replacePlayer(Player player)
{
    for (int i = 0; i < this->players.size(); i++)
    {
        if (this->players[i].getSymbol() == player.getSymbol())
        {
            this->players[i] = player;
        }
    }
}

Player Game::findPlayerBySymbol(std::string symbol)
{
    for (unsigned int i = 0; i < this->players.size(); i++)
    {
        if (this->players[i].getSymbol() == symbol)
        {
            return this->players[i];
        }
    }
    return Player("", "");
}