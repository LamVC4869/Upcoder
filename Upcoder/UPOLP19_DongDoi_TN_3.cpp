#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

ull reverse (ull n) {
    int temp = 0;
    while (n) {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp;
}

bool kiem_tra_so_nguyen_to (int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main () {
    ull P, Q, count = 0;
    cin >> P >> Q;
    for (ull X = P; X <= Q; X++) if (kiem_tra_so_nguyen_to (reverse (X))) {
        count++;
        cout << X << endl;
    }
    if (count == 0) cout << -1;
    return 0;
}