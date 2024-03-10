#include <iostream>

using namespace std;

void Sort (int a[], int &n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void push (int* &a, int &n, int k) {
    int *b = new int [n + 1];

    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    b[n] = k;

    delete []a;
    n++;
    a = b;
}


int main () {
    int n; cin >> n;
    int *a = new int [100];;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k; cin >> k;
    Sort (a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    push (a, n, k);
    Sort (a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    delete []a;
    return 0;
}