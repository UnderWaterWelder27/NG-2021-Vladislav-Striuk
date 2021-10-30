#include <iostream>
#include <random>

using namespace std;

int main()
{
/*****************************************************************************************************************/
    int bank_cash[10], hard_cash[10], pincod[10], acc, save_value, action;
    for (int i = 0; i < 10; i++) {                                          //index loop iteration
        bank_cash[i] = rand();                                              //set value for bank cash
        hard_cash[i] = rand();                                              //set value for hard cash
        pincod[i] = rand() % 10000;                                         //set value for pincod
    }
/*****************************************************************************************************************/
    while (true) {                                                          ///main infinite cycle
        for (int i = 0; i < 10; i++) {                                      //index loop iteration
            cout << "#" << i+1 << " pincode [" << i << "] = " << pincod[i] << "\t";
            if (i == 4) cout << endl;
        }
        while (true) {                                                      ///bank account/pincod cycle
            cout << endl << endl << "Bank account: ";
            cin >> acc;
            if (acc > 0 && acc <= 10) {                                     //check: does the account exist
                do {                                                        //pincod cycle
                    cout << "PIN for " << acc << " account: ";
                    cin >> save_value;
                    if (save_value != pincod[acc-1]) {                      //case: incorrect password
                        cout << "Your password is incorrect!" << endl;
                    }
                } while (save_value != pincod[acc-1]);
                break;                                                      //exit the cycle password is correct
            }
            else
                cout << "Account does not exist";                           //if account does exist
        }
/*****************************************************************************************************************/
        do {                                                                ///action (add/divide) cycle
            cout << "Money on your card: "  << bank_cash[acc-1] << " $" << endl;
            cout << "Your cash: "           << hard_cash[acc-1] << " $" << endl;
            cout << "What I can do?"        << endl;
            cout << "1 - add money"         << endl;
            cout << "2 - withdraw money"    << endl;

            cin >> action;                                                  //read action (1 or 2)
            /*===================================================================================================*/
            if (action == 1) {                                              ///action 1 - add money
                cout << "How much money to add to your account?: ";
                cin >> save_value;                                          //read action for add
                if (save_value >= 0 && save_value <= hard_cash[acc-1]) {    //check: is there enough hard cash
                    hard_cash[acc-1] -= save_value;                         //hard cash decrease
                    bank_cash[acc-1] += save_value;                         //bank cash increase
                    cout << "Transaction successful!";
                    getchar(); getchar();
                    break;
                }
                else
                    cout << "You don't have so much money" << endl;
            }
            /*===================================================================================================*/
            else if (action == 2) {                                         ///action 2 - withdraw money
                cout << "How much money to withdraw?: ";
                cin >> save_value;                                          //read action for divide
                if (save_value >= 0 && save_value <= bank_cash[acc-1]) {    //check: is there enough bank cash
                    bank_cash[acc-1] -= save_value;                         //bank cash decrease
                    hard_cash[acc-1] += save_value;                         //hard cash increase
                    cout << "Transaction successful!";
                    getchar(); getchar();
                    break;
                }
                else
                    cout << "There are not enough money in the account" << endl;
            }
            /*===================================================================================================*/
            else                                                            ///if action != 1 or 2
                cout << "Unacceptable action! Try again." << endl << endl;
        } while (true);
/*****************************************************************************************************************/
        cout << "Do you wanna to continue (1 - yes; 2 - no)?: ";            ///request to continue
        cin >> action;
        if (action == 1) {                                                  //start again main infinite cycle
            system ("cls");                                                 //console clear
            continue;
        }
        else if (action == 2) {                                             //go to the end of the program
            system ("cls");                                                 //console clear
            break;
        }
    }
/*****************************************************************************************************************/
    system("pause");
    return 0;
}
