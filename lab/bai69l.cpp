#include <iostream>

using namespace std;

int main () {
    char c;
    int max = (int) 'A';
    while (cin >> c) {
        if ((int) c > max) max = c;
        if (c == '0') {
            cout << (char) max;
            break;
        }
    }
    return 0;
}