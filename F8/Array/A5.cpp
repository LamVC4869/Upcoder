// Tổng các giá trị biên của mảng 2 chiều
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

    int sum = 0;
    for (int i = 1; i < n - 1; i++) {
        sum += a[i][0];
        sum += a[i][m - 1];
        for (int j = 0; j < m; j++) {
            sum += a[0][j];
            sum += a[n - 1][j];
        }
    }

   /* Hoặc làm theo cách khác dưới đây
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                sum += a[i][j];
            }
        }
    }
    */ 

    cout << "Tong cac gia tri bien la: " << sum;

    return 0;
}