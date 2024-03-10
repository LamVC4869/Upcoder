#include <iostream>

using namespace std;

int main () {
    string n; cin >> n;
    if (n.length () < 2) {
        if (n == "0") {
            cout << 1;
            return 0;
        }
        int i = stoi (n);
        switch (i % 4) {
            case 0: cout << 6; break;
            case 1: cout << 8; break;
            case 2: cout << 4; break;
            default: cout << 2;
        }
    } else {
        string str = n.substr (n.length () - 2, 2);
        int digit = stoi (str);
        switch (digit % 4) {
            case 0: cout << 6; break;
            case 1: cout << 8; break;
            case 2: cout << 4; break;
            default: cout << 2;
        }
    }
    return 0;
}