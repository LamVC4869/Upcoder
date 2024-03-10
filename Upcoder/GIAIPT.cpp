#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main () {
    int a, b, c;
    cin >> a >> b >> c;
    cout.precision (4);
    if (a == 0) {
        if (b == 0) {
            c == 0 ? cout << "VSN" : cout << "VN";
        } else {
            c == 0 ? cout << fixed << (double) c / b : cout << fixed << - (double) c / b;
        }
    } else {
        int delta = b*b - 4*a*c;
        if (delta < 0) {
            cout << "VN";
        } else if (delta == 0) {
            double x = - b/(2*a);
            cout << fixed << x;
        } else {
            double x1 = (-b + sqrt (delta)) / (2*a);
            double x2 = (-b - sqrt (delta)) / (2*a);
            cout << fixed << x1 << endl << x2;
        }
    }
    return 0;
}