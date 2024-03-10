#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int n, k; cin >> n >> k;
    vector<int> v, t, z, y;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back (x);
        if (x <= k) z.push_back (x);
        else if (x > k) y.push_back (x);
    }
    t = v;
    sort (t.begin (), t.end ());
    int max = t.front ();
    for (int i = 0; i < n; i++) {
        if (v[i] > max && v[i] < t.back ()) max = v[i];
    }
    if (max == t.front ()) cout << -1 << endl;
    else {
        for (int i = 0; i < n; i++) {
            if (v[i] == max) cout << i << ' ';
        }
        cout << endl;
    }
    if (z.empty ()) cout << -1 << endl;
    else {
        sort (z.begin (), z.end ());
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == z.back ()) {
                cout << i << endl; break;
            }
        }
    }
    if (y.empty ()) cout << "00";
    else {
        sort (y.begin (), y.end ());
        for (auto it = y.begin (); it != y.end (); it++) cout << *it << ' ';
    }
    return 0;
}