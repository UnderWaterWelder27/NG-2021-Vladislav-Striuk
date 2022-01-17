#include "consolegame.h"


int main()
{
    ConsoleGame mainGame;

    mainGame.keybindsInformation();
    mainGame.worldGeneration();
    while (true)
    {
        mainGame.showUndiscoveredWorld();
        mainGame.playerPosition();
        mainGame.playerKeyAction();
    }
    return 0;
}
