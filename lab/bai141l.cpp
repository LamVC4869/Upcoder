#include <iostream>
#include <cmath>

using namespace std;

string np (char c[]) {
    int index = c[1];
    string t = "";
    while (index) {
        t += index % 2 == 0 ? "0" : "1";
        index /= 2;
    }
    for (char &x : t) if (x == '0') {
        x = '1';
    } else x = '0';
    return t;
}

char res (string &t) {
    int num = 0;
    for (int i = 0; i < t.length (); i++) {
        num += ((t[i] - '0') * pow (2, i));
    }
    return char (num);
}

int main () {
    char c[3];
    cin >> c;
    string r = np (c);
    cout << res (r);
    return 0;
}