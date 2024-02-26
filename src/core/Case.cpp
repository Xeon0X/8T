#include "Case.h"

Case::Case() : pieces(), caseEffects()
{

}

Case(std::vector<Piece> pieces, std::map<std::string, float> caseEffects) :
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

vector[piece] Case::getPieces() {
    return this->pieces;
}

map[string, float] Case::getEffects() const{
    return this->caseEffects;
}