#include <iostream>
#include "consolegame.h"
#include "playerstatistic.h"
#include "gamemanual.h"

using namespace std;

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
