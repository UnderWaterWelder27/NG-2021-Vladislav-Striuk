#ifndef CONSOLEGAME_H
#define CONSOLEGAME_H


class ConsoleGame
{

public:
    ConsoleGame();

    static const int WORLD_SIZE_X = 100;
    static const int WORLD_SIZE_Y = 20;
    char currentWorld;

    char savannahMap [WORLD_SIZE_Y][WORLD_SIZE_X];                           // main map
    char playerSavannahMap [WORLD_SIZE_Y][WORLD_SIZE_X];                     // visible general map
    char caveMap [WORLD_SIZE_Y][WORLD_SIZE_X];
    char playerCaveMap [WORLD_SIZE_Y][WORLD_SIZE_X];

    void worldGeneration(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X], char o1, char o2, char o3, char o4);
    void showUndiscoveredWorld(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X]);
    void changeWorld();

    void playerPosition(char (*playerWorldArray)[WORLD_SIZE_X]);
    void playerKeyAction(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X]);
    bool takeStepOportunity(char nextCell);

    void resourceMining(char (*worldArray)[WORLD_SIZE_X]);
    void resourcePlacing(char availableItem, char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X]);
    void placeItemInHand();

    void openInventory();
    void openCraftMenu();
    void showGameManual();
    void closeTab();

    char *getSavannahWorld() { return *savannahMap;}

protected:

    char playerActionInput;
    int playerPosX;
    int playerPosY;

    int stickCount;
    int woodCount;
    int stoneCount;
    int ironCount;
    int diamondCount;

    bool woodenPickaxeAvailable;
    bool stonePickaxeAvailable;
    bool ironPickaxeAvailable;
    bool diamondSuperLegendaryMegaSwordAvailable;

    char itemInHand;
};

#endif // CONSOLEGAME_H
