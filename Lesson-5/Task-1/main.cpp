#include <iostream>

using namespace std;

int input_lenght ()                                                                 //length input
{
    int lenght = 0;
    cout << "Enter length of square (integer & positive number): ";
    cin >> lenght;
    return lenght;
}

void output_square (int lenght)
{
    for (int y = 1; y <= lenght; y++)                                               //for each line
    {
        for (int x = 1; x <= lenght; x++)                                           //for each column
        {
            if ((y < lenght && y > 1) && (x < lenght && x > 1))     cout << "  ";   //inner emptiness
            else    cout << "* ";                                                   //outer contour
        }
        cout << endl;
    }
}

int main()
{
    int square_lenght = input_lenght();
    output_square(square_lenght);
    return 0;
}
