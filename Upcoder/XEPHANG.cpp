#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n, cnt = 1; cin >> n;
    int a[n];
    for (int &i : a) cin >> i;
    vector<int> v;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) cnt++;
        else {
            v.push_back (cnt);
            cnt = 1;
        }
    }
    cout << n - *max_element (v.begin (), v.end ());
    return 0;
}