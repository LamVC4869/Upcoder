#include <iostream>

using namespace std;

int count (int a[], int n, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) if (a[i] == x) cnt++;
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n, x; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    cin >> x;
    cout << count (a, n, x);
    return 0;
}