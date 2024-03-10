#include <iostream>

using namespace std;

void XuliChuoi (string str);

int main () {
    string a; cin >> a;
    XuliChuoi (a);
    return 0;
}

void XuliChuoi (string str) {
    int count = 1;
    for (int i = 0; i < str.length (); i++) {
        if (i + 1 < str.length () && str[i] == str[i + 1]) {
            count++;
        } else {
            cout << count << str[i];
            count = 1;
        }
    }
}