#include "Piece.h"

Piece::Piece(/* args */)
{
}

Piece::Piece(std::string symbol, std::string color)
{
    this->symbol = symbol;
    this->color = color;
}

Piece::~Piece()
{
}

void Piece::addEffects(std::string effect, float value) {
    this->pieceEffects.insert({effect, value});
}

map[string, float] Piece::getEffects(){
    return pieceEffects;
}