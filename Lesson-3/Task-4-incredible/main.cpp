#include "consolegame.h"


int main()
{
    ConsoleGame mainGame;

    mainGame.showGameManual();
    mainGame.worldGeneration(mainGame.savannahMap, mainGame.playerSavannahMap, 'T', 't', 'S', 's');
    mainGame.worldGeneration(mainGame.caveMap, mainGame.playerCaveMap, 'I', 'i', 'D', 'd');

    while (true) {
        while (mainGame.currentWorld == '1') {
            mainGame.showUndiscoveredWorld(mainGame.savannahMap, mainGame.playerSavannahMap);
            mainGame.playerPosition(mainGame.playerSavannahMap);
            mainGame.playerKeyAction(mainGame.savannahMap, mainGame.playerSavannahMap);
        }
        while (mainGame.currentWorld == '2') {
            mainGame.showUndiscoveredWorld(mainGame.caveMap, mainGame.playerCaveMap);
            mainGame.playerPosition(mainGame.playerCaveMap);
            mainGame.playerKeyAction(mainGame.caveMap, mainGame.playerCaveMap);
        }
    }

    return 0;
}
