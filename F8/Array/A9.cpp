#include <iostream>

using namespace std;

int main () {
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    cout << "Nhap ma tran:" << endl;
    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] % 2 != 0) {
                sum += a[i][j];
            }
        }
    }

    cout << "Tong cac so le la: " << sum;

    return 0;
}