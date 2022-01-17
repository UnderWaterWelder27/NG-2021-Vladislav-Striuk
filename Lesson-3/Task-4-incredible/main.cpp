#include <iostream>
#include "consolegame.h"
#include "playerstatistic.h"

using namespace std;

int main()
{
    ConsoleGame mainGame;
    mainGame.worldGeneration();
    while (true)
    {
        mainGame.showUndiscoveredWorld();
        mainGame.playerPosition();
        mainGame.playerKeyAction();
    }
    return 0;
}
