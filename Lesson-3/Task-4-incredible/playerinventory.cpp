#include "playerinventory.h"

#include <iostream>
#include <conio.h>


PlayerInventory::PlayerInventory()
{

}

void PlayerInventory::openInventory()
{
    system("cls");
    std::cout << "INVENTORY" << std::endl << std::endl
            << "Stick - " << getSticksCount() << std::endl
            << "Wood - " << getWoodCount() << std::endl
            << "Stone - " << getStoneCount() << std::endl << std::endl;

    std::cout << "Press any key to close this tab";
    _getch();
    system("cls");
}
