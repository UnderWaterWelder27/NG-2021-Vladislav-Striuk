#include <iostream>

using namespace std;

int main()
{
    long long int num = 0;
    short int near_1 = 0, near_2 = 0, n_hash = 0;
    cout << "Enter any positive integer number: "; cin >> num;

    for (long long int i = num; i >= 1; i /= 10) {
        near_1 = i % 10;                //saving digit
        near_2 = i/10 % 10;             //saving near digit
        if (near_1 == near_2)           //if neighbor digits are equal
            n_hash += near_1;           //digit hash += one of the neighbor digits
    }
    if (near_1 == num % 10) {           //if opposite digits are equal
        n_hash += near_1;               //digit hash += one of the opposite digits
    }
    cout << "Hash of your number is: " << n_hash << endl;
    return 0;
}
