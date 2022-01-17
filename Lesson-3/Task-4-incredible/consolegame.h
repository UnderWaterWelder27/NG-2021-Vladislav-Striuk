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
    void openInventory();
    void keybindsInformation();

    void setSticksCount(int fStick) { sticks = fStick; }
    void setWoodCount(int fWood) { wood = fWood; }
    void setStoneCount(int fStone) { stone = fStone; }

    int getSticksCount() { return sticks; }
    int getWoodCount() { return wood; }
    int getStoneCount() { return stone; }

protected:
    static const int WORLD_SIZE_X = 100;
    static const int WORLD_SIZE_Y = 20;

    char generalMap [WORLD_SIZE_Y][WORLD_SIZE_X];                       // main map
    char playerMap [WORLD_SIZE_Y][WORLD_SIZE_X];                        // visible map
    char playerActionInput;

    int playerPosX;
    int playerPosY;

    int sticks;
    int wood;
    int stone;
};

#endif // CONSOLEGAME_H
