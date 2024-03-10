#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Geometry {
    public:
    virtual double perimeter () = 0;
    virtual double area () = 0;
    virtual void display () {
        cout << "Perimeter: " << perimeter () << endl;
        cout << "Area: " << area () << endl;
    }
};

class Traingle : public Geometry { //triangle
    private:
    int a;
    int b;
    int c;
    public:
    Traingle () {}
    Traingle (int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double perimeter () {
        return a + b + c;
    }
    double area () {
        double p = perimeter () / 2;
        return sqrt (p * (p - a) * (p - b) * (p - c));
    }
};  

class Circle : public Geometry {
    private:
    int r;
    public:
    Circle () {}
    Circle (int r) {
        this->r = r;
    }
    double perimeter () {
        return 2 * 3.14 * r;
    }
    double area () {
        return 3.14 * r * r;
    }
};

class Rectangle : public Geometry {
    private:
    int h;
    int w;
    public:
    Rectangle () {}
    Rectangle (int h, int w) {
        this->h = h;
        this->w = w;
    }
    double perimeter () {
        return 2 * (h + w);
    }
    double area () {
        return h * w;
    }
};