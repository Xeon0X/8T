#ifndef CASE
#define CASE

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