#include "Grid.h"

Grid::Grid(Player player1, int SCREEN_HEIGHT, int SCREEN_WIDTH)
{
    this->currentPlayer = player1;
    for (int i = 0; i < 3; i++)
    {
        std::vector<Case> row;
        for (int j = 0; j < 3; j++)
        {
            int caseX = (SCREEN_WIDTH / 2) - (50 / 2) + ((i - 1) * 50);
            int caseY = (SCREEN_HEIGHT / 2) - (50 / 2) + ((j - 1) * 50);
            row.push_back(Case(caseX, caseY));
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
