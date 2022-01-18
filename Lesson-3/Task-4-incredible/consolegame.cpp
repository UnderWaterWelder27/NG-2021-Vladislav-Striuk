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
    ironCount = 0;
    diamondCount = 0;

    woodenPickaxeAvailable = false;
    stonePickaxeAvailable = false;
    ironPickaxeAvailable = false;
    diamondSuperLegendaryMegaSwordAvailable = false;

    itemInHand = ' ';
}

void ConsoleGame::worldGeneration(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X], char o1, char o2, char o3, char o4)
{
    srand(time(0));
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (y == WORLD_SIZE_Y - 1 || x == WORLD_SIZE_X - 1 || y == 0 || x == 0) {
                if (currentWorld == '1' && (y == WORLD_SIZE_Y - 1 && x == (WORLD_SIZE_X - 1)/2)) {
                    worldArray[y][x] = 'O';
                }
                else if (currentWorld == '2' && (y == WORLD_SIZE_Y - 1 && x == (WORLD_SIZE_X - 1)/2)) {
                    worldArray[y][x] = 'O';
                }
                else {
                     worldArray[y][x] = '/';                                //inaccessible frame
                }
            }
            else {
                switch(rand()%23) {
                case 1:  worldArray[y][x] = o1; break;                     //trees
                case 2:  worldArray[y][x] = o2; break;                     //small trees
                case 3:  worldArray[y][x] = o3; break;                     //stones
                case 4:  worldArray[y][x] = o4; break;                     //small stones
                default: worldArray[y][x] = ' ';                            //empty field
                }
            }
            playerWorldArray[y][x] = '*';                                          //map fog
        }
    }
}

void ConsoleGame::showUndiscoveredWorld(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X])
{
    for (int y = playerPosY - 2; y <= playerPosY + 2; y++) {
        for (int x = playerPosX - 2; x <= playerPosX + 2; x++) {
            if (y < WORLD_SIZE_Y && x < WORLD_SIZE_X && y >= 0 && x >= 0) {
                playerWorldArray[y][x] = worldArray[y][x];
            }
        }
    }
    system("cls");
}

void ConsoleGame::changeWorld()
{
    if (currentWorld == '1' && (playerPosY == WORLD_SIZE_Y - 1 && playerPosX == (WORLD_SIZE_X - 1)/2)) {
        currentWorld = '2';
    }
    else if (currentWorld == '2' && (playerPosY == WORLD_SIZE_Y - 1 && playerPosX == (WORLD_SIZE_X - 1)/2)) {
        currentWorld = '1';
    }

}

void ConsoleGame::playerPosition(char (*playerWorldArray)[WORLD_SIZE_X])
{
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (playerPosX == x && playerPosY == y) {
                cout << "@";
            }
            else {
                cout << playerWorldArray[y][x];
            }
        } cout << endl;
    }
}

void ConsoleGame::playerKeyAction(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X])
{
    cout << ">";
    playerActionInput = _getch();
    switch(playerActionInput) {
        case 'w': if (takeStepOportunity(worldArray[playerPosY-1][playerPosX])) { playerPosY--; } break;
        case 's': if (takeStepOportunity(worldArray[playerPosY+1][playerPosX])) { playerPosY++; } break;
        case 'd': if (takeStepOportunity(worldArray[playerPosY][playerPosX+1])) { playerPosX++; } break;
        case 'a': if (takeStepOportunity(worldArray[playerPosY][playerPosX-1])) { playerPosX--; } break;

        case 'e': resourceMining(worldArray); changeWorld(); break;
        case 'q': resourcePlacing(itemInHand, worldArray, playerWorldArray); break;
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

void ConsoleGame::resourceMining(char (*worldArray)[WORLD_SIZE_X])
{
    for (int y = playerPosY - 1; y <= playerPosY + 1; y++) {
        for (int x = playerPosX - 1; x <= playerPosX + 1; x++) {
            if (y < WORLD_SIZE_Y && x < WORLD_SIZE_X && y >= 0 && x >= 0) {
                switch (worldArray[y][x]) {
                    case 'T': woodCount += 2; worldArray[y][x] = 't'; break;
                    case 't': stickCount += 1; worldArray[y][x] = ' '; break;
                    case 'S': if (woodenPickaxeAvailable) { stoneCount += 2; worldArray[y][x] = 's'; } break;
                    case 's': if (woodenPickaxeAvailable) { stoneCount += 1; worldArray[y][x] = ' '; } break;
                }
            }
        }
    }
    system("cls");
}

void ConsoleGame::resourcePlacing(char availableItem, char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X])
{
    if (availableItem == ' ') { return; }

    switch (availableItem) {
        case 't': if (stickCount == 0) { return; } stickCount--; break;
        case 'T': if (woodCount == 0) { return; }; woodCount--; break;
        case 'S': if (stoneCount == 0) { return; }; stoneCount--; break;
    }

    worldArray[playerPosY][playerPosX] = availableItem;
    playerWorldArray[playerPosY][playerPosX] = worldArray[playerPosY][playerPosX];
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
         << "e - to mine / to enter the underground level" << endl
         << "c - to craft" << endl
         << "q - to place item" << endl;
    _getch(); system("cls");
}
