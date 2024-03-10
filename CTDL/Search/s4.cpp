#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    bool kt = false;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1 && !(i & 1)) {
            cout << a[i] << ' ';
            kt = true;
        }
    }
    if (!kt) cout << "NULL";
    return 0;
}