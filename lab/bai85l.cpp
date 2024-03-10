#include <iostream>

using namespace std;

void Max (double a, double b, double c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    cout << max;
}

void Template (char c) {
    if (c == 'a') {
        int a, b, c;
        cin >> a >> b >> c;
        Max (a, b, c);
    } else if (c == 'b') {
        float a, b, c;
        cin >> a >> b >> c;
        Max (a, b, c);
    } else if (c == 'c') {
        int a1, a2, b1, b2, c1, c2;
        cin >> a1 >> a2;
        cin >> b1 >> b2;
        cin >> c1 >> c2;
        double x, y, z;
        x = (double) a1 / a2;
        y = (double) b1 / b2;
        z = (double) c1 / c2;
        int max = x;
        if (y > max) max = y;
        if (z > max) max = z;

        if (max == x) {
            cout << a1 << "/" << a2;
        } else if (max == y) {
            cout << b1 << "/" << b2;
        } else {
            cout << c1 << "/" << c2;
        }
    }
}

int main () {
    char c; cin >> c;
    Template (c);
    return 0;
}