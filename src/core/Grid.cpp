#include "Grid.h"

Grid(): currentPlayer(), grid(), cards() 
{

}

Grid::Grid(int player, std::vector<Player> players, std::pair<int, int> size, std::vector<Card> cards) :
currentPlayer(player), player(players), grid(size.first, std::vector<Case>(size.second)), cards(cards)
{

}

Grid::~Grid()
{

}

int Grid::nextPlayer(int next) {
    this->currentPlayer = (currentPlayer + next) % size(players);
    return this->currentPlayer;
}

void Grid::setCurrentPlayer(int player) {
    this->currentPlayer = player;
}

void Grid::addCard(Card card)
{
    this->cards.push_back(card);
}

int Grid::getCurrentPlayer() const {
    return currentPlayer;
}

std::vector<std::vector<Case>> Grid::getGrid() const {
    return this->grid;
}

std::vector<Card> Grid::getCards() const {
    return this->cards;
}