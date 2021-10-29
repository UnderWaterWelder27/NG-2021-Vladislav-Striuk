#include <iostream>

using namespace std;

int main()
{
    int mass[10], add;
    for (int i = 0; i < 10; i++) {
        cout << "mass[" << i << "] = "; cin >> mass[i];
    } cout << endl;

    cout << "Value for increase all elements of the array: ";
    cin >> add;

    for (int i = 0; i < 10; i++) {
        mass[i] += add;
        cout << "mass[" << i << "] = " << mass[i] << endl;
    }
    return 0;
}
