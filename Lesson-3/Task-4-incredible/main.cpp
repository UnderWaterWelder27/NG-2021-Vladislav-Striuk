#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
/**************************************************************************************************************************************/
///INITIALIZING VARIABLES

    srand(time(0));
    const int world_size_x = 100;                                               //width of the world
    const int world_size_y = 40;                                                //height of the world

    char general_map [world_size_y][world_size_x];                              //main map[][]
    char player_map [world_size_y][world_size_x];                               //player map[][]

    int player_pos_x = world_size_x/2;                                          //player x position
    int player_pos_y = world_size_y/2;                                          //player y position

    char player_action = ' ';                                                   //player action

/**************************************************************************************************************************************/
///GENERATING MAP

    for (int y = 0; y < world_size_y; y++) {                                    //for Y (line)
        for (int x = 0; x < world_size_x; x++) {                                //for X (column)
            if (y == world_size_y - 1 || y == 0 ||
                x == world_size_x - 1 || x == 0) {                              //coordinates of the frame
                    general_map[y][x] = '/';                                    //inaccessible frame
            }
            else {
                switch(rand()%23) {                                             //generating map
                    case 1:  general_map[y][x] = 't'; break;                    //trees
                    case 2:  general_map[y][x] = 's'; break;                    //stones
                    default: general_map[y][x] = '.';                           //empty field
                }
            }
            player_map[y][x] = '*';                                             //map fog
        }
    }

/**************************************************************************************************************************************/
///DISCOVERING WORLD

    while (true) {
        player_map[player_pos_y][player_pos_x + 1]      =    general_map[player_pos_y][player_pos_x + 1];       //right
        player_map[player_pos_y][player_pos_x - 1]      =    general_map[player_pos_y][player_pos_x - 1];       //left
        player_map[player_pos_y + 1][player_pos_x]      =    general_map[player_pos_y + 1][player_pos_x];       //down
        player_map[player_pos_y - 1][player_pos_x]      =    general_map[player_pos_y - 1][player_pos_x];       //up

        player_map[player_pos_y + 1][player_pos_x + 1]  =    general_map[player_pos_y + 1][player_pos_x + 1];   //down right
        player_map[player_pos_y - 1][player_pos_x - 1]  =    general_map[player_pos_y - 1][player_pos_x - 1];   //up left
        player_map[player_pos_y + 1][player_pos_x - 1]  =    general_map[player_pos_y + 1][player_pos_x - 1];   //down left
        player_map[player_pos_y - 1][player_pos_x + 1]  =    general_map[player_pos_y - 1][player_pos_x + 1];   //up right
        system("cls");

        for (int y = 0; y < world_size_y; y++) {
            for (int x = 0; x < world_size_x; x++) {
                if (player_pos_x == x && player_pos_y == y)
                    cout << "@";
                else
                    cout << player_map[y][x];
            } cout << endl;
        }

        cout << ">";
        cin >> player_action;
        switch(player_action)
        {
            case 'w': if (general_map[player_pos_y-1][player_pos_x] == '.') player_pos_y--; break; //movement to up
            case 's': if (general_map[player_pos_y+1][player_pos_x] == '.') player_pos_y++; break; //movement to down
            case 'd': if (general_map[player_pos_y][player_pos_x+1] == '.') player_pos_x++; break; //movement to right
            case 'a': if (general_map[player_pos_y][player_pos_x-1] == '.') player_pos_x--; break; //movement to left
        }
    }

/**************************************************************************************************************************************/
    return 0;
}
