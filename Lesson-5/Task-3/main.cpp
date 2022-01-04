#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

char arithmetic_operation[6] = {'+', '-', '*', '/', '(', ')'},
     available_digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

struct savenumber { float first; float second; };

///****************   ARITHMETIC OPERATION   ******************///

    float Add         (float a, float b) { return a + b; }
    float Subtract    (float a, float b) { return a - b; }
    float Multiply    (float a, float b) { return a * b; }
    float Divide      (float a, float b) { return a / b; }
    float Sqrt        (float a)          { return sqrt(a); }
    float Pow         (float a, float b) { return pow(a, b); }

///************************************************************///

string InputExpression ()
{
    cout << "Please, write arithmetic expression!" << endl;
    char expression[256] = "";
    cin.getline(expression, 256);
    return expression;
}

///************************************************************///

float ConvertDigitToNumber(string expression, int ind)
{
    cout << "C O N V E R T D I G I T T O N U M B E R" << endl;
    string erase_num = "";
    float number = 0;
    int index_2 = 0, index_1 = ind;
    bool next_operation = true;

    while (next_operation)
    {
        for (int j = 0; j < 6; j++)
        {
            if (expression[ind] == arithmetic_operation[j] || expression[ind] == '\0')
            {
                index_2 = ind - 1;
                next_operation = false;
            }
        }
        ind++;
    }
    erase_num = expression.substr(index_1, index_2 - (index_1 - 1));
    number = atof(erase_num.c_str());
    cout << "N U M B E R = " << number << endl;
    return number;
}

///************************************************************///

string ShiftAndSimplifiedArray (string expression, int leftindex, int rightindex, float microresult)
{
    cout << endl << endl << "S H I F T A N D S I M P L E" << endl;
    string smicroresult = to_string(microresult);
    cout << "smicroresult = to_string(microresult):     " << smicroresult << endl;
    expression.erase(leftindex, rightindex - (leftindex-1));
    cout << "expression.erase(leftindex, rightindex - (leftindex + 1)):     " << expression << endl;
    expression.insert(leftindex, smicroresult);
    cout << "expression.insert(leftindex, smicroresult):     " << expression << endl;
    return expression;
}

///************************************************************///

int OperationsCount (string expression)
{
    int count = 0;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (expression[i] == arithmetic_operation[j])
                count++;
        }
    }
    cout << " O P E R A T I O N S C O U N T (" << count << ")" << endl;
    return count;
}

///************************************************************///

string Priority(string expression, char operation)
{
    cout << "P R I O R I T Y O P E R A T I O N:  (" << operation << ")" << endl;
    savenumber operand ={0, 0};
    float savenum = 0;
    unsigned long long index = 0;
    int leftindex = 0,
        rightindex = 0,
        count = -1;

    cout << " savenum = " << savenum;
    cout << " leftindex = " << leftindex;
    cout << " rightindex = " << rightindex << endl;

    for (index = 0; expression[index] != '\0' && index < expression.length(); index++)
    {
        leftindex = 0; rightindex = 0;

        if (expression[index] == operation && count != 0)
        {
            if  (expression[index] == '-' && expression[index-1] == '+')
            {
                for (unsigned long long i = index; expression[i] != '\0' && i < expression.length(); i++)
                {
                    expression[i-1] = expression[i];
                    cout << " i" << i;
                }
                index--;
            }

            for (int c = index; c != 0 && leftindex == 0; c--)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (expression[c-1] == arithmetic_operation[j] || c == 0)
                    {
                        leftindex = c;
                    }
                }
            }

            for (int c = index; expression[c] != '\0' && rightindex == 0; c++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (expression[c+1] == arithmetic_operation[j] || expression[c+1] == '\0')
                    {
                        rightindex = c;
                    }
                }
            }

            cout << endl;
            cout << " LEFTINDEX = "  << leftindex
                 << " RIGHTINDEX = " << rightindex
                 << " index = "          << index          << endl;

            operand.first = ConvertDigitToNumber(expression, leftindex);
            operand.second = ConvertDigitToNumber(expression, index+1);

            cout << " operand.first = " << operand.first << endl;
            cout << " operand.second = " << operand.second << endl;

            if (operation == '/')
                savenum = Divide(operand.first, operand.second);
            if (operation == '*')
                savenum = Multiply(operand.first, operand.second);
            if (operation == '-')
            {
                if (count == 1 && expression[0] == '-')
                {
                    cout << endl << " - minus at the beginnig - " << endl;
                    savenum = atof(expression.c_str());
                }
                else
                    savenum = Subtract(operand.first, operand.second);
            }
            if (operation == '+')
                savenum = Add(operand.first, operand.second);
            cout << endl << " savenum = " << savenum << endl;

            expression = ShiftAndSimplifiedArray(expression, leftindex, rightindex, savenum);
            cout << " expression = " << expression << endl << endl << endl;

            if (count >= 1 && !(count == 1 && expression[0] != '-'))
            {
                cout << " recursive expression = " << expression << endl;
                break;
            }
            index = 0;

        }

        cout << endl << "-------------------------------------------------" << endl;
    }
    return expression;
}

///************************************************************///

int main()
{
    string expression = InputExpression();
    expression = Priority(expression, '/');
    expression = Priority(expression, '*');
    expression = Priority(expression, '-');
    expression = Priority(expression, '+');
    expression.erase(expression.length()-2);
    cout << " E X P R E S S I O N = " << expression << endl;
    return 0;
}
