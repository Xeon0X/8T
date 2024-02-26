#ifndef CASE
#define CASE

#include <vector>
#include <map>
#include "Piece.h"
#include <string>
#include <SDL2/SDL.h>

class Case
{
private:
    int dimX, dimY;
    SDL_Rect rect;
    std::vector<Piece> pieces;
    std::map<std::string, float> caseEffects;

public:
    Case(int posX, int posY);
    ~Case();
    void showCase(SDL_Renderer *renderer, int x, int y);
    SDL_Rect getRect();
};

#endif // CASE
