#include <iostream>

using namespace std;

int n, x, a[1000010];

int search (int a[], int n, int x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return i;
    return -1;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    cout << search(a, n, x);
    return 0;
}