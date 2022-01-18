#include "consolegame.h"


int main()
{
    ConsoleGame mainGame;

    mainGame.showGameManual();
    mainGame.worldGeneration();

    while (mainGame.changeWorld() == '1') {
        mainGame.showUndiscoveredWorld();
        mainGame.playerPosition();
        mainGame.playerKeyAction(mainGame.playerSavannahMap);
    }

    return 0;
}
