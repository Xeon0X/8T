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
    Case(std::vector<Piece> pieces, std::map<std::string, float> caseEffects)
    ~Case();
    void addPiece(const Piece& piece);
    void addEffect(std::string effect, float value);
    vector[Piece] getPieces() const;
    map[string, float] getEffects() const;
};

#endif // CASE
