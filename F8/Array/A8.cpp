#include <iostream>

using namespace std;

int main () {
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    cout << "Nhap ma tran 1: " << endl;
    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Nhap ma tran 2: " << endl;
    int b[100][100];
    for (int c = 0; c < n; c++) {
        for (int d = 0; d < m; d++) {
            cin >> b[c][d];
        }
    }

    cout << "Tong 2 ma tran: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}