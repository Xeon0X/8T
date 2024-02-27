#ifndef GRAPHIC
#define GRAPHIC

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "GridGraphic.h"

class Graphic
{

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color color;
    TTF_Font *font;
    SDL_Color fontColor;
    int fontSize;
    int fontStyle;

    bool running = true;

    GridGraphic grid;

public:
    Graphic();
    ~Graphic();

    void drawRect(int x, int y, int w, int h);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawCircle(int x, int y, int r);
    void drawPoint(int x, int y);
    void drawText(const char *text, int x, int y);
    void clear();
    void present();
    void setColor(int r, int g, int b, int a);
    void setDrawColor(int r, int g, int b, int a);
    void setFont(const char *font, int size);
    void setFontSize(int size);
    void setFontColor(int r, int g, int b, int a);
    void setFontStyle(int style);

    void eventHolder();
    void play();
};

#endif // GRAPHIC
