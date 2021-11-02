#include <iostream>

using namespace std;

int main()
{
    int num = 0, sum = 0;
    cout << "Enter any positive integer number: "; cin >> num;
    for (int i = num; i >= 1; i /= 10) {
        sum += (i % 10);
    }
    cout << endl << "sum = " << sum << endl;
    return 0;
}
