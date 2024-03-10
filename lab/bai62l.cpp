#include <iostream>

using namespace std;

void Swap (int a, int b, int &n, int arr[100][100]) {
    for (int i = 0; i < n; i++) {
        int temp = arr[i][a];
        arr[i][a] = arr[i][b];
        arr[i][b] = temp;
    }
}

int main () {
    int n; cin >> n;

    int arr[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int a, b;
    cin >> a >> b;
    Swap (a - 1, b - 1, n, arr);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}