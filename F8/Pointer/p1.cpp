#include <iostream>

using namespace std;

void Add_Value (int* &arr, int &n, int x) {
    int *b = new int [n + 1];
    for (int i = 0; i < n; i++) {
        b[i] = arr[i];
    }
    b[n] = x;
    delete []arr;
    arr = b;
    n++;
}

int main () {
    int n;
    cout << "n = ";
    cin >> n;

    int *a = new int [100];
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cout << "x = ";
    cin >> x;

    cout << "Mang sau khi them: ";
    Add_Value (a, n, x);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    delete []a;
    return 0;
}