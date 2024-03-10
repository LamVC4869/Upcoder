#include <iostream>
#include <cmath>

using namespace std;

bool kt (int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != a[i]) return false;
    }
    return true;
}

int main () {
    int n, a[21];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int k = 0; k < 1000; k++) {
        if (kt (a, n)) {
            cout << k;
            return 0;
        }
        a[n] = a[0];
        for (int i = 0; i < n; i++) a[i] = abs (a[i] - a[i + 1]);
    }
    cout << "Impossible";
    return 0;
}