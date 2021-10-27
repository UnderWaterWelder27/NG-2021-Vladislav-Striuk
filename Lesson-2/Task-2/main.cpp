#include <iostream>

using namespace std;

int main()
{
    long long int num;
    short int near_1, near_2, n_hash, first;
    cout << "Enter any positive integer number: "; cin >> num;
    first = num % 10;                   //storing the minimum digit
    for (long long int i = num; i >= 1; i /= 10) {
        near_1 = i % 10;                //saving digit
        near_2 = i/10 % 10;             //saving near digit
        if (near_1 == near_2)           //if neighbor digits are equal
            n_hash += near_1;           //digit hash += one of the neighbor digits
    }
    if (near_1 == first) {              //if opposite digits are equal
        n_hash += near_1;               //digit hash += one of the opposite digits
    }
    cout << "Hash of your number is: " << n_hash << endl;
    return 0;
}
