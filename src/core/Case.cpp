#include "Case.h"
Case::Case() : pieces(), caseEffects()
{

}

Case::Case(std::vector<Piece> pieces, std::map<std::string, float> caseEffects) :
    pieces(pieces), caseEffects(caseEffects) 
{

}

Case::~Case()
{

}

void Case::addPiece(const Piece &piece) {
    this->pieces.push_back(piece);
}

void Case::addEffect(std::string effect, float value) {
    this->caseEffects.insert({effect, value});
}

std::vector<Piece> Case::getPieces() const {
    return this->pieces;
}

std::map<std::string, float> Case::getEffects() const{
    return this->caseEffects;
}