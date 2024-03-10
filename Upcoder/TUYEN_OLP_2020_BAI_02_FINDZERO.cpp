#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int a[n], b[n];
    int dem = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            b[i] = 0;
            dem++;
        }
    }

    if (dem == 1) {
        int pos;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) pos = i;
        }
        int count = 0;
        int x;
        for (x = 0; x <= pos; x++) {
            if (a[x] != 0) count++;
        }
        b[x]
        for (int i = n - 1; i > pos; i--) {

        }
    } else {

    }

    for (int i = 0; i < n; i++) cout << b[i] << " ";
    
    return 0;
}