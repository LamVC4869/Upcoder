#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n, m; cin >> n >> m;
    vector<int> v;
    vector<bool> t(1000010, false);
    for (int i = n; i > 0; i--) {
        v.push_back (i);
    }
    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        v.push_back (tmp);
    }
    for (auto it = t.begin (); it != t.end (); it++) {
        if (!t[*it]) {
            cout << *it << ' ';
            t[*it] = true;
        }
    }
    return 0;
}