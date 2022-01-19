#include "consolegame.h"


int main()
{
    ConsoleGame mainGame;

    mainGame.showGameManual();
    mainGame.worldGeneration(mainGame.savannahMap, mainGame.playerSavannahMap, 'T', 't', 'S', 's');
    mainGame.worldGeneration(mainGame.caveMap, mainGame.playerCaveMap, 'I', 'i', 'D', 'd');
    mainGame.worldGeneration(mainGame.battleMap, mainGame.playerBattleMap, ' ', ' ', ' ', ' ');
    mainGame.enemyRandomizeStarterPosition();

    while (true) {
        while (mainGame.getCurrentWorld() == '1') {
            mainGame.showUndiscoveredWorld(mainGame.savannahMap, mainGame.playerSavannahMap);
            mainGame.playerPosition(mainGame.playerSavannahMap);
            mainGame.playerKeyAction(mainGame.savannahMap, mainGame.playerSavannahMap);
        }
        while (mainGame.getCurrentWorld() == '2') {
            mainGame.showUndiscoveredWorld(mainGame.caveMap, mainGame.playerCaveMap);
            mainGame.playerPosition(mainGame.playerCaveMap);
            mainGame.playerKeyAction(mainGame.caveMap, mainGame.playerCaveMap);
        }
        while (mainGame.getCurrentWorld() == '3') {
            mainGame.showUndiscoveredWorld(mainGame.battleMap, mainGame.playerBattleMap);
            mainGame.playerPosition(mainGame.playerBattleMap);
            mainGame.playerKeyAction(mainGame.battleMap, mainGame.playerBattleMap);
        }
    }

    return 0;
}
