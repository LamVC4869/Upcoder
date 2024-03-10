#include <iostream>

using namespace std;

char kt (int n) {
    char c[27];
    c[1] = 'Z';
    for (int i = 2; i < 27; i++) {
        c[i] = char ('A' + (i - 2));
    }
    return c[n];
}

int main () {
    int a[5];
    for (int i = 0; i < 5; i++) cin >> a[i];
    for (int i = 0; i < 5; i++) cout << kt (a[i]);
    return 0;
}