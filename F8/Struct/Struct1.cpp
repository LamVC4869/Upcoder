#include <iostream>

using namespace std;

struct Circle {
    double r;
    friend istream& operator>>(istream &s, Circle &c) {
        cout << "Nhap ban kinh: ";
        s >> c.r;
        return s;
    }
    // friend ostream& operator<<(ostream &os, Circle c) {
    //     os << "Chu vi hinh tron: " << c.r * 2 * 3.14 << endl;
    //     os << "Dien tich hinh tron: " << c.r * c.r * 3.14;
    //     return os;
    // }
    double chu_vi () {
        return r * 2 * 3.14;
    }
    double dien_tich () {
        return r * r * 3.14;
    }
};

int main () {
    Circle a;
    cin >> a;
    cout << "Chu vi hinh tron: " << a.chu_vi() << endl;
    cout << "Dien tich hinh tron: " << a.dien_tich ();
    return 0;
}