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
    friend istream& operator >> (istream &is, PhanSo &ps) {
        is >> ps.tu >> ps.mau;
        if (ps.mau < 0) {
            ps.mau = abs (ps.mau);
            ps.tu *= -1;
        }
        return is;
    }
    friend ostream& operator << (ostream &os, PhanSo ps) {
        ps.rutGon ();
        os << ps.tu << '/' << ps.mau;
        return os << '\n';
    }
    PhanSo operator + (PhanSo another) {
        PhanSo ps;
        ps.tu = this->tu * another.mau + this->mau * another.tu;
        ps.mau = this->mau * another.mau;
        ps.rutGon ();
        return ps;
    }
    PhanSo operator - (PhanSo another) {
        PhanSo ps;
        ps.tu = this->tu * another.mau - this->mau * another.tu;
        ps.mau = this->mau * another.mau;
        ps.rutGon ();
        return ps;
    }
    PhanSo operator * (PhanSo another) {
        PhanSo ps;
        ps.tu = this->tu * another.tu;
        ps.mau = this->mau * another.mau;
        ps.rutGon ();
        return ps;
    }
    PhanSo operator / (PhanSo another) {
        PhanSo ps;
        ps.tu = this->tu * another.mau;
        ps.mau = this->mau * another.tu;
        ps.rutGon ();
        return ps;
    }
    bool operator < (PhanSo another) {
        return this->getGiaTri () < another.getGiaTri ();
    }
};

int main () {
    int n, m; cin >> n >> m;
    PhanSo arr[n];
    for (PhanSo &i : arr) cin >> i;
    PhanSo tong, hieu, max, min;
    tong = hieu = max = min = arr[0];
    for (int i = 1; i < n; i++) {
        tong = tong + arr[i];
        hieu = hieu - arr[i];
        if (max < arr[i]) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    if (m == 0) cout << tong << max * min;
    else if (m == 1) cout << hieu << max / min;
    return 0;
}