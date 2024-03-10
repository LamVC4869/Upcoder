#include <iostream>

using namespace std;

void input_integer (string label, int &n) {
    cout << label;
    cin >> n;
}

void Sort_Array (int* &a, int &n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main () {
    int n;
    input_integer ("n = ", n);

    int *a = new int [100];
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Sort_Array (a, n);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}