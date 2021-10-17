#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the missing value for the next fragment of the netmask:" << endl;
    cout << "Available values: 255, 254, 252, 248, 240, 224, 192, 128, 000\n" << endl;
    unsigned int frg;

    do {
        cout << "255.255.255.";
        cin >> frg;
        switch (frg) {
        case 255:
            cout << "Number of addresses in a subnet: 1\n" << endl;
            break;
        case 254:
            cout << "Number of addresses in a subnet: 2\n" << endl;
            break;
        case 252:
            cout << "Number of addresses in a subnet: 4\n" << endl;
            break;
        case 248:
            cout << "Number of addresses in a subnet: 8\n" << endl;
            break;
        case 240:
            cout << "Number of addresses in a subnet: 16\n" << endl;
            break;
        case 224:
            cout << "Number of addresses in a subnet: 32\n" << endl;
            break;
        case 192:
            cout << "Number of addresses in a subnet: 64\n" << endl;
            break;
        case 128:
            cout << "Number of addresses in a subnet: 128\n" << endl;
            break;
        case 000:
            cout << "Number of addresses in a subnet: 256\n" << endl;
            break;
        default:
            cout << "Invalid value\a\n" << endl;
            }
        } while (frg == frg);
    return 0;
}
