#include <iostream>

using namespace std;

int main () {
    int n, a;
    cin >> n >> a;
    int arr[1000][1000];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            arr[i][j] = a;
            a++;
        }
    }

    for (int j = 0; j < n; j++) {
        if (j % 2 != 0) {
            for (int i = 0; i < n; i++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    int min = arr[0][n - 1] * 2;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][n - 1] < min && arr[i][n - 1] % 2 != 0) {
            min = arr[i][n - 1];
            count++;
        }
    }

    if (count == 0) {
        cout << "NULL" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (arr[i][n - 1] == min) {
                cout << arr[i][n - 1];
            }
        }
        cout << endl;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 && (j == 0 || j == n - 1)) || (j == 0 && (i == 0 || i == n - 1))) {
                if (arr[i][j] % 2 == 0) {
                    result += arr[i][j];
                }
            }
        }
    }
    cout << result;
    return 0;
}