#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point {
    private:
    int x;
    int y;
    public:
    Point () {}
    Point (int x, int y) : x(x), y(y) {}
    friend Point operator- (Point A, Point B) {
        Point c;
        c.x = A.x - B.x;
        c.y = A.y - B.y;
        return c;
    }
    int getX () {
        return x;
    }
    int getY () {
        return y;
    }
    double distance (Point B) {
        return sqrt (pow (this->x - B.x, 2) + pow (this->y - B.y, 2));
    }
};

class Traingle : public Point { //Triangle
    private:
    Point A;
    Point B;
    Point C;
    public:
    Traingle () {}
    Traingle (Point A, Point B, Point C) {
        this->A = A;
        this->B = B;
        this->C = C;
    }
    double perimeter () {
        return A.distance (B) + B.distance (C) + C.distance (A);
    }
    double area () {
        double p = perimeter () / 2;
        return sqrt (p * (p - A.distance (B)) * (p - B.distance (C)) * (p - C.distance (A)));
    }
    Point center () {
        return Point ((A.getX () + B.getX () + C.getX ())/3, (A.getY () + B.getY () + C.getY ()) / 3);
    }
    bool isTraingle () {
        return (A.distance(B) > abs(B.distance(C) - C.distance(A)) && A.distance(B) < B.distance(C) + C.distance(A)) &&
               (A.distance(B) + B.distance(C) > C.distance(A) && C.distance(A) > abs(A.distance(B) - B.distance(C))) &&
               (A.distance(B) + C.distance(A) > B.distance(C) && B.distance(C) > abs(A.distance(B) - C.distance(A)));
    }
};