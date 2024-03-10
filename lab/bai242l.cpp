#include <iostream>
#include <algorithm>

using namespace std;

struct PhanSo {
    int a, b;
    friend istream& operator >> (istream &is, PhanSo &p) {
        char c;
        is >> p.a >> c >> p.b;
        return is;
    }
    static int gcd (int a, int b) {
        int x = a, y = b;
        return y == 0 ? x : gcd (y, x % y);
    }
    PhanSo rutGon () {
        int ucln = gcd (a, b);
        a /= ucln, b /= ucln;
        return *this;
    }
    friend ostream& operator << (ostream &os, PhanSo p) {
        if (p.a == 0) os << 0;
        else if (p.b == 1) os << p.a;
        else {
            p.rutGon ();
            os << p.a << '/' << p.b;
        }
        return os;
    }
    PhanSo operator + (PhanSo another) {
        PhanSo tmp;
        tmp.a = a * another.b + b * another.a;
        tmp.b = b * another.b;
        return tmp.rutGon ();
    }
    bool operator == (PhanSo another) {
        return a * another.b == b * another.a;
    }
    bool operator > (const PhanSo& another) const {
        return a * another.b > b * another.a;
    }
    bool operator < (PhanSo another) {
        return a * another.b < b * another.a;
    }
};

template <typename T>
struct Arr {
    int n;
    T a[100];
    friend istream& operator >> (istream &is, Arr &tmp) {
        is >> tmp.n;
        for (int i = 0; i < tmp.n; i++) is >> tmp.a[i];
        return is;
    }
    friend ostream& operator << (ostream &os, Arr tmp) {
        for (int i = 0; i < tmp.n; i++) os << tmp.a[i] << ' ';
        return os;
    }
    T tongPhanTu () {
        T Sum = a[0];
        for (int i = 1; i < n; i++) Sum = Sum + a[i];
        return Sum;
    }
    T phanTuMax () {
        T maxVal = a[0];
        for (int i = 1; i < n; i++) if (a[i] > maxVal) maxVal = a[i];
        return maxVal;
    }
    void sapXep(char options) {
        if (options == '<') sort (a, a + n);
        else if (options == '>') sort (a, a + n, greater<T>());
    }
    Arr operator + (Arr another) {
        Arr res;
        res.n = min (n, another.n);
        for (int i = 0; i < res.n; i++) res.a[i] = a[i] + another.a[i];
        if (n > res.n) {
            for (int i = res.n; i < n; i++) {
                res.n++;
                res.a[i] = a[i];
            }
        } else if (res.n < another.n) {
            for (int i = res.n; i < another.n; i++) {
                res.n++;
                res.a[i] = another.a[i];
            }
        }
        return res;
    }
};

int main () {
    Arr<int> a, b, c;
    Arr<PhanSo> d, e, f;
    char Type; cin >> Type;
    if (Type == 'I') {
        cin >> a >> b;
        c = a + b;
        cout << a << endl;
        cout << "MAX 1 = " << a.phanTuMax () << endl;
        cout << "SUM 1 = " << a.tongPhanTu () << endl;
        a.sapXep ('<');
        for (int i = 0; i < a.n; i++) if (a.a[i] % 2 == 0) cout << a.a[i] << ' ';
        for (int i = 0; i < a.n; i++) if (a.a[i] % 2 != 0) cout << a.a[i] << ' ';
        cout << endl << b << endl;
        cout << "MAX 2 = " << b.phanTuMax () << endl;
        cout << "SUM 2 = " << b.tongPhanTu () << endl;
        b.sapXep ('>');
        for (int i = 0; i < b.n; i++) if (b.a[i] % 2 != 0) cout << b.a[i] << ' ';
        for (int i = 0; i < b.n; i++) if (b.a[i] % 2 == 0) cout << b.a[i] << ' ';
        cout << endl << c;
    } else if (Type == 'F') {
        cin >> d >> e;
        f = d + e;
        cout << d << endl;
        cout << "MAX 1 = " << d.phanTuMax () << endl;
        cout << "SUM 1 = " << d.tongPhanTu () << endl;
        d.sapXep ('<');
        cout << d << endl << e << endl;
        cout << "MAX 2 = " << e.phanTuMax () << endl;
        cout << "SUM 2 = " << e.tongPhanTu () << endl;
        e.sapXep ('>');
        cout << e << endl;
        cout << f;
    }
    return 0;
}