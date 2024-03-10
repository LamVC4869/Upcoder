#include <iostream>
#include <cmath>

using namespace std;

double SQRT (int n) {
    if (n < 1) return 0;
    return sqrt (n + SQRT (n - 1));
}

int main () {
    int n; cin >> n;
    cout << roundf (SQRT (n) * 1000) / 1000;
    return 0;
}