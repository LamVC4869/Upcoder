#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n/2; i++) if (a[i] != a[n - i - 1]) cnt++;
    if (cnt == 0) {
        cout << "mang doi xung";
    } else {
        cout << "mang khong doi xung" << endl;
        for (int i = 0; i < n/2; i++) {
            if (a[i] != a[n - i - 1]) cout << a[i] << " " << a[n - i - 1] << endl;
        }
    }
    delete []a;
    return 0;
}