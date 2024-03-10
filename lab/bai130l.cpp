#include <iostream>
#include <cmath>

using namespace std;

string reverse (string &str) {
    string s = "";
    for (int i = 0; i < str.length (); i++) s += str[str.length () - i - 1];
    return s;
}

int main () {
    string num;
    long long p, d;
    cin >> num >> p >> d;
    num = reverse (num);
    int a = num[p - 1] - '0';
    string s;
    if (a >= 0 && a < 5) {
        a = (a + d) % 10;
    } else {
        a = abs (a - d);
        s = to_string (a);
        a = s[0] - '0';
    }
    num[p - 1] = a + '0';
    for (int i = p - 2; i > -1; i--) num[i] = '0';
    cout << reverse (num);
    return 0;
}