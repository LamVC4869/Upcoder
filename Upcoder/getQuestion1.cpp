#include <iostream>

using namespace std;

typedef long long ll;

ll TongChuSo (ll n) {
    ll result = 0;
    while (n) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main () {
    ll n; cin >> n;
    n = TongChuSo (n);
    while (TongChuSo (n) > 9) n = TongChuSo (n);
    cout << TongChuSo (n);
    return 0;
}