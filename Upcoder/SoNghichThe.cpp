#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int a[n];
    bool b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) b[j] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int k = 0, pos[n];
        for (int j = i + 1; j < n; j++) {
            for (int x = j + 1; x < n; x++) {
                if (a[j] == a[x]) pos[j] = j;
            }
            if (a[j] == k || j == pos[j]) continue;
            if (i < j && a[i] > a[j] && b[i] == false) {
                cnt++;
                k = a[j];
            }
        }
    }
    cout << cnt;
    return 0;
}