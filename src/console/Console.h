#ifndef GAME_CONSOLE
#define GAME_CONSOLE

#include "../console/GameConsole.h"

class Console
{
private:
    bool running = true;
    GameConsole console;

public:
    Console();
    ~Console();
    void play();
};

#endif // CONSOLE