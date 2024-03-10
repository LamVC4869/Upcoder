#include <iostream>

using namespace std;

typedef long long ll;
string name (ll n) {
    string result = "";
    while (n) {
        ll kt = (n - 1) % 26;
        result = char ('a' + kt) + result;
        n = (n - 1) / 26;
    }
    return result;
}

int main () {
    ll n; cin >> n;
    cout << name (n);
    return 0;
}