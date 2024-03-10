#include <iostream>

using namespace std;

int solve (int n, int a[], int k) {
    if (k == 4) {
        for (int i = 0; i < n; i++) if (a[i] % k == 0) return 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) if (!(a[i] & 1)) cnt++;
        if (cnt % 2 == 0 && cnt) return 0;
        else if (cnt & 1) return 1;
        else if (cnt == 0) {
            for (int i = 0; i < n; i++) {
                if ((1 + a[i]) % k == 0) return 1;
            }
            return 2;
        }
    }
    int MaxVal = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] % k == 0) return 0;
        MaxVal = max(a[i] % k, MaxVal);
    }
    return k - MaxVal;
}

int main () {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n]; for (int &i : a) cin >> i;
        cout << solve (n, a, k) << endl;
    }
    return 0;
}