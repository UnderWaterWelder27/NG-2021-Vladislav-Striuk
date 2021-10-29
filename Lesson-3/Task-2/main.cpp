#include <iostream>
#include <random>

using namespace std;

int main()
{
    int cash[10], pincode[10], acc, save_pin, action;
    for (int i = 0; i < 10; i++) {
        cash[i] = rand();
        cout << "cash [" << i << "] = " << cash[i] << "    ";
        pincode[i] = rand() % 10000;
        cout << "pincode [" << i << "] = " << pincode[i] << endl;
    }

    do {                                //main cycle
        do {                            //bank account/pincode cycle
            cout << "Bank account: "; cin >> acc;
            if (acc > 0 && acc <= 10) {
                do {
                    cout << "PIN for " << acc << " account: "; cin >> save_pin;
                    if (save_pin != pincode[acc-1])
                        cout << "Your password is incorrect!" << endl;
                } while (save_pin != pincode[acc-1]);
            }
            else
                cout << "Account does not exist" << endl;
        } while (!(acc > 0 && acc <= 10));

        do {                        //cab i do cycle (BUG)
            cout << "Your money: " << cash[acc-1] << " $" << endl;
            cout << "What I can do?" << endl;
            cout << "1 - add money" << endl;
            cout << "2 - withdraw money" << endl;

            cin >> action;
            if (action == 1) {
                do {
                    cout << "How much money to add to your account?: ";
                    cin >> action;
                    if (action >= 0) {
                        cash[acc-1] += action;
                        break;
                    }
                    else cout << "Incorrect value . . . " << endl;
                } while (action < 0);
            }

            else if (action == 2) {
                do {
                    cout << "How much money to withdraw?: ";
                    cin >> action;
                    if (action <= cash[acc-1] && action >= 0) {
                        cash[acc-1] -= action;
                        break;
                    }
                    else
                        cout << "There are not enough money in the account" << endl;
                } while (action > cash[acc-1]);
            }

            else
                cout << "Unacceptable action! Try again." << endl << endl;
        } while (action != 1 && action !=2);
    } while (true);

    /*switch (acc) {
        case 1:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 2:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 3:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 4:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 5:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 6:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 7:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 8:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 9:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        case 10:
        do {
            cout << "PIN for " << acc << " account: "; cin >> save_pin;
            acc -= 1;
            if (save_pin != pincode[acc])
                cout << "Your password is incorrect!";
        } while (save_pin != pincode[acc]);
        break;

        default: cout << "Account does not exist";
    }*/


    system("pause");
    return 0;
}
