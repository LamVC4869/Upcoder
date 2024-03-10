#include <iostream>

using namespace std;

int main () {
    int a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    int max1 = a[0], max2 = a[0];
    for (int i = 0; i < 4; i++) {
        if (a[i] > max1) {
            max1 = a[i];
        } else {
            max2 = a[i];
        }
    }

    for (int i = 0; i < 4; i++) {
        if (a[i] > max2 && a[i] < max1) max2 = a[i];
    }
    cout << max2 << " " << max1;
    return 0;
}