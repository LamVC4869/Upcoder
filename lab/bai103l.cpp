#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int x;
    int a[10001];
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            cout << i << " ";
        } else {
            cout << -1 << " ";
        }
    }
    
    return 0;
}