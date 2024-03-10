#include <bits/stdc++.h>

using namespace std;

bool isPrime (int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt (n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isSquare (int n) {
    int x = sqrt (n);
    if (x*x == n) return true;
    return false;
}

bool isPerfect (int n) {
    int result = n;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == result;
}

int main () {

    int n, a[1000], t1 = 0, t2 = 0, t3 = 0, count = 0, x1 = 0, x2 = 0, x3 = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << "NULL";
    } else {
        for (int j = 0; j < n; j++) {
            if (isPrime (a[j])) {
                t1++;
            } else if (isSquare (a[j])) {
                t2++;
            } else if (isPerfect (a[j])) {
                t3++;
            }
        }
    }

    for (int x = 0; x < n; x++) {
        if (isPrime (a[x])) {
            x1++;
            if (x1 < t1) {
            cout << a[x] << " ";
            }
            if (x1 == t1) {
                cout << a[x];
            }
        }
    }

    cout << endl;

    for (int k = 0; k < n; k++) {
        if (isSquare (a[k])) {
            x2++;
            if (x2 < t2) {
                cout << a[k] << " ";
            }
            if (x2 == t2) {
                cout << a[k];
            }
        }
    }

    cout << endl;

    for (int s = 0; s < n; s++) {
        if (isPerfect (a[s])) {
            x3++;
            if (x3 < t3) {
                cout << a[s] << " ";
            }
            if (x3 == t3) {
                cout << a[s];
            }
        }
    }

    return 0;
}