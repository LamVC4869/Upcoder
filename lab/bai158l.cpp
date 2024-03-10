#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14;

struct Diem {
    int x, y;
    friend istream& operator >> (istream &is, Diem &a) {
        is >> a.x >> a.y;
        return is;
    }
    friend ostream& operator << (ostream &os, Diem a) {
        os << "(" << a.x << ',' << a.y << ")";
        return os;
    }
    friend double operator - (Diem a1, Diem a2) {
        return sqrt (pow (a2.x - a1.x, 2) + pow (a2.y - a1.y, 2));
    }
    friend bool operator == (Diem a1, Diem a2) {
        return a1.x == a2.x && a1.y == a2.y;
    }
};

struct DTRON {
    Diem O;
    int r;
    friend istream& operator >> (istream &is, DTRON &d) {
        is >> d.O >> d.r;
        return is;
    }
    friend ostream& operator << (ostream &os, DTRON d) {
        os << d.O << ' ' << d.r;
        return os << endl;
    }
    double Perimeter () {
        return 2 * pi * this->r;
    }
    double Area () {
        return pi * pow (this->r, 2);
    }
    bool operator == (DTRON d) {
        return this->Perimeter () == d.Perimeter ();
    }
    bool operator < (DTRON d) {
        return this->Perimeter () < d.Perimeter ();
    }
    double operator + (DTRON d) {
        return this->Area() + d.Area ();
    }
    string ViTriTuongDoi (DTRON dt) {
        double d = this->O - dt.O;
        string result;
        if (d > abs (this->r - dt.r) && d < this->r + dt.r) result = "C";
        else if (d == abs (this->r - dt.r)) result = "TXT";
        else if (d == this->r + dt.r) result = "TXN";
        else if (d > this->r + dt.r) result = "NN";
        else if (d < abs (this->r - dt.r) && d != 0) result = "DN";
        else if (d == 0) result = "DT";
        return result;
    }
};

int main () {
    DTRON d1, d2; cin >> d1 >> d2;
    cout << d1 << d2;
    cout << roundf ((d1 + d2) * 1000) / 1000 << endl;
    if (d1 == d2) cout << "1 = 2" << endl;
    else if (d1 < d2) cout << "1 < 2" << endl;
    else cout << "1 > 2" << endl;
    cout << d1.ViTriTuongDoi (d2);
    return 0;
}