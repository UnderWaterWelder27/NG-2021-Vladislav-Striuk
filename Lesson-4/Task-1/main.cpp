#include <iostream>

using namespace std;

int main()
{
    int punctsymb = 0;
    char my_string[255] = "";
    for (int i = 0; i < 255; i++) {
        cin >> my_string[i];
        if (getchar() == '\0') {
            break;
        }
    }
    for (int i = 0; i < 255; i++) {
        if (my_string[i] == '.' || my_string[i] == ',' ||
            my_string[i] == '!' || my_string[i] == '?' ||
            my_string[i] == ':' || my_string[i] == ';' ||
            my_string[i] == '-' || my_string[i] == '"' ||
            my_string[i] == ')' || my_string[i] == '('   )
            punctsymb += 1;
    }
    cout << "Punctuation marks: " << punctsymb << endl;
    return 0;
}
