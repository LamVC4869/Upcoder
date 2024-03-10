#include <iostream>
#include <vector>

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

template <typename T>
struct Arr {
    int i;
    T v[1001];
    void Printf () {
        T temp;
        i = 0;
        while (cin >> temp) v[i++] = temp;
    }
    T Max () {
        T max = v[0];
        for (int j = 1; j < i; j++) {
            if (!(v[j] < max)) max = v[j];
        }
        return max;
    }
    T Tong () {
        T res = v[0];
        for (int j = 1; j < i; j++) res = res + v[j];
        return res;
    }
};

int main () {
    char Type; cin >> Type;
    switch (Type) {
    case 'A':
        Arr<int> arr;
        arr.Printf ();
        cout << arr.Max () << endl;
        cout << arr.Tong ();
        break;
    default:
        Arr<TapSoMoi> b;
        b.Printf ();
        cout << b.Max () << b.Tong ();
        break;
    }
    return 0;
}   