#include <iostream>

using namespace std;

int main()
{
    char first_string[255] = "", second_string[255] = "";
    cin.getline(first_string, 255);
    cin.getline(second_string, 255);
    for (int i = 0; i < 255; i++) {
        if (first_string[i] != second_string[i]) {
            cout << "Strings are not equivalent!" << endl;
            return 0;
        }
    }
    cout << "These strings are the same" << endl;
    return 0;
}
