#include <iostream>
#include <cmath>

using namespace std;

unsigned long long Check (int n) {
    for (int i = 0; i <= sqrt (n); i++) {
        if (pow (2, i) == n) return true;
    }
    return false;
}

int main () {
    int n;
    cin >> n;
    Check (n) ? cout << "true" : cout << "false";
    return 0;
}