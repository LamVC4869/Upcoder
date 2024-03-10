#include <iostream>
#define ull unsigned long long

using namespace std;

ull f (int n) {
    if (n == 0) return 0;
    ull f[n + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            f[i] = f[i / 2];
        } else {
            ull m = (i - 1) / 2;
            f[i] = f[m] + f[m + 1];
        }
    }
    return f[n];
}

int main () {
    int n; cin >> n;
    ull max = 0;
    for (int i = 0; i <= n; i++) if (f (i) > max) max = f (i);
    cout << max;
    return 0;
}