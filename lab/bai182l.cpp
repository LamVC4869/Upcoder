#include <iostream>
#define ll long long

using namespace std;

ll _Mod (ll a, ll b, ll mod) {
    ll result = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            result = (result + a) % mod;
        }
        a = (a * 2) % mod;
        b = b >> 1;
    }
    return result;
}

ll Mod(ll a, ll n, ll mod) {
    ll result = 1;
    while (n > 0) {
        if (n & 1) result = _Mod(result, a, mod);
        a = _Mod(a, a, mod);
        n = n >> 1;
    }
    return result;
}

int main() {
    ll a, n;
    cin >> a >> n;
    ll res = Mod(a, n, 100);
    cout << res / 10 << res % 10 << endl;
    return 0;
}