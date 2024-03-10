#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs (a[i]) > abs (a[j])) swap (a[i], a[j]);
        }
    }
    vector<int> v;
    v.push_back (a[n - 1]);
    v.push_back (a[n - 2]);
    v.push_back (a[n - 3]);
    sort(v.begin (), v.end ());
    for (int i : v) cout << i << ' ';
    return 0;
}