#include <iostream>

using namespace std;

void input_integer (string lable, int &n) {
    cout << lable;
    cin >> n;
}

void input_array (int* &a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void remove_integer (int* &a, int &n, int x) {
    int *b = new int [n - 1];
    for (int i = 0; i < x; i++) {
        b[i] = a[i];
    }

    for (int i = x; i < n - 1; i++) {
        b[i] = a[i + 1];
    }

    delete []a;
    a = b;
    n--;
}

int main () {
    int n, x;
    input_integer ("n = ", n);

    int *a = new int [100];
    cout << "Nhap mang: ";
    input_array (a, n);
    input_integer ("x = ", x);
    remove_integer (a, n, x);

    cout << "Mang sau khi xoa: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}