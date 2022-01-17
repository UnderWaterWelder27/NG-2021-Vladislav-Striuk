#include "gamemanual.h"

#include <iostream>
#include <conio.h>


GameManual::GameManual()
{

}

void GameManual::keybindsInformation()
{
    system("cls");

    std::cout << "You can open this manual everywhere, by presing 'm'" << std::endl << std::endl;
    std::cout << "KEYBOARD SHORTCUTS:" << std::endl
            << "w - move up" << std::endl
            << "s - move down" << std::endl
            << "a - move left" << std::endl
            << "d - move right" << std::endl
            << "m - game manual" << std::endl
            << "i - player inventory" << std::endl << std::endl;
    std::cout << "Press any key to close this tab";

    _getch();
    system("cls");
}
