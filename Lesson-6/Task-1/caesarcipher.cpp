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

string CaesarCipher::enterDecipherInputData()                   /// input a non-cipher text
{
    string InputData;
    cin.ignore();                                               //  ignore '\n' from previous "cin"
    cout << "Enter a text, which you want to cipher: ";
    getline(cin, InputData, '\n');
    return InputData;
}

string CaesarCipher::enterCipherInputData()                     /// input a cipher text
{
    string InputData;
    cin.ignore();                                               // ignore '\n' from previous "cin"
    cout << "Enter a text, which you want to decipher: ";
    getline(cin, InputData, '\n');
    return InputData;
}

int CaesarCipher::enterCipherKey()                              /// enter value for text codding
{
    int CipherKey;
    cout << "Enter a key for Caesar cipher: ";
    cin >> CipherKey;
    return CipherKey;
}

void CaesarCipher::showInfo()                                   /// function, that show getters
{
    cout << endl << "==================================================================" << endl << endl
         << "Cipher Key: " << getCipherKey() << endl
         << "Input Data: " << getInputData() << endl
         << "Output Cipher Data: " << getOutputCipherData() << endl
         << "Output Decipher Data: " << getOutputDecipherData() << endl
         << endl << "==================================================================" << endl << endl;
}

int CaesarCipher::chooseAction()                                /// choosing beetwen cipher & decipher
{
    int action;
    cout << "Cipher (1) or decipher (2) text? ";
    cin  >> action;
    return action;
}

string CaesarCipher::cipherInputText(string data, int key)      /// algoritm of text cipher
{
    if (data == "")                                             //  checking the emptiness availability
    {
        setInputData("NO_INPUT_DATA");
        return "NO_OUTPUT_CIPHER_DATA";
    }

    if (key <= 0)                                               //  checking the correct key input
    {
        setCipherKey(0);
        return data;
    }

    for (unsigned long long i = 0; i < data.length(); i++)
    {
        if (data[i] >= 'a' && data[i] <= 'z')                   //  extension only for lowercase letters
        {
            data[i] = data[i] + key;                            //  shift char to the right by "key" elements
            if (data[i] > 'z')                                  //  if char is non-letter
                data[i] = 'a' + (data[i] - 'z') - 1;
        }

        if (data[i] >= 'A' && data[i] <= 'Z')                   //  extension only for uppercase letters
        {
            data[i] = data[i] + key;                            //  shift char to the right by "key" elements
            if (data[i] > 'Z')                                  //  if char is non-letter
                data[i] = 'A' + (data[i] - 'Z') - 1;
        }
    }
    return data;
}

string CaesarCipher::decipherInputText(string data, int key)    /// algoritm of text decipher
{
    if (data == "")                                             //  checking the emptiness availability
    {
        setInputData("NO_INPUT_DATA");
        return "NO_OUTPUT_DECIPHER_DATA";
    }
    if (key <= 0)                                               //  checking the correct key input
    {
        setCipherKey(0);
        return data;
    }

    for (unsigned long long i = 0; i < data.length(); i++)
    {
        if (data[i] >= 'a' && data[i] <= 'z')                   //  extension only for lowercase letters
        {
            data[i] = data[i] - key;                            //  shift char to the left by "key" elements
            if (data[i] < 'a')                                  //  if char is non-letter
                data[i] = 'z' - ('a' - data[i]) + 1;
        }

        if (data[i] >= 'A' && data[i] <= 'Z')                   //  extension only for uppercase letters
        {
            data[i] = data[i] - key;                            //  shift char to the left by "key" elements
            if (data[i] < 'A')                                  //  if char is non-letter
                data[i] = 'Z' - ('A' - data[i]) + 1;
        }
    }
    return data;
}
