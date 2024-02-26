#include "Grid.h"

Grid::Grid(Player player, std::pair<int, int> size)
{
    this->currentPlayer = player1;
    for (int column = 0; i < size.first; column++)
    {
        std::vector<Case> cases;
        for (int row = 0; row < size.second; row++)
        {
            int caseX = (SCREEN_WIDTH / 2) - (50 / 2) + ((i - 1) * 50);
            int caseY = (SCREEN_HEIGHT / 2) - (50 / 2) + ((j - 1) * 50);
            cases.push_back(Case(caseX, caseY));
        }
        this->cases.push_back(cases);
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
