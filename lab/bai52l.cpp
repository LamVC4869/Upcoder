#include <iostream>

using namespace std;

int main () {
    int n, a[1000][1000];

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        cout << a[k][k] << " ";
    }

    return 0;
}