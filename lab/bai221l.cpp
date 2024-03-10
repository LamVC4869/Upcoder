#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    int n; cin >> n;
    int res = n;
    for (int i = 0; i < 3; i++) {
        int x, y; cin >> x >> y;
        if (x == res) res = y;
        else if (y == res) res = x;
    }
    cout << res;
    return 0;
}