#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime (int n) {
    for (int i = 2; i <= sqrt (n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

bool isSquareNumber (int n) {
    return int (sqrt (n)) == sqrt (n);
}

void Nhap (string label, int &n) {
    cout << label;
    cin >> n;
}

void Xuat_Mang (string label, vector<int> v) {
    cout << label;
    for (vector<int>::iterator it = v.begin (); it != v.end (); it++) cout << *it << " ";
}

int main () {
    int n;
    Nhap ("So luong phan tu: ", n);
    int digit, i = 0;
    vector<int> a, b;
    cout << "Cac phan tu trong mang: ";
    while (i < n) {
        cin >> digit;
        if (isPrime (digit)) a.push_back (digit);
        else if (isSquareNumber (digit)) b.push_back (digit);
        i++;
    }

    Xuat_Mang ("Cac phan tu la so nguyen to: ", a);
    cout << endl;
    Xuat_Mang ("Cac phan tu la so chinh phuong: ", b);

    return 0;
}