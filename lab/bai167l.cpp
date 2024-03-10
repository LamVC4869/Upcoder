#include <iostream>
#include <vector>
#define ll long long

using namespace std;

void pushElements (vector<ll> &v, ll n) {
    string str = to_string (n);
    for (int i = 0; i < 9; i++) {
        v[i] = i + 1;
        for (int j = 1; j < str.size (); j++) {
            v[i] = v[i] * 10 + (i + 1);
        }
    }
    while (v[0] < n) v.erase (v.begin ());
    cout << v.front ();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    ll n; cin >> n;
    vector<ll> v (9);
    pushElements (v, n);
    return 0;
}