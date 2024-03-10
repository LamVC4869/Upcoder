#include <iostream>
#define ull unsigned long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    ull n; cin >> n;
    cout << n - (n/2 + n/3 + n/5 + n/7 - n/6 - n/10 - n/35 - n/21 - n/14 - n/15 + n/30 + n/42 + n/70 + n/105 - n/210);
    return 0;
}
