#include <iostream>
#define ll long long

using namespace std;

ll a[1000];

int main () {
    ll money, i = 0, index, total = 0; cin >> money;
    bool duTien = true;
    while (cin >> index) a[i++] = index;
    for (int j = 0; j < i; j++) {
        total += money - a[i];
        if (total < 0) {
            cout << -1;
            duTien = false;
            break;
        }
    }
    if (duTien) cout << total;
    return 0;
}