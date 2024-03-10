#include <iostream>
#include <string>

using namespace std;

int main () {
    string a;
    getline (cin, a);

    while (a[0] == ' ') {
        a.erase (0, 1);
    }

    for (int i = 0; i < a.length(); i++) {
        if (a[i] != ' ') {
            cout << a[i];
        }
        if (a[i] == ' ' && a[i + 1] != ' ') {
            cout << endl;
        }
    }

    return 0;
}