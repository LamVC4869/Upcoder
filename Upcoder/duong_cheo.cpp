#include <iostream>
#include <cmath>

using namespace std;

int main () {
    double x, y;
    cin >> x >> y;
    if (x <= 0 || y <= 0 || x != int (x) || y != int (y)) {
        cout << "Error";
        return 0;
    }

    cout << double (sqrt (x * x + y * y));

    return 0;
}