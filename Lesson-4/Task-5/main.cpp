#include <iostream>

using namespace std;

int main()
{
    char bad_language [256] = "";
    cin.getline(bad_language, 256);
    for (int i = 0; i < 256; i++) {
        if (bad_language[i]   == 'f' && bad_language[i+1] == 'u' &&
            bad_language[i+2] == 'c' && bad_language[i+3] == 'k'   ) {
                bad_language[i]   = '*';
                bad_language[i+1] = '*';
                bad_language[i+2] = '*';
                bad_language[i+3] = '*';
        }
        cout << bad_language[i];
    }
    return 0;
}
