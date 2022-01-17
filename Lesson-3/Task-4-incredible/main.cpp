#include "consolegame.h"


int main()
{
    ConsoleGame mainGame;

    mainGame.showGameManual();
    mainGame.worldGeneration();
    while (true)
    {
        mainGame.showUndiscoveredWorld();
        mainGame.playerPosition();
        mainGame.playerKeyAction();
    }
    return 0;
}
