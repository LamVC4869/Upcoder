#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int n, sum = 0; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];
    int tien = (sum * 2 + max) / (n + 1);
    cout << tien << endl;
    tien >= pow (10, n) ? cout << "yes" << endl : cout << "no" << endl;
    string str = to_string (tien);
    pow (2, str.length ()) <= 100 ? cout << pow (2, str.length ()) : cout << "death";
    return 0;
}