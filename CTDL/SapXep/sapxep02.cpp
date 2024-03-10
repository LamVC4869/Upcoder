#include <iostream>

using namespace std;

void insertionSort (int a[], int n) {
    int index, value;
    for (int i = 1; i < n; i++) {
        index = i;
        value = a[i];
        while (index && a[index - 1] > value) {
            a[index] = a[index - 1];
            index--;
        }
        a[index] = value;
    }
}

int main () {
    int n; cin >> n;
    int a[n]; for (int &i : a) cin >> i;
    insertionSort (a, n);
    for (int i : a) cout << i << ' ';
    return 0;
}