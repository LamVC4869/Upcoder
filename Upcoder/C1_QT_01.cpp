#include <iostream>
#include <cmath>

using namespace std;

struct PhanSo {
    int tu, mau;
    friend istream& operator >> (istream &is, PhanSo &ps) {
        is >> ps.tu >> ps.mau;
        return is;
    }
    static int gcd (int tu, int mau) {
        int x = tu, y = mau;
        while (y) {
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    void rutGon (PhanSo &ps) {
        int ucln = gcd (ps.tu, ps.mau);
        ps.tu /= ucln;
        ps.mau /= ucln;
        if (ps.mau < 0) {
            ps.mau = abs (ps.mau);
            ps.tu *= -1;
        }
    }
    friend ostream& operator << (ostream &os, PhanSo &ps) {
        ps.rutGon (ps);
        os << ps.tu << '/' << ps.mau;
        return os;
    }
};

struct SoPhuc {
    int a, b;
    friend istream& operator >> (istream &is, SoPhuc &sp) {
        is >> sp.a >> sp.b;
        return is;
    }
    friend ostream& operator << (ostream &os, SoPhuc sp) {
        if (sp.a != 0 && sp.b != 0) {
            if (sp.b == -1) {
                os << sp.a << "-i";
            } else if (sp.b == 1) {
                os << sp.a << "+i";
            } else if (sp.b > 1) {
                os << sp.a << '+' << sp.b << 'i';
            } else {
                os << sp.a << sp.b << 'i';
            }
        }
        if (sp.b == 0) os << sp.a;
        if (sp.a == 0) {
            if (sp.b == 1) {
                os << 'i';
            } else if (sp.b == -1) {
                os << "-i";
            } else if (sp.b > 1) {
                os << sp.b << 'i';
            } else if (sp.b < 1) {
                os << sp.b << 'i';
            }
        }
        return os;
    }
    friend SoPhuc operator + (SoPhuc s1, SoPhuc s2) {
        SoPhuc s3;
        s3.a = s1.a + s2.a;
        s3.b = s1.b + s2.b;
        return s3;
    }
    friend SoPhuc operator + (SoPhuc s1, int index) {
        SoPhuc s2;
        s2.a = s1.a + index;
        s2.b = s1.b;
        return s2;
    }
    friend SoPhuc operator + (SoPhuc s1, PhanSo &ps) {
        SoPhuc s2;
        ps.rutGon (ps);
        s2.a = s1.a + ps.tu;
        s2.b = s1.b + ps.mau;
        return s2;
    }
};

int main () {
    SoPhuc x;
    cin >> x;
    char Type; cin >> Type;
    if (Type == 'i') {
        int index; cin >> index;
        cout << x << endl << index << endl << x + index;
    } else if (Type == 'p') {
        PhanSo ps; cin >> ps;
        ps.rutGon(ps);
        cout << x << endl << ps << endl << x + ps;
    } else if (Type == 'z') {
        SoPhuc y; cin >> y;
        cout << x << endl << y << endl << x + y;
    }
    return 0;
}