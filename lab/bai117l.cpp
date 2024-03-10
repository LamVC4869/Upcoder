#include <iostream>

using namespace std;

void Sort (int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main () {
    int n; cin >> n;
    int a[n];
    bool b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = false;
    }
    Sort (a, n);
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (a[i] == a[j]) b[j] = true;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        if (!b[i]) {
            cout << a[i] << " - ";
            for (int j = i + 1; j < n; j++) if (a[j] == a[i]) cnt++;
            cout << cnt << "; ";
        }
    }
    return 0;
}