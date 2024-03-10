#include <iostream>

using namespace std;

void input_integer (string label, int &n) {
    cout << label;
    cin >> n;
}

void input_array (int* &a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Add_integer (int* &a, int &n, int y, int x);

int main () {
    int n, y, x;
    input_integer ("n = ", n);
    
    int *a = new int [100];
    cout << "Nhap mang: ";
    input_array (a, n);

    input_integer ("y = ", y);
    input_integer ("x = ", x);

    cout << "Mang sau khi them: ";
    Add_integer (a, n, y, x);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

void Add_integer (int* &a, int &n, int y, int x) {
    int *b = new int [n + 1];
    for (int i = 0; i < x; i++) {
        b[i] = a[i];
    }
    b[x] = y;
    for (int i = x + 1; i < n + 1; i++) {
        b[i] = a[i - 1];
    }

    delete []a;
    a = b;
    n++;
} 