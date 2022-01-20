#include "consolegame.h"

#include <iostream>
#include <random>
#include <time.h>
#include <conio.h>

using namespace std;

ConsoleGame::ConsoleGame()
{
    currentWorld = '1';
    playerPosX = WORLD_SIZE_X / 2;
    playerPosY = WORLD_SIZE_Y / 2;
    playerActionInput = ' ';
    itemInHand = ' ';

    for (int i = 0; i < ENEMIES_AMOUNT; i++) {
        enemyDead[i] = false;
    }

    amount.stick = 0;
    amount.wood = 0;
    amount.stone = 0;
    amount.iron = 0;
    amount.diamond = 0;

    available.woodenPickaxe = false;
    available.stonePickaxe = false;
    available.ironPickaxe = false;
    available.diamondSword = true;
    available.diamondShield = true;
}

void ConsoleGame::worldGeneration(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X], char o1, char o2, char o3, char o4)
{
    srand(time(0));
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (y == WORLD_SIZE_Y - 1 || x == WORLD_SIZE_X - 1 || y == 0 || x == 0) {
                if ((y == WORLD_SIZE_Y - 1 && x == (WORLD_SIZE_X - 1)/2)) {
                    worldArray[y][x] = 'O';
                }
                else { worldArray[y][x] = '/'; }
            }
            else {
                switch(rand()%30) {
                case 1:  worldArray[y][x] = o1; break;
                case 2:  worldArray[y][x] = o2; break;
                case 3:  worldArray[y][x] = o3; break;
                case 4:  worldArray[y][x] = o4; break;
                default: worldArray[y][x] = ' ';
                }
            }
            for (int clearWay = WORLD_SIZE_Y - 2; clearWay > (WORLD_SIZE_Y/3)*2; clearWay--) {
                worldArray[clearWay][(WORLD_SIZE_X - 1)/2] = ' ';
            }
            playerWorldArray[y][x] = '.';
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

void ConsoleGame::changeWorld(char changeLevel)
{
    if ((currentWorld == '1' && changeLevel == '1') || (currentWorld == '3' && changeLevel == '2')) {
        return;
    }
    else if (changeLevel == '1' && (playerPosY == WORLD_SIZE_Y - 1 && playerPosX == (WORLD_SIZE_X - 1)/2)) {
        currentWorld--;
    }
    else if (changeLevel == '2' && (playerPosY == WORLD_SIZE_Y - 1 && playerPosX == (WORLD_SIZE_X - 1)/2)) {
        currentWorld++;
    }
}

void ConsoleGame::playerPosition(char (*playerWorldArray)[WORLD_SIZE_X])
{
    defendFromEnemyOnCell(available.diamondSword);
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (playerPosX == x && playerPosY == y) {
                cout << "@";
            }
            else { cout << playerWorldArray[y][x]; }
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

        case 'e': resourceMining(worldArray); break;
        case 'q': resourcePlacing(itemInHand, worldArray, playerWorldArray); break;
        case 'm': showGameManual(); break;
        case 'i': openInventory(); break;
        case 'c': openCraftMenu(); break;

        case '1': changeWorld('1'); break;
        case '2': changeWorld('2'); break;
    }
}

bool ConsoleGame::takeStepOportunity(char nextCell)
{
    switch (nextCell) {
        case ' ': return true; break;
        case 'O': return true; break;
        case '!': return true; break;
    }   return false;
}

void ConsoleGame::defendFromEnemyOnCell(bool artefact)
{
    for (int enemyNum = 0; enemyNum < ENEMIES_AMOUNT; enemyNum++) {
        if (enemyPosX[enemyNum] != playerPosX || enemyPosY[enemyNum] != playerPosY) { return; }
        if (enemyPosX[enemyNum] == playerPosX && enemyPosY[enemyNum] == playerPosY) {
            if (artefact == false) {
                switch(rand()%2) {
                case 0: gameOver(); break;
                default:
                    enemyDead[enemyNum] = true;
                    battleMap[playerPosY][playerPosX] = '?';
                    break;
                }
            }
            else {
                switch(rand()%149) {
                case 0: gameOver(); break;
                default:
                    enemyDead[enemyNum] = true;
                    battleMap[playerPosY][playerPosX] = '?';
                }
            }
        }
    }
}

