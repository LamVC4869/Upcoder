#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        ull n; cin >> n;
        ull x = round(pow (n, 1.0/3));
        pow (x, 3) == n ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}