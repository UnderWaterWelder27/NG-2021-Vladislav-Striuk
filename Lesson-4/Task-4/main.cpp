#include <iostream>

using namespace std;

int main()
{
    char sentence[256] = "";
    int word_hash = 0;
    cin.getline(sentence, 256);

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'A' || sentence[i] == 'E' ||
            sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'I' || sentence[i] == 'O' ||
            sentence[i] == 'u' || sentence[i] == 'y' || sentence[i] == 'U' || sentence[i] == 'Y'   )
            word_hash += 1;

        if (sentence[i] == ' ' || sentence[i+1] == '\0') {
            cout << word_hash;
            word_hash = 0;
            continue;
        }
    }
    return 0;
}
