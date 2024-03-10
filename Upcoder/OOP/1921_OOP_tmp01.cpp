#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class PhanSo {
    private:
    int tu;
    int mau;
    public:
    static int gcd (int tu, int mau) {
        int x = tu, y = mau;
        while (y) {
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    void rutGon () {
        int ucln = abs (gcd (this->tu, this->mau));
        this->tu /= ucln;
        this->mau /= ucln;
        if (this->mau < 0) {
            this->mau = abs (this->mau);
            this->tu *= -1;
        }
    }
    PhanSo () : tu(0), mau(1) {}
    PhanSo (int tu, int mau) : tu(tu), mau(mau) {
        if (this->mau < 0) {
            this->mau = abs (this->mau);
            this->tu *= -1;
        }
    }
    PhanSo (const PhanSo& ps) : tu(ps.tu), mau(ps.mau) {
        if (this->mau < 0) {
            this->mau = abs (this->mau);
            this->tu *= -1;
        }
    }
    double getGiaTri () {
        return (this->tu * 1.0) / this->mau;
    }
    int getTu () {
        return tu;
    }
    int getMau () {
        return mau;
    }
    PhanSo psrutGon () {
        rutGon ();
        return *this;
    }
    PhanSo psNghichDao () {
        swap (this->tu, this->mau);
        rutGon ();
        return *this;
    }
    void output () {
        cout << this->tu << '/' << this->mau << '\n';
    }
};

int main () {
    PhanSo a, b;
    int tuA, mauA, tuB, mauB;
    cin >> tuA >> mauA >> tuB >> mauB;
    a = PhanSo (tuA, mauA), b = PhanSo (tuB, mauB);
    a.output ();
    b.output ();
    cout << a.getTu () + b.getMau () << '\n';
    cout << fixed << setprecision (3) << a.getGiaTri () << ' ' << b.getGiaTri () << '\n';
    a.psrutGon ().output ();
    b.psNghichDao ().output ();
    return 0;
}