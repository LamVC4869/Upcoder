#include <iostream>

using namespace std;

int searchMin (int a[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (a[index] > a[i]) index = i;
    }
    return index;
}

int searchMax (int a[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (a[index] <= a[i]) index = i;
    }
    return index;
}

int main () {
    int n; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    int indexMin = searchMin (a, n);
    int indexMax = searchMax (a, n);
    swap (a[indexMin], a[indexMax]);
    for (int i : a) cout << i << " ";
    return 0;
}