void ConsoleGame::enemyRandomizeStarterPosition()
{
    for (int enemyNum = 0; enemyNum < ENEMIES_AMOUNT; enemyNum++) {
        enemyPosY[enemyNum] = rand()%(WORLD_SIZE_Y - 2) + 1;
        enemyPosX[enemyNum] = rand()%(WORLD_SIZE_X - 2) + 1;
        battleMap[ enemyPosY[enemyNum] ][ enemyPosX[enemyNum] ] = '!';
    }
}

bool ConsoleGame::enemyChangePostion(int posY, int posX, int chagePosY, int changePosX)
{
    if (battleMap[chagePosY][changePosX] != ' ') { return false; }
    if (battleMap[chagePosY][changePosX] == battleMap[playerPosY][playerPosX]) {
        defendFromEnemyOnCell(available.diamondShield);
        return false;
    }
    battleMap[chagePosY][changePosX] = '!';
    battleMap[posY][posX] = ' ';
    if (playerBattleMap[chagePosY][changePosX] != '.') {
        playerBattleMap[chagePosY][changePosX] = battleMap[chagePosY][changePosX];
    }
    return true;
}

void ConsoleGame::enemyRandomMove()
{
    for (int enemyNum = 0; enemyNum < ENEMIES_AMOUNT; enemyNum++) {
        int Y = enemyPosY[enemyNum];
        int X = enemyPosX[enemyNum];

        if (rand()%1 == 0) {
            if (enemyDead[enemyNum] == false) {
                switch(rand()%4) {
                    case 0: if (enemyChangePostion(Y, X, Y - 1, X)) { enemyPosY[enemyNum]--; } break;
                    case 1: if (enemyChangePostion(Y, X, Y + 1, X)) { enemyPosY[enemyNum]++; } break;
                    case 2: if (enemyChangePostion(Y, X, Y, X - 1)) { enemyPosX[enemyNum]--; } break;
                    case 3: if (enemyChangePostion(Y, X, Y, X + 1)) { enemyPosX[enemyNum]++; } break;
                }
            }
        }
        if (playerBattleMap[Y][X] != '.') {
            playerBattleMap[Y][X] = battleMap[Y][X];
        }
    }
}

