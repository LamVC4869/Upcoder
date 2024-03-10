#include <iostream>

using namespace std;

bool isPrime (int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

void Print (int m, int n) {
    int count = 0, x = 0;
    for (int i = m; i <= n; i++) {
        if (isPrime (i)) {
            if (x) cout << " ";
            cout << i;
            count++;
            x++;
        }
    }
    if (!count) cout << -1;
}

int main () {
    int m, n;
    cin >> m >> n;
    Print (m, n);
    return 0;
}