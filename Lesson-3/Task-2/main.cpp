#include <iostream>
#include <random>

using namespace std;

int main()
{
/************************************************************************************************/
    int cash[10], pincode[10], acc, save_value, action;
    for (int i = 0; i < 10; i++) {                              //index loop iteration
        cash[i] = rand();                                       //set value for cash[i]
        pincode[i] = rand() % 10000;                            //set value for pincode[i]
        cout << "#" << i+1 << " pincode [" << i << "] = " << pincode[i] << endl;
    }
/************************************************************************************************/
    start_pos: while (true) {                                              ///main infinite cycle
        while (!(acc > 0 && acc <= 10)) {                       ///bank account/pincode cycle
            cout << endl << "Bank account: ";
            cin >> acc;
            if (acc > 0 && acc <= 10) {                         //check: does the account exist
                do {                                            //pincode cycle
                    cout << "PIN for " << acc << " account: ";
                    cin >> save_value;
                    if (save_value != pincode[acc-1])             //case: incorrect password
                        cout << "Your password is incorrect!" << endl;
                } while (save_value != pincode[acc-1]);
            }
            else
                cout << "Account does not exist" << endl;       //if account does exist
        }
/************************************************************************************************/
        while (true) {                                          ///add/withdraw cycle
            cout << "Your money: " << cash[acc-1] << " $" << endl;
            cout << "What I can do?" << endl;
            cout << "1 - add money" << endl;
            cout << "2 - withdraw money" << endl;

            cin >> action;                                      //read action (1 or 2)
            /*==================================================================================*/
            if (action == 1) {                                  ///action 1 - add money
                cout << "How much money to add to your account?: ";
                cin >> save_value;                              //read action for add
                if (save_value >= 0)
                    cash[acc-1] += save_value;                  //account increase
                else
                    cout << "Incorrect value . . . " << endl;
            }
            /*==================================================================================*/
            else if (action == 2) {                             ///action 2 - withdraw money
                cout << "How much money to withdraw?: ";
                cin >> save_value;                              //read action for divide
                if (save_value <= cash[acc-1] && save_value >= 0)
                    cash[acc-1] -= save_value;                  //account decrease
                else
                    cout << "There are not enough money in the account" << endl;
            }
            /*==================================================================================*/
            else                                                ///if action != 1 or 2
                cout << "Unacceptable action! Try again." << endl << endl;
            break;
        }
        goto start_pos;
    }
/************************************************************************************************/
    system("pause");
    return 0;
}
