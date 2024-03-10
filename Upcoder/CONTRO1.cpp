#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int *a = new int [100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= max) max = a[i];
    }

    cout << max << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] == max) cout << i + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (a[i] <= max) max = a[i];
    }
    cout << max << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] == max) cout << i + 1<< " ";
    }

    delete []a;

    return 0;
}