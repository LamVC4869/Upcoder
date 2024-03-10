#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

bool isPrime (ull n) {
    for (ull i = 2; i <= sqrt (n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

ull Fibonacci (ull n) {
    if (n < 2) return n;
    ull a = 0, b = 1, temp;
    for (ull i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ull n; cin >> n;
    ull i = 2, total = 0;
    while (total <= n) {
        total = Fibonacci (i);
        if (isPrime (total) && total <= n) {
            cout << total << endl;
        }
        ++i;
    }
    return 0;
}