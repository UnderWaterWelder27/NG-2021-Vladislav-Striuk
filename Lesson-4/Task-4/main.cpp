#include <iostream>

using namespace std;

int main()
{
    char sentence[256] = "";
    char vowels[] = "AaEeIiOoUuYy";
    int word_hash = 0;
    cin.getline(sentence, 256);

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (sentence[i] == vowels[j])
            {
                word_hash += 1;
                break;
            }
        }
        if (sentence[i] == ' ' || sentence[i+1] == '\0')
        {
            cout << word_hash;
            word_hash = 0;
            continue;
        }
    }
    return 0;
}
