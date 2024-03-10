#include <iostream>

using namespace std;

void Sort (int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main () {
    int n, m; cin >> n >> m;
    int arr[1000];
    for (int i = 0; i < n*m; i++) {
        cin >> arr[i];
    }
    Sort (arr, n*m);
    for (int i = 0; i < n*m; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % m == 0) {
            cout << endl;
        }
    }
    return 0;
}