#include "consolegame.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

ConsoleGame::ConsoleGame()
{
    playerPosX = WORLD_SIZE_X / 2;
    playerPosY = WORLD_SIZE_Y / 2;
    playerActionInput = ' ';
}

void ConsoleGame::worldGeneration()
{
    srand(time(0));
    for (int y = 0; y < WORLD_SIZE_Y; y++) {                                //for Y (line)
        for (int x = 0; x < WORLD_SIZE_X; x++) {                            //for X (column)
            if (   y == WORLD_SIZE_Y - 1 || y == WORLD_SIZE_Y - 2           //coordinates of the frame
                || x == WORLD_SIZE_X - 1 || x == WORLD_SIZE_X - 2
                || y == 0 || y == 1 || x == 0 || x == 1)
            {
                generalMap[y][x] = '/';                                     //inaccessible frame
            }
            else {
                switch(rand()%23) {                                         //generating map
                case 1:  generalMap[y][x] = 't'; break;                     //trees
                case 2:  generalMap[y][x] = 's'; break;                     //stones
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
            playerMap[y][x] = generalMap[y][x];
        }
    }
    system("cls");
}

void ConsoleGame::showPlayerPosition()
{
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            if (playerPosX == x && playerPosY == y)
                cout << "@";
            else
                cout << playerMap[y][x];
        } cout << endl;
    }
}

void ConsoleGame::playerMovement()
{
    cout << ">";
    cin >> playerActionInput;
    switch(playerActionInput) {
    case 'w': if (generalMap[playerPosY-1][playerPosX] == ' ') playerPosY--; break;             //movement to up
    case 's': if (generalMap[playerPosY+1][playerPosX] == ' ') playerPosY++; break;             //movement to down
    case 'd': if (generalMap[playerPosY][playerPosX+1] == ' ') playerPosX++; break;             //movement to right
    case 'a': if (generalMap[playerPosY][playerPosX-1] == ' ') playerPosX--; break;             //movement to left
    }
}
