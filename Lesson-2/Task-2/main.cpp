#include <iostream>

using namespace std;

int main()
{
    unsigned long long int num;
    unsigned short int near_1, near_2, n_hash, first;
    cout << "Enter any positive integer number: ";
    cin >> num;
    first = num % 10;
    for ( ; num >= 1; ) {
        near_1 = num % 10;
        num /= 10;
        near_2 = num % 10;
        if (near_1 == near_2) {
            n_hash += near_1;
        }
    }
    if (near_1 == first) {
        n_hash += near_1;
    }
    cout << "Hash of your number is: " << n_hash << endl;
    return 0;
}
