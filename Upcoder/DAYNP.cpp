#include <iostream>
#include <vector>

using namespace std;

void DayNP (int n, string x, vector<string> &v) {
    if (n == 0) {
        v.push_back (x);
        return;
    }
    DayNP (n - 1, x + "0", v);
    DayNP (n - 1, x + "1", v);
}

int main () {
    int n; cin >> n;
    vector<string> v;
    DayNP (n, "", v);
    for (string &x : v) cout << x << endl;
    return 0;
}