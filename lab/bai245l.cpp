#include <iostream>
#include <cmath>

using namespace std;

struct PhanSo {

};

struct DTHANG {
    int a, b, c;
    friend istream& operator >> (istream &is, DTHANG &dt) {
        is >> dt.a >> dt.b >> dt.c;
        return is;
    }
    friend ostream& operator << (ostream &os, DTHANG dt) {
        if (dt.a != 0) {
            if (dt.a < 0) os << "-";
            if (abs(dt.a) != 1) os << abs(dt.a);
            os << "x";
        }
        if (dt.b != 0) {
            if (dt.b > 0 && dt.a != 0) os << " + ";
            if (dt.b < 0 && dt.a != 0) os << " - ";
            if (dt.b < 0 && dt.a == 0) os << "-";
            if (abs(dt.b) != 1) os << abs(dt.b);
            os << "y";
        }
        if (dt.c != 0) {
            if (dt.c > 0 && (dt.a != 0 || dt.b != 0)) os << " + " << dt.c;
            else if (dt.a == 0 && dt.b == 0 && dt.c > 0) os << dt.c;
            if (dt.c < 0 && (dt.a != 0 || dt.b != 0)) os << " - " << abs (dt.c);
            else if (dt.a == 0 && dt.b == 0 && dt.c < 0) os << dt.c;
        }   
        return os << " = 0" << endl;
    }
    bool operator == (DTHANG dt) {
        return a == dt.a && b == dt.b && c == dt.c;
    }
    string vttd (DTHANG dt) {
        string res;
        int d = a * dt.b - b * dt.a;
        int dx = (-c) * dt.b - b * (-dt.c);
        int dy = a * (-dt.c) - (-c) * dt.a;
        if ((d == 0 && dx == 0 && dy == 0) || *this == dt) res = "T";
        else if (a * dt.a + b * dt.b == 0) res = "V";
        else if (d == 0 && dx != 0 && dy != 0)
        return res;
    }
};

int main () {
    DTHANG d1, d2;
    cin >> d1 >> d2;
    cout << d1 << d2;
    return 0;
}