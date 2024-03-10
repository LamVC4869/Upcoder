#include <iostream>
#include <cmath>

using namespace std;

int not_prime[1000010] = {};
int count_prime[1000001] = {};

void sangsnt () {
    not_prime[0] = 1;
    not_prime[1] = 1;
    for (int i = 2; i <= sqrt (1000000); i++) {
        if (!not_prime[i]) {
            for (int j = i*i; j <= 1000000; j += i) {
                if (j % i == 0) not_prime[j] = 1;
            }
        }
    }
}

void count () {
    count_prime[0] = 0;
    for (int i = 1; i <= 1000000; i++) {
        count_prime[i] = count_prime[i - 1] + !not_prime[i];
    }
}

int main () {
    sangsnt ();
    count ();
    int t, L, R, cnt = 0; cin >> t;
    while (t--) {
        cin >> L >> R;
        cout << count_prime[R] - count_prime[L - 1] << endl;
    }
    return 0;
}