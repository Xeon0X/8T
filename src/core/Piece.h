#ifndef PIECE
#define PIECE
#include <string>
#include <map>

class Piece {
    private:
        std::string symbol;
        std::string color;
        std::map<std::string, float> pieceEffects;
    public:
        std::string getSymbol();
        std::string getColor();
        void addEffects(std::string, float);
        map[string, float] getEffects();
};

#endif // PIECE