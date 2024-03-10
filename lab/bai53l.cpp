#include <iostream>

using namespace std;

int main () {
    int pos, value, i = 0, n, a[1000];

    cin >> pos >> value;
    while (cin >> n) {
        a[i] = n;
        i++;
    }

    for (int j = 0; j < i; j++) {
        a[j] = a[j - 1];
    }

    a[pos] = value;

    for (int j = 0; j <= i; j++) {
        cout << a[j] << " ";
    }

    return 0;
}