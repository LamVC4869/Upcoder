#include <iostream>
#include <cmath>

using namespace std;

double Value (double x, double arr[], int n[], int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i] * pow (x, n[i]);
    }
    return sum;
}

void Dao_Ham (int k, double arr[], int n[]) {
    for (int i = 0; i < k; i++) {
        arr[i] = arr[i] * n[i];
        n[i]--;
        if (arr[i] == 0) {
            continue;
        } else if (n[i] == 0) {
            cout << arr[i];
        } else if (n[i] == 1) {
            cout << arr[i] << "x";
        } else if (arr[i] == 1) {
            cout << "x^" << n[i];
        } else {
            cout << arr[i] << "x^" << n[i];
        }
        if (i < k - 1) {
                cout << " + ";
            }
    }
}

int main () {
    int k; cin >> k;
    double arr[100];
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    int n[100];
    for (int i = 0; i < k; i++) {
        cin >> n[i];
    }
    double x; cin >> x;
    for (int i = 0; i < k; i++) {
        if (arr[i] == 0) {
            continue;
        } else if (n[i] == 0) {
            cout << arr[i];
        } else if (n[i] == 1) {
            cout << arr[i] << "x";
        } else if (arr[i] == 1) {
            cout << "x^" << n[i];
        } else {
            cout << arr[i] << "x^" << n[i];
        }
        if (i < k - 1) {
                cout << " + ";
            }
    }
    cout << endl << Value (x, arr, n, k) << endl;
    Dao_Ham (k, arr, n);
    return 0;
}