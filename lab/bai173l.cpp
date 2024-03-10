// [DHLTNC].HINHHOC.BAI4
#include <iostream>
#include <cmath>
#include <iomanip>

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

double Area (Point p[], int size = 3) {
    double ab = d (p[0], p[1]), bc = d (p[1], p[2]), ca = d (p[2], p[0]);
    double chuvi = (ab + bc + ca) / 2;
    return sqrt (chuvi * (chuvi - ab) * (chuvi - bc) * (chuvi - ca));
}

bool ktTamGiac (Point p[], int size = 3) {
    return Area (p) != 0;
}

int main () {
    Point p[3];
    for (Point &i : p) cin >> i;
    string result = (ktTamGiac (p) ? "YES" : "NO");
    cout << result << endl;
    if (result == "YES") cout << fixed << setprecision (5) << Area (p);
    return 0;
}