#include <iostream>

using namespace std;

bool KtKhongHopLe (int arr[], int pos) {
    return arr[pos - 1] > arr[pos];
}

int main () {
    int n; cin >> n;
    int arr[51];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 1;
    for (int i = 1; i < n; i++) {
        if (!KtKhongHopLe (arr, i)) count++;
    }

    cout << count;

    return 0;
}