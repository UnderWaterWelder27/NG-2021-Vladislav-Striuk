#include <iostream>

using namespace std;

int main()
{
    unsigned int l, up, down;
    cout << "Enter length of square (integer & positive number): ";
    cin >> l;
    for (down = 1; down <=l; down ++) {
        if (down == 1 || down == l) {
            for (up = 1; up <= l; up++) {
                cout << "* ";
            }
        cout << endl;
        }
        else {
            for (up = 1; up <=l; up++) {
                if (up == 1 || up == l - 1) cout << "* ";
                cout << "  ";
            }
            cout << endl;
        }
    }
    return 0;
}
