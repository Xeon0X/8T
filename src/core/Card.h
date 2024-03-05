#ifndef CARD
#define CARD

#include <string>

typedef void (*FuncType)();

class Card
{
private:
    std::string name;
    std::string description;
    int id;
    std::string pathCardImage;
    std::string pathCardSound;

public:
    Card(std::string name, std::string description, int id, std::string pathCardImage, std::string pathCardSound);
    ~Card();
    void applyCard(void *allCards[5]);
};

#endif // CARD