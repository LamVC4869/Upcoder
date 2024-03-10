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

int Position (int n) {
    int count = 0, pos = 1;
    while (count < n) {
        pos++;
        if (isPrime (pos)) {
            count++;
        }
    }
    return pos;
}

int main () {
    int k; cin >> k;
    cout << Position (k);
    return 0;
}