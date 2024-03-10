#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int fibo[22];
bool kt[10947] = {};

void solve (int fibo[], bool kt[]) {
    fibo[1] = fibo[2] = 1;
    kt[fibo[1]] = kt[fibo[2]] = true;
    for (int i = 3; i < 22; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        kt[fibo[i]] = true;
    }
}

int main () {
    freopen ("DAYSO.INP", "r", stdin);
    freopen ("DAYSO.OUT", "w", stdout);
    solve (fibo, kt);
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    vector<int> v;
    int n;
    while (cin >> n) if (kt[n]) v.push_back (n);
    int maxFib = v[0];
    for (int i = 1; i < v.size (); i++) maxFib = max(v[i], maxFib);
    for (int i : v) cout << i << ' ';
    cout << '\n' << maxFib << ' ';
    for (int i = 1; i < 22; i++) if (fibo[i] == maxFib) {
        cout << i; break;
    }
    return 0;
}