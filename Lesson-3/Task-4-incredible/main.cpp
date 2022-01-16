#include <iostream>
#include "consolegame.h"

using namespace std;

int main()
{
    ConsoleGame mainGame;

    mainGame.worldGeneration();
    while (true)
    {
        mainGame.showUndiscoveredWorld();
        mainGame.showPlayerPosition();
        mainGame.playerMovement();
    }

    return 0;
}
