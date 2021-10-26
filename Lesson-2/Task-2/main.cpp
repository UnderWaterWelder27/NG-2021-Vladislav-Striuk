#include <iostream>

using namespace std;

int main()
{
    unsigned long long int num, d = 1;  //d - division coefficient
    unsigned short int near_1, near_2, n_hash, first;
    cout << "Enter any positive integer number: ";
    cin >> num;
    first = num % 10;                   //storing the minimum digit
    do {
        near_1 = (num/d) % 10;          //saving digit
        near_2 = (num/(d*10)) % 10;     //saving near digit
        d *= 10;                        //increase division coefficient
        if (near_1 == near_2) {         //if neighbor digits are equal
            n_hash += near_1;           //digit hash += one of the neighbor digits
        }
    } while (num/d >= 1);               //end of cycle if num/d < 1;
    if (near_1 == first) {              //if opposite digits are equal
        n_hash += near_1;               //digit hash += one of the opposite digits
    }
    cout << "Hash of your number is: " << n_hash << endl;
    return 0;
}
