#include <iostream>

using namespace std;

void sort (char a[], char tmp[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (tmp[i] > tmp[j]) {
                swap (a[i], a[j]);
                swap (tmp[i], tmp[j]);
            } else if (tmp[i] == tmp[j]) {
                if (a[i] < a[j]) {
                    swap (a[i], a[j]);
                    swap (tmp[i], tmp[j]);
                }
            }
        }
    }
}

void rsort (char a[], char tmp[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (tmp[i] < tmp[j]) {
                swap (a[i], a[j]);
                swap (tmp[i], tmp[j]);
            } else if (tmp[i] == tmp[j]) {
                if (a[i] > a[j]) {
                    swap (a[i], a[j]);
                    swap (tmp[i], tmp[j]);
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    char TypeSort;
    int n;
    cin >> TypeSort >> n;
    char kt[n], tmp[n];
    for (int i = 0; i < n; i++) {
        cin >> kt[i];
        tmp[i] = tolower(kt[i]);
    }
    switch (TypeSort) {
    case 'A':
        sort (kt, tmp, n);
        break;
    default:
        rsort (kt, tmp, n);
        break;
    }
    for (char i : kt) cout << i << ' ';
    return 0;
}