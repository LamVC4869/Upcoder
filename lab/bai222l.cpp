#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int n, k; cin >> n >> k;
    int cnt = 0, a[n];
    for (int &i : a) cin >> i;
    bool check = false;
    for (int i : a) if (i != 0) check = true;
    if (!check) {
        cout << 0;
        return 0;
    }
    int score = a[k - 1];
    if (score == 0) {
        for (int i : a) if (i > 0) cnt++;
    } else {
        for (int i : a) if (i >= score) cnt++;
    }
    cout << cnt;
    return 0;
}