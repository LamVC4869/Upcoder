#include <iostream>

using namespace std;

void Sort (int a[], int n, int m) {
    for (int i = n * m - 1; i > 0; i--) {
        for (int j = 0; j < n * m - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void Xuat_Mang_ZicZac (int a[], int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int col = count;
        if (i % 2 == 0) {
            for (int j = col; j < col + m; j++) {
                cout << a[j] << " ";
                count++;
            }
        } else {
            for (int j = col + m - 1; j > col - 1; j--) {
                cout << a[j] << " ";
                count++;
            }
        }
        cout << endl;
    }
}

int main () {
    int n, m; cin >> n >> m;
    int a[100];
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }

    Sort (a, n, m);
    Xuat_Mang_ZicZac (a, n, m);
    return 0;
}