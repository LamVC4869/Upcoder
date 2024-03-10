#include <iostream>
#include <cmath>
#define endl "\n"

using namespace std;

struct Point {
    int x, y;
    friend istream& operator >> (istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, Point p) {
        os << "(" << p.x << ',' << p.y << ")";
        return os;
    }
    Point diemGanNhat (Point* &a, int size) {
        Point res = a[0];
        for (int i = 1; i < size; i++) {
            if (res.x > a[i].x || (res.x == a[i].x && res.y < a[i].y)) res = a[i];
        }
        return res;
    }
};

double d (Point a, Point b) {
    return sqrt ((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}

void haiDiemXaNhat (Point* &a, int size) {
    Point t1, t2;
    double _size = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            double _d = d (a[i], a[j]);
            if (_d > _size) {
                _size = _d;
                t1 = a[i];
                t2 = a[j];
            }
        }
    }
    cout << t1 << ' ' << t2 << endl;
}

bool kt (Point* &a, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i].x == a[j].x) return true;
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int n; cin >> n;
    Point *arr = new Point [n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << arr->diemGanNhat (arr, n) << endl;
    haiDiemXaNhat (arr, n);
    cout << (kt (arr, n) ? "YES": "NO");
    delete []arr;
    return 0;
}