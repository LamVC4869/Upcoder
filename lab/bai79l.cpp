#include <iostream>

using namespace std;

int main () {
    string a;
    getline (cin, a);
    for (int j = a.length() - 1; j >= 0; j--) {
        if (j % 2 != 0) {
            cout << a[j];
        }
    }

    return 0;
}