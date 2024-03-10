// Tính tổng các phần tử trong mảng 2 chiều
#include <iostream>

using namespace std;

int main () {
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    int a[100][100];
    int sum = 0;
    cout << "Nhap mang: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Tong cac phan tu trong mang la: " << sum;

    return 0;
}