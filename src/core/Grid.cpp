#include "Grid.h"
#include "Case.h"
#include "./rules/GlobalRules.hpp"
#include "./rules/RulesRare.hpp"


Grid::Grid()
{
    for (int i = 0; i < 3; i++)
    {
        std::vector<Case *> row; // Change the type of the vector from std::vector<Case> to std::vector<Case*>

        for (int j = 0; j < 3; j++)
        {
            row.push_back(new Case()); // Allocate new Case objects with 'new'
        }
        this->cases.push_back(row);
    }

    this->createGlobalRules();
}

Grid::~Grid()
{
}

std::vector<std::vector<Case *>> Grid::getCases()
{
    return this->cases;
}

void Grid::setCases(std::vector<std::vector<Case *>> cases)
{
    this->cases = cases;
}

int Grid::getGridWidth()
{
    return this->cases[0].size();
}

int Grid::getGridHeight()
{
    return this->cases.size();
}

void Grid::setCase(int x, int y, Case *c)
{
    this->cases[y][x] = c;
}

Case *Grid::getCase(int x, int y)
{
    return this->cases[y][x];
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
                this->getCase(x, y)->getPieces().size() > 0 && this->getCase(x, y)->getPieces()[0].getSymbol() == symbol)
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
            this->setCase(i, j, new Case());
        }
    }
}

void Grid::addGlobalRule(Card *card)
{
    this->globalRules.push_back(card);
}

void Grid::createGlobalRules()
{
    // CardAlignToWin *card = new CardAlignToWin("AlignToWin", "Le nombre d'alignement pour gagner", 1);
    // this->addGlobalRule(card);
    // CardPlacePiece *card3 = new CardPlacePiece("PlacePiece", "Pose une pièce", 1);
    // this->addGlobalRule(card3);
    CardPlacePiece *card8 = new CardPlacePiece("PlacePiece", "Pose une pièce", 1);
    this->addGlobalRule(card8);
    CardPlayCard *card4 = new CardPlayCard("PlayCard", "Joue une carte", 1);
    this->addGlobalRule(card4);
    CardDrawCard *card1 = new CardDrawCard("DrawCard", "Pioche une carte", 1);
    this->addGlobalRule(card1);
    CardGravity *card5 = new CardGravity("Gravity", "Applique la gravité", 1);
    this->addGlobalRule(card5);
    CardSwitchPlayer *card2 = new CardSwitchPlayer("SwitchPlayer", "Change de joueur", 1);
    this->addGlobalRule(card2);

}

std::vector<Card *> Grid::getGlobalRules(){
        return this->globalRules;
    }

void Grid::showGridTerminal()
{
    std::cout << "in showGrid\n";
    for (int i = 0; i < this->getGridWidth(); i++)
    {
        for (int j = 0; j < this->getGridHeight(); j++)
        {
            std::cout << this->getCase(i, j)->getPieces().size() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "after showGrid\n";
}

GridRules Grid::getRules()
{
    return this->rules;
}

void Grid::setRules(GridRules rules)
{
    this->rules = rules;
}

int Grid::getCurrentGlobalRule() const
{
    return this->currentGlobalRule;
}

int Grid::getCurrentGlobalRuleIteration() const
{
    return this->currentGlobalRuleIteration;
}

void Grid::addCurrentGlobalRuleIteration()
{
    this->currentGlobalRuleIteration += 1;
}

void Grid::resetCurrentGlobalRuleIteration()
{
    this->currentGlobalRule = 0;
}

void Grid::nextGlobalRule()
{
    this->currentGlobalRule = (this->currentGlobalRule + 1) % (this->globalRules.size());
}