#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Triangle {
    double a, b, c;

    bool isValidTriangle() {
        return (a + b > c && a + c > b && b + c > a);
    }

    string getType() {
        if (!isValidTriangle()) return "impossible";
        if (a == b && b == c) return "DEU";
        else if (a == b || a == c || b == c) return "CAN";
        else if (a * a == b * b + c * c || a * a + b * b == c * c || a * a + c * c == b * b) return "VUONG";
        else return "THUONG";
    }

    friend istream& operator>>(istream& is, Triangle& tg) {
        is >> tg.a >> tg.b >> tg.c;
        return is;
    }

    friend ostream& operator<<(ostream& os, Triangle t) {
        if (!t.isValidTriangle ()) os << "impossible"; 
        else os << t.getType() << " " << t.a << " " << t.b << " " << t.c;
        return os;
    }
};

int main() {
    freopen("TAMGIAC.INP", "r", stdin);
    freopen("TAMGIAC.OUT", "w", stdout);
    vector<Triangle> v;
    Triangle n; while (cin >> n) v.push_back (n);
    for (int i = 0; i < v.size (); i++) {
        cout << v[i];
        if (i < v.size () - 1) cout << endl;
    }
    return 0;
}
