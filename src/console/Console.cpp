#include "Console.h"
#include <iostream>
#include "../core/Game.h"
#include "../core/Card.h"
#include "../core/Case.h"

Console::Console()
{
    
}

Console::~Console()
{

}

void Console::play()
{
    while (running) {
        console.printGrid();
        running = false;
    }
}
