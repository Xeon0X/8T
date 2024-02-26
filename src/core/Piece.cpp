#include "Piece.h"

Piece::Piece(std::string symbol, std::string color, std::map<std::string, float> pieceEffects) : symbol(symbol), color(color), pieceEffects(pieceEffects) 
{

}

Piece::~Piece()
{
    
}

void Piece::setSymbol(std::string symbol) {
    this->symbol = symbol;
}

void Piece::setColor(std::string color) {
    this->color = color;
}

std::string Piece::getSymbol() const {
    return this-> symbol;
}

std::string Piece::getColor() const {
    return this->color;
}

void Piece::addEffects(std::string effect, float value) {
    this->pieceEffects.insert({effect, value});
}

std::map<std::string, float> Piece::getEffects() const {
    return this->pieceEffects;
}