#include <iostream>
#include <random>

using namespace std;

int main()
{
    int bank_cash[10] = {0}, pincod[10] = {0}, acc = 0, value = 0;
    for (int i = 0; i < 10; i++) {                                              //index loop iteration
        bank_cash[i] = rand();                                                  //set value for bank cash
        pincod[i] = rand() % 10000;                                             //set value for pincod
    }

    while (true) {                                                              ///main infinite cycle
        system ("cls");                                                         //console clear
        for (int i = 0; i < 10; i++) {                                          //pincod list
            cout << "#" << i+1 << " pincode = " << pincod[i] << endl;
        }

        cout << endl << endl << "Bank account: ";
        cin >> acc;
        if (!(acc > 0 && acc <= 10))                                            //check: does the account exist
            continue;

        cout << "PIN for " << acc << " account: ";
        cin >> value;
        if (value != pincod[acc-1])                                             //case: incorrect password
            continue;

        cout << "Money on your card: "  << bank_cash[acc-1] << " $" << endl;
        cout << "What I can do?"        << endl;
        cout << "1 - add money"         << endl;
        cout << "2 - withdraw money"    << endl;
        cin >> value;                                                           //read action (1 or 2)

        if (value != 1 && value != 2)
            continue;

        switch (value) {
            case 1:                                                             ///action 1 - add money
            cout << "How much money to add to your account?: ";
            cin >> value;                                                       //read action for add
            if (value >= 0) {                                                   //check: is there enough hard cash
                bank_cash[acc-1] += value;                                      //bank cash increase
                cout << "Transaction successful!";
                getchar(); getchar();
                break;
                }
            else {
                cout << "Unacceptable count! Try again." << endl << endl;
                getchar(); getchar();
            }
            case 2:                                                             ///action 2 - withdraw money
            cout << "How much money to withdraw?: ";
            cin >> value;                                                       //read action for divide
            if (value >= 0 && value <= bank_cash[acc-1]) {                      //check: is there enough bank cash
                bank_cash[acc-1] -= value;                                      //bank cash decrease
                cout << "Transaction successful!";
                getchar(); getchar();
                break;
                }
            else {
                cout << "Unacceptable count! Try again." << endl << endl;
                getchar(); getchar();
            }
        }
    }
    return 0;
}
