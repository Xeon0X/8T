#ifndef CASE
#define CASE

#include <map>
#include <string>
#include <map>
#include <string>
#include <vector>
#include "Piece.h"

struct CaseEffects
{
    /* data */
};

class Case
{
private:
    std::vector<Piece> pieces;
    CaseEffects caseEffects;

public:
    Case();
    Case(std::vector<Piece> pieces, CaseEffects caseEffects);
    ~Case();
    void addPiece(const Piece &piece);
    void addEffect(std::string effect, float value);
    std::vector<Piece> getPieces() const;
    CaseEffects getEffects() const;
    bool isPiecesEmpty() const;
};

#endif // CASE
