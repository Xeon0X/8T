#ifndef PIECE
#define PIECE

#include <map>
#include <string>
#include <vector>

#include <map>
#include <string>
#include <vector>

struct PieceEffects
{
    bool test;
};

class Piece
{
private:
    std::string symbol;
    std::string color;
    PieceEffects pieceEffects;

public:
    Piece();
    Piece(std::string symbol, std::string color, PieceEffects pieceEffects);
    ~Piece();
    void setSymbol(std::string symbol);
    void setColor(std::string symbol);
    std::string getSymbol() const;
    std::string getColor() const;
    PieceEffects getEffects() const;
};

#endif // PIECE