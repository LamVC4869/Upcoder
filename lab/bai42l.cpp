#include <iostream>

using namespace std;

int main () {
    int n, a[1000], i = 0, count = 0, res = i;
    int max2 = INT_MIN;
    int max = max2 + 1;

    while (cin >> n) {
        a[i] = n;
        i++;
    }

    for (i = 0; i < count; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    for (i = 0; i < count; i++) {
        if (a[i] > max2 && a[i] < max) {
            max2 = a[i];
        }
    }

    cout << max2 << " " << max;

    return 0;
}