#include <iostream>
#include <random>

using namespace std;

void SetCashAndPincod(int bank_cash[], int pincod[])                        //  initialize cash & pincod
{
    for (int i = 0; i < 10; i++) {
        bank_cash[i] = rand();                                              /// set value for bank cash
        pincod[i] = rand() % 10000;                                         /// set value for pincod
    }
}

void GetPincod(int pincod[])                                                // pincod output
{
    for (int i = 0; i < 10; i++) {
        cout << "#" << i+1 << " pincode = " << pincod[i] << endl;
    }
}

int AskForBankAccount()                                                     //  input bank account №
{
    int acc = 0;
    do {
        cout << endl << endl << "Bank account: ";
        cin >> acc;
    } while (acc <= 0 || acc > 10);                                         /// check: does the account exist
    return acc;
}

void AskForPincod(int pincod, int acc)                                      //  input pincod for n-account
{
    int value = 0;
    do {
        cout << "PIN for " << acc << " account: ";
        cin >> value;
    } while (value != pincod);                                              /// check: does the password is correct
}

int ChooseAction(int bank_cash)                                             //  choosing the -add- or -withdraw- action
{
    int value = 0;
    do {
        cout << "Money on your card: "  << bank_cash << " $" << endl;
        cout << "What I can do?"        << endl;
        cout << "1 - add money"         << endl;
        cout << "2 - withdraw money"    << endl;
        cin >> value;                                                       /// check: does the action equals 1 or 2
    } while (value < 1 || value > 2);
    return value;
}

int AddMoney()                                                              //  add money to bank cash
{
    int value = 0;
    do {
        cout << "How much money to add to your account?: ";
        cin >> value;
    } while (value < 0);                                                    /// check: does the value no less then 0
    return value;
}

int WithdrawMoney(int bank_cash)                                            //  withdraw money from bank cash
{
    int value = 0;
    do {
        cout << "How much money to withdraw?: ";
        cin >> value;
    } while (bank_cash - value < 0);                                        /// check: is there enough bank cash
    return value;
}

int main()
{
    int bank_cash[10] = {0}, pincod[10] = {0}, acc = 0, value = 0;
    SetCashAndPincod(bank_cash, pincod);
    while (true)
    {
        system ("cls");                                                     //  console clear
        GetPincod(pincod);

        acc = AskForBankAccount();
        AskForPincod(pincod[acc-1], acc);
        value = ChooseAction(bank_cash[acc-1]);

        switch (value)
        {
        case 1:                                                             //  action 1 - add money
            value = AddMoney();
            bank_cash[acc-1] += value;                                      /// bank cash increase
            cout << "Transaction successful!";
            break;

        case 2:                                                             //  action 2 - withdraw money
            value = WithdrawMoney(bank_cash[acc-1]);
            bank_cash[acc-1] -= value;                                      /// bank cash decrease
            cout << "Transaction successful!";
            break;
        }
    }
    return 0;
}
