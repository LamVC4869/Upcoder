#include <iostream>

using namespace std;

class TapSoMoi {
    private:
    int x;
    int y;
    int z;
    int t;
    public:
    TapSoMoi () : x(0), y(0), z(0), t(0) {}
    TapSoMoi (int x, int y, int z, int t) : x(x), y(y), z(z), t(t) {}
    friend istream& operator >> (istream &is, TapSoMoi &tsm) {
        is >> tsm.x >> tsm.y >> tsm.z >> tsm.t;
        return is;
    } 
    friend ostream& operator << (ostream &os, TapSoMoi tsm) {
        os << "[TapSoMoi] " << tsm.x << ';' << tsm.y << ';' << tsm.z << ';' << tsm.t << endl;
        return os;
    }
    TapSoMoi operator + (const TapSoMoi another) {
        TapSoMoi res;
        res.x = this->x + another.x;
        res.y = this->y + another.y;
        res.z = this->z + another.z;
        res.t = this->t + another.t;
        return res;
    }
    int getTong () {
        return x + y + z + t;
    }
    friend bool operator < (TapSoMoi t1, TapSoMoi t2) {
        return t1.getTong () < t2.getTong ();
    }
    TapSoMoi& operator = (const TapSoMoi& another) {
        this->x = another.x;
        this->y = another.y;
        this->z = another.z;
        this->t = another.t;
        return *this;
    }
    TapSoMoi& operator ++ (int) {
        this->x++, this->t++;
        return *this;
    }
};

int main () {
    TapSoMoi t1, t2, t3; cin >> t1 >> t2;
    cout << t1 << t2;
    cout << ((t1 < t2) ? "true" : "false") << endl;
    cout << t1 + t2;
    cout << t1++;
    return 0;
}   