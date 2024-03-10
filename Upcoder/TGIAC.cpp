#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    friend istream& operator>>(istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator<<(ostream &os, Point &p) {
        os << "(" << p.x << ',' << p.y << ")";
        return os;
    }
    double Khoang_Cach (Point a, Point b) {
        return sqrt (pow (b.x - a.x, 2) + pow (b.y - a.y, 2));
    }
    friend bool operator==(Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }
};

struct TamGiac {
    Point a, b, c;
    friend istream& operator>>(istream &is, TamGiac &t) {
        is >> t.a >> t.b >> t.c;
        return is;
    }
    double Chuvi (TamGiac t) {
        double d1 = t.a.Khoang_Cach (a, b);
        double d2 = t.b.Khoang_Cach (b, c);
        double d3 = t.c.Khoang_Cach (c, a);
        return d1 + d2 + d3;
    }
    friend TamGiac operator+(TamGiac t1, TamGiac t2) {
        TamGiac t3;
        t3.a.x = t1.a.x + t2.a.x;
        t3.a.y = t1.a.y + t2.a.y;
        t3.b.x = t1.b.x + t2.b.x;
        t3.b.y = t1.b.y + t2.b.y;
        t3.c.x = t1.c.x + t2.c.x;
        t3.c.y = t1.c.y + t2.c.y;
        return t3;
    }
    friend bool operator<(TamGiac t1, TamGiac t2) {
        return t1.Chuvi (t1) < t2.Chuvi (t2);
    }
    friend bool operator== (TamGiac t1, TamGiac t2) {
        return  (t1.a == t2.a && t1.b == t2.b && t1.c == t2.c) ||
                (t1.a == t2.b && t1.b == t2.c && t1.c == t2.a) ||
                (t1.a == t2.c && t1.b == t2.a && t1.c == t2.b) ||
                (t1.a == t2.a && t1.b == t2.c && t1.c == t2.b) ||
                (t1.a == t2.b && t1.b == t2.a && t1.c == t2.c) ||
                (t1.a == t2.c && t1.b == t2.b && t1.c == t2.a);
    }
};

int main () {
    TamGiac t1, t2;
    cin >> t1;
    cin >> t2;
    cout << t1.a << t1.b << t1.c << endl;
    cout << t2.a << t2.b << t2.c << endl;
    t1 < t2 ? cout << "TRUE" << endl : cout << "FALSE" << endl;
    t1 == t2 ? cout << "TRUE" : cout << "FALSE";
    return 0;
}