#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n, l; cin >> n >> l;
    string str[l];
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        v.push_back (str[i]);
    }
    sort (v.begin (), v.end ());
    for (string x : v) cout << x;
    return 0;
}