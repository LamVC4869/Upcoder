#include <iostream>
#include <cmath>

using namespace std;

bool isPrime (int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt (n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main () {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        while (isPrime (i) && n % i == 0) {
            cout << i;
            if (i < n) {
                cout << "*";
            }
            n /= i;
        }
    }
    return 0;
}