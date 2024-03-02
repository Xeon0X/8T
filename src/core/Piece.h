#ifndef PIECE
#define PIECE

#include <map>
#include <string>
#include <vector>

#include <map>
#include <string>
#include <vector>

class Piece
{
private:
    std::string symbol;
    std::string color;
    std::map<std::string, float> pieceEffects;

public:
    Piece();
    Piece(std::string symbol, std::string color, std::map<std::string, float> pieceEffects);
    ~Piece();
    void setSymbol(std::string symbol);
    void setColor(std::string symbol);
    std::string getSymbol() const;
    std::string getColor() const;
    void addEffects(std::string, float);
    std::map<std::string, float> getEffects() const;
};

#endif // PIECE