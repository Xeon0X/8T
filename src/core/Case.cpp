#include "Case.h"
Case::Case() : pieces(), caseEffects()
{
}

Case::Case(std::vector<Piece> pieces, CaseEffects caseEffects) : pieces(pieces), caseEffects(caseEffects)
{
}

Case::~Case()
{
}

void Case::addPiece(const Piece &piece)
{
    this->pieces.push_back(piece);
}

std::vector<Piece> Case::getPieces() const
{
    return this->pieces;
}

CaseEffects Case::getEffects() const
{
    return this->caseEffects;
}
