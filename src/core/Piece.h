#ifndef PIECE
#define PIECE

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
    Piece(std::string, std::color, std::map<std::string, float>)
    ~Piece();
    void setSymbol(std::string);
    void setColor(std::string);
    std::string getSymbol() const;
    std::string getColor() const;
    void addEffects(std::string, float);
    map[string, float] getEffects() const;
};

#endif // PIECE