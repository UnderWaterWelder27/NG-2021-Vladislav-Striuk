#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
    ///INITIALIZING VARIABLES
    srand(time(0));
    const int WORLD_SIZE_X = 100;                                           //width of the world
    const int WORLD_SIZE_Y = 20;                                            //height of the world

    char generalMap [WORLD_SIZE_Y][WORLD_SIZE_X];                           //main map[][]
    char playerMap [WORLD_SIZE_Y][WORLD_SIZE_X];                            //player map[][]

    int playerPosX = WORLD_SIZE_X/2;                                        //player x position
    int playerPosY = WORLD_SIZE_Y/2;                                        //player y position

    char playerAction = ' ';                                                //player action

    ///GENERATING MAP
    for (int y = 0; y < WORLD_SIZE_Y; y++) {                                //for Y (line)
        for (int x = 0; x < WORLD_SIZE_X; x++) {                            //for X (column)
            if (   y == WORLD_SIZE_Y - 1 || y == WORLD_SIZE_Y - 2
                || x == WORLD_SIZE_X - 1 || x == WORLD_SIZE_X - 2
                || y == 0 || y == 1 || x == 0 || x == 1)
            {                                                               //coordinates of the frame
                generalMap[y][x] = '/';                                     //inaccessible frame
            }
            else {
                switch(rand()%23) {                                         //generating map
                case 1:  generalMap[y][x] = 't'; break;                     //trees
                case 2:  generalMap[y][x] = 's'; break;                     //stones
                default: generalMap[y][x] = ' ';                            //empty field
                }
            }
            playerMap[y][x] = '*';                                          //map fog
        }
    }

    ///DISCOVERING WORLD
    while (true) {
        playerMap[playerPosY][playerPosX + 1]      =    generalMap[playerPosY][playerPosX + 1];         //right
        playerMap[playerPosY][playerPosX - 1]      =    generalMap[playerPosY][playerPosX - 1];         //left
        playerMap[playerPosY + 1][playerPosX]      =    generalMap[playerPosY + 1][playerPosX];         //down
        playerMap[playerPosY - 1][playerPosX]      =    generalMap[playerPosY - 1][playerPosX];         //up

        playerMap[playerPosY][playerPosX + 2]      =    generalMap[playerPosY][playerPosX + 2];         //double right
        playerMap[playerPosY][playerPosX - 2]      =    generalMap[playerPosY][playerPosX - 2];         //double left
        playerMap[playerPosY + 2][playerPosX]      =    generalMap[playerPosY + 2][playerPosX];         //double down
        playerMap[playerPosY - 2][playerPosX]      =    generalMap[playerPosY - 2][playerPosX];         //double up

        playerMap[playerPosY + 1][playerPosX + 1]  =    generalMap[playerPosY + 1][playerPosX + 1];     //down right
        playerMap[playerPosY - 1][playerPosX - 1]  =    generalMap[playerPosY - 1][playerPosX - 1];     //up left
        playerMap[playerPosY + 1][playerPosX - 1]  =    generalMap[playerPosY + 1][playerPosX - 1];     //down left
        playerMap[playerPosY - 1][playerPosX + 1]  =    generalMap[playerPosY - 1][playerPosX + 1];     //up right

        playerMap[playerPosY + 2][playerPosX + 1]      =    generalMap[playerPosY + 2][playerPosX + 1];
        playerMap[playerPosY + 2][playerPosX - 1]      =    generalMap[playerPosY + 2][playerPosX - 1];
        playerMap[playerPosY - 2][playerPosX + 1]      =    generalMap[playerPosY - 2][playerPosX + 1];
        playerMap[playerPosY - 2][playerPosX - 1]      =    generalMap[playerPosY - 2][playerPosX - 1];

        playerMap[playerPosY + 1][playerPosX + 2]      =    generalMap[playerPosY + 1][playerPosX + 2];
        playerMap[playerPosY + 1][playerPosX - 2]      =    generalMap[playerPosY + 1][playerPosX - 2];
        playerMap[playerPosY - 1][playerPosX + 2]      =    generalMap[playerPosY - 1][playerPosX + 2];
        playerMap[playerPosY - 1][playerPosX - 2]      =    generalMap[playerPosY - 1][playerPosX - 2];

        playerMap[playerPosY + 2][playerPosX + 2]      =    generalMap[playerPosY + 2][playerPosX + 2];
        playerMap[playerPosY + 2][playerPosX - 2]      =    generalMap[playerPosY + 2][playerPosX - 2];
        playerMap[playerPosY - 2][playerPosX + 2]      =    generalMap[playerPosY - 2][playerPosX + 2];
        playerMap[playerPosY - 2][playerPosX - 2]      =    generalMap[playerPosY - 2][playerPosX - 2];
        system("cls");

        for (int y = 0; y < WORLD_SIZE_Y; y++) {
            for (int x = 0; x < WORLD_SIZE_X; x++) {
                if (playerPosX == x && playerPosY == y)
                    cout << "@";
                else
                    cout << playerMap[y][x];
            } cout << endl;
        }


        cout << ">";
        cin >> playerAction;
        switch(playerAction) {
        case 'w': if (generalMap[playerPosY-1][playerPosX] == ' ') playerPosY--; break;             //movement to up
        case 's': if (generalMap[playerPosY+1][playerPosX] == ' ') playerPosY++; break;             //movement to down
        case 'd': if (generalMap[playerPosY][playerPosX+1] == ' ') playerPosX++; break;             //movement to right
        case 'a': if (generalMap[playerPosY][playerPosX-1] == ' ') playerPosX--; break;             //movement to left
        }
    }
    return 0;
}
