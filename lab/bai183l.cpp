#include <iostream>
#define endl '\n'

using namespace std;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int n, x; cin >> n >> x;
    bool tonTaiX = false, lonHonX[n] = {}, sure = false;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == x) tonTaiX = true;
        if (a[i] > x) {
            lonHonX[i] = true;
            sure = true;
        }
    }
    if (!tonTaiX) {
        cout << 'N' << endl;
        if (!sure) cout << -1;
        else {
            for (int i = 0; i < n; i++) {
                if (lonHonX[i]) {
                    cout << i;
                    break;
                }
            }
        }
    } else {
        cout << 'Y' << endl;
        for (int i = n - 1; i > -1; i--) {
            if (a[i] == x) {
                cout << i;
                break;
            }
        }
    }
    return 0;
}