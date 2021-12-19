#include <iostream>
#include <random>

using namespace std;

int main();
int bank_cash[10] = {0}, pincod[10] = {0}, acc = 0, value = 0;
bool setter = false;

void Set_Cash_and_Pincod(int m_bank_cash[10], int m_pincod[10])
{
    for (int i = 0; i < 10; i++) {                                          //index loop iteration
        m_bank_cash[i] = rand();                                            //set value for bank cash
        m_pincod[i] = rand() % 10000;                                       //set value for pincod
    }
}

void Get_Pincod(int m_pincod[10])
{
    for (int i = 0; i < 10; i++) {                                          //pincod list
        cout << "#" << i+1 << " pincode = " << m_pincod[i] << endl;
    }
}

int Bank_Account(int m_acc)
{
    cout << endl << endl << "Bank account: ";
    cin >> m_acc;
    if (!(m_acc > 0 && m_acc <= 10))                                        //check: does the account exist
        main();
    return m_acc;
}

int Pincod_Account(int m_pincod[10], int m_acc, int m_value)
{
    cout << "PIN for " << m_acc << " account: ";
    cin >> m_value;
    if (m_value != m_pincod[m_acc-1])                                       //case: incorrect password
        main();
    return m_pincod[m_acc-1];
}

int Action_Question(int m_bank_cash[10], int m_acc, int m_value)
{
    cout << "Money on your card: "  << m_bank_cash[m_acc-1] << " $" << endl;
    cout << "What I can do?"        << endl;
    cout << "1 - add money"         << endl;
    cout << "2 - withdraw money"    << endl;
    cin >> m_value;                                                         //read action (1 or 2)

    if (m_value != 1 && m_value != 2)
        main();
    return m_value;
}

void Add_Money(int m_bank_cash[10], int m_acc, int m_value)
{
    cout << "How much money to add to your account?: ";
    cin >> m_value;                                                         //read action for add
    if (m_value >= 0)
    {                                                                       //check: is there enough hard cash
        m_bank_cash[m_acc-1] += m_value;                                    //bank cash increase
        cout << "Transaction successful!";
        main();
    }
    else
    {
        cout << "Unacceptable count! Try again." << endl << endl;
        main();
    }
}

void Divide_Money(int m_bank_cash[10], int m_acc, int m_value)
{
    cout << "How much money to withdraw?: ";
    cin >> m_value;                                                         //read action for divide
    if (m_value >= 0 && m_value <= m_bank_cash[m_acc-1])
    {                                                                       //check: is there enough bank cash
        m_bank_cash[m_acc-1] -= m_value;                                    //bank cash decrease
        cout << "Transaction successful!";
        main();
    }
    else
    {
        cout << "Unacceptable count! Try again." << endl << endl;
        main();
    }
}

int main()
{
    if (setter == false)
    {
        Set_Cash_and_Pincod(bank_cash, pincod);
        setter = true;
    }
    system ("cls");                                                         //console clear
    Get_Pincod(pincod);

    acc = Bank_Account(acc);
    pincod[acc-1] = Pincod_Account(pincod, acc, value);
    value = Action_Question(bank_cash, acc, value);

    switch (value)
    {
        case 1: Add_Money(bank_cash, acc, value);                           ///action 1 - add money
        case 2: Divide_Money(bank_cash, acc, value);                        ///action 2 - withdraw money
    }
    return 0;
}
