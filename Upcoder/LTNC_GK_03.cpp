#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull f (ull n) {
    ull f[n + 1];
    f[1] = 1;
    for (ull i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            f[i] = i / 2 + f[i / 2];
        } else {
            ull v = (i - 1) / 2;
            f[i] = v * v + f[v] * f[v + 1];
        }
    }
    return f[n];
}

int main () {
    ull n; cin >> n;
    cout << f (n);
    return 0;
}