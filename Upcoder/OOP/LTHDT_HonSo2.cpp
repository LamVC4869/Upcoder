#include <iostream>
#include <cmath>

using namespace std;

class PhanSo {
    private:
    int tuSo;
    int mauSo;
    public:
    PhanSo () : tuSo(0), mauSo(1) {}
    PhanSo (int tuSo, int mauSo) : tuSo(tuSo), mauSo(mauSo) {}
    PhanSo (const PhanSo& another) : tuSo(another.tuSo), mauSo(another.mauSo) {}
    friend istream& operator >> (istream &is, PhanSo &ps) {
        is >> ps.tuSo >> ps.mauSo;
        return is;
    }
    static int gcd (int a, int b) {
        int x = a, y = b;
        while (y) {
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    void rutGon () {
        if (this->mauSo < 0) {
            this->tuSo = -this->tuSo;
            this->mauSo = -this->mauSo;
        }
        int ucln = abs (gcd (this->tuSo, this->mauSo));
        this->tuSo /= ucln;
        this->mauSo /= ucln;
    }
    int getValue () {
        return this->tuSo * this->mauSo;
    }
    friend ostream& operator << (ostream &os, PhanSo ps) {
        ps.rutGon ();
        os << ps.tuSo << '/' << ps.mauSo;
        return os;
    }
    void setTuSo (int tuSo) {
        this->tuSo = tuSo;
    }
    int getTuSo () {
        return tuSo;
    }
    int getMauSo () {
        return mauSo;
    }
    PhanSo operator + (PhanSo another) {
        PhanSo result;
        result.tuSo = this->tuSo * another.mauSo + this->mauSo * another.tuSo;
        result.mauSo = this->mauSo * another.mauSo;
        result.rutGon ();
        return result;
    }
};

class HonSo : public PhanSo {
    private:
    int inTeger;
    PhanSo phanso;
    public:
    HonSo () : inTeger(0), phanso() {}
    HonSo (int inTeger, PhanSo phanso) : inTeger(inTeger), phanso(phanso) {}
    HonSo (const HonSo& another) : inTeger(another.inTeger), phanso(another.phanso) {}
    void Solve () {
        this->phanso.rutGon ();
        if (this->inTeger < 0 && this->phanso.getValue() > 0) {
            this->phanso.setTuSo (-this->phanso.getTuSo ());
        } 
    }
    friend istream& operator >> (istream &is, HonSo &honso) {
        is >> honso.inTeger >> honso.phanso;
        return is;
    }
    friend ostream& operator << (ostream &os, HonSo honso) {
        honso.Solve ();
        os << honso.inTeger << ' ' << honso.phanso;
        return os;
    }
    int getInTeger () {
        return inTeger;
    }
    HonSo operator + (HonSo &another) {
        HonSo result;
        this->Solve ();
        another.Solve ();
        result.inTeger = this->inTeger + another.inTeger;
        result.phanso = this->phanso + another.phanso;
        result.Solve ();
        return result;
    }
};

int main () {
    HonSo a, b; cin >> a >> b;
    cout << a + b;
    return 0;
}