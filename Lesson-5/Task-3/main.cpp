#include <iostream>
#include <cmath>

using namespace std;

float convertStreamToNumber()
{
    int number = 0;
    while (true)
    {
        char digit = cin.get();
        if (digit >= '0' && digit <= '9')
            number = number * 10 + digit - 48;
        else
        {
            cin.putback(digit);
            return number;
        }
    }
}

float expressionAddSubtract();

float bracketsPriority()
{
    char digit = cin.get();
    if (digit == '(')
    {
        float num = expressionAddSubtract();
        cin.get();
        return num;
    }
    else
    {
        cin.putback(digit);
        return convertStreamToNumber();
    }
    return 0;
}

float sqrtPow()
{
    float num = bracketsPriority();
    while(true)
    {
        char digit = cin.get();
        switch (digit)
        {
        case '^':
            num = pow(num, bracketsPriority());
            break;
        case '#':
            num = sqrt(num);
            break;
        default:
            cin.putback(digit);
            return num;
        }
    }
}

float expressionMutiplyDivide()
{
    float num = sqrtPow();
    while(true)
    {
        char digit = cin.get();
        switch (digit)
        {
        case '*':
            num *= sqrtPow();
            break;
        case '/':
            num /= sqrtPow();
            break;
        default:
            cin.putback(digit);
            return num;
        }
    }
}

float expressionAddSubtract()
{
    float num = expressionMutiplyDivide();
    while(true)
    {
        char digit = cin.get();
        switch (digit)
        {
        case '+':
            num += expressionMutiplyDivide();
            break;
        case '-':
            num -= expressionMutiplyDivide();
            break;
        default:
            cin.putback(digit);
            return num;
        }
    }
}


int main()
{
    cout << "Input expression: ";
    float result = expressionAddSubtract();
    cout << "Result: " << result << endl;
}
