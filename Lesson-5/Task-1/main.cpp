#include <iostream>

using namespace std;

int LenghtInput ()                                          // function length input
{
    int lenght = 0;
    cout << "Enter length of square (integer & positive number): ";
    cin >> lenght;
    return lenght;
}

void FrameBuilding (int lenght, int y, int x)               // function of line output
{
    if (x <= lenght && y <= lenght)                         // repeat condition for every column
    {
        if ((y < lenght && y > 1) && (x < lenght && x > 1)) // for emptiness
            cout << "  ";
        else                                                // for frame
            cout << "* ";
        FrameBuilding(lenght, y, x + 1);                    // recursion for the next elementin line

    }
    if (x == lenght + 1)                                    // repeat condition for every line
    {
        cout << endl;
        FrameBuilding(lenght, y + 1, 1);                    // recursion for the next line
    }

}

void DrawSquare (int lenght)                                // function for output every line in square
{
    FrameBuilding(lenght, 1, 1);                            // line output
}

int main()
{
    int lenght = LenghtInput();                             // input lenght
    DrawSquare(lenght);                                     // output square frame
    return 0;
}
