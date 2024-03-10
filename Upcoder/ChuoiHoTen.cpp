#include <iostream>
#include <string>

using namespace std;

int main () {
    string a;
    getline (cin, a);

    for (int i = 0; i < a.length(); i++) {
        a[i] = tolower (a[i]);
    }

    while (a[0] == ' ') {
        a.erase (0, 1);
    }

    while (a[a.length() - 1] == ' ') {
        a.erase (a.length() - 1, 1);
    }

    int i = 0;
    while (i < a.length()) {
        if (a[i] == ' ' && a[i + 1] == ' ') {
            a.erase (i, 1);
        } else {
            i++;
        }
    }

    a[0] = toupper (a[0]);

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == ' ') {
            a[i + 1] = toupper (a[i + 1]);
        }
    }
    
    cout << a;

    return 0;
}