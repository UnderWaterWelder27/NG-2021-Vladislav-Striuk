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

    case 'm': GameManual::keybindsInformation(); break;
    }
}
