#include <iostream>
#include <cmath>

using namespace std;

struct PhanSo {
    int b, c;
    friend istream& operator>> (istream &is, PhanSo &ps) {
        is >> ps.b >> ps.c;
        return is;
    }
    friend ostream& operator<< (ostream &os, PhanSo ps) {
        os << ps.b << '/' << ps.c << endl;
        return os;
    }
    friend bool operator!= (PhanSo p1, PhanSo p2) {
        return p1.b != p2.b && p1.c != p2.c;
    }
};

int UCLN (int a, int b) {
    int x = a, y = b;
    while (y) {
        int tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

struct HonSo {
    PhanSo ps;
    int a;
    friend istream& operator>>(istream &is, HonSo &hs) {
        is >> hs.a >> hs.ps.b >> hs.ps.c;
        return is;
    }
    friend ostream& operator<< (ostream &os, const HonSo hs) {
        os << hs.a << ' ' << hs.ps;
        return os;
    }
    HonSo toiGian (const HonSo hs) {
        HonSo tmp = hs;
        int ucln = UCLN (tmp.ps.b, tmp.ps.c);
        tmp.ps.b /= ucln;
        tmp.ps.c /= ucln;
        while (tmp.ps.b >= tmp.ps.c) {
            tmp.ps.b -= tmp.ps.c;
            tmp.a++;
        }
        return tmp;
    }
    PhanSo _toiGian (const HonSo &hs) {
        HonSo t = hs;
        PhanSo tg;
        tg.b = t.a * t.ps.c + t.ps.b;
        tg.c = t.ps.c;
        int ucln = UCLN (tg.b, tg.c);
        tg.b /= ucln;
        tg.c /= ucln;
        return tg;
    }
    friend bool operator!= (HonSo h1, HonSo h2) {
        return h1.a != h2.a && h1.ps.b != h2.ps.b && h1.ps.c != h2.ps.c;
    }
    int tongCacThanhPhan () {
        return a + ps.b + ps.c;
    }
    friend bool operator> (HonSo h1, HonSo h2) {
        return h1.tongCacThanhPhan () > h2.tongCacThanhPhan ();
    }
};

int main () {
    HonSo h1, h2;
    cin >> h1 >> h2;
    string Type;
    cin >> Type;
    h1 != h2 ? cout << "TRUE" << endl : cout << "FALSE" << endl;
    h1 > h2 ? cout << "TRUE" << endl : cout << "FALSE" << endl;
    if (Type == "true") {
        cout << h1.toiGian (h1) << h2.toiGian (h2);
    } else if (Type == "false") {
        cout << h1._toiGian (h1) << h2._toiGian (h2);
    }
    return 0;
}