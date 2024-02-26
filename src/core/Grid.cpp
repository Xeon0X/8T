#include "Grid.h"

Grid::Grid(Player player, std::pair<int, int> size) : currentPlayer(player), grid(size.first, std::vector<Case>(size.second)) {
}

Grid::~Grid()
{
}

void Grid::addGlobalRule(Card card)
{
    this->globalRules.push_back(card);
}

void Grid::showGrid(SDL_Renderer *renderer)
{
    for (unsigned int i = 0; i < this->cases.size(); i++)
    {
        for (unsigned int j = 0; j < this->cases[0].size(); j++)
        {
            this->cases[i][j].showCase(renderer, i, j);
        }
    }
}
