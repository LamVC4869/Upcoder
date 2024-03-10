#include <iostream>

using namespace std;

int main () {
    long long a, n; cin >> a >> n;
    if (n == 0) cout << 1;
    else {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * a) % 10;
        }
        cout << res;
    }
    return 0;
}