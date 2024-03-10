#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {
    freopen ("DIGITS.INP", "r", stdin);
    freopen ("DIGITS.OUT", "w", stdout);
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int n, cnt = 0; cin >> n;
    while (n) {
        vector<int> v;
        int total = n;
        while (total) {
            v.push_back (total % 10);
            total /= 10;
        }
        n -= *max_element (v.begin (), v.end ());
        cnt++;
    }
    cout << cnt;
    return 0;
}