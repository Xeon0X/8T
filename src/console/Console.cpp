#include "Console.h"

Console::Console()
{
}

Console::~Console()
{
}

void Console::play()
{

    while (running)
    {
        int gridIndex = 0;
        gameConsole.printGrid(gridIndex);
        gameConsole.printDeck(gridIndex);
        running = false;
    }
}
