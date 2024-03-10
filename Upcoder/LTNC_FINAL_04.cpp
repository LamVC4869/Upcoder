#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)

bool Kiem_Tra_Hop_le (string a) {
    if (a.length () != 10) return false;
    if (a[1] == '4' || a[1] == '8') return true;
    if ((a[1] == '5' && a[2] == '9') || (a[1] == '6' && a[2] == '1')) return true;
    if ((a[1] == '5' && a[2] == '1' && a[3] == '1') || (a[1] == '7' && a[2] == '1' && a[3] == '0')) return true;
    return false;
}

int main () {
    string a;
    cin >> a;
    int length = a.length ();
    if (!Kiem_Tra_Hop_le (a)) {
        cout << "Khong hop le";
        return 0;
    }
    if (a[1] == '4') {
        cout << "Ha Noi - ";
        FOR(i, 2, length) cout << a[i];
    } else if (a[1] == '8') {
        cout << "TPHCM - ";
        FOR(i, 2, length) cout << a[i];
    } else if (a[1] == '5' && a[2] == '9') {
        cout << "Gia Lai - ";
        FOR(i, 3, length) cout << a[i];
    } else if (a[1] == '6' && a[2] == '1') {
        cout << "Dong Nai - ";
        FOR(i, 3, length) cout << a[i];
    } else if (a[1] == '5' && a[2] == '1' && a[3] == '1') {
        cout << "Da Nang - ";
        FOR(i, 4, length) cout << a[i];
    } else if (a[1] == '7' && a[2] == '1' && a[3] == '0') {
        cout << "Can Tho - ";
        FOR(i, 4, length) cout << a[i];
    }
    return 0;
}