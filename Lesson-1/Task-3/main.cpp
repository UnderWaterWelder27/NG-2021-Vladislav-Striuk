#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    b = a + b;
    a = b - a;
    b = b - a;
    cout << endl << "a = " << a << endl << "b = " << b << endl;
    return 0;
}
