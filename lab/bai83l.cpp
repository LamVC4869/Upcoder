#include <iostream>

using namespace std;

unsigned long long Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n;
    cin >> n;

    cout << Fibonacci (n);

    return 0;
}
