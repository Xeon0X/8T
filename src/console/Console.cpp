#include "Console.h"
#include <iostream>

Console::Console()
{
    
}

Console::~Console()
{

}

void Console::play()
{
    while (running) {
        std::cout << "running ";
    }
}
