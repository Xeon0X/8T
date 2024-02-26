#include "Case.h"

Case::Case() : pieces(), caseEffects()
{

}

Case::Case(std::vector<Piece> pieces, std::map<std::string, float> caseEffects;) {
    this->pieces = pieces;
    this->caseEffects = caseEffects;
}

Case::~Case()
{
    
}

void Case::addPiece(const Piece &piece) {
    this->pieces.push_back(piece);
}

vector[piece] getPieces() {
    return this->pieces;
}

void addEffects(string effect, float value) {
    this->caseEffects.insert({effect, value});
}

map[string, float] getEffects() const{
    return this->caseEffects;
}