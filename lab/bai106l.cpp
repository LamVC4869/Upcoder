#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

double Distance (Point a, Point b) {
    return sqrt ( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Perimeter (Point a, Point b, Point c) {
    return Distance (a, b) + Distance (a, c) + Distance (b, c);
}

double Area (Point a, Point b, Point c) {
    double p = Perimeter (a, b, c) / 2;
    return sqrt (p * (p - Distance (a, b)) * (p - Distance (b, c)) * (p - Distance (a, c)));
}

bool KtHopLe (Point a, Point b, Point c) {
    return ((a.x != b.x && a.y != b.y) || (a.x != c.x && a.y != c.y) || (b.x != c.x && b.y != c.y));
}

int main () {
    Point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    if (!KtHopLe (a, b, c)) {
        cout << -1;
        return 0;
    } else {
        cout.precision (2);
        cout << fixed << Perimeter (a, b, c) << endl << Area (a, b, c);
    }
    return 0;
}