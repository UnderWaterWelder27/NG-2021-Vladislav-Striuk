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
    currentWorld = '1';

    stickCount = 0;
    woodCount = 0;
    stoneCount = 0;

    woodenPickaxeAvailable = false;
    stonePickaxeAvailable = false;

    itemInHand = ' ';
}

void ConsoleGame::worldGeneration()
{
    srand(time(0));
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (y == WORLD_SIZE_Y - 1 || x == WORLD_SIZE_X - 1 || y == 0 || x == 0) {
                savannahWorld[y][x] = '/';                                     //inaccessible frame
                if (currentWorld == '1' && (y == WORLD_SIZE_Y - 1 && x == (WORLD_SIZE_X - 1)/2)) {
                    savannahWorld[y][x] = 'O';
                }
            }
            else {
                switch(rand()%23) {
                case 1:  savannahWorld[y][x] = 'T'; break;                     //trees
                case 2:  savannahWorld[y][x] = 't'; break;                     //small trees
                case 3:  savannahWorld[y][x] = 'S'; break;                     //stones
                case 4:  savannahWorld[y][x] = 's'; break;                     //small stones
                default: savannahWorld[y][x] = ' ';                            //empty field
                }
            }
            playerSavannahMap[y][x] = '*';                                          //map fog
        }
    }
}

void ConsoleGame::showUndiscoveredWorld()
{
    for (int y = playerPosY - 2; y <= playerPosY + 2; y++) {
        for (int x = playerPosX - 2; x <= playerPosX + 2; x++) {
            if (y < WORLD_SIZE_Y && x < WORLD_SIZE_X && y >= 0 && x >= 0) {
                playerSavannahMap[y][x] = savannahWorld[y][x];
            }
        }
    }
    system("cls");
}

char ConsoleGame::changeWorld()
{
    if (currentWorld == '1' && (playerPosY == WORLD_SIZE_Y - 1 && playerPosX == (WORLD_SIZE_X - 1)/2)) {
        return '2';
    }
    return '1';
}

void ConsoleGame::playerPosition()
{
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (playerPosX == x && playerPosY == y) {
                cout << "@";
            }
            else {
                cout << playerSavannahMap[y][x];
            }
        } cout << endl;
    }
}

void ConsoleGame::playerKeyAction(char (*worldArray)[WORLD_SIZE_X])
{
    cout << ">";
    playerActionInput = _getch();
    switch(playerActionInput) {
        case 'w': if (takeStepOportunity(worldArray[playerPosY-1][playerPosX])) { playerPosY--; } break;
        case 's': if (takeStepOportunity(worldArray[playerPosY+1][playerPosX])) { playerPosY++; } break;
        case 'd': if (takeStepOportunity(worldArray[playerPosY][playerPosX+1])) { playerPosX++; } break;
        case 'a': if (takeStepOportunity(worldArray[playerPosY][playerPosX-1])) { playerPosX--; } break;

        case 'e': resourceMining(); break;
        case 'q': resourcePlacing(itemInHand); break;
        case 'm': showGameManual(); break;
        case 'i': openInventory(); break;
        case 'c': openCraftMenu(); break;
    }
}

bool ConsoleGame::takeStepOportunity(char nextCell)
{
    switch (nextCell) {
        case ' ': return true; break;
        case 'O': return true; break;
        default: return false; break;
    }
}

void ConsoleGame::resourceMining()
{
    for (int y = playerPosY - 1; y <= playerPosY + 1; y++) {
        for (int x = playerPosX - 1; x <= playerPosX + 1; x++) {
            if (y < WORLD_SIZE_Y && x < WORLD_SIZE_X && y >= 0 && x >= 0) {
                switch (playerSavannahMap[y][x]) {
                    case 'T': woodCount += 2; savannahWorld[y][x] = 't'; break;
                    case 't': stickCount += 1; savannahWorld[y][x] = ' '; break;
                    case 'S': if (woodenPickaxeAvailable) { stoneCount += 2; savannahWorld[y][x] = 's'; } break;
                    case 's': if (woodenPickaxeAvailable) { stoneCount += 1; savannahWorld[y][x] = ' '; } break;
                }
            }
        }
    }
    system("cls");
}

void ConsoleGame::resourcePlacing(char availableItem)
{
    if (availableItem == ' ') { return; }

    switch (availableItem) {
        case 't': if (stickCount == 0) { return; } stickCount--; break;
        case 'T': if (woodCount == 0) { return; }; woodCount--; break;
        case 'S': if (stoneCount == 0) { return; }; stoneCount--; break;
    }

    savannahWorld[playerPosY][playerPosX] = availableItem;
    playerSavannahMap[playerPosY][playerPosX] = savannahWorld[playerPosY][playerPosX];
}

void ConsoleGame::placeItemInHand()
{
    switch (_getch()) {
        case '1': if (stickCount > 0) { itemInHand = 't'; } break;
        case '2': if (woodCount > 0) { itemInHand = 'T'; } break;
        case '3': if (stoneCount > 0) { itemInHand = 'S'; } break;
    }
}

void ConsoleGame::openInventory()
{
    cout << "INVENTORY" << endl << endl;
    cout << "1. "; if (stickCount > 0) { cout << "Stick - " << stickCount; } cout << endl;
    cout << "2. "; if (woodCount > 0) { cout << "Wood - " << woodCount; } cout << endl;
    cout << "3. "; if (stoneCount > 0) { cout << "Stone - " << stoneCount; } cout << endl;
    cout << "4. "; if (woodenPickaxeAvailable) { cout << "Wooden Pickaxe - available"; } cout << endl;
    cout << "5. "; if (stonePickaxeAvailable) { cout << "Stone Pickaxe - available"; } cout << endl;

    cout << endl << "Y - put an item in hand ? >";
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
    if (stickCount >= 12 && woodCount >= 20 && woodenPickaxeAvailable == false)
        cout << "1. Wooden pickaxe | Cost: 12 stick, 20 wood" << endl;

    if (stickCount >= 12 && stoneCount >= 20 && stonePickaxeAvailable == false)
        cout << "2. Stone pickaxe | Cost: 12 stick, 20 stone" << endl;

    cout << ">";
    switch (_getch()) {
        case '1': stickCount -= 12; woodCount -= 20; woodenPickaxeAvailable = true; break;
        case '2': stickCount -= 12; stoneCount -= 20; stonePickaxeAvailable = true; break;
    }
    system("cls");
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
    _getch(); system("cls");
}
