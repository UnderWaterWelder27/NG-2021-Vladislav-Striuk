#include <iostream>

using namespace std;

int input_lenght ()                                         // function length input
{
    int lenght = 0;
    cout << "Enter length of square (integer & positive number): ";
    cin >> lenght;
    return lenght;
}

void line_output (int lenght, int y, int x)                 // function of line output
{
    if (x <= lenght)                                        // repeat condition for every column
    {
        if ((y < lenght && y > 1) && (x < lenght && x > 1)) // for emptiness
            cout << "  ";
        else                                                // for frame
            cout << "* ";
        line_output(lenght, y, x += 1);                     // recursion for the next elementin line
    }
}

void square_output (int lenght, int y, int x)               // function for output every line in square
{
    line_output(lenght, y, x);                              // line output
    cout << endl;
    if (y < lenght) {                                       // repeat condition for every line
        square_output(lenght, y += 1, x);                   // recursion for the next line
    }
}

int main()
{
    int square_lenght = input_lenght();                     // input lenght
    square_output(square_lenght, 1, 1);                     // output square frame
    return 0;
}
