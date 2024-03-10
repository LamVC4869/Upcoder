// Tìm phần tử lớn nhất trong mảng 1 chiều
#include <iostream>

using namespace std;

int main () {
    int n;
    cout << "n = ";
    cin >> n;

    cout << "Nhap mang: ";
    int a[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    cout << "Gia tri lon nhat la: " << max;

    return 0;
}