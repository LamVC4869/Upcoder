#include <iostream>

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
    // static int gcd (int a, int b) {
    //     int x = a, y = b;
    //     while (y) {
    //         int t = x % y;
    //         x = y;
    //         y = t;
    //     }
    //     return x;
    // }
    // void Solve () {
    //     if (this->mauSo < 0) {
    //         mauSo *= -1;
    //         tuSo *= -1;
    //     }
    //     int ucln = gcd (this->tuSo, this->mauSo);
    //     this->tuSo /= ucln, this->mauSo /= ucln;
    // }
    friend ostream& operator << (ostream &os, PhanSo ps) {
        os << ps.tuSo << '/' << ps.mauSo;
        return os;
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
    friend istream& operator >> (istream &is, HonSo &honso) {
        is >> honso.inTeger >> honso.phanso;
        return is;
    }
    friend ostream& operator << (ostream &os, HonSo honso) {
        os << honso.inTeger << ' ' << honso.phanso;
        return os;
    }
    int getInTeger () {
        return inTeger;
    }
    HonSo operator + (HonSo another) {
        HonSo result;
        result.inTeger = this->inTeger + another.inTeger;
        result.phanso = this->phanso + another.phanso;
        return result;
    }
};

int main () {
    HonSo a, b; cin >> a >> b;
    cout << a + b;
    return 0;
}