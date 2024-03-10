#include <iostream>

using namespace std;

int main () {
    int m; cin >> m;
    int x, y, min_x, cnt = 0;
    if (m == 1) {
        cout << "NO";
        return 0;
    }
    for (x = 0; x < m; x++) {
        for (y = x; y < m; y++) {
            if (x*x + 2*x*y + x + 1 == m) {
                cnt++;
                if (x < min_x) min_x = x;
            }
        }
    }
    for (x = 0; x < m; x++) {
        for (y = x; y < m; y++) {
            if (x*x + 2*x*y + x + 1 == m && x == min_x) {
                cout << min_x << ' ' << y;
                break;
            }
        }
    }
    if (cnt == 0) cout << "NO";
    return 0;
}