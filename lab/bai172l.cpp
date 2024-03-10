//[DHLTNC].HINHHOC.BAI1
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    friend istream& operator >> (istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
};

double d (Point a, Point b) {
    return sqrt (pow (b.x - a.x, 2) + pow (b.y - a.y, 2));
}

bool ktTamGiac (Point p[], int size = 3) {
    double ab = d (p[0], p[1]), bc = d (p[1], p[2]), ca = d (p[2], p[0]);
    double chuvi = (ab + bc + ca) / 2;
    return chuvi * (chuvi - ab) * (chuvi - bc) * (chuvi - ca) != 0;
}

int main () {
    Point p[3];
    for (Point &i : p) cin >> i;
    cout << (ktTamGiac (p) ? "YES" : "NO");
    return 0;
}