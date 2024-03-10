#include <iostream>

using namespace std;

bool isPrime (int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int sum (int n) {
    if (n == 2) return 2;
    if (!isPrime (n)) {
        return sum (n - 1);
    }
    return n + sum (n - 1);
}

int main () {
    int n; cout << "n = "; cin >> n;
    cout << sum (n);
    return 0;
}