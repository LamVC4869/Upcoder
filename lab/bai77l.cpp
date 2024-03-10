#include <iostream>
#include <string>

using namespace std;

int main () {
    string a;
    getline (cin, a);
    
    while (a[0] == ' ') {
        a.erase (0, 1);
    }

    while (a[a.length() - 1] == ' ') {
        a.erase(a.length() - 1, 1);
    }

    int i = 0;
    while (i < a.length()) {
        if (a[i] == ' ' && a[i + 1] == ' ') {
            a.erase (a[i], 1);
        } else {
            i++;
        }
    }
    
    int j = a.length() - 1;
    while (j >= 0) {
        int x = j;
        while (x >= 0 && a[x] != ' ') {
            x--;
        }

        for (int k = x + 1; k <= j; k++) {
            cout << a[k];
        }

        if (x >= 0) {
            cout << ' ';
        }

        j = x - 1;
    }
    return 0;
}