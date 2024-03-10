#include <iostream>

using namespace std;

int BinarySearch (int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (a[middle] < x) left = middle + 1;
        else right = middle;
    }
    if (a[left] == x) return left;
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    int n; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    int x; cin >> x;
    cout << BinarySearch (a, n, x);
    return 0;
}