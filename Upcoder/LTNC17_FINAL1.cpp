#include <iostream>

using namespace std;

int main () {
    string str;
    cin >> str;
    int res = 0, l = str.length (), pos = 0;
    if (str[0] == '-') {
        res -= str[1] - '0';
        pos = 3;
    } else {
        res += str[0] - '0';
        pos = 2;
    }
    for (int i = pos; i < l; i += 2) {
        if (str[i - 1] == '-') {
            res -= str[i] - '0';
        } else {
            res += str[i] - '0';
        }
    }
    cout << res;
    return 0;
}