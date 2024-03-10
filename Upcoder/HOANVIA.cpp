#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ull tmp = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;

        int cnt = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                cnt++;
                a[j] = 0;
            }
        }
        tmp *= factorial(cnt);
    }

    ull result = factorial(n) / tmp;

    cout << result;
    return 0;
}
