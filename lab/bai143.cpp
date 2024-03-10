#include <iostream>
#include <iomanip>

using namespace std;

struct HCN {
    double length, width;
    friend istream& operator >> (istream &is, HCN &hcn) {
        is >> hcn.length >> hcn.width;
        return is;
    }
    double Perimeter () {
        return double ((this->length + this->width) * 2);
    }
    friend ostream& operator << (ostream &os, HCN hcn) {
        os << "[HCN] " << hcn.length << ',' << hcn.width;
        return os;
    }
    friend double operator + (double perimiter, HCN h2) {
        return perimiter + h2.Perimeter ();
    }
    
    friend bool operator < (HCN h1, HCN h2) {
        return h1.Perimeter () < h2.Perimeter ();
    }
};


template <typename T, typename t>
struct Arr {
    int size;
    T arr[100010];
    void pushback () {
        this->size = 0;
        T index;
        while (cin >> index) this->arr[this->size++] = index;
    }
    void Out () {
        T res = this->arr[0];
        for (int i = 1; i < this->size; i++) if (this->arr[i] < res) {
            res = this->arr[i];
        }
        cout << res << endl;
    }
    t Tong () {
        t sum = 0;
        for (int i = 0; i < this->size; i++) sum = sum + this->arr[i];
        return sum;
    }
};

int main () {
    char Type; cin >> Type;
    switch (Type) {
        case 'N':
        Arr<int, int> a;
        a.pushback ();
        a.Out ();
        cout << a.Tong ();
        break;
        case 'H':
        Arr<HCN, double> b;
        b.pushback ();
        b.Out ();
        cout << fixed << setprecision (1) << b.Tong ();
        break;
    }
    return 0;
}