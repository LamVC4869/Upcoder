#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // tong tung dong
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
        cout << sum << " ";
    }

    cout << endl;

    //tong tung cot
    for (int i = 0; i < n; i++) {
        int sum1 = 0;
        for (int j = 0; j < n; j++) {
            sum1 += a[j][i];
        }
        cout << sum1 << " ";
    }

    return 0;
}