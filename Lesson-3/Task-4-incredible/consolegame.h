#ifndef CONSOLEGAME_H
#define CONSOLEGAME_H

#include "gamemanual.h"
#include "playerinventory.h"
#include "resourcemining.h"


class ConsoleGame : public GameManual, PlayerInventory
{

public:
    ConsoleGame();

    void worldGeneration();
    void showUndiscoveredWorld();
    void playerPosition();
    void playerKeyAction();

    int getPlayerPosX() { return playerPosX; }
    int getPlayerPosY() { return playerPosY; }

private:
    static const int WORLD_SIZE_X = 100;
    static const int WORLD_SIZE_Y = 20;

    char generalMap [WORLD_SIZE_Y][WORLD_SIZE_X];                       // main map
    char playerMap [WORLD_SIZE_Y][WORLD_SIZE_X];                        // visible map
    char playerActionInput;

    int playerPosX;
    int playerPosY;
};

#endif // CONSOLEGAME_H
