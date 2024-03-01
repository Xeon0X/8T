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
    int nbAlign = 0;
    int x = cellX;
    int y = cellY;

    // Check horizontal
    for (int i = 0; i < this->getGridWidth(); i++)
    {
        if (this->getCase(i, y).getPieces().size() > 0 && this->getCase(i, y).getPieces()[0].getSymbol() == symbol)
        {
            nbAlign++;
        }
        else
        {
            nbAlign = 0;
        }
        if (nbAlign == this->getNbAlignToWin())
        {
            return true;
        }
    }

    // Check vertical
    nbAlign = 0;
    for (int j = 0; j < this->getGridHeight(); j++)
    {
        if (this->getCase(x, j).getPieces().size() > 0 && this->getCase(x, j).getPieces()[0].getSymbol() == symbol)
        {
            nbAlign++;
        }
        else
        {
            nbAlign = 0;
        }
        if (nbAlign == this->getNbAlignToWin())
        {
            return true;
        }
    }

    // Check diagonal
    nbAlign = 0;
    for (int i = 0; i < this->getGridWidth(); i++)
    {
        if (x - i >= 0 && y - i >= 0 && this->getCase(x - i, y - i).getPieces().size() > 0 && this->getCase(x - i, y - i).getPieces()[0].getSymbol() == symbol)
        {
            nbAlign++;
        }
        else
        {
            nbAlign = 0;
        }
        if (nbAlign == this->getNbAlignToWin())
        {
            return true;
        }
    }

    nbAlign = 0;
    for (int i = 0; i < this->getGridWidth(); i++)
    {
        if (x + i < this->getGridWidth() && y - i >= 0 && this->getCase(x + i, y - i).getPieces().size() > 0 && this->getCase(x + i, y - i).getPieces()[0].getSymbol() == symbol)
        {
            nbAlign++;
        }
        else
        {
            nbAlign = 0;
        }
    }
    if (nbAlign == this->getNbAlignToWin())
    {
        return true;
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