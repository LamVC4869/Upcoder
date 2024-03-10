#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000000; // Số lớn nhất bạn muốn kiểm tra

bool prime[MAX + 1];

void Sang_Prime() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= MAX; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    unsigned long long x;
    cin >> x;
    unsigned long long result = 1;

    Sang_Prime();

    for (int i = 2; i <= x; i++) {
        if (prime[i] && x % i == 0) {
            result *= i;
            x /= i;

            // Kiểm tra x lại với i

        }
    }

    cout << result;

    return 0;
}
