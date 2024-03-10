#include <iostream>

using namespace std;

int main () {
    long long digit, min = 0, i = 0;
    long long a[100000];
    while (cin >> digit) {
        a[i++] = digit;
        if (a[i] < min) min = a[i];
    }
    cout << min;
    return 0;
}