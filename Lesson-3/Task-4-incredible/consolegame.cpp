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
}

void ConsoleGame::worldGeneration()
{
    srand(time(0));
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (   y == WORLD_SIZE_Y - 1
                || x == WORLD_SIZE_X - 1
                || y == 0 || x == 0)
            {
                generalMap[y][x] = '/';                                     //inaccessible frame
            }
            else {
                switch(rand()%23) {
                case 1:  generalMap[y][x] = 'T'; break;                     //trees
                case 2:  generalMap[y][x] = 't'; break;                     //small trees
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

    case 'm': showGameManual(); break;
    case 'i': openInventory(); break;
    case 'e': resourceMining(); break;
    case 'c': openCraftMenu(); break;
    }
}

void ConsoleGame::resourceMining()
{
    for (int y = playerPosY - 1; y <= playerPosY + 1; y++) {
        for (int x = playerPosX - 1; x <= playerPosX + 1; x++) {
            if (y < WORLD_SIZE_Y && x < WORLD_SIZE_X && y >= 0 && x >= 0) {
                if (playerMap[y][x] == 't') {
                    itemStick++;
                    generalMap[y][x] = ' ';
                }
                if (playerMap[y][x] == 'T') {
                    itemWood++;
                    generalMap[y][x] = 't';
                }
            }
        }
    }
    system("cls");
}

void ConsoleGame::openInventory()
{
    system("cls");
    cout << "INVENTORY" << endl << endl;
    cout << "Materials:" << endl;
    if (itemStick > 0) { cout << "Stick - " << itemStick << endl; }
    if (itemWood > 0) { cout << "Wood - " << itemWood << endl; }
    if (itemStone > 0) { cout << "Stone - " << itemStone << endl ; }

    cout << endl << "Items:" << endl;

    closeTab();
}

void ConsoleGame::openCraftMenu()
{
    system("cls");
    cout << "CRAFT MENU" << endl
         << "Choose, what do you wnat ot craft:" << endl << endl;

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
         << "c - to craft" << endl;

    closeTab();
}

void ConsoleGame::closeTab()
{
    cout << endl <<"Press any key to close this tab";
    _getch();
    system("cls");
}
