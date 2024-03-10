#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int s = 0, a[n];
    for (int &i : a) {
        cin >> i;
        s += i;
    }
    if (int (s/n) != s*1.0/n) {
        cout << -1;
        return 0;
    }
    int tb = s/n;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] > tb) {
            a[i]--;
            dem++;
        }
        while (a[i] < tb) {
            a[i]++;
            dem--;
        }
    }
    cout << dem;
    return 0;
}