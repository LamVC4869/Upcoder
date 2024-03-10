#include <iostream>
#include <iomanip>

using namespace std;

struct HCN {
    double length, width;
    friend istream& operator >> (istream &is, HCN &hcn) {
        is >> hcn.length >> hcn.width;
        return is;
    }
    friend ostream& operator << (ostream &os, HCN hcn) {
        os << "[HCN] " << hcn.length << "," << hcn.width;
        return os << '\n';
    }
    double Perimeter () {
        return 2 * (length + width);
    }
    bool operator < (HCN another) {
        return this->Perimeter () < another.Perimeter ();
    }
    double operator + (double R) {
        return Perimeter () + R;
    }
    double operator = (double R) {
        R = this->Perimeter ();
        return R;
    }
};

template <typename T>
struct Arr {
    int size = 0;
    T arr[100];
    friend istream& operator >> (istream &is, Arr<T> &a) {
        T tmp;
        while (is >> tmp) a.arr[a.size++] = tmp;
        return is;
    }
    T Min () {
        T min = arr[0];
        for (int i = 1; i < size; i++) if (arr[i] < min) min = arr[i];
        return min;
    }
    double tong () {
        double res = 0;
        for (int i = 0; i < size; i++) res = arr[i] + res;
        return res;
    }
};  

int main () {
    Arr<int> a;
    Arr<HCN> b;
    char c; cin >> c;
    if (c == 'N') {
        cin >> a;
        cout << a.Min () << '\n' << a.tong ();
    } else if (c == 'H') {
        cin >> b;
        cout << b.Min () << '\n' << fixed << setprecision (1) << b.tong () * 1.0;
    }
    return 0;
}
