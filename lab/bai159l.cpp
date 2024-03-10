#include <iostream>
#define ll long long
#define mod 1000000007

using namespace std;

ll powMod (ll a, ll b, ll c) {
    if (b == 0) return 1;
    ll tmp = powMod (a, b/2, c);
    return (b & 1) ? (a % c * ((tmp % c) * (tmp % c) % c)) % c : (tmp % c) * (tmp % c) % c;
}

int main () {
    ll a, b, c; cin >> a >> b >> c;
    a %= c;
    cout << powMod (a, b, c);
    return 0;
}