#include "Case.h"

Case::Case()
{
}

Case::~Case()
{
}

void Case::addPiece(const Piece &piece) {
    this->pieces.push_back(piece);
}

vector[piece] getPieces() {
    return pieces;
}

void addEffects(string effect, float value) {
    caseEffects.insert({effect, value});
}

map[string, float] getEffects() const{
    return this->caseEffects;
}