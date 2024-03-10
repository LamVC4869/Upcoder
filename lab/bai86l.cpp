#include <iostream>
#include <cmath>

using namespace std;

struct phanso {
    int x, y;
};

int UCLN (phanso x) {
    if (x.x > x.y) {
        while (x.y != 0) {
            int temp = x.x % x.y;
            x.x = x.y;
            x.y = temp;
        }
        return x.x;
    } else {
        while (x.x != 0) {
            int tmp = x.y % x.x;
            x.y = x.x;
            x.x = tmp;
        }
        return x.y;
    }
}

void Tong (phanso a, phanso b) {
    phanso c;
    c.x = a.x * b.y + a.y * b.x;
    c.y = a.y * b.y;
    if (c.x == 0) cout << 0 << endl;
    else cout << c.x / UCLN (c) << "/" << c.y / UCLN (c) << endl;
}

void Hieu (phanso a, phanso b) {
    phanso c;
    c.x = a.x * b.y - a.y * b.x;
    c.y = a.y * b.y;
    if (c.x < 0) {
        c.x = abs (c.x);
        c.y = abs (c.y);
        cout << - (c.x / UCLN (c)) << "/" << c.y / UCLN (c) << endl;
    } else {
        cout << c.x / UCLN (c) << "/" << c.y / UCLN (c) << endl;
    }
}

void Tich (phanso a, phanso b) {
    phanso c;
    c.x = a.x * b.x;
    c.y = a.y * b.y;
    cout << c.x / UCLN (c) << "/" << c.y / UCLN (c) << endl;
}

void Thuong (phanso a, phanso b) {
    phanso c;
    c.x = a.x * b.y;
    c.y = a.y * b.x;
    cout << c.x / UCLN (c) << "/" << c.y / UCLN (c);
    
}

int main () {
    phanso a, b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    if (a.y == 0 || b.y == 0) {
        cout << -1;
        return 0;
    }
    Tong (a, b);
    if (a.x * b.y == a.y * b.x) {
        cout << 0 << endl;
    } else {
        Hieu (a, b);
    }
    if (a.x == 0 || b.x == 0) {
        cout << 0 << endl;
    } else {
        Tich (a, b);
    }
    if (a.x == 0 && b.x != 0) {
        cout << 0;
    } else if (b.x != 0 && a.x != 0) {
        Thuong (a, b);
    }

    return 0;
}