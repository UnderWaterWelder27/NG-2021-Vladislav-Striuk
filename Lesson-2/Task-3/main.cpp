#include <iostream>

using namespace std;

int main()
{
    int l = 0;
    cout << "Enter length of square (integer & positive number): ";
    cin >> l;                                           //length input
    for (int y = 1; y <= l; y++) {                      //for each line
        for (int x = 1; x <= l; x++) {                  //for each column
            if ((y < l && y > 1) && (x < l && x > 1))   //inner emptiness
                cout << "  ";
            else                                        //outer contour
                cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
