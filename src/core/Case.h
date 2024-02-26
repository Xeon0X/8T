#ifndef CASE
#define CASE

#include <vector>
#include <map>
#include "Piece.h"
#include <string>

class Case
{
private:
    std::vector<Piece> pieces;
    std::map<std::string, float> caseEffects;

public:
    Case();
    ~Case();
    void addPiece(const Piece& piece);
    vector[Piece] getPieces() const;
    void addEffects(string effect, float value);
    map[string, float] getEffects() const;
};

#endif // CASE
