#include <iostream>

using namespace std;

int main()
{
    double m;
    cout << "Enter the mass of the ship: ";
    cin >> m;
    int f = m/3 - 2;
    cout << "Required amount of fuel: " << f << endl;
    return 0;
}
