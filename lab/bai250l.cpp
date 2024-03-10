#include <iostream>
#define endl '\n'

using namespace std;

void binarySearch (int v[], int n, int x) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r)/2;
        if (v[mid] < x) l = mid + 1;
        else r = mid;
    }
    if (v[l] == x) cout << "Yes " << l << endl;
    else cout << "No " << ((v[l] < x) ? l + 1 : l) << endl;
}

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int n, q; cin >> n;
    int v[n + 1];
    for (int i = 1; i <= n; i++) cin >> v[i];
    cin >> q;
    while (cin >> q) {
        binarySearch (v, n, q);
    }
    return 0;
}