#include <iostream>

using namespace std;

int main()
{
    unsigned int num, sum;
    cout << "Enter any positive integer number: ";
    cin >> num;
    for ( ; num >= 1; num /= 10) {
        sum += (num % 10);
    }
    cout << "sum = " << sum << endl;
    return 0;
}
