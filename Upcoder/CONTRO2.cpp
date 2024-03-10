#include <iostream>

using namespace std;

void xoa_phan_tu (int* &a, int &n, int k) {
    int *b = new int [n - k];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != k) {
            b[count++] = a[i];
        } else {
            continue;
        }
    }

    delete []a;
    a = b;
    n = n - k;
}

int main () {
    int n, k;
    cin >> n >> k;
    int *a = new int [100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << n - k << endl;
    xoa_phan_tu (a, n, k);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    delete []a;
    return 0;
}