#include "Game.h"
#include <iostream>

Game::Game()
{

    this->players.push_back(Player("X"));
    this->players.push_back(Player("O"));

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
