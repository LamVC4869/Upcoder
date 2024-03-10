#include <iostream>

using namespace std;

void them_phan_tu (int* &arr, int &n, int a, int k) {
    int *b = new int [n + 2];
    for (int i = 1; i < k; i++) {
        b[i] = arr[i];
    }
    b[k] = a;
    for (int i = k + 1; i <= n + 1; i++) {
        b[i] = arr[i - 1];
    }

    delete []arr;
    arr = b;
    n++;
}

int main () {
    int n, a, k;
    cin >> n >> a >> k;
    int *arr = new int [100];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << n + 1 << endl;
    them_phan_tu (arr, n, a, k);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    delete []arr;
    return 0;
}