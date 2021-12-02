#include <iostream>
#include <random>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
    srand(time(0));

    int first_number = 0,       second_number = 0,
        first_array[4] = {0},   second_array[4] = {0};

///     i - for every array elements from first to last
///     j - for pow of digit for multiplying (10, 100, 1000)

    for (int i = 0, j = 3; j >= 0; i ++, j--) {
        first_array[i] = rand()%10;                         //assignment first_array[]
        first_number += first_array[i] * pow(10, j);        //sum of the digits from first_array (complete number)
        second_array[i] = rand()%10;                        //assignment second_array[]
        second_number += second_array[i] * pow(10, j);      //sum of the digits from second_array(complete number)
    }
    cout <<  first_number << " + " << second_number
         << " = " << first_number + second_number
         << endl;

    return 0;
}
