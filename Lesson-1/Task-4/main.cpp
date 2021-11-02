#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Enter coefficients (a, b, c) for ax^2 + bx + c = 0" << endl;
    int a = 0; cout << "a = "; cin >> a;
    int b = 0; cout << "b = "; cin >> b;
    int c = 0; cout << "c = "; cin >> c;

    double D = pow(b, 2) - 4*a*c;

    if (D > 0) {
        cout << endl << "D = " << D << endl;
        cout << "x1 = " << (-b + sqrt(D))/2*a << endl;
        cout << "x2 = " << (-b - sqrt(D))/2*a << endl;
    }
    else if (D == 0) {
        cout << endl << "D = 0" << endl;
        cout << "x = " << -b/2*a << endl;
    }
    else {
        cout << endl << "D < 0" << endl;
        cout << "No solution . . ." << endl;
    }
    return 0;
}
