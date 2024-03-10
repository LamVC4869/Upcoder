#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Toado {
    float x, y;
};

void OutputofToado (Toado a) {
    cout << "(" << a.x << "," << a.y << ")" << " ";
}

float length (Toado a, Toado b) {
    return sqrt (pow (a.x - b.x, 2) + pow (a.y - b.y, 2));
}

bool ThangHang (Toado a, Toado b, Toado c) {
    return (b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x);
}

void Output (Toado a, Toado b, Toado c) {
    if (ThangHang (a, b, c)) {
        cout << -1;
    } else {
        double p = (length (a, b) + length (b, c) + length (a, c)) / 2;
        cout << fixed << setprecision (3) << sqrt (p * (p - length (a, b)) * (p - length (b, c)) * (p - length (a, c))) << " " << 2 * p;
    }
    
}

int main () {
    Toado a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    OutputofToado (a);
    OutputofToado (b);
    OutputofToado (c);
    cout << endl;

    cout << fixed << setprecision (3) << length (a, b) << endl << length (a, c) << endl << length (b, c) << endl;
    Output (a, b, c);

    return 0;
}