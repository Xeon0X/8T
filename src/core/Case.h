#ifndef CASE
#define CASE

#include <map>
#include <string>
#include <vector>
#include "Piece.h"

class Case
{
private:
    std::vector<Piece> pieces;
    std::map<std::string, float> caseEffects;

public:
    Case();
    Case(std::vector<Piece>, std::map<std::string, float>)
    ~Case();
    void addPiece(const Piece&);
    void addEffects(std::string, float);
    vector[Piece] getPieces() const;
    map[string, float] getEffects() const;
};

#endif // CASE
