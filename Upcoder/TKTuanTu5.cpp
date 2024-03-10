#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main () {
    int n, x, y;
    cin >> n >> x >> y;
    int a[n];
    vector<int> v1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == x) v1.push_back (i);
    }
    if (!v1.empty ()) {
        cout << v1.front();
    } else {
        int max = x + y;
        int min = x - y;
        vector<int> v2;
        for (int i = 0; i < n; i++) {
            if (a[i] >= min && a[i] <= max) v2.push_back (i);
        }
        if (v2.empty ()) cout << -1;
        else {
            int do_lech_min = y;
            for (int i = 0; i < n; i++) {
                if (abs (a[i] - x) <= y) do_lech_min = abs (a[i] - x);
            }
            for (int i = 0; i < n; i++) {
                if (abs (a[i] - x) == do_lech_min) {
                    cout << i;
                    break;
                }
            }
        }
    }
    return 0;
}
