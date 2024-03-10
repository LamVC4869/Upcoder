#include <iostream>

using namespace std;

int binSearch (int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r)/2;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return a[l] == x ? l : -1;
}

int main () {
    int n, x; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    cin >> x;
    cout << binSearch (a, n, x);
    return 0;
}