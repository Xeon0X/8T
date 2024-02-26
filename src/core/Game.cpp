#include "Game.h"
#include <iostream>

Game::Game() 
{

}

Game::~Game()
{

}

void addGrid(const Grid& grid){
    this->grids.push_back(grid)
}