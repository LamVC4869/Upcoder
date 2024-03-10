#include <iostream>
#include <cmath>
#include <iomanip>
#define ll long long

using namespace std;

ll factorial (ll n) {
    if (n <= 1) return 1;
    return factorial (n - 1) * n;
}

int main () {
    cout.precision (10);
    string s1, s2; cin >> s1 >> s2;
    int arr[4] = {};
    for (int i = 0; i < s1.length (); i++) {
        arr[0] += (s1[i] == '+');
        arr[1] += (s2[i] == '+');
        arr[2] += (s1[i] == '-');
        arr[3] += (s2[i] == '-');
    }
    cout << fixed << factorial (arr[0] - arr[1] + arr[2] - arr[3]) * 1.0 / (pow (2, arr[0] - arr[1] + arr[2] - arr[3]) * factorial (arr[0] - arr[1]) * factorial (arr[2] - arr[3]));
    return 0;
}