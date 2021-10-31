#include <iostream>

using namespace std;

int main()
{
    int a = 50, b = 20;
    b = a + b;
    a = b - a;
    b = b - a;
    cout << endl << "a = " << a << endl << "b = " << b << endl;
    return 0;
}
