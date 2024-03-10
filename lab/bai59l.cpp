#include <iostream>

using namespace std;

bool isPrime (int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main () {
    int n; cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime (a[i]) && a[i] < 10) {
            sum += a[i];
        }
        if (isPrime (a[i]) && a[i] >= 10) {
            while (a[i] != 0) {
                int temp = a[i] % 10;
                sum += temp;
                a[i] /= 10;
            }
        }
    }

    cout << sum;

    return 0;
}