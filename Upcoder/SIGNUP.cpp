#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    string str[n];
    for (int i = 0; i < n; i++) cin >> str[i];
    bool d[n] = {};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] == str[j]) d[j] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!d[i]) {
            cout << "OK";
            int cnt = 1;
            for (int j = i + 1; j < n; j++) {
                if (d[j] && str[i] == str[j]) {
                    str[j] += cnt + '0';
                    cnt++;
                }
            }
        } else cout << str[i];
    }
    return 0;
}