#include <iostream>

using namespace std;

int main()
{
    int mass[10], add;
    for (int i = 0; i < 10; i++) {          //index iteration loop
        cout << "mass[" << i << "] = ";
        cin >> mass[i];                     //enter values for array
    } cout << endl;

    cout << "Value for increase all elements of the array: ";
    cin >> add;

    for (int i = 0; i < 10; i++) {          //index iteration loop
        mass[i] += add;                     //add value for every array element
        cout << "mass[" << i << "] = " << mass[i] << endl;
    }
    return 0;
}
