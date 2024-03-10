#include <iostream>

using namespace std;

bool isPrime (int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool SumPrime (int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return isPrime (sum);
}

int main () {
    int n, a;
    cin >> n >> a;

    int arr[100][100];
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > 0; j--) {
            arr[i][j] = a;
            a += 2;
        }
    }

    for (int j = 1; j <= n; j++) {
        if (j % 2 != 0) {
            for (int i = 1; i <= n; i++) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;

    int max = -100;
    for (int j = n; j > 0; j--) {
        if (j % 2 != 0) {
            for (int i = 1; i <= n; i++) {
                if (arr[i][j] % 2 == 0 && arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
            break;
        }
    }

    if (max == -100) {
        cout << "NULL" << endl;
    } else {
            for (int j = n; j > 0; j--) {
            if (j % 2 != 0) {
                for (int i = 1; i <= n; i++) {
                    if (arr[i][j] == max) {
                    cout << arr[i][j] << endl; break;
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (SumPrime (arr[n - i + 1][i])) count++;
    }
    if (count == 0) {
        cout << "NULL";
    } else {
        for (int i = 1; i <= n; i++) {
        if (SumPrime (arr[n - i + 1][i])) {
            cout << "("<<n - i + 1<<","<<i<<")";
        }
    }
    }

    return 0;
}