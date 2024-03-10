#include <iostream>

using namespace std;

struct DTBN {
    int a, b;
};

void Output (DTBN a) {
    cout << a.a << "x+" << a.b;
}

int Value (DTBN a, int x) {
    return a.a * x + a.b;
}

void Sum (DTBN a, DTBN b) {
    Output (a);
    cout << "+";
    Output (b);
    cout << "=" << (a.a + b.a) << "x+" << (a.b + b.b) << endl;
}

bool Sosanh (DTBN a, DTBN b) {
    if (a.a + a.b == b.a + b.b) return true;
    return false;
}

int main () {
    DTBN a, b;
    float x;
    cin >> a.a >> a.b;
    cin >> b.a >> b.b;
    cin >> x;
    Output (a);
    cout << endl;
    Output (b);
    cout << endl;
    Sum (a, b);
    cout << Value (a, x) << endl << Value (b, x) << endl;
    Sosanh (a, b) ? cout << "TRUE" : cout << "FALSE";

    return 0;
}