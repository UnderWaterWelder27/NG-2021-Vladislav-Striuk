#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));

    int first_number = 0, second_number = 0, first_array[4] = {0}, second_array[4] = {0};

    for (int i = 0, digit = 1000; i < 4; i ++, digit /= 10) {
        first_array[i] = rand()%10;                         //assignment first_array[]
        cout << first_array[i] << " ";
        first_array[i] *= digit;                            //first_array[i] * digit in number
        first_number += first_array[i];                     //sum of the digits from first_array (complete number)
    }
    cout << endl;
    for (int i = 0, digit = 1000; i < 4; i ++, digit /= 10) {
        second_array[i] = rand()%10;                        //assignment second_array[]
        cout << second_array[i] << " ";
        second_array[i] *= digit;                           //second_array[i] * digit in number
        second_number += second_array[i];                   //sum of the digits from second_array(complete number)
    }
    cout << endl <<  first_number << " + " << second_number
    << " = " << first_number + second_number << endl;
    return 0;
}
