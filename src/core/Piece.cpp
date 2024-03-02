#include "Piece.h"

Piece::Piece()
{
    this->symbol = "";
    this->color = "";
    std::map<std::string, float> pieceEffects;
}

Piece::Piece(std::string symbol, std::string color, std::map<std::string, float> pieceEffects)
{
    this->symbol = symbol;
    this->color = color;
    this->pieceEffects = pieceEffects;
}

Piece::~Piece()
{
}

void Piece::setSymbol(std::string symbol)
{
    this->symbol = symbol;
}

void Piece::setColor(std::string color)
{
    this->color = color;
}

std::string Piece::getSymbol() const
{
    return this->symbol;
}

std::string Piece::getColor() const
{
    return this->color;
}

void Piece::addEffects(std::string effect, float value)
{
    this->pieceEffects.insert({effect, value});
}

std::map<std::string, float> Piece::getEffects() const
{
    return this->pieceEffects;
}
