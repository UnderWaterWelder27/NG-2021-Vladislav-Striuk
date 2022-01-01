#include <iostream>
#include "caesarcipher.h"

using namespace std;

int main()
{
    CaesarCipher Program1;

    switch (Program1.chooseAction())
    {
    case 1:
        Program1.setInputData(Program1.enterDecipherInputData());
        Program1.setCipherKey(Program1.enterCipherKey());
        Program1.setOutputCipherData(Program1.cipherInputText(Program1.getInputData(), Program1.getCipherKey()));
        Program1.showInfo();
        break;

    case 2:
        Program1.setInputData(Program1.enterCipherInputData());
        Program1.setCipherKey(Program1.enterCipherKey());
        Program1.setOutputDecipherData(Program1.decipherInputText(Program1.getInputData(), Program1.getCipherKey()));
        Program1.showInfo();
        break;

    default:
        cout << "UNCORRECT ACTION!" << endl;
        Program1.showInfo();
        break;
    }
    return 0;
}
