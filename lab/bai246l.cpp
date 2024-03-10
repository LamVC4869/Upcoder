#include <iostream>
#include <vector>
typedef unsigned long long ll;

using namespace std;

vector<ll> v(10000010, 0);

ll TriBonacci (ll n) {
    if (n < 2) return 0;
    v[2] = 1;
    for (int i = 3; i <= 100; i++) {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }
    return v[n];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie (0);
    ll n;
    while (cin >> n) cout << TriBonacci (n) << '\n';
    return 0;   
}