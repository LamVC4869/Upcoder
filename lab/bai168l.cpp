#include <iostream>
#define ll long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    ll n; cin >> n;
    ll a[n], T = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        T += a[i];
    }
    ll S = T / (n - 1);
    for (int i = 0; i < n; i++) {
        cout << S - a[i] << ' ';
    }
    return 0;
}