#include "consolegame.h"
#include "gamemanual.h"


int main()
{
    ConsoleGame mainGame;
    GameManual help;

    help.keybindsInformation();
    mainGame.worldGeneration();
    while (true)
    {
        mainGame.showUndiscoveredWorld();
        mainGame.playerPosition();
        mainGame.playerKeyAction();
    }
    return 0;
}
