#include <iostream>

using namespace std;

bool KiemTra (char c) {
    return c >= 'a' && c <= 'z';
}

int main () {
    char c;
    cin >> c;
    c = KiemTra (c) ? toupper (c) : tolower (c);
    cout << c;
    return 0;
}