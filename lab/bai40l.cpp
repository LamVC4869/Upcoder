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

bool isPalindrome (int n) {
    if (n < 0) return false;
    int res = n, total = 0;
    while (n > 0) {
        int value = n % 10;
        total = total * 10 + value;
        n /= 10;
    }

    return res == total;

}

int main () {
    int a, b, count = 0; cin >> a >> b;
    if (a >= 10000 && b > a && b < 100000) {
        for (int i = a; i <= b; i++) {
            if (isPrime (i) && isPalindrome (i)) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}