#include <iostream>

using namespace std;

int main () {
    int x, max = -10000; cin >> x;
    int a[1000], i = 0, value;
    while (cin >> value) {
        a[i] = value;
        if (a[i] > max && a[i] <= x) {
            max = a[i];
        }
        i++;
    }

    int count = 0;
    for (int j = 0; j < i; j++) {
        if (a[j] == max) {
            count++;
        }
    }

    if (count == 0) {
        cout << -1;
    } else {
        for (int k = 0; k < i; k++) {
            if (a[k] == max) {
                cout << k << " ";
            }
        }
    }

    return 0;
}