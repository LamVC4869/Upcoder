#include <iostream>

using namespace std;

int main () {
    int n, t;
    cin >> n >> t;
    int a[n];
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (sum < t) {
            sum += a[i];
            cnt++;
        }
    }

    if (cnt >= n) cout << -1;
    else cout << cnt + 1;

    return 0;
}