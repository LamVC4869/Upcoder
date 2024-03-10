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

void output (int n) {
    for (int i = 2; i <= sqrt (n); i++) {
        while (isPrime (i) && n % i == 0) {
            cout << i;
            n /= i;
            if (n > 1) cout << " x ";
        }
    }
    if (isPrime (n)) cout << n;
}

int main () {
    int n;
    cout << "n = ";
    cin >> n;
    cout << "Tich cac thua so nguyen to cua " << n << " la: ";
    output (n);
    return 0;
}