void ConsoleGame::resourceMining(char (*worldArray)[WORLD_SIZE_X])
{
    for (int y = playerPosY - 1; y <= playerPosY + 1; y++) {
        for (int x = playerPosX - 1; x <= playerPosX + 1; x++) {
            if (y < WORLD_SIZE_Y && x < WORLD_SIZE_X && y >= 0 && x >= 0) {
                switch (worldArray[y][x]) {
                    case 'T': amount.wood += 1; worldArray[y][x] = ' '; break;
                    case 't': amount.stick += 1; worldArray[y][x] = ' '; break;
                    case 'S': if (available.woodenPickaxe) { amount.stone += 2; worldArray[y][x] = ' '; } break;
                    case 's': if (available.woodenPickaxe) { amount.stone += 1; worldArray[y][x] = ' '; } break;
                    case 'I': if (available.stonePickaxe) { amount.iron += 2; worldArray[y][x] = ' '; } break;
                    case 'i': if (available.stonePickaxe) { amount.iron += 1; worldArray[y][x] = ' '; } break;
                    case 'D': if (available.ironPickaxe) { amount.diamond += 2; worldArray[y][x] = ' '; } break;
                    case 'd': if (available.ironPickaxe) { amount.diamond += 1; worldArray[y][x] = ' '; } break;
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
        case 't': if (amount.stick == 0) { return; } amount.stick--; break;
        case 'T': if (amount.wood == 0) { return; }; amount.wood--; break;
        case 'S': if (amount.stone == 1) { return; }; amount.stone -= 2; break;
        case 'I': if (amount.iron <= 1) { return; }; amount.iron -= 2; break;
        case 'D': if (amount.diamond <= 1) { return; }; amount.diamond -= 2; break;
        default: return;
    }
    worldArray[playerPosY][playerPosX] = availableItem;
    playerWorldArray[playerPosY][playerPosX] = worldArray[playerPosY][playerPosX];
}

void ConsoleGame::placeItemInHand()
{
    switch (_getch()) {
        case '1': if (amount.stick > 0) { itemInHand = 't'; } break;
        case '2': if (amount.wood > 0) { itemInHand = 'T'; } break;
        case '3': if (amount.stone > 0) { itemInHand = 'S'; } break;
        case '4': if (amount.iron > 0) { itemInHand = 'I'; } break;
        case '5': if (amount.diamond > 0) { itemInHand = 'D'; } break;
        default: itemInHand = ' '; break;
    }
}

void ConsoleGame::openInventory()
{
    cout << "INVENTORY" << endl << endl;
    cout << "1.  "; if (amount.stick > 0)      { cout << "Stick    - " << amount.stick; } cout << endl;
    cout << "2.  "; if (amount.wood > 0)       { cout << "Wood     - " << amount.wood; } cout << endl;
    cout << "3.  "; if (amount.stone > 0)      { cout << "Stone    - " << amount.stone; } cout << endl;
    cout << "4.  "; if (amount.iron > 0)       { cout << "Iron     - " << amount.iron; } cout << endl;
    cout << "5.  "; if (amount.diamond > 0)    { cout << "Diamond  - " << amount.diamond; } cout << endl;

    cout << "6.  "; if (available.woodenPickaxe) { cout << "Wooden Pickaxe    - available"; } cout << endl;
    cout << "7.  "; if (available.stonePickaxe) { cout << "Stone Pickaxe      - available"; } cout << endl;
    cout << "8.  "; if (available.ironPickaxe) { cout << "Iron Pickaxe        - available"; } cout << endl;
    cout << "9.  "; if (available.diamondSword) { cout << "Diamond Sword      - available"; } cout << endl;
    cout << "10. "; if (available.diamondShield) { cout << "Diamond Shield   - available"; } cout << endl;

    cout << endl << "Y - put an item in hand ? >";
    if (_getch() == 'y') {
        cout << endl << "Choose item: ";
        placeItemInHand();
    }
    else { system("cls"); }
}

void ConsoleGame::openCraftMenu()
{
    cout << "CRAFT MENU" << endl
         << "Choose, what do you want ot craft:" << endl << endl;
    if (amount.stick >= 6 && amount.wood >= 20 && available.woodenPickaxe == false)
        cout << "1. Wooden pickaxe      | Cost: 6 stick, 20 wood" << endl;

    if (amount.stick >= 6 && amount.stone >= 20 && available.stonePickaxe == false)
        cout << "2. Stone pickaxe       | Cost: 6 stick, 20 stone" << endl;

    if (amount.stick >= 6 && amount.iron >= 30 && available.ironPickaxe == false)
        cout << "3. Iron pickaxe        | Cost: 6 stick, 30 iron" << endl;

    if (amount.stick >= 6 && amount.diamond >= 50 && available.diamondSword == false)
        cout << "4. Diamond Sword       | Cost: 6 stick, 50 diamond" << endl;

    if (amount.iron >= 10 && amount.diamond >= 50 && available.diamondShield == false)
        cout << "5. Diamond Shield      | Cost: 10 iron, 50 diamond" << endl;

    cout << ">";
    switch (_getch()) {
        case '1': amount.stick -= 6; amount.wood -= 20; available.woodenPickaxe = true; break;
        case '2': amount.stick -= 6; amount.stone -= 20; available.stonePickaxe = true; break;
        case '3': amount.stick -= 6; amount.iron -= 30; available.ironPickaxe = true; break;
        case '4': amount.stick -= 6; amount.diamond -= 50; available.diamondSword = true; break;
        case '5': amount.iron -= 10; amount.diamond -= 50; available.diamondShield = true; break;
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
         << "q - to place item" << endl
         << "1 - move to previous level" << endl
         << "2 - move to next level" << endl;
    _getch(); system("cls");
}

void ConsoleGame::gameOver()
{
    system("cls");
    currentWorld = '0';
    cout << "\a B R U H " << endl;
    _getch();
}
