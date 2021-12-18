#include <iostream>

using namespace std;

int main()
{
    char sentence[256] = "";
    int word_hash = 0;
    cin.getline(sentence, 256);
    for (int i = 0; i < 256; i++) {
        if (sentence[i] == 'a' || sentence[i] == 'e' ||
            sentence[i] == 'i' || sentence[i] == 'o' ||
            sentence[i] == 'u' || sentence[i] == 'y'   )
            word_hash += 1;
        if (sentence[i] == ' ') {
            cout << word_hash;
            word_hash = 0;
            continue;
            }
        if (sentence[i] == '\0') {
            cout << word_hash;
            break;
        }
    }
    return 0;
}
