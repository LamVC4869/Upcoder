#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool soChinhPhuong (int n) {
    return int (sqrt (n)) == sqrt (n);
}

void Sort_Tang (vector<int> &v) {
    for (int i = 0; i < v.size (); i++) {
        for (int j = i + 1; j < v.size (); j++) {
            if (v[i] > v[j]) swap (v[i], v[j]);
        }
    }
}

int main () {
    int n, m; cin >> n >> m;
    int a[n], b[m];
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!soChinhPhuong (a[i])) v.push_back (a[i]);
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
        if (!soChinhPhuong(b[j])) v.push_back (b[j]);
    }
    Sort_Tang (v);
    for (int x : v) cout << x << ' ';
    cout << endl;
    vector<int> t;
    for (int i = 0; i < n; i++) {
        if (!soChinhPhuong (a[i])) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) t.push_back (a[i]);
            }
        }
    }
    Sort_Tang (t);
    for (int x : t) cout << x << ' ';
    return 0;
}
