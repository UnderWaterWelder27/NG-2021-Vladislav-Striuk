#include <iostream>
#include <string>
#include "caesarcipher.h"

using namespace std;

CaesarCipher::CaesarCipher()                                    /// NO args constructor
{
    m_CipherKey = 0;
    m_InputData = "NO_INPUT_DATA";
    m_OutputCipherData = "NO_OUTPUT_CIPHER_DATA";
    m_OutputDecipherData = "NO_OUTPUT_DECIPHER_DATA";
}

CaesarCipher::CaesarCipher(string data)                         /// InputData args constructor
{
    m_CipherKey = 0;
    m_InputData = data;
    m_OutputCipherData = "NO_OUTPUT_CIPHER_DATA";
    m_OutputDecipherData = "NO_OUTPUT_DECIPHER_DATA";
}

CaesarCipher::CaesarCipher(string data, int key)                /// InputData, CipherKey args constructor
{
    m_CipherKey = key;
    m_InputData = data;
    m_OutputCipherData = "NO_OUTPUT_CIPHER_DATA";
    m_OutputDecipherData = "NO_OUTPUT_DECIPHER_DATA";
}

string CaesarCipher::enterDecipherInputData()
{
    string InputData;
    cin.ignore();
    cout << "Enter a text, which you want to cipher: ";
    getline(cin, InputData, '\n');
    return InputData;
}

string CaesarCipher::enterCipherInputData()
{
    string InputData;
    cin.ignore();
    cout << "Enter a text, which you want to decipher: ";
    getline(cin, InputData, '\n');
    return InputData;
}

int CaesarCipher::enterCipherKey()
{
    int CipherKey;
    cout << "Enter a key for Caesar cipher: ";
    cin >> CipherKey;
    return CipherKey;
}

void CaesarCipher::showInfo()
{
    cout << endl << "==================================================================" << endl << endl
         << "Cipher Key: " << getCipherKey() << endl
         << "Input Data: " << getInputData() << endl
         << "Output Cipher Data: " << getOutputCipherData() << endl
         << "Output Decipher Data: " << getOutputDecipherData() << endl
         << endl << "==================================================================" << endl << endl;
}

int CaesarCipher::chooseAction()
{
    int action;
    cout << "Cipher (1) or decipher (2) text? ";
    cin  >> action;
    return action;
}

string CaesarCipher::cipherInputText(string data, int key)
{
    if (data == "")
    {
        setInputData("NO_INPUT_DATA");
        return "NO_OUTPUT_CIPHER_DATA";
    }

    if (key <= 0)
    {
        setCipherKey(0);
        return data;
    }

    for (unsigned long long i = 0; i < data.length(); i++)
    {
        if (data[i] >= 'a' && data[i] <= 'z')
        {
            data[i] = data[i] + (key % 26);
            if (data[i] > 'z')
                data[i] = 'a' + (data[i] - 'z') - 1;
        }

        if (data[i] >= 'A' && data[i] <= 'Z')
        {
            data[i] = data[i] + (key % 26);
            if (data[i] > 'Z')
                data[i] = 'A' + (data[i] - 'Z') - 1;
        }
    }
    return data;
}

string CaesarCipher::decipherInputText(string data, int key)
{
    if (data == "")
    {
        setInputData("NO_INPUT_DATA");
        return "NO_OUTPUT_DECIPHER_DATA";
    }
    if (key <= 0)
    {
        setCipherKey(0);
        return data;
    }

    for (unsigned long long i = 0; i < data.length(); i++)
    {
        if (data[i] >= 'a' && data[i] <= 'z')
        {
            data[i] = data[i] - (key % 26);
            if (data[i] < 'a')
                data[i] = 'z' - ('a' - data[i]) + 1;
        }

        if (data[i] >= 'A' && data[i] <= 'Z')
        {
            data[i] = data[i] - (key % 26);
            if (data[i] < 'A')
                data[i] = 'Z' - ('A' - data[i]) + 1;
        }
    }
    return data;
}
