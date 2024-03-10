#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull f (ull n) {
    return 3*n*n + 3*n + 1;
}

int main () {
    ull n; cin >> n;
    cout << f (n);
    return 0;
}