#include <iostream>

using namespace std;

struct Arr {
    int size, arr [100];
};

// 1. operator==
// 2. operator[]
// 3. operator!=
// 4. operator<<
// 5. operator>>
// 6. operator+
// 7. operator=

#define FOR(i, a, b) for (int i = a; i < b; i++)

bool ktGiongNhau (int n1, int n2, int arr1[], int arr2[]) {
    if (n1 != n2) return false;
    FOR(i, 0, n1) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

int main () {
    Arr a[2];
    FOR(i, 0, 2) {
        cin >> a[i].size;
        FOR(j, 0, a[i].size) {
            cin >> a[i].arr[j];
        }
    }

    ktGiongNhau (a[0].size, a[1].size, a[0].arr, a[1].arr) ? cout << "yes" : cout << "no";

    return 0;
}