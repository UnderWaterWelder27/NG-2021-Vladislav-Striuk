#ifndef CONSOLEGAME_H
#define CONSOLEGAME_H


class ConsoleGame
{

public:
    ConsoleGame();

    void worldGeneration();
    void showUndiscoveredWorld();
    void showPlayerPosition();
    void playerMovement();

private:
    static const int WORLD_SIZE_X = 100;
    static const int WORLD_SIZE_Y = 20;

    char generalMap [WORLD_SIZE_Y][WORLD_SIZE_X];                       // main map
    char playerMap [WORLD_SIZE_Y][WORLD_SIZE_X];                        // visible map
    char playerActionInput;

    int playerPosX;
    int playerPosY;

};

#endif // CONSOLEGAME_H
