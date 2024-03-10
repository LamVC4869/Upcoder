#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n, k, cnt = 0; cin >> n >> k;
    int a[n]; for (int &i : a) cin >> i;
    sort (a, a + n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i] + k) break;
            else if (a[j] == a[i] + k) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}