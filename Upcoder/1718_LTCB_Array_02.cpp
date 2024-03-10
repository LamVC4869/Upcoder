#include <iostream>
#include <math.h>

using namespace std;

bool isPrime (int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt (n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isSquareNumber (int n) {
    return int (sqrt (n)) == sqrt (n);
}

bool isPerfectNumber (int n) {
    int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

int main () {
    int n, n1 = 0, n2 = 0, n3 = 0;
    int arr1[1000], arr2[1000], arr3[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (isPrime (temp)) {
            n1++;
            arr1[n1] = temp;
        } else if (isSquareNumber (temp)) {
            n2++;
            arr2[n2] = temp;
        } else if (isPerfectNumber (temp)) {
            n3++;
            arr3[n3] = temp;
        }
    }
        if (n1 == 0) {
        cout << "NULL" << endl;
    } else {
        cout << arr1[1];
        for (int i = 2; i <= n1; i++) {
            cout << " " << arr1[i];
        }
        cout << endl;
    }
        if (n2 == 0) {
        cout << "NULL" << endl;
    } else {
        cout << arr2[1];
        for (int i = 2; i <= n2; i++) {
            cout << " " << arr2[i];
        }
        cout << endl;
    }
        if (n3 == 0) {
        cout << "NULL";
    } else {
        cout << arr3[1];
        for (int i = 2; i <= n3; i++) {
            cout << " " << arr3[i];
        }
    }
    return 0;
}