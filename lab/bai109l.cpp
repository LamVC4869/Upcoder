#include <iostream>

using namespace std;

bool isPrime (int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

int Sum_n (int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void Sum (int n) {
    n = Sum_n (n);
    if (isPrime (n)) {
        cout << n;
    } else {
       if (n > 9) {
        n = Sum_n (n);
        isPrime (n) ? cout << n : cout << "error";
       } else {
        isPrime (n) ? cout << n : cout << "error";
       }
    }
}

int main () {
    int n; cin >> n;
    Sum (n);
    return 0;
}