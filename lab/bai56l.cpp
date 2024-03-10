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

bool SuperPrime (int n) {
    if (isPrime (n)) {
        while (n != 0) {
            int temp = n;
            if (!isPrime (temp)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main () {
    int a;
    cin >> a;
    if (SuperPrime (a)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}