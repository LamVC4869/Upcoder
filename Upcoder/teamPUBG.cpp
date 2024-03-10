#include <iostream>

using namespace std;

int main () {
    int n; cin >> n;
    int min, max;
    if (n <= 25) max = n;
    else max = 25;
    if (n % 4 == 0) min = n / 4;
    else min = n / 4 + 1;
    cout << min << ' ' << max;
    return 0;
}