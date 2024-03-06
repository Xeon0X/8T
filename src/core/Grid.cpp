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

    this->createGlobalRules();
}

Grid::~Grid()
{
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

Case Grid::getCase(int x, int y)
{
    return this->cases[x][y];
}

void Grid::setNbAlignToWin(int nb)
{
    this->nbAlignToWin = nb;
}

int Grid::getNbAlignToWin()
{
    return this->nbAlignToWin;
}

bool Grid::checkWin(Player player, int cellX, int cellY)
{
    std::string symbol = player.getSymbol();
    int dx[] = {-1, 0, 1, 1};
    int dy[] = {1, 1, 1, 0};

    for (int dir = 0; dir < 4; ++dir)
    {
        int nbAlign = 0;
        for (int i = -this->getNbAlignToWin() + 1; i < this->getNbAlignToWin(); ++i)
        {
            int x = cellX + i * dx[dir];
            int y = cellY + i * dy[dir];
            if (x >= 0 && y >= 0 && x < this->getGridWidth() && y < this->getGridHeight() &&
                this->getCase(x, y).getPieces().size() > 0 && this->getCase(x, y).getPieces()[0].getSymbol() == symbol)
            {
                nbAlign++;
                if (nbAlign == this->getNbAlignToWin())
                {
                    return true;
                }
            }
            else
            {
                nbAlign = 0;
            }
        }
    }
    return false;
}

void Grid::resetGrid()
{
    std::cout << "reset grid" << std::endl;
    for (int i = 0; i < this->getGridWidth(); i++)
    {
        for (int j = 0; j < this->getGridHeight(); j++)
        {
            this->setCase(i, j, Case());
        }
    }
}

void Grid::addGlobalRule(Card card)
{
    this->globalRules.push_back(card);
}

void Grid::createGlobalRules()
{
    Card card = Card("AlignToWin", "Le nombre d'alignement pour gagner", 1);
    this->addGlobalRule(card);
    card = Card("SwitchPlayer", "Switch le joueur", 0);
    this->addGlobalRule(card);
}

void Grid::showGridTerminal()
{
    for (int i = 0; i < this->getGridWidth(); i++)
    {
        for (int j = 0; j < this->getGridHeight(); j++)
        {
            std::cout << this->getCase(i, j).getPieces().size() << " ";
        }
        std::cout << std::endl;
    }
}