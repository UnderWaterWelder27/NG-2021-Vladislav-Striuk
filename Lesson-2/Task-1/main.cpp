#include <iostream>

using namespace std;

int main()
{
    unsigned int num, sum, d = 1;
    cout << "Enter any positive integer number: "; cin >> num;
    do {
        sum += (num/d % 10);
        d *= 10;
    } while (num/d >= 1);
    cout << endl << "sum = " << sum << endl;
    return 0;
}
