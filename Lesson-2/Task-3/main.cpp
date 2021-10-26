#include <iostream>

using namespace std;

int main()
{
    unsigned int l, x, y;
    cout << "Enter length of square (integer & positive number): ";
    cin >> l;                           //length input
    for (y = 1; y <= l; y++) {          //for each line
        for (x = 1; x <= l; x++) {      //for each column
            if ((y < l && y > 1) && (x < l && x > 1)) //inner emptiness
            cout << "  ";
            else cout << "* ";          //outer contour
        }
        cout << endl;
    }
    return 0;
}
