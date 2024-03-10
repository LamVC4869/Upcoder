#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    vector<int> v;
    bool duyet[100000] = {};
    int x;
    while (cin >> x) {
        if (!duyet[x]) {
            v.push_back (x);
            duyet[x] = true;
        }
    }
    sort (v.begin (), v.end ());
    int n = (int (sqrt (v.size ())) == sqrt (v.size ()) ? sqrt (v.size ()) : sqrt (v.size ()) + 1);
    for (int i = v.size (); i < n * n; i++) v.push_back (0);
    int cnt = 0;
    for (int i = 0; i < n * n; i++) {
        if (cnt == n) {
            cout << endl;
            cnt = 0;
        }
        cout << v[i] << ' ';
        cnt++;
    }
    return 0;
}