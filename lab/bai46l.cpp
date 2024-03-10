#include <iostream>
#include <string>

using namespace std;

int main () {
    string a; getline (cin, a);
    int n, m; cin >> n >> m;
    if (m >= a.length() || m < n || n < 0) {
        cout << "gioi han khong dung";
    } else {
        for (int i = n; i <= m; i++) {
            cout << a[i];
        }
    }
    return 0;
}