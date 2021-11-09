#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int punctsymb = 0;
    char my_string[255] = "";
    cin.getline(my_string,255);
    for (int i = 0; i < strlen(my_string); i++) {
        if (my_string[i] == '.' || my_string[i] == ',' ||
            my_string[i] == '!' || my_string[i] == '?' ||
            my_string[i] == ':' || my_string[i] == ';' ||
            my_string[i] == '-' || my_string[i] == '"' ||
            my_string[i] == ')' || my_string[i] == '('   )
            punctsymb += 1;
    }
    cout << "Punctuation marks: " << punctsymb << endl;
    getchar(); getchar();
    return 0;
}
