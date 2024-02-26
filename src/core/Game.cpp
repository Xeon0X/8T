#include "Game.h"
#include <iostream>

Game::Game(std::vector<Grid> grids, std::vector<Player> players) :
    grids(grids), players(players)
{

}

Game::~Game()
{

}

void addGrid(const Grid& grid){
    this->grids.push_back(grid)
}