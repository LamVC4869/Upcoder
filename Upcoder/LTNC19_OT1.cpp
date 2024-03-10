#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;


bool scp (ll n) {
    return round (sqrt (n)) == sqrt (n);
}

int main () {
    ll n, k, cnt = 0; cin >> n >> k;
    vector<ll> arr(n);
    set<ll> s;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        if (scp (arr[i])) cnt++;
        else s.insert (arr[i]);
    }
    cout << cnt << endl;
    !(find (arr.begin (), arr.end(), k) != arr.end ()) ? cout << "No" << endl : cout << "Yes" << endl;
    for (set<ll>::iterator it = s.begin (); it != s.end (); it++) cout << *it << ' ';
    return 0;
}