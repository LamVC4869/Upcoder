// Tìm phần tử lớn nhất của các hàng
#include <iostream>

using namespace std;

int main () {
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    cout << "Nhap mang:" << endl;
    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Cac phan tu lon nhat la: ";
    int max;
    for (int i = 0; i < n; i++) {
        max = a[i][0];
        for (int j = 0; j < m; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        cout << max << " ";
    }

    return 0;
}