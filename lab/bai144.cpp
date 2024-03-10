#include <iostream>

using namespace std;

bool not_prime[100001] = {};
void Eratosthenes () {
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i * i <= 100000; i++) {
        if (!not_prime[i]) {
            for (int j = i * i; j <= 100000; j += i) not_prime[j] = true;
        }
    }
}

int main () {
    int t; cin >> t;
    Eratosthenes ();
    while (t--) {
        int A, B, m, n, sum = 0;
        cin >> A >> B >> m >> n;
        for (int i = A; i <= B; i++) {
            if (!not_prime[i] && i % m == n) sum += i;
        }
        cout << sum << endl;
    }
    return 0;
}