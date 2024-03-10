#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point2d {
    int x, y;
    friend istream& operator >> (istream &is, Point2d &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, Point2d p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    friend double operator - (Point2d p1, Point2d p2) {
        return sqrt (pow (p2.x - p1.x, 2) + pow (p2.y - p1.y, 2));
    }
    friend bool operator < (Point2d p1, Point2d p2) {
        if (p1.x < p2.x) return true;
        else if (p1.x == p2.y) {
            if (p1.y < p2.y) return true;
        }
        return false;
    }
};

struct Point3d {
    Point2d p;
    int z;
    friend istream& operator >> (istream &is, Point3d &pt) {
        is >> pt.p >> pt.z;
        return is;
    }
    friend ostream& operator << (ostream &os, Point3d pt) {
        os << '(' << pt.p.x << ", " << pt.p.y << ", " << pt.z << ')';
        return os;
    }
    friend double operator - (Point3d p1, Point3d p2) {
        return sqrt (pow (pow (p2.p - p1.p, 2), 2) + pow (p2.z - p1.z, 2));
    }
    friend bool operator < (Point3d p1, Point3d p2) {
        if (p1.p.x < p2.p.x) return true;
        else if (p1.p.x == p2.p.x) {
            if (p1.p.y < p2.p.y) return true;
            else if (p1.p.y == p2.p.y) {
                if (p1.z < p2.z) return true;
            }
        }
        return false;
    }
};

template <typename T>
struct Arr {
    vector<T> arr;
    
};

int main () {
    
    return 0;
}