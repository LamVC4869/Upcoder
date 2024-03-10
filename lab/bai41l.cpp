#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int n, a[1000]; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs (a[i]) > abs(a[j])) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << pow (a[i], 2) << " ";
    }

    return 0;
}