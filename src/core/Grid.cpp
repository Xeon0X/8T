#include "Grid.h"

Grid::Grid()
{

    for (int i = 0; i < 3; i++)
    {
        std::vector<Case> row;
        for (int j = 0; j < 3; j++)
        {
            row.push_back(Case());
        }
        this->cases.push_back(row);
    }
}

Grid::~Grid()
{
}

void Grid::addGlobalRule(Card card)
{
    this->globalRules.push_back(card);
}

std::vector<std::vector<Case>> Grid::getCases()
{
    return this->cases;
}

int Grid::getGridWidth()
{
    return this->cases[0].size();
}

int Grid::getGridHeight()
{
    return this->cases.size();
}

void Grid::setCase(int x, int y, Case c)
{
    this->cases[x][y] = c;
}