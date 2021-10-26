#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter coefficients (a, b, c) for ax^2 + bx + c = 0" << endl;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;

    double D = pow(b, 2) - 4*a*c;
    if ( D < 0) {
        cout << endl << "D < 0" << endl;
        cout << "No solution . . ." << endl;
    }
    else if (D == 0) {
        cout << endl << "D = 0" << endl;
        cout << "x = " << -b/2*a << endl;
    }
    else {
        cout << endl << "D = " << D << endl;
        cout << "x1 = " << (-b + sqrt(D))/2*a << endl;
        cout << "x2 = " << (-b - sqrt(D))/2*a << endl;
    }
    return 0;
}
