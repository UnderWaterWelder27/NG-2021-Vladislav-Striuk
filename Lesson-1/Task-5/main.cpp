#include <iostream>

using namespace std;

int main()
{
    double m = 0;
    cout << "Enter the mass of the ship: ";
    cin >> m;
    cout << "Required amount of fuel: " << m/3 - 2 << endl;
    return 0;
}
