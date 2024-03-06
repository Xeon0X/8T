#ifndef CARD
#define CARD

#include <string>

class Game;
typedef void (*FuncType)(int, int, int, Game &);
class Card
{
private:
    std::string name;
    std::string description;
    int id;
    std::string pathCardImage;
    std::string pathCardSound;

public:
    Card(std::string name, std::string description, int id);
    ~Card();
    void applyCard(void *allCards[5], int posX, int posY, int currentGrid, Game &game);
    std::string getName();
};

#endif // CARD