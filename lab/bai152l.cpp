#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie(0);
    int n, k, pos = 1, cnt = 1; cin >> n >> k;
    int h[n];
    vector<int> v;
    for (int &i : h) cin >> i;
    v.push_back (h[0]);
    int min1 = 1000000;
    for (int i = pos; i < n; i++) {
        if (h[i] < min1 && i < k) min1 = h[i];
        v.push_back (min1);
        pos = i + 1;
        cout << i << ' ';
        min1 = 1000000;
        cnt++, k *= cnt;
    }
    int res = 0;
    for (int i = 1; i < v.size (); i++) {
        res += abs (v[i] - v[i - 1]);
    }
    cout << endl << res;
    return 0;
}