// Thêm 1 phần tử y vào mảng tại vị trí x bất kì nằm trong mảng
#include <iostream>

using namespace std;

int main () {
    
    int n;
    cout << "n = ";
    cin >> n;

    int a[1000];
    cout << "Nhap mang:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int x, y;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;

    for (int i = n; i > x; i--) {
        a[i] = a[i - 1];
    }

    a[x] = y;

    cout << "Mang sau khi them " << y << " vao vi tri " << x << " la: " << endl;
    for (int j = 0; j <= n; j++) {
        cout << a[j] << " ";
    }

    return 0;
}