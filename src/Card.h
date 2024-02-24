#ifndef CARD
#define CARD

#include <string>

class Card
{
private:
    std::string name;
    std::string description;
    int id;
    std::string pathCardImage;
    std::string pathCardSound;

public:
    Card();
    Card(std::string name, std::string description, int id, std::string pathCardImage, std::string pathCardSound);
    ~Card();
};

#endif // CARD