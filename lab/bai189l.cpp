#include <iostream>
#include <iomanip>
#include <cmath>
#define ll long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    ll n; cin >> n;
    double a = sqrt ((2 * n * sqrt (3)) / 9);
    cout << fixed << setprecision (8) << a * 6.0;
    return 0;
}