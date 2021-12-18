#include <iostream>

using namespace std;

int main()
{
    long long num = 0;

    cout << "Enter any positive integer number: ";
    cin >> num;

    short int digit  = num % 10,                    //saving digit num % 10
              n_hash = 0;

    for (long long i = num; i >= 1; i /= 10) {
        if (i % 10 == i/10 % 10 || digit == i)      //if neighbor and opposite digits are equal
            n_hash += i % 10;                       //digit hash += one of the neighbor/opposite digits
    }
    cout << "Hash of your number is: " << n_hash << endl;
    return 0;
}
