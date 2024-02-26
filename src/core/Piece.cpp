#include "Piece.h"

Piece::Piece() : symbol(""), color(""), pieceEffects()
{

}


Piece::Piece(std::string symbol, std::string color, std::map<std::string, int> pieceEffects = {})
{
    this->symbol = symbol;
    this->color = color;
    this->pieceEffects = pieceEffects;
}

Piece::~Piece()
{
    
}

void setSymbol(std::string symbol) {
    this->symbol = symbol;
}

void setColor(std::string color) {
    this->color = color;
}

std::string Piece::getSymbol() {
    return this-> symbol;
}

std::string Piece::getColor() {
    return this->color;
}

void Piece::addEffects(std::string effect, float value) {
    this->pieceEffects.insert({effect, value});
}

map[string, float] Piece::getEffects(){
    return this->pieceEffects;
}