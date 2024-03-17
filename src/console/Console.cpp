#include "Console.h"

Console::Console()
{
}

Console::~Console()
{
}

void clear()
{
    #if defined _WIN32
        system("cls");
        //clrscr(); // including header file : conio.h
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void Console::play()
{

    while (running)
    {
        int gridIndex = 0;
        gameConsole.printGrid(gridIndex);
        gameConsole.printDeck(gridIndex);
        int run = gameConsole.menu(gridIndex);
        if (run == 1) 
        {
            std::cout << "\n----- Next player -----" << std::endl;
        } else {
            running = false;
        }
        clear();
        
    }
}
