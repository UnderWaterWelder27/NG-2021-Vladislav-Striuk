#include <iostream>
#include <string>

#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

using namespace std;

class CaesarCipher
{

public:

/// CONSTRUCTORS ///
    CaesarCipher();
    CaesarCipher(string data);
    CaesarCipher(string data, int key);

/// ENTER functions for string and key ///
    int enterCipherKey();
    string enterDecipherInputData();
    string enterCipherInputData();

/// SETTERS for string and key ///
    void setCipherKey(int key) { m_CipherKey = key; }
    void setInputData(string data) { m_InputData = data; }
    void setOutputCipherData(string data) { m_OutputCipherData = data; }
    void setOutputDecipherData(string data) { m_OutputDecipherData = data; }

/// GETTERS for string and key ///
    int getCipherKey() { return m_CipherKey; }
    string getInputData() { return m_InputData; }
    string getOutputCipherData() { return m_OutputCipherData; }
    string getOutputDecipherData() { return m_OutputDecipherData; }

/// SHOW inforamation ///
    void showInfo();

/// OPERATIONS with text ///
    int chooseAction();
    string cipherInputText(string data, int key);
    string decipherInputText(string data, int key);

private:

    int m_CipherKey;
    string m_InputData;
    string m_OutputCipherData;
    string m_OutputDecipherData;
};

#endif // CAESARCIPHER_H
