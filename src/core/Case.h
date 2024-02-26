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
};

#endif // CASE
