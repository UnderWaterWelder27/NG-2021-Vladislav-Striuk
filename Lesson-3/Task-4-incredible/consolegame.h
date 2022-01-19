#ifndef CONSOLEGAME_H
#define CONSOLEGAME_H


class ConsoleGame
{

public:
    ConsoleGame();

/// WORLD STATS
    static const int WORLD_SIZE_X = 100;
    static const int WORLD_SIZE_Y = 20;

/// WORLD MAPS /// (public, because new worlds is created by main function)
    char savannahMap [WORLD_SIZE_Y][WORLD_SIZE_X];
    char playerSavannahMap [WORLD_SIZE_Y][WORLD_SIZE_X];
    char caveMap [WORLD_SIZE_Y][WORLD_SIZE_X];
    char playerCaveMap [WORLD_SIZE_Y][WORLD_SIZE_X];

/// WORLD GENERATION AND OUTPUT
    void worldGeneration(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X], char o1, char o2, char o3, char o4);
    void showUndiscoveredWorld(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X]);
    void changeWorld(char changeLevel);
    void playerPosition(char (*playerWorldArray)[WORLD_SIZE_X]);

/// PLAYER ACTIONS
    void playerKeyAction(char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X]);
    bool takeStepOportunity(char nextCell);

/// RESOURCE ACTIONS
    void resourceMining(char (*worldArray)[WORLD_SIZE_X]);
    void resourcePlacing(char availableItem, char (*worldArray)[WORLD_SIZE_X], char (*playerWorldArray)[WORLD_SIZE_X]);
    void placeItemInHand();

/// GUI FUNCTIONS
    void openInventory();
    void openCraftMenu();
    void showGameManual();

/// GETTERS
    char getCurrentWorld() { return currentWorld; }

private:

/// WORLD STAT
    char currentWorld;

/// SAVE PLAYER ACTIONS
    int playerPosX;
    int playerPosY;   
    char playerActionInput;
    char itemInHand;

/// RESOURCES COUNT
    struct resource {
        int stick, wood, stone, iron, diamond;
    } count;

/// ITEMS AVAILABLE
    struct items {
        bool woodenPickaxe, stonePickaxe, ironPickaxe, diamondSword, diamondShield;
    } available;
};

#endif // CONSOLEGAME_H
