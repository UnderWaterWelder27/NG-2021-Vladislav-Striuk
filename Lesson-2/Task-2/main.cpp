#include <iostream>

using namespace std;

int main()
{
    long long num = 0;
    short int digit = 0, n_hash = 0;
    cout << "Enter any positive integer number: "; cin >> num;

    for (long long i = num; i >= 1; i /= 10) {
        digit = i % 10;                //saving digit
        if (digit == i/10 % 10)        //if neighbor digits are equal
            n_hash += digit;           //digit hash += one of the neighbor digits
    }
    if (digit == num % 10) {           //if opposite digits are equal
        n_hash += digit;               //digit hash += one of the opposite digits
    }
    cout << "Hash of your number is: " << n_hash << endl;
    return 0;
}
