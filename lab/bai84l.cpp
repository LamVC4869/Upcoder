#include <iostream>
#include <cmath>

using namespace std;

unsigned long long factorial (int n) {
    if (n == 1) return 1;
    return n * factorial (n - 1);
}

double Sin (int x, int n) {
    if (n == 0) return x;
    return pow (-1, n) * (pow (x, 2*n + 1) / factorial (2*n + 1)) + Sin (x, n - 1);
}

double Cos (double x, int n) {
    if (n == 0) return 1;
    return pow (-1, n) * (pow (x, 2*n) / factorial (2*n)) + Cos (x, n - 1);
}

int main () {
    double x;
    cin >> x;
    cout << roundf (Sin (x, 4) * 100) / 100 << endl;
    cout << roundf (Cos (x, 4) * 100) / 100;
    return 0;
}