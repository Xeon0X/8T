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
