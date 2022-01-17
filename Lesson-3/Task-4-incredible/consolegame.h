#ifndef CONSOLEGAME_H
#define CONSOLEGAME_H


class ConsoleGame
{

public:
    ConsoleGame();

    void worldGeneration();
    void showUndiscoveredWorld();

    void playerPosition();
    void playerKeyAction();

    void resourceMining();
    void resourcePlacing(char availableItem);
    void placeItemInHand();

    void openInventory();
    void openCraftMenu();
    void showGameManual();
    void closeTab();

protected:
    static const int WORLD_SIZE_X = 100;
    static const int WORLD_SIZE_Y = 20;

    char generalMap [WORLD_SIZE_Y][WORLD_SIZE_X];                       // main map
    char playerMap [WORLD_SIZE_Y][WORLD_SIZE_X];                        // visible map

    char playerActionInput;
    int playerPosX;
    int playerPosY;

    int itemStick;
    int itemWood;
    int itemStone;

    char itemInHand;
};

#endif // CONSOLEGAME_H
