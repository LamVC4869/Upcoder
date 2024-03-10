#include <iostream>

using namespace std;

void selectionSort (int a[], int n) {
    
}

int main () {
    int n; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    selectionSort (a, n);
    for (int i : a) cout << i << ' ';
    return 0;
}