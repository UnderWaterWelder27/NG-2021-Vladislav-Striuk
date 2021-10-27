#include <iostream>

using namespace std;

int main()
{
    int num, sum;
    cout << "Enter any positive integer number: "; cin >> num;
    for (int i = num; i >= 1; i /= 10) {
        sum += (i % 10);
    }
    cout << endl << "sum = " << sum << endl;
    return 0;
}
