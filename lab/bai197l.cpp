#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int n, q;
    cin >> n;
    vector<int> a(n); for (int &i : a) cin >> i;
    cin >> q;
    while (cin >> q) a.erase (a.begin () + q - 1);
    for (int i : a) cout << i << ' ';
    return 0;
}