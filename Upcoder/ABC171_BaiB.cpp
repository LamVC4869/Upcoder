#include <iostream>

using namespace std;

void Sort (int n, int a[]) {
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
    int n, k;
    cin >> n >> k;
    int a[1001];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Sort (n, a);
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    cout << sum;
    return 0;
}