//H_MT_2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int reverse (int n) {
    int res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    vector<int> v;
    int input;
    while (cin >> input) v.push_back (reverse (input));
    cout << *max_element (v.begin (), v.end ());
    return 0;
}