#include <iostream>

using namespace std;

bool La_So_Hoan_Chinh (int n) {
    int sum = 1;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

int main () {
    int so_luong; cin >> so_luong;
    int *a = new int [100];
    int count = 0;
    for (int i = 0; i < so_luong; i++) {
        cin >> a[i];
        if (La_So_Hoan_Chinh (a[i])) count++;
    }

    if (count == 0) {
        cout << "mang khong co so hoan chinh";
    } else {
        cout << "cac phan tu la so hoan chinh" << endl;
        for (int i = 0; i < so_luong; i++) {
            if (La_So_Hoan_Chinh (a[i])) cout << a[i] << " ";
        }
    }

    delete []a;

    return 0;
}