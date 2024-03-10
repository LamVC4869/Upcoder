#include <iostream>
#include <cmath>

using namespace std;

bool KiemTra (char a[], char b[]) {
    int i = a[1] - '0', j = b[1] - '0';
    if (i == j || a[0] == b[0] || (abs(a[0] - b[0]) == abs(i - j))) return true;
    return false;
}

int main () {
    char a[3], b[3];
    cin >> a >> b;
    KiemTra (a, b) ? cout << "YES" : cout << "NO";
    return 0;
}