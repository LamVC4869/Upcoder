#include <iostream>

using namespace std;

int binarySearch (int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r)/2;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    if (a[l] == x) return l;
    return -1;
}

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int n, x; cin >> n >> x;
    int a[n]; for (int &i : a) cin >> i;
    cout << binarySearch (a, n, x);
    return 0;
}