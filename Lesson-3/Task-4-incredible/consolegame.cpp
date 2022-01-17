#include "consolegame.h"

#include <iostream>
#include <random>
#include <time.h>
#include <conio.h>

using namespace std;

ConsoleGame::ConsoleGame()
{
    playerActionInput = ' ';
    playerPosX = WORLD_SIZE_X / 2;
    playerPosY = WORLD_SIZE_Y / 2;

    itemStick = 0;
    itemWood = 0;
    itemStone = 0;

    itemInHand = ' ';
}

void ConsoleGame::worldGeneration()
{
    srand(time(0));
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (y == WORLD_SIZE_Y - 1 || x == WORLD_SIZE_X - 1 || y == 0 || x == 0) {
                generalMap[y][x] = '/';                                     //inaccessible frame
            }
            else {
                switch(rand()%23) {
                case 1:  generalMap[y][x] = 'T'; break;                     //trees
                case 2:  generalMap[y][x] = 't'; break;                     //small trees
                case 3:  generalMap[y][x] = 'S'; break;                     //stones
                case 4:  generalMap[y][x] = 's'; break;                     //small stones
                default: generalMap[y][x] = ' ';                            //empty field
                }
            }
            playerMap[y][x] = '*';                                          //map fog
        }
    }
}

void ConsoleGame::showUndiscoveredWorld()
{
    for (int y = playerPosY - 2; y <= playerPosY + 2; y++) {
        for (int x = playerPosX - 2; x <= playerPosX + 2; x++) {
            if (y < WORLD_SIZE_Y && x < WORLD_SIZE_X && y >= 0 && x >= 0) {
                playerMap[y][x] = generalMap[y][x];
            }
        }
    }
    system("cls");
}

void ConsoleGame::playerPosition()
{
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (playerPosX == x && playerPosY == y) {
                cout << "@";
            }
            else {
                cout << playerMap[y][x];
            }
        } cout << endl;
    }
}

void ConsoleGame::playerKeyAction()
{
    cout << ">";
    playerActionInput = _getch();
    switch(playerActionInput) {
    case 'w': if (generalMap[playerPosY-1][playerPosX] == ' ') playerPosY--; break;             //movement to up
    case 's': if (generalMap[playerPosY+1][playerPosX] == ' ') playerPosY++; break;             //movement to down
    case 'd': if (generalMap[playerPosY][playerPosX+1] == ' ') playerPosX++; break;             //movement to right
    case 'a': if (generalMap[playerPosY][playerPosX-1] == ' ') playerPosX--; break;             //movement to left

    case 'e': resourceMining(); break;
    case 'q': resourcePlacing(itemInHand); break;
    case 'm': showGameManual(); break;
    case 'i': openInventory(); break;
    case 'c': openCraftMenu(); break;
    }
}

void ConsoleGame::resourceMining()
{
    for (int y = playerPosY - 1; y <= playerPosY + 1; y++) {
        for (int x = playerPosX - 1; x <= playerPosX + 1; x++) {
            if (y < WORLD_SIZE_Y && x < WORLD_SIZE_X && y >= 0 && x >= 0) {
                switch (playerMap[y][x]) {
                    case 't': itemStick++; generalMap[y][x] = ' '; break;
                    case 'T': itemWood++; generalMap[y][x] = 't'; break;
                    case 'S': itemStone += 4; generalMap[y][x] = 's'; break;
                    case 's': itemStone += 2; generalMap[y][x] = ' '; break;
                }
            }
        }
    }
    system("cls");
}

void ConsoleGame::resourcePlacing(char availableItem)
{
    if (availableItem == ' ') {
        return;
    }

    generalMap[playerPosY][playerPosX] = availableItem;
    playerMap[playerPosY][playerPosX] = generalMap[playerPosY][playerPosX];
}

void ConsoleGame::placeItemInHand()
{
    switch (_getch()) {
        case 1: if (itemStick > 0) itemInHand = 't'; break;
        case 2: if (itemWood > 0) itemInHand = 'T'; break;
        case 3: if (itemStone > 0) itemInHand = 'S'; break;
    }
}

void ConsoleGame::openInventory()
{
    cout << "INVENTORY" << endl << endl;
    if (itemStick > 0) { cout << "1. Stick - " << itemStick << endl; }
    if (itemWood > 0) { cout << "2. Wood - " << itemWood << endl; }
    if (itemStone > 0) { cout << "3. Stone - " << itemStone << endl ; }

    cout << "Y - put an item in hand";
    if (_getch() == 'y') {
        cout << endl << "Choose item: ";
        placeItemInHand();
    }
    else {
        system("cls");
    }
}

void ConsoleGame::openCraftMenu()
{
    cout << "CRAFT MENU" << endl
         << "Choose, what do you want ot craft:" << endl << endl;
    if (itemStick >= 6 && itemWood >= 4) {
        cout << "1. Wooden pickaxe | Cost: 6 stick, 4 wood" << endl;
    }
    closeTab();
}

void ConsoleGame::showGameManual()
{
    system("cls");
    cout << "You can open this manual everywhere, by presing 'm'" << endl << endl;
    cout << "KEYBOARD SHORTCUTS:" << endl
         << "w, a, s, d - movement" << endl
         << "m - game manual" << endl
         << "i - player inventory" << endl
         << "e - to mine" << endl
         << "c - to craft" << endl
         << "q - to place item" << endl;
    closeTab();
}

void ConsoleGame::closeTab()
{
    _getch(); system("cls");
}
