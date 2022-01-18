#ifndef CONSOLEGAME_H
#define CONSOLEGAME_H


class ConsoleGame
{

public:
    ConsoleGame();

    static const int WORLD_SIZE_X = 100;
    static const int WORLD_SIZE_Y = 20;

    char savannahWorld [WORLD_SIZE_Y][WORLD_SIZE_X];                           // main map
    char playerSavannahMap [WORLD_SIZE_Y][WORLD_SIZE_X];                     // visible general map
    char caveWorld [WORLD_SIZE_Y][WORLD_SIZE_X];
    char playerCaveWorld [WORLD_SIZE_Y][WORLD_SIZE_X];

    void worldGeneration();
    void showUndiscoveredWorld();
    char changeWorld();

    void playerPosition();
    void playerKeyAction(char (*worldArray)[WORLD_SIZE_X]);
    bool takeStepOportunity(char nextCell);

    void resourceMining();
    void resourcePlacing(char availableItem);
    void placeItemInHand();

    void openInventory();
    void openCraftMenu();
    void showGameManual();
    void closeTab();

    char *getSavannahWorld() { return *savannahWorld;}

protected:

    char currentWorld;

    char playerActionInput;
    int playerPosX;
    int playerPosY;

    int stickCount;
    int woodCount;
    int stoneCount;

    bool woodenPickaxeAvailable;
    bool stonePickaxeAvailable;

    char itemInHand;
};

#endif // CONSOLEGAME_